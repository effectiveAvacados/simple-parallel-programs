# Finding the nth triangular number

> Language : C
\
> Environment : Windows


The nth triangular number is the sum of the first n natural numbers.

For example, the 3rd triangular number is 3 + 2 + 1 = 6.

The 6th triangular number is 6 + 5 + 4 + 3 + 2 + 1 = 21.

## Special instructions

### For execution on Linux environment

If you are using a Linux environment, you need to make the following changes to the program before compilation:

1. Change the `#include <time.h>` to `#include <sys/time.h>`.
2. Change the `mingw_gettimeofday()` function to `gettimeofday()`.

Author - [@espurrr](https://github.com/espurrr) 👻
