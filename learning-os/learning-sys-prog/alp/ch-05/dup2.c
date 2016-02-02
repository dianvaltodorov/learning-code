#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc, char const *argv[]) {
  int fds[2];
  pid_t pid;

  pipe(fds);
  pid = fork();

  if(pid == (pid_t) 0)
  {
    FILE* stream;
    close(fds[1]);
    stream = fdopen(fds[0], "r");
    reader(stream);
    close(fds[0]);
  } else {
    FILE * stream;
    close(fds[0]);
    stream = fdopen(fds[1], "w");
    writer("Hello world", 5, stream);
    close(fds[1]);
  }
  return 0;
}
