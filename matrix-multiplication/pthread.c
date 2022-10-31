// Pthread program for matrix multiplication
// Note: Refer README file for more information.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define N 1000
#define NUM_THREADS 4

// Declare global variables
int n;
int **a, **b, **c;

// Thread function for matrix multiplication
void *threadFunc(void *arg) {
    int x, low, high;

    // Calculate which rows to calculate by each thread
    x = n / NUM_THREADS;
    low = x * (int) arg;
    high = low + x;

    int i, j, k;
    for (i = low; i < high; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    pthread_exit(NULL);
}

// Main function
int main() {
    // Declare local variables
    struct timeval start, stop;
    n = N;
    int i, j;
    pthread_t tid[NUM_THREADS];
    double cpu_time_used;

    a = (int **) malloc(n * sizeof(int *));
    b = (int **) malloc(n * sizeof(int *));
    c = (int **) malloc(n * sizeof(int *));

    // Allocate memory for matrices
    for (i = 0; i < n; i++) {
        a[i] = (int *) malloc(n * sizeof(int));
        b[i] = (int *) malloc(n * sizeof(int));
        c[i] = (int *) malloc(n * sizeof(int));
    }
    
    // Initialize matrices with random values
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            a[i][j] = rand() % 10;
            b[i][j] = rand() % 10;
        }
    }

    // Create threads
    mingw_gettimeofday(&start, 0);
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&tid[i], NULL, threadFunc, (void *)i);
    }

    // Join threads
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(tid[i], NULL);
    }
    mingw_gettimeofday(&stop, 0);
    
    // Calculate time taken
    cpu_time_used = (stop.tv_sec - start.tv_sec) + (stop.tv_usec - start.tv_usec) / 1000000.0;
    printf("Time taken: %f", cpu_time_used);

    return 0;
}
// End of main()
// End of pthread.c