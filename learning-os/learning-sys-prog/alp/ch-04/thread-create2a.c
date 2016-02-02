#include <pthread.h>
#include <stdio.h>

// TO RUN: gcc -pthread -o a.out thread-create.c

struct char_print_params
{
  char character;
  int count;
};

void* char_print(void* parameters)
{
  struct char_print_params* p = (struct char_print_params*) parameters;
  int i;
  printf("%c\n", p->character);
  printf("%d\n", p->count);
  for(i = 0; i < p->count; ++i)
    fputc(p->character, stderr);
  return NULL;
}

int main()
{
  pthread_t thread1_id;
  pthread_t thread2_id;

  struct char_print_params thread1_args;
  struct char_print_params thread2_args;

  thread1_args.character = 'x';
  thread1_args.count = 4;
  pthread_create(&thread1_id, NULL, &char_print, &thread1_args);

  thread2_args.character = 'o';
  thread2_args.count = 2;
  pthread_create(&thread2_id, NULL, &char_print, &thread2_args);;
  printf("YOLO\n");
  return 0;
}
