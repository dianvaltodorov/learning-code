#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define NTHREADS      4
#define ARRAYSIZE   1000
#define ITERATIONS   ARRAYSIZE / NTHREADS

double  sum=0.0, a[ARRAYSIZE];
pthread_mutex_t sum_mutex;


void *do_work(void *tid) 
{
    int i, start, *mytid, end;
    double mysum=0.0;
    mytid = (int *) tid;
    start = (*mytid * ITERATIONS);
    end = start + ITERATIONS;
    printf ("Thread %d doing iterations %d to %d\n",*mytid,start,end-1); 
    for (i=start; i < end ; i++) 
    {
        mysum = mysum + a[i];
    }
    pthread_mutex_lock (&sum_mutex);
    sum = sum + mysum;
    pthread_mutex_unlock (&sum_mutex);
    pthread_exit(NULL);
}


void main()
{
    int i, start, tids[NTHREADS];

    srand(time(NULL));
    for (i=0; i<ARRAYSIZE; i++)
    {
        a[i] = rand() % 20;  
    }

    for(i = 0; i < 10; i++)
    {
        printf("%f\n", a[i]);
    }
    pthread_t threads[NTHREADS];
    pthread_attr_t attr;
    pthread_mutex_init(&sum_mutex, NULL);
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    for (i=0; i<NTHREADS; i++) 
    {
       tids[i] = i;
       pthread_create(&threads[i], &attr, do_work, (void *) &tids[i]);
    }
    for (i=0; i<NTHREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }
    printf ("Done. Sum= %e \n", sum);
    sum=0.0;
    for (i=0;i<ARRAYSIZE;i++)
    { 
        sum = sum + a[i];
    }
    printf("Check Sum= %e\n",sum);
    pthread_attr_destroy(&attr);
    pthread_mutex_destroy(&sum_mutex);
    pthread_exit (NULL);
}

