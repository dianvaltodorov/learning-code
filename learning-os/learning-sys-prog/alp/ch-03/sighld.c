#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

sig_atomic_t child_exit_status;

void clean_up_child_process(int signal_number)
{
  int status;
  wait(&status);
  child_exit_status = status;
}

int main()
{
  struct sigaction sigchld_action;
  memset (&sigchld_action, 0, sizeof (sigchld_action));
  sigchld_action.sa_handler = &clean_up_child_process;
  sigaction (SIGCHLD, &sigchld_action, NULL);
  /* Now do things, including forking a child process.
  /* ... */
  */
  return 0;
}
