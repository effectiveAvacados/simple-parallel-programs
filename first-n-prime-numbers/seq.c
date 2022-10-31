// Sequential code to get first n prime numbers

// Language: C

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 1000000

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

// Main function
int main(int argc, char *argv[]) {
    // Declare variables
    int n = N;
    int i, count = 0;
    struct timeval start, stop;
    double cpu_time_used;
    printf("Sequential code to get first %d prime numbers\n\n", n);

    // Get prime numbers
    mingw_gettimeofday(&start, 0);
    for (i = 2; count < n; i++) {
        if (isPrime(i)) {
            count++;
        }
    }
    mingw_gettimeofday(&stop, 0);
    
    // Calculate time taken
    cpu_time_used = (stop.tv_sec - start.tv_sec) + (stop.tv_usec - start.tv_usec) / 1000000.0;
    printf("Time taken: %f", cpu_time_used);
    
    return 0;
}
// End of main()
// End of seq.c

