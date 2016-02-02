#include <malloc.h>
#include <pthread.h>

void* allocate_buffer(size_t size)
{
    return malloc(size);
}

void deallocate_buffer(void* buffer)
{
    free(buffer);
}

void do_some_work()
{
    void* temp_buffer = allocate_buffer(1024);
    pthread_cleanup_push (deallocate_buffer, temp_buffer); 
    pthread_cleanup_pop (1);
}
