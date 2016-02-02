#include <malloc.h>

struct job
{
    struct job* next;
};

struct job* job_queue;

void process_job(struct job* next_job)
{
    
}
void* thread_function(void* arg)
{
        while(job_queue)
        {
            struct job* next_job = job_queue;
            job_queue = job_queue->next;
            process_job(next_job);
            free(job_queue);
        }
        return NULL;
}
