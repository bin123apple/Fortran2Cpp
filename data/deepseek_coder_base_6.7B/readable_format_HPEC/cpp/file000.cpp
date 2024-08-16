To translate the given Fortran code to C++, we need to understand the structure and functionality of the original code, including the parallel loop structure. The Fortran code uses OpenMP for parallelization and performs a simple operation on a 2D array. Below is the equivalent C++ code using OpenMP for parallelization.

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int len = 100;
    std::vector<std::vector<int>> a(len, std::vector<int>(len));

    // Parallel loop to increment each element of the 2D array
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
1. **Include Libraries**: We include `<iostream>` for input/output operations, `<vector>` for dynamic arrays, and `<omp.h>` for OpenMP functionalities.
2. **Constants and Variables**: We define the length of the 2D array as `const int len = 100`. We then create a 2D vector `a` with dimensions `len x len`.
3. **Parallel Loop**: We use the `#pragma omp parallel for collapse(2)` directive to parallelize the nested loops. The `collapse(2)` clause tells the compiler to collapse the nested loops into a single loop, which is then parallelized.
4. **Loop Body**: The loop increments each element of the 2D array by 1.

### Notes:
- **Array Indexing**: Remember that C++ arrays (and vectors) are zero-indexed, unlike Fortran arrays which are one-indexed. Therefore, the loop indices start from 0 up to `len - 1`.
- **Compilation**: To compile this C++ code with OpenMP support, you need to enable OpenMP in your compiler. For example, if you are using `g++`, you can compile the code with the `-fopenmp` flag:
  ```sh
  g++ -fopenmp your_program.cpp -o your_program
  ```

This C++ code should give you the same functionality as the original Fortran code, with the added benefit of parallelization using OpenMP.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code to verify the correctness of the translation.

### Fortran Unit Test Code

```fortran
program test_DRB093_doall2_collapse_orig_no
    use omp_lib
    use DRB093
    implicit none

    integer :: len, i, j, errors
    integer, allocatable :: a(:,:)
    len = 100
    errors = 0

    allocate (a(len,len))
    a = 0

    !$omp parallel do collapse(2)
    do i = 1, len
        do j = 1, len
            a(i,j) = a(i,j)+1
        end do
    end do
    !$omp end parallel do

    ! Check if all elements are incremented by 1
    do i = 1, len
        do j = 1, len
            if (a(i,j) /= 1) then
                errors = errors + 1
            end if
        end do
    end do

    if (errors == 0) then
        print *, "Test Passed"
    else
        print *, "Test Failed"
    end if

end program test_DRB093_doall2_collapse_orig_no
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int len = 100;
    std::vector<std::vector<int>> a(len, std::vector<int>(len, 0));
    int errors = 0;

    // Parallel loop to increment each element of the 2D array
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            a[i][j] = a[i][j] + 1;
        }
    }

    // Check if all elements are incremented by 1
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

### Explanation:
1. **Fortran Unit Test Code**:
   - We initialize a 2D array `a` with zeros.
   - We parallelize the nested loops to increment each element of the array.
   - We then check if all elements are incremented by 1 and count the errors.
   - If there are no errors, the test passes; otherwise, it fails.

2. **C++ Unit Test Code**:
   - We initialize a 2D vector `a` with zeros.
   - We parallelize the nested loops to increment each element of the array.
   - We then check if all elements are incremented by 1 and count the errors.
   - If there are no errors, the test passes; otherwise, it fails.

### Compilation and Execution:
- **Fortran**:
  - Compile the Fortran code with OpenMP support:
    ```sh
    gfortran -fopenmp test_DRB093_doall2_collapse_orig_no.f90 -o test_DRB093_doall2_collapse_orig_no
    ```
  - Run the executable:
    ```sh
    ./test_DRB093_doall2_collapse_orig_no
    ```

- **C++**:
  - Compile the C++ code with OpenMP support:
    ```sh
    g++ -fopenmp test_DRB093_doall2_collapse_orig_no.cpp -o test_DRB093_doall2_collapse_orig_no
    ```
  - Run the executable:
    ```sh
    ./test_DRB093_doall2_collapse_orig_no
    ```

Both unit tests should output "Test Passed" if the translation is correct.
