#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

// TODO: run -e -o pid,ppid,stat,cmd
// TODO: what does defunct mean?
// TODO: difference between zombie and daemon?
int main()
{
  pid_t child_pid;

  child_pid = fork();
  if(child_pid > 0)
  {
    sleep(600);
  }
  else
  {
    exit(0);
  }
  //TODO: does it even go here?
  return 0;
}
