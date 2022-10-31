# Matrix Multiplication

> Language : C
\
> Environment : Windows


Matrix multiplication is a binary operation that produces a matrix from two matrices. The number of columns in the first matrix must be equal to the number of rows in the second matrix. The product of two matrices is a new matrix whose number of rows is equal to the number of rows in the first matrix and whose number of columns is equal to the number of columns in the second matrix.

For example, if A is a 2 × 3 matrix and B is a 3 × 2 matrix, then AB is a 2 × 2 matrix.

## Special instructions

### For execution on Linux environment

If you are using a Linux environment, you need to make the following changes to the program before compilation:

1. Change the `#include <time.h>` to `#include <sys/time.h>`.
2. Change the `mingw_gettimeofday()` function to `gettimeofday()`.

Author - [@VinuUD](https://github.com/VinuUD) 😎
