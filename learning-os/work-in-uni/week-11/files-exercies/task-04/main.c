#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//int main(int argc, char* argv[])
int main(int argc, char* argv[])
{
  int fd1, fd2;
  int i = 0;
  char c;

  if (argc != 3) {
    write(2, "err\n", 4);
    exit(-1);
  }

  int n = strlen(argv[2]));
  if(argv[2][n - 1] == '\\')
  {

  }
  else
  {

  }


  if ((fd1 = open(argv[1], O_RDONLY)) == -1) {
    err(1, "%s", argv[1]);
  }

  if ((fd2 = open(argv[2], O_WRDONLY)) == -1) {
    close(fd1);
    err(1, "%s", argv[2]);
  }

  while (read(fd1, &c, 1)) {
    if (c == '\n') {
      i=i+1;
    }

    write(1, &c, 1);

    if (i == 10) {
      close(fd1);
      exit(0);
    }
  }

  close(fd1);
  close(fd2);
  exit(0);
}
