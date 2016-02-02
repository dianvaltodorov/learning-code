#include <sys/ipc.h>
#include <sys/sem.h>
#include <sts/types.h>

union semun
{
    int val;
    struct semid_ds  *buf;
    unsigned short int *array;
    struct seminfo *__buf;
}
