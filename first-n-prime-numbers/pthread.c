// Pthread code to get first n prime numbers
// Note: Refer README file for more information.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pthread.h>

#define N 1000000
#define N_THREADS 8

// Declare global variables
int count = 0;
int n;

// Function to check if a number is prime
int isPrime(int n) {
    int i;
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}
// End of isPrime()

// Function to be executed by each thread
void *getPrimes(void *threadid) {
    unsigned long tid;
    tid = (uintptr_t)threadid;
    int i;
    for (i = 2 + tid; count < n; i += N_THREADS) {
        if (isPrime(i)) {
            count++;
        }
    }
    pthread_exit(NULL);
}
// End of getPrimes()

// Main function
int main() {
    // Declare variables
    n = N;
    pthread_t threads[N_THREADS];
    int rc;
    long t;
    struct timeval start, stop;
    double cpu_time_used;
    
    printf("Pthread code to get first %d prime numbers\n", n);
    printf("Threads: %d\n\n", N_THREADS);
    
    // Create threads
    mingw_gettimeofday(&start, 0);
    for(t=0; t<N_THREADS; t++){
        rc = pthread_create(&threads[t], NULL, getPrimes, (void *)(intptr_t)t);
        if (rc){
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    // Wait for threads to finish
    for(t=0; t<N_THREADS; t++){
        pthread_join(threads[t], NULL);
    }
    mingw_gettimeofday(&stop, 0);

    // Calculate time taken
    cpu_time_used = (stop.tv_sec - start.tv_sec) + (stop.tv_usec - start.tv_usec) / 1000000.0;
    printf("Time taken: %f", cpu_time_used);

    pthread_exit(NULL);
}
// End of main function
// End of pthread.c

