Certainly! Below is the translated Fortran code to C++:

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int len = 100;
    std::vector<std::vector<int>> a(len, std::vector<int>(len));

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            a[i][j] = a[i][j] + 1;
        }
    }

    return 0;
}
```

### Explanation:
1. **Include necessary headers**:
   - `#include <iostream>` for input/output operations.
   - `#include <vector>` for dynamic array support.
   - `#include <omp.h>` for OpenMP support.

2. **Define constants and variables**:
   - `const int len = 100;` defines the length of the square matrix.
   - `std::vector<std::vector<int>> a(len, std::vector<int>(len));` creates a 2D vector `a` with dimensions `len x len`.

3. **Parallel for loop**:
   - `#pragma omp parallel for collapse(2)` specifies that the following loop should be parallelized and that it should collapse the two nested loops into a single parallel loop.
   - The loop runs from `0` to `len - 1` to match C++'s 0-based indexing.

4. **Incrementing elements**:
   - The nested loops increment each element of the matrix by 1.

5. **Return statement**:
   - The `main` function returns `0` to indicate successful execution.

This C++ code should perform the same operations as the original Fortran code, utilizing OpenMP for parallelization.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code.

### Fortran Unit Test Code

```fortran
program test_drb073_doall2_orig_yes
    use omp_lib
    implicit none

    integer :: i, j, len
    integer, dimension(:,:), allocatable :: a
    logical :: test_passed
    len = 100

    allocate (a(len,len))
    a = 0

    !$omp parallel do
    do i = 1, 100
        do j = 1, 100
            a(i,j) = a(i,j)+1
        end do
    end do
    !$omp end parallel do

    test_passed = .true.
    do i = 1, 100
        do j = 1, 100
            if (a(i,j) /= 1) then
                test_passed = .false.
                exit
            endif
        end do
        if (.not. test_passed) exit
    end do

    if (test_passed) then
        print *, "Test Passed"
    else
        print *, "Test Failed"
    endif

    deallocate(a)
end program test_drb073_doall2_orig_yes
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

bool test_drb073_doall2_orig_yes() {
    const int len = 100;
    std::vector<std::vector<int>> a(len, std::vector<int>(len, 0));

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            a[i][j] = a[i][j] + 1;
        }
    }

    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            if (a[i][j] != 1) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    if (test_drb073_doall2_orig_yes()) {
        std::cout << "Test Passed" << std::endl;
    } else {
        std::cout << "Test Failed" << std::endl;
    }
    return 0;
}
```

### Explanation:

1. **Fortran Unit Test Code**:
   - The `test_drb073_doall2_orig_yes` program initializes a 2D array `a` with zeros.
   - It then performs the parallel increment operation as in the original program.
   - After the parallel loop, it checks if each element of the array is equal to 1.
   - If all elements are equal to 1, it prints "Test Passed"; otherwise, it prints "Test Failed".

2. **C++ Unit Test Code**:
   - The `test_drb073_doall2_orig_yes` function initializes a 2D vector `a` with zeros.
   - It then performs the parallel increment operation as in the translated C++ code.
   - After the parallel loop, it checks if each element of the vector is equal to 1.
   - If all elements are equal to 1, it returns `true`; otherwise, it returns `false`.
   - The `main` function calls `test_drb073_doall2_orig_yes` and prints "Test Passed" if the function returns `true`, otherwise it prints "Test Failed".

These unit tests will help verify that the translated C++ code behaves the same as the original Fortran code.
