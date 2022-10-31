// Pthread program to get nth triangular number.
// Note: Refer README file for more information.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pthread.h>

#define N 1000000000
#define NUM_THREADS 4

int sum = 0;
pthread_mutex_t mutex;

// Thread function
void *sum_triangular(void *arg)
{
    int i, j;
    int start = (uintptr_t)arg;
    int end = start + N / NUM_THREADS;
    int local_sum = 0;
    for (i = start; i < end; i++) {
        local_sum += i;
    }

    // Update shared variable sum
    pthread_mutex_lock(&mutex);
    sum += local_sum;
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main()
{
    // Initialization of variables
    struct timeval start, end;
    int i, j;
    double time_taken;
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&mutex, NULL);
    
    // Creating threads
    mingw_gettimeofday(&start, NULL);
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, sum_triangular, (void *)(uintptr_t)(i * N / NUM_THREADS));
    }
    // Joining threads
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    mingw_gettimeofday(&end, NULL);

    // Calculating time taken by the pthread parallel code segment
    time_taken = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

    printf("Time taken to execute (pthread) : %f\n", time_taken);
    
    return 0;
}