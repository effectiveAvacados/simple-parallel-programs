# simple-parallel-programs
A collection of simple applications to understand OpenMP and Pthread coding with C. 

## What the repo has
This repo has Sequential, OpenMP and Pthread implementations of the following programs:

\
The programs are written in C and are compiled using gcc.

## How to run
1.  Clone the repo
2.  Run the following commands in the terminal:

    ``` 
    cd <folder_name>    
    ```
    This will take you to the folder of the program you want to run. Once you are in the folder, you will see that there are 3 code files:
    1.  seq.c
    2.  omp.c
    3.  pthread.c
    
    \
    The seq.c file contains the sequential implementation of the program. The omp.c file contains the OpenMP implementation of the program. The pthread.c file contains the Pthread implementation of the program.
    
    To run the sequential implementation, run the following command:
    ```
    gcc seq.c -o seq
    ./seq
    ```
    \
    To run the OpenMP implementation, run the following command:
    ```
    gcc omp.c -o omp -fopenmp
    ./omp
    ```
    \
    To run the Pthread implementation, run the following command:
    ```
    gcc pthread.c -o pthread -lpthread
    ./pthread
    ```

## How to contribute
1.  Fork the repo.
2.  Clone the repo.
3.  Create a new branch.
4.  Add a new folder for the program you want to add.
5.  Add one or more of the following files in the folder:
    -  `seq.c` - Sequential implementation
    -  `omp.c` - OpenMP implementation
    -  `pthread.c` - Pthread implementation
6.  Add a README.md file in the folder. Describe the problem addressed by the program.
7. Commit and push the changes to your forked repo.
8. Create a pull request.

Hope you find this repo useful. Happy coding! ❤
