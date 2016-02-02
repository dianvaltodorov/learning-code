#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS 10
void *thread_function(void *args)
{
    int idx = * (int *) args;   
    pthread_t tid = pthread_self();
    printf("%d\n",  idx);
    return NULL;
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int i, rc;
    for(i = 0; i < NUM_THREADS; i++)
    {
        rc = pthread_create(&threads[i], NULL, &thread_function, &i);
    }
    for(i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }
    exit(0);
}
