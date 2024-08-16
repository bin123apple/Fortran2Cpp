Certainly! Below is the translated Fortran code to C++:

```cpp
#include <iostream>
#include <omp.h>

int main() {
    const int len = 100;
    int x[len];
    int numNodes = len;
    int numNodes2 = 0;

    // Initialize the array
    for (int i = 0; i < len; ++i) {
        if ((i + 1) % 2 == 0) {
            x[i] = 5;
        } else {
            x[i] = -5;
        }
    }

    // Parallel loop
    #pragma omp parallel for
    for (int i = numNodes - 1; i >= 0; --i) {
        if (x[i] <= 0) {
            #pragma omp atomic
            numNodes2--;
        }
    }

    std::cout << "numNodes2 = " << numNodes2 << std::endl;

    return 0;
}
```

### Explanation:
1. **Array Initialization**: The Fortran code initializes the array `x` based on the condition. In C++, this is done using a loop.
2. **Parallel Loop**: The Fortran code uses OpenMP directives for parallelization. In C++, we use `#pragma omp parallel for` to parallelize the loop.
3. **Atomic Operation**: The `numNodes2` variable is decremented in the parallel loop. In C++, we use `#pragma omp atomic` to ensure that the decrement is atomic.
4. **Output**: The final result is printed using `std::cout`.

### Notes:
- The `#include <omp.h>` directive is used to include the OpenMP library.
- The loop indices in C++ start from 0, unlike Fortran which starts from 1. Therefore, the loop indices are adjusted accordingly.
- The `#pragma omp atomic` directive is used to ensure that the decrement of `numNodes2` is atomic, which is necessary because `numNodes2` is accessed and modified in a parallel region.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code.

### Fortran Unit Test Code

```fortran
program test_DRB011_minusminus_orig_yes
    use omp_lib
    implicit none

    integer :: i, len, numNodes, numNodes2
    integer :: x(100)
    len = 100
    numNodes = len
    numNodes2 = 0

    ! Initialize the array
    do i = 1, len
        if (MOD(i,2) == 0) then
            x(i) = 5
        else
            x(i) = -5
        end if
    end do

    !$omp parallel do
    do i = numNodes, 1, -1
        if (x(i) <= 0) then
            numNodes2 = numNodes2 - 1
        end if
    end do
    !$omp end parallel do

    ! Check the result
    if (numNodes2 == 50) then
        print*, "Test Passed"
    else
        print*, "Test Failed"
    end if
end program test_DRB011_minusminus_orig_yes
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <omp.h>
#include <cassert>

int main() {
    const int len = 100;
    int x[len];
    int numNodes = len;
    int numNodes2 = 0;

    // Initialize the array
    for (int i = 0; i < len; ++i) {
        if ((i + 1) % 2 == 0) {
            x[i] = 5;
        } else {
            x[i] = -5;
        }
    }

    // Parallel loop
    #pragma omp parallel for
    for (int i = numNodes - 1; i >= 0; --i) {
        if (x[i] <= 0) {
            #pragma omp atomic
            numNodes2--;
        }
    }

    // Check the result
    assert(numNodes2 == 50);
    std::cout << "Test Passed" << std::endl;

    return 0;
}
```

### Explanation:
1. **Fortran Unit Test Code**:
    - The Fortran program initializes the array `x`.
    - It then parallelizes the loop to decrement `numNodes2` based on the condition.
    - Finally, it checks if `numNodes2` is equal to 50 and prints "Test Passed" if true, otherwise "Test Failed".

2. **C++ Unit Test Code**:
    - The C++ program does the same as the Fortran program.
    - It initializes the array `x` and parallelizes the loop to decrement `numNodes2`.
    - It uses `assert` to check if `numNodes2` is equal to 50 and prints "Test Passed" if true.

### Compilation and Execution:
1. **Fortran**:
    - Compile the Fortran code using a Fortran compiler that supports OpenMP, e.g., `gfortran`:
        ```sh
        gfortran -fopenmp test_DRB011_minusminus_orig_yes.f90 -o test_DRB011_minusminus_orig_yes
        ./test_DRB011_minusminus_orig_yes
        ```

2. **C++**:
    - Compile the C++ code using a C++ compiler that supports OpenMP, e.g., `g++`:
        ```sh
        g++ -fopenmp test_DRB011_minusminus_orig_yes.cpp -o test_DRB011_minusminus_orig_yes
        ./test_DRB011_minusminus_orig_yes
        ```

Both programs should output "Test Passed" if the translation is correct.
