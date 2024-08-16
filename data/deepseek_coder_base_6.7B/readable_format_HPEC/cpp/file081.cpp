To translate the given Fortran code to C++, we need to understand the structure and the functionality of the original Fortran code and then implement similar functionality using C++ syntax and OpenMP directives. Here's a C++ version of the code:

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int len = 1000;
    int b = 5;
    std::vector<int> a(len);
    int error = 0;

    // Initialize the array
    for (int i = 0; i < len; ++i) {
        a[i] = i + 1; // Fortran arrays are 1-based
    }

    // Parallel region with shared variables
    #pragma omp parallel shared(b, error)
    {
        // Parallel loop
        #pragma omp for
        for (int i = 0; i < len; ++i) {
            a[i] = b + a[i] * 5;
        }
        // No wait clause for the parallel loop
        #pragma omp barrier
        // Single thread to compute error
        #pragma omp single
        {
            error = a[8] + 1; // Adjusted for 0-based indexing
        }
    }

    // Print the error
    std::cout << "error = " << error << std::endl;

    return 0;
}
```

### Key Points in Translation:

1. **Array Initialization**: The Fortran code initializes the array `a` with values from 1 to `len`. In C++, arrays are 0-based, so we adjust the initialization accordingly.

2. **Parallel Region and Loop**: The OpenMP directives for parallelization and loop parallelization are used similarly in both Fortran and C++. The `#pragma omp parallel` directive is used to start a parallel region, and `#pragma omp for` is used to parallelize the loop. The `#pragma omp barrier` and `#pragma omp single` are used to synchronize threads as in the original Fortran code.

3. **Error Calculation**: The error calculation in the C++ code uses 0-based indexing, so we adjust the index to `a[8]` to match the Fortran code's 1-based indexing.

4. **Output**: The C++ code uses `std::cout` for output, similar to the Fortran `print` statement.

5. **Memory Management**: The C++ code uses `std::vector` for dynamic array allocation, which automatically manages memory and is safer compared to raw pointers.

6. **Compilation**: To compile this C++ code with OpenMP support, you need to enable OpenMP in your compiler. For example, if you are using GCC, you can compile the program with the `-fopenmp` flag:
   ```sh
   g++ -fopenmp your_program.cpp -o your_program
   ```

This translation aims to maintain the original program's logic and functionality while adapting it to C++ syntax and OpenMP conventions.
Let's write some test to verify if the translation is correct. 
Creating unit tests for both the Fortran and C++ versions of the code involves checking if the final state of the array `a` and the calculated error value are as expected. Below are the unit test codes for both languages.

### Fortran Unit Test Code

For Fortran, we can use a simple program that checks the final state of the array `a` and the calculated error value.

```fortran
program test_DRB104_nowait_barrier_orig_no
    use omp_lib
    implicit none

    integer :: i, error, len, b
    integer, dimension(:), allocatable :: a

    len = 1000
    b = 5
    allocate (a(len))

    do i = 1, len
        a(i) = i
    end do

    !$omp parallel shared(b, error)
        !$omp do
        do i = 1, len
            a(i) = b + a(i) * 5
        end do
        !$omp end do nowait
    !$omp end parallel

    !$omp barrier
    !$omp single
    error = a(9) + 1
    !$omp end single

    ! Check the final state of the array a
    do i = 1, len
        if (a(i) /= b + 5 * i) then
            print *, "Test failed for array a at index: ", i
            stop
        end if
    end do

    ! Check the calculated error
    if (error /= 6) then
        print *, "Test failed for error calculation"
        stop
    end if

    print *, "All tests passed successfully"

    deallocate(a)
end program test_DRB104_nowait_barrier_orig_no
```

### C++ Unit Test Code

For C++, we can use a simple main function to check the final state of the array `a` and the calculated error value.

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int len = 1000;
    int b = 5;
    std::vector<int> a(len);
    int error = 0;

    // Initialize the array
    for (int i = 0; i < len; ++i) {
        a[i] = i + 1; // Fortran arrays are 1-based
    }

    // Parallel region with shared variables
    #pragma omp parallel shared(b, error)
    {
        // Parallel loop
        #pragma omp for
        for (int i = 0; i < len; ++i) {
            a[i] = b + a[i] * 5;
        }
        // No wait clause for the parallel loop
        #pragma omp barrier
        // Single thread to compute error
        #pragma omp single
        {
            error = a[8] + 1; // Adjusted for 0-based indexing
        }
    }

    // Check the final state of the array a
    for (int i = 0; i < len; ++i) {
        if (a[i] != b + 5 * (i + 1)) { // Adjust for 0-based indexing
            std::cout << "Test failed for array a at index: " << i << std::endl;
            return 1;
        }
    }

    // Check the calculated error
    if (error != 6) {
        std::cout << "Test failed for error calculation" << std::endl;
        return 1;
    }

    std::cout << "All tests passed successfully" << std::endl;

    return 0;
}
```

### Compilation and Execution

- **For Fortran**: Use a Fortran compiler that supports OpenMP, such as gfortran, and compile the test program with the `-fopenmp` flag:
  ```sh
  gfortran -fopenmp test_DRB104_nowait_barrier_orig_no.f90 -o test_DRB104
  ./test_DRB104
  ```

- **For C++**: Use a C++ compiler that supports OpenMP, such as g++, and compile the test program with the `-fopenmp` flag:
  ```sh
  g++ -fopenmp test_DRB104_nowait_barrier_orig_no.cpp -o test_DRB104
  ./test_DRB104
  ```

These unit tests will verify that the final state of the array `a` and the calculated error value are as expected, ensuring that the translated C++ code behaves similarly to the original Fortran code.
