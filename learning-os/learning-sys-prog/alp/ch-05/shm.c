#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>

int main()
{
  int segment_id;
  char* shared_memory;
  struct shmid_ds shmbuffer;
  int segment_size;
  const int share_segment_size=0x6400;

  segment_id = shmget(IPC_PRIVATE, share_segment_size, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);

  shared_memory = (char* ) shmat(segment_id, 0, 0);
  printf("Shared memory attached at address %p\n", shared_memory);

  shmctl(segment_id, IPC_STAT, &shmbuffer);
  shmdt (shared_memory);
  printf("%d\n", share_segment_size);
  return 0;
}
