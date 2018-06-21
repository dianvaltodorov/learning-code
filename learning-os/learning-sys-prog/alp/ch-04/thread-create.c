#include <pthread.h>
#include <stdio.h>

// TO RUN: gcc -pthread -o a.out thread-create.c 

void* print_xs(void *unused)
{
  while(1)
  {
    fputc('X', stderr);
  }
  return NULL;
}

int main()
{
  pthread_t thread_id;
  pthread_create (&thread_id, NULL, &print_xs, NULL);

  while(1)
  {
    fputc('o', stderr);
  }
  return 0;
}
