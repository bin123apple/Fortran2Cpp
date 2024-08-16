Certainly! Below is the translated version of the provided Fortran code into C++. This translation takes into account the OpenMP directives for parallelization.

```cpp
#include <omp.h>
#include <iostream>

int main() {
    const int N = 100;
    int a[N][N];

    // Initialize the array to zero
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            a[i][j] = 0;
        }
    }

    // Parallel region
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            a[i][j] = a[i][j] + 1;
        }
    }

    return 0;
}
```

### Explanation:
1. **Include OpenMP**: The `#include <omp.h>` directive is used to include the OpenMP library.
2. **Array Declaration**: The array `a` is declared with dimensions `NxN`.
3. **Initialization**: The array `a` is initialized to zero using nested loops.
4. **Parallel Region**: The `#pragma omp parallel for collapse(2)` directive is used to parallelize the nested loops. The `collapse(2)` clause is used to collapse the nested loops into a single parallel loop construct.
5. **Loop Constructs**: The nested loops are translated directly, with the `a[i][j] = a[i][j] + 1` operation inside the parallel region.

### Compilation:
To compile this C++ code with OpenMP support, you can use a command similar to the following (assuming you have an OpenMP-capable compiler like `g++`):

```sh
g++ -fopenmp -o DRB046_doall2_orig_no DRB046_doall2_orig_no.cpp
```

This command enables OpenMP and compiles the program into an executable named `DRB046_doall2_orig_no`.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code to verify the correctness of the translation.

### Fortran Unit Test Code

```fortran
program test_DRB046_doall2_orig_no
    use omp_lib
    implicit none

    integer :: i, j
    integer, parameter :: N = 100
    integer :: a(N,N)
    logical :: test_passed

    ! Initialize the array to zero
    a = 0

    ! Parallel region
    !$omp parallel do private(j)
    do i = 1, N
        do j = 1, N
            a(i,j) = a(i,j) + 1
        end do
    end do
    !$omp end parallel do

    ! Verify the results
    test_passed = .true.
    do i = 1, N
        do j = 1, N
            if (a(i,j) /= 1) then
                test_passed = .false.
                exit
            end if
        end do
        if (.not. test_passed) exit
    end do

    if (test_passed) then
        print *, "Test Passed"
    else
        print *, "Test Failed"
    end if
end program test_DRB046_doall2_orig_no
```

### C++ Unit Test Code

```cpp
#include <omp.h>
#include <iostream>
#include <cassert>

int main() {
    const int N = 100;
    int a[N][N];
    bool test_passed = true;

    // Initialize the array to zero
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            a[i][j] = 0;
        }
    }

    // Parallel region
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            a[i][j] = a[i][j] + 1;
        }
    }

    // Verify the results
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (a[i][j] != 1) {
                test_passed = false;
                break;
            }
        }
        if (!test_passed) break;
    }

    if (test_passed) {
        std::cout << "Test Passed" << std::endl;
    } else {
        std::cout << "Test Failed" << std::endl;
    }

    return 0;
}
```

### Explanation:
1. **Fortran Unit Test Code**:
   - The array `a` is initialized to zero.
   - The parallel region increments each element of the array by 1.
   - A nested loop checks if each element of the array is equal to 1. If any element is not 1, the test fails.

2. **C++ Unit Test Code**:
   - The array `a` is initialized to zero.
   - The parallel region increments each element of the array by 1.
   - A nested loop checks if each element of the array is equal to 1. If any element is not 1, the test fails.

### Compilation and Execution:
- **Fortran**:
  ```sh
  gfortran -fopenmp -o test_DRB046_doall2_orig_no test_DRB046_doall2_orig_no.f90
  ./test_DRB046_doall2_orig_no
  ```

- **C++**:
  ```sh
  g++ -fopenmp -o test_DRB046_doall2_orig_no test_DRB046_doall2_orig_no.cpp
  ./test_DRB046_doall2_orig_no
  ```

These unit tests will verify if the array elements are correctly incremented by 1 in both the Fortran and C++ versions. If the tests pass, it indicates that the translation is correct.
