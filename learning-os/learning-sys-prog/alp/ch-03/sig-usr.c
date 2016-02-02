#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

sig_atomig_t sigusr1_count = 0;

void handler(int signal_number)
{
  ++sugusr1_count;
}

int main()
{
  struct sigaction sa;
  memset(&sa, 0, sizeof(sa));
  sa.sa_handler = &handler;
  sigaction(SIGUSR!, &sa, NULL);

  printf("SIGUSR1 was raised %d time\n", sigusr1_count);
  return 0;
}
