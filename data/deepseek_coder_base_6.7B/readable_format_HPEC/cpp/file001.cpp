To translate the given Fortran code to C++, we need to consider several aspects, including the array indexing, parallel execution, and the OpenMP directives. Fortran arrays are 1-based, while C++ arrays are 0-based. Also, the OpenMP syntax and directives are different between the two languages. Here's a C++ version of the given Fortran code:

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int len = 100;
    std::vector<std::vector<int>> a(len, std::vector<int>(len, 0));

    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp taskloop collapse(2)
            for (int i = 0; i < len; ++i) {
                for (int j = 0; j < len; ++j) {
                    a[i][j] = a[i][j] + 1;
                }
            }
        }
    }

    std::cout << "a(50,50) = " << a[49][49] << std::endl; // 50-1 for 0-based indexing

    return 0;
}
```

Key Points:
- The `std::vector` is used to create a 2D array dynamically.
- The OpenMP pragmas (`#pragma omp`) are used similarly to the Fortran code.
- The loop indices `i` and `j` start from 0 up to `len-1` to accommodate C++'s 0-based indexing.
- The `std::cout` line prints the value of `a[49][49]`, which corresponds to the 50th row and column in a 1-based indexing system (as in the original Fortran code).
- Remember to compile this C++ code with OpenMP support enabled. For example, if you're using `g++`, you would compile the code with the `-fopenmp` flag:
  ```sh
  g++ -fopenmp your_program.cpp -o your_program
  ```

This translation assumes that the original Fortran code's intention is to increment each element of the array `a` by 1 in parallel, and then print the value of `a(50,50)`. The C++ version achieves this by using OpenMP for parallel execution and array indexing is adjusted accordingly.
Let's write some test to verify if the translation is correct. 
To verify the correctness of both the original Fortran code and the translated C++ code, we can create simple unit tests. These tests will check if the array `a` has been correctly updated by the parallel tasks.

### Fortran Unit Test

For the Fortran code, we can modify the program to include a simple check after the parallel execution. Fortran lacks a built-in unit testing framework, so we'll do a simple manual check.

```fortran
program DRB096_doall2_taskloop_collapse_orig_no_test
    use omp_lib
    implicit none

    integer :: len, i, j, expected_value
    integer, allocatable :: a(:,:)
    logical :: test_passed

    len = 100
    expected_value = len * len

    allocate (a(len,len))
    a = 0

    !$omp parallel
        !$omp single
            !$omp taskloop collapse(2)
            do i = 1, len
                do j = 1, len
                    a(i,j) = a(i,j) + 1
                end do
            end do
        !$omp end single
    !$omp end parallel

    test_passed = .true.
    do i = 1, len
        do j = 1, len
            if (a(i,j) /= expected_value) then
                test_passed = .false.
                exit
            endif
        end do
        if (.not. test_passed) exit
    end do

    if (test_passed) then
        print *, "Test Passed: Array a is correctly updated."
    else
        print *, "Test Failed: Array a is not correctly updated."
    endif

end program DRB096_doall2_taskloop_collapse_orig_no_test
```

### C++ Unit Test

For the C++ code, we can use a simple test framework like Google Test for more structured testing. However, for simplicity, I'll provide a basic manual check similar to the Fortran example.

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

bool testArrayUpdate(const std::vector<std::vector<int>>& a, int len, int expected_value) {
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            if (a[i][j] != expected_value) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    const int len = 100;
    std::vector<std::vector<int>> a(len, std::vector<int>(len, 0));
    const int expected_value = len * len;

    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp taskloop collapse(2)
            for (int i = 0; i < len; ++i) {
                for (int j = 0; j < len; ++j) {
                    a[i][j] = a[i][j] + 1;
                }
            }
        }
    }

    if (testArrayUpdate(a, len, expected_value)) {
        std::cout << "Test Passed: Array a is correctly updated." << std::endl;
    } else {
        std::cout << "Test Failed: Array a is not correctly updated." << std::endl;
    }

    return 0;
}
```

### Compilation and Execution

- For the Fortran code, compile with OpenMP support:
  ```sh
  gfortran -fopenmp DRB096_doall2_taskloop_collapse_orig_no_test.f90 -o DRB096_doall2_taskloop_collapse_orig_no_test
  ./DRB096_doall2_taskloop_collapse_orig_no_test
  ```
- For the C++ code, compile with OpenMP support:
  ```sh
  g++ -fopenmp DRB096_doall2_taskloop_collapse_orig_no_test.cpp -o DRB096_doall2_taskloop_collapse_orig_no_test
  ./DRB096_doall2_taskloop_collapse_orig_no_test
  ```

These tests will verify that the array `a` has been correctly updated by the parallel tasks, ensuring the correctness of both the original Fortran code and its C++ translation.
