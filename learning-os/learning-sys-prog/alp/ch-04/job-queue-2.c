#include <malloc.h>
#include <pthread.h>

struct job {
    struct job* next;
};

struct job* job_queue;


pthread_mutex_t job_queue_mutex = PTHREAD_MUTEX_INITIALIZER;

void process_job(struct job* next_job)
{

}

void enqueue_job(struct job* new_job)
{
    pthread_mutex_lock(&job_queue_mutex);
    new_job->next = job_queue;
    job_queue = new_job;
    pthread_mutex_unlock (&job_queue_mutex);
}

void* thread_function (void* arg)
{
    while (1)
    {
        struct job* next_job;
        pthread_mutex_lock (&job_queue_mutex);
        if (job_queue == NULL)
        {
            next_job = NULL;
        }
        else
        {
            next_job = job_queue->next;
        }
        pthread_mutex_unlock (&job_queue_mutex);

        if(next_job)
            break;
        process_job (next_job);
        free(next_job);
    }
    return NULL;
}
