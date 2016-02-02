#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    pid_t child_pid;
    printf("the main program process ID is %d\n", (int)getpid());

    child_pid = fork();
    if(child_pid != 0)
    {
        printf("this is the parent process with process ID %d\n", (int)getpid());
        printf("the child process ID is %d", (int)child_pid);
    }
    else
    {
        printf("this is the child process with id %d\n", getpid());
    }
    return 0;
}
