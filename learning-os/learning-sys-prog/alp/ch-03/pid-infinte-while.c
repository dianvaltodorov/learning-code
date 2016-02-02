#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

//TODO: Why the output?
int main()
{
  pid_t child_pid;
  printf("the main programm process ID is %d\n", (int) getpid());
  child_pid = fork();
  if(child_pid != 0)
  {
    while(1)
    {
      printf("XXXX thi is the parent process, with id %d'n. The child's process ID is %d\n", (int) getpid(), (int) child_pid);
    }
  }
  else
  {
    while(1)
    {
      printf("this is the child process with id %d\n", (int) getpid());
    }
  }
  return 0;
}
