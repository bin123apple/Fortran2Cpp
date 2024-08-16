To translate the given Fortran code to C++, we need to consider several aspects, including the syntax differences between Fortran and C++, the OpenMP directives, and the memory management for dynamic arrays. The Fortran code uses OpenMP for parallel processing and array operations. Below is a C++ translation that maintains the original functionality:

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int len = 100;
    std::vector<std::vector<int>> a(len, std::vector<int>(len));

    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp taskloop
            for (int i = 0; i < len; ++i) {
                for (int j = 0; j < len; ++j) {
                    a[i][j] = a[i][j] + 1;
                }
            }
        }
    }

    std::cout << "a(50,50) = " << a[50][50] << std::endl;

    return 0;
}
```

Key Points in the Translation:

1. **Array Initialization**: In C++, dynamic arrays are often handled using `std::vector`. This provides a more modern and safer approach compared to raw pointers.

2. **OpenMP Directives**: The OpenMP directives in C++ are similar to those in Fortran, but the syntax is slightly different. The `#pragma omp` directive is used in C++ for OpenMP.

3. **Loop Indices**: C++ uses 0-based indexing, unlike Fortran's 1-based indexing. Therefore, the loop indices start from 0 and go up to `len - 1`.

4. **Printing**: The `std::cout` is used for output in C++, and the formatting is handled directly in the output statement.

5. **Memory Management**: The Fortran `allocate` statement is replaced by direct initialization of the `std::vector`. The vector automatically manages its memory, so no explicit deallocation is needed.

6. **Compilation**: To compile this C++ code with OpenMP support, you need to enable OpenMP in your compiler. For example, if you are using GCC, you can compile the program with the `-fopenmp` flag:
   ```sh
   g++ -fopenmp your_program.cpp -o your_program
   ```

This translation aims to maintain the original functionality and structure of the Fortran code while adapting it to C++ syntax and conventions.
Let's write some test to verify if the translation is correct. 
To verify the correctness of both the original Fortran code and the translated C++ code, we can create unit tests. These tests will check if the array `a` is correctly updated with the value `1` in each element after the parallel execution.

### Fortran Unit Test

For the Fortran code, we can write a simple test by modifying the program to check the final state of the array `a` after the parallel execution.

```fortran
program DRB095_doall2_taskloop_orig_yes_test
    use omp_lib
    implicit none

    integer :: len, i, j, errors
    integer, allocatable :: a(:,:)
    len = 100
    allocate (a(len,len))
    a = 0

    !$omp parallel
        !$omp single
            !$omp taskloop
            do i = 1, len
                do j = 1, len
                    a(i,j) = a(i,j)+1
                end do
            end do
        !$omp end taskloop
    !$omp end single
    !$omp end parallel

    errors = 0
    do i = 1, len
        do j = 1, len
            if (a(i,j) /= 1) then
                errors = errors + 1
            endif
        end do
    end do

    if (errors == 0) then
        print *, "Test Passed"
    else
        print *, "Test Failed"
    endif

end program DRB095_doall2_taskloop_orig_yes_test
```

### C++ Unit Test

For the C++ code, we can use a simple test by checking the final state of the array `a` after the parallel execution.

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
            #pragma omp taskloop
            for (int i = 0; i < len; ++i) {
                for (int j = 0; j < len; ++j) {
                    a[i][j] = a[i][j] + 1;
                }
            }
        }
    }

    int errors = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            if (a[i][j] != 1) {
                errors++;
            }
        }
    }

    if (errors == 0) {
        std::cout << "Test Passed" << std::endl;
    } else {
        std::cout << "Test Failed" << std::endl;
    }

    return 0;
}
```

### Compilation and Execution

- **Fortran**: Compile the Fortran test with OpenMP support using a Fortran compiler like `gfortran`:
  ```sh
  gfortran -fopenmp DRB095_doall2_taskloop_orig_yes_test.f90 -o DRB095_doall2_taskloop_orig_yes_test
  ./DRB095_doall2_taskloop_orig_yes_test
  ```

- **C++**: Compile the C++ test with OpenMP support using a C++ compiler like `g++`:
  ```sh
  g++ -fopenmp DRB095_doall2_taskloop_orig_yes_test.cpp -o DRB095_doall2_taskloop_orig_yes_test
  ./DRB095_doall2_taskloop_orig_yes_test
  ```

Both tests should output "Test Passed" if the array `a` is correctly updated with the value `1` in each element after the parallel execution. This verifies that the translation from Fortran to C++ is correct.
