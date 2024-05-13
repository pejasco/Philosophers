Given the constraints, you can use a combination of a mutex and a shared counter to synchronize the threads. Here's how you might modify the all_threads_created function:

#include <pthread.h>

pthread_mutex_t mutex;
int ready_threads = 0;

void *thread_function(void *arg)
{
    // Thread initialization code...

    // Lock the mutex before updating the shared counter
    pthread_mutex_lock(&mutex);
    ready_threads++;
    pthread_mutex_unlock(&mutex);

    // Rest of the thread function...
}

void all_threads_created(t_feast *feast)
{
    // Initialize mutex
    pthread_mutex_init(&mutex, NULL);

    // Create threads
    for (int i = 0; i < feast->num_threads; i++)
    {
        pthread_create(&feast->threads[i], NULL, thread_function, NULL);
    }

    // Wait for all threads to be ready
    while (1)
    {
        pthread_mutex_lock(&mutex);
        if (ready_threads == feast->num_threads)
        {
            pthread_mutex_unlock(&mutex);
            break;
        }
        pthread_mutex_unlock(&mutex);

        // Sleep for a short time to reduce CPU usage
        usleep(100);
    }

    // Destroy mutex
    pthread_mutex_destroy(&mutex);
}

In this code, each thread increments a shared counter (ready_threads) when it's ready. The main thread checks this counter in a loop and breaks the loop when all threads are ready. To prevent race conditions, a mutex is used to ensure that only one thread can update the counter at a time.

Please note that this code still uses a form of busy waiting, but it's more efficient than the original code because it includes a call to usleep() to reduce CPU usage. Also, this code assumes that feast->num_threads is the number of threads and feast->threads is an array of pthread_t that holds the threads.
