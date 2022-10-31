// Sequential program for matrix multiplication
// Note: Refer README file for more information.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000

// Declare global variables
int n;
int **a, **b, **c;

// Main function
int main() {
    // Declare local variables
    n = N;
    int i, j, k;
    a = (int **) malloc(n * sizeof(int *));
    b = (int **) malloc(n * sizeof(int *));
    c = (int **) malloc(n * sizeof(int *));
    struct timeval start, stop;
    double cpu_time_used;
    
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

    // Perform matrix multiplication
    mingw_gettimeofday(&start, 0);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    mingw_gettimeofday(&stop, 0);

    // Calculate time taken for sequential code
    cpu_time_used = (stop.tv_sec - start.tv_sec) + (stop.tv_usec - start.tv_usec) / 1000000.0;
    printf("Time taken: %f", cpu_time_used);
    
    return 0;
}
// End of main()
// End of seq.c