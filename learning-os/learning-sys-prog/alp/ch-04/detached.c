#include <pthread.h>
#include <stdio.h>

void* thread_function(void* thread_arg)
{
    printf("Hello world");
    return NULL;
}

int main()
{
    pthread_attr_t attr;
    pthread_t thread;
    
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    pthread_create(&thread, &attr, &thread_function, NULL);
    pthread_attr_destroy(&attr);

    return 0;
}

