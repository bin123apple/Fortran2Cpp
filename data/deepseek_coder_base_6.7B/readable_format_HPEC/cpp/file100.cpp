Certainly! Below is the translated Fortran code to C++:

```cpp
#include <omp.h>
#include <iostream>

int main() {
    int numThreads = 0;

    #pragma omp parallel
    {
        if (omp_get_thread_num() == 0) {
            numThreads = omp_get_num_threads();
        }
    }

    std::cout << "numThreads = " << numThreads << std::endl;

    return 0;
}
```

### Explanation:
1. **Include OpenMP**: The `#include <omp.h>` directive is used to include the OpenMP library in C++.
2. **Main Function**: The main function is the entry point of the C++ program.
3. **Variable Declaration**: The variable `numThreads` is declared as an integer.
4. **Parallel Region**: The `#pragma omp parallel` directive is used to parallelize the region.
5. **Check Thread Number**: Inside the parallel region, we check if the current thread is the master thread (thread number 0).
6. **Get Number of Threads**: If the current thread is the master thread, it sets `numThreads` to the total number of threads in the parallel region.
7. **Output**: The `std::cout` is used to print the value of `numThreads`.

### Compilation:
To compile this C++ program, you need to enable OpenMP support. If you are using `g++`, you can compile the program with the `-fopenmp` flag:

```sh
g++ -fopenmp -o DRB051_getthreadnum_orig_no DRB051_getthreadnum_orig_no.cpp
```

This will compile the program and enable OpenMP support, allowing the program to run in parallel.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code to verify the correctness of the translation.

### Fortran Unit Test Code

Save the following Fortran code in a file named `DRB051_getthreadnum_orig_no_test.f90`:

```fortran
program DRB051_getthreadnum_orig_no_test
    use omp_lib
    implicit none

    integer :: numThreads
    integer :: expectedNumThreads
    logical :: testPassed

    ! Set the expected number of threads
    expectedNumThreads = omp_get_max_threads()

    !$omp parallel
    if (omp_get_thread_num() == 0) then
        numThreads = omp_get_num_threads()
    end if
    !$omp end parallel

    testPassed = (numThreads == expectedNumThreads)

    if (testPassed) then
        print *, "Test Passed: numThreads = ", numThreads
    else
        print *, "Test Failed: numThreads = ", numThreads, "Expected: ", expectedNumThreads
    end if
end program DRB051_getthreadnum_orig_no_test
```

### C++ Unit Test Code

Save the following C++ code in a file named `DRB051_getthreadnum_orig_no_test.cpp`:

```cpp
#include <omp.h>
#include <iostream>
#include <cassert>

int main() {
    int numThreads = 0;
    int expectedNumThreads = omp_get_max_threads();

    #pragma omp parallel
    {
        if (omp_get_thread_num() == 0) {
            numThreads = omp_get_num_threads();
        }
    }

    assert(numThreads == expectedNumThreads);

    std::cout << "Test Passed: numThreads = " << numThreads << std::endl;

    return 0;
}
```

### Compilation and Execution

#### Fortran

To compile and run the Fortran unit test, use the following commands:

```sh
gfortran -fopenmp -o DRB051_getthreadnum_orig_no_test DRB051_getthreadnum_orig_no_test.f90
./DRB051_getthreadnum_orig_no_test
```

#### C++

To compile and run the C++ unit test, use the following commands:

```sh
g++ -fopenmp -o DRB051_getthreadnum_orig_no_test DRB051_getthreadnum_orig_no_test.cpp
./DRB051_getthreadnum_orig_no_test
```

### Explanation

1. **Fortran Unit Test Code**:
   - The `expectedNumThreads` variable is set to the maximum number of threads that the system supports.
   - The `numThreads` variable is set to the number of threads in the parallel region if the current thread is the master thread (thread number 0).
   - The `testPassed` variable checks if `numThreads` matches the `expectedNumThreads`.
   - The program prints "Test Passed" if the test is successful, otherwise it prints "Test Failed".

2. **C++ Unit Test Code**:
   - The `expectedNumThreads` variable is set to the maximum number of threads that the system supports.
   - The `numThreads` variable is set to the number of threads in the parallel region if the current thread is the master thread (thread number 0).
   - The `assert` function checks if `numThreads` matches the `expectedNumThreads`.
   - The program prints "Test Passed" if the test is successful.

By running these unit tests, you can verify that the translated C++ code behaves the same as the original Fortran code.
