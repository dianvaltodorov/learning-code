#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define BUFFSIZE 1024

int main()
{
    char buff[BUFFSIZE];
    size_t readlen, writelen, slen;
    pid_t cpid, mypid;
    pid_t pid = getpid();
    printf("Parent pid: %d\n", pid);
    cpid = fork();
    if(cpid > 0)
    {
        mypid = getpid();
        printf("[%d] parent of [%d]\n", mypid, cpid);
    }
    else if (cpid == 0)
    {
        mypid = getpid();
        printf("[%d] child\n", mypid);
    }
    else 
    {
        perror("Fork failed");
        exit(1);
    }
    exit(0);
} 
