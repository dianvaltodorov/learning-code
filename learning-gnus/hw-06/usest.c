#include <stdio.h>
#include <signal.h>
#include <syslog.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DAEMON_NAME "usest"
#define COMMAND "who | cut -d' ' -f1 | sort | uniq"

#define RUNDIR "/tmp/"
#define PID_FILE "/tmp/usestdaemon.pid"

void daemon_shutdown();
void signal_handler(int sig);
void daemonize(char *rundir, char *pidfile);

int pid_file_handle;

void signal_handler(int sig)
{
    switch (sig)
    {
    case SIGHUP:
        syslog(LOG_WARNING, "Received SIGHUP signal.");
        break;
    case SIGINT:
    case SIGTERM:
        syslog(LOG_INFO,  "Daemon exiting");
        daemon_shutdown();
        exit(EXIT_SUCCESS);
        break;
    default:
        syslog(LOG_WARNING, "Unhandled signal %s", strsignal(sig));
        break;
    }
}

void daemon_shutdown()
{
    close(pid_file_handle);
}

void daemonize(char *rundir, char *pidfile)
{
    int pid, sid, i;
    char str[10];
    struct sigaction new_sig_action;
    sigset_t new_sig_set;

    /* Check if parent process id is set */
    if (getppid() == 1)
    {
        /* PPID exists, therefore we are already a daemon */
        return;
    }

    /* Set signal mask - signals we want to block */
    sigemptyset(&new_sig_set);
    sigaddset(&new_sig_set, SIGCHLD);           /* ignore child - i.e. we don't need to wait for it */
    sigaddset(&new_sig_set, SIGTSTP);           /* ignore Tty stop signals */
    sigaddset(&new_sig_set, SIGTTOU);           /* ignore Tty background writes */
    sigaddset(&new_sig_set, SIGTTIN);           /* ignore Tty background reads */
    sigprocmask(SIG_BLOCK, &new_sig_set, NULL); /* Block the above specified signals */

    /* Set up a signal handler */
    new_sig_action.sa_handler = signal_handler;
    sigemptyset(&new_sig_action.sa_mask);
    new_sig_action.sa_flags = 0;

    /* Signals to handle */
    sigaction(SIGHUP, &new_sig_action, NULL);  /* catch hangup signal */
    sigaction(SIGTERM, &new_sig_action, NULL); /* catch term signal */
    sigaction(SIGINT, &new_sig_action, NULL);  /* catch interrupt signal */

    /* Fork*/
    pid = fork();

    if (pid < 0)
    {
        /* Could not fork */
        exit(EXIT_FAILURE);
    }

    if (pid > 0)
    {
        /* Child created ok, so exit parent process */
        printf("Child process created: %d\n", pid);
        exit(EXIT_SUCCESS);
    }

    /* Child continues */

    umask(027); /* Set file permissions 750 */

    /* Get a new process group */
    sid = setsid();

    if (sid < 0)
    {
        exit(EXIT_FAILURE);
    }

    /* close all descriptors */
    for (i = getdtablesize(); i >= 0; --i)
    {
        close(i);
    }

    /* Route I/O connections */

    /* Open STDIN */
    i = open("/dev/null", O_RDWR);

    /* STDOUT */
    dup(i);

    /* STDERR */
    dup(i);

    chdir(rundir); /* change running directory */

    /* Ensure only one copy */
    pid_file_handle = open(pidfile, O_RDWR | O_CREAT, 0600);

    if (pid_file_handle == -1)
    {
        /* Couldn't open lock file */
        syslog(LOG_INFO, "Could not open PID lock file %s, exiting", pidfile);
        exit(EXIT_FAILURE);
    }

    /* Try to lock file */
    if (lockf(pid_file_handle, F_TLOCK, 0) == -1)
    {
        /* Couldn't get lock on lock file */
        syslog(LOG_INFO, "Could not lock PID lock file %s, exiting", pidfile);
        exit(EXIT_FAILURE);
    }

    /* Get and format PID */
    sprintf(str, "%d\n", getpid());

    /* write pid to lockfile */
    write(pid_file_handle, str, strlen(str));
}

int main ( int argc, char *argv[] )
{

    setlogmask(LOG_UPTO(LOG_INFO));
    openlog(DAEMON_NAME, LOG_CONS | LOG_PERROR, LOG_USER);


    if ( argc != 2 ) /* argc should be 2 for correct execution */
    {
        printf( "usage: %s filename", DAEMON_NAME);
        exit(1);
    }

    char tracked_user[1024];
    FILE *fptr;

    if ((fptr = fopen(argv[1], "r")) == NULL)
    {
        syslog(LOG_ERR, "Error opening config file");
        exit(1);         
    }
    fscanf(fptr,"%s", tracked_user);

    fclose(fptr);
    
    
    /* Debug logging
    setlogmask(LOG_UPTO(LOG_DEBUG));
    openlog(DAEMON_NAME, LOG_CONS, LOG_USER);
    */

    /* Logging */
    syslog(LOG_INFO, "Starting sesion tracking for user %s", tracked_user);

    /* Deamonize */
    daemonize(RUNDIR, PID_FILE);

    syslog(LOG_INFO, "Tracking sessions for user %s running", tracked_user);

    FILE *fp;
    int logged = 0;
    int running_session = 0;
    char user[1035];

    while (1)
    {
        fp = popen(COMMAND, "r");
        if (fp == NULL)
        {
            syslog(LOG_ERR, "Failed to run command");
            exit(1);
        }

        logged = 0;
        while (fgets(user, sizeof(user) - 1, fp) != NULL)
        {
            user[strcspn(user, "\r\n")] = 0;
            if (strcmp(user, tracked_user) == 0)
            {
                logged = 1;
            }
        }

        if (running_session == 0 && logged == 1)
        {
            syslog(LOG_INFO, "Tracked user %s logged in", tracked_user);
            running_session = 1;
        }

        else if (running_session == 1 && logged == 0)
        {
            syslog(LOG_INFO, "Tracked user %s logged out", tracked_user);
            running_session = 0;
        }
        sleep(1);
    }
}