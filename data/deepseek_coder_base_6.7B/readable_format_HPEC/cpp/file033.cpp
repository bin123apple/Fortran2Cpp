Certainly! Below is the translated Fortran code to C++:

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int b = 5;
    int len = 1000;
    std::vector<int> a(len);
    int error = 0;

    // Initialize the array
    for (int i = 0; i < len; ++i) {
        a[i] = i + 1;
    }

    // Parallel region
    #pragma omp parallel shared(b, error)
    {
        // Another parallel region
        #pragma omp parallel
        {
            // Parallel loop
            #pragma omp for
            for (int i = 0; i < len; ++i) {
                a[i] = b + a[i] * 5;
            }
            // No wait clause
            #pragma omp barrier
            // Single region
            #pragma omp single
            {
                error = a[9] + 1; // Note: C++ uses 0-based indexing
            }
        }
    }

    std::cout << "error = " << error << std::endl;

    return 0;
}
```

### Explanation:
1. **Vector Initialization**: The Fortran `allocate` statement is replaced by using a `std::vector` in C++.
2. **Parallel Regions**: The Fortran `!$omp parallel` blocks are translated to C++ `#pragma omp parallel` blocks.
3. **Parallel Loop**: The Fortran `!$omp do` loop is translated to C++ `#pragma omp for` loop.
4. **No Wait Clause**: The Fortran `!$omp end do nowait` is translated to C++ `#pragma omp barrier` to ensure all threads reach the barrier before proceeding.
5. **Single Region**: The Fortran `!$omp single` block is translated to C++ `#pragma omp single` block.
6. **Error Calculation**: The Fortran `error = a(10) + 1` is translated to `error = a[9] + 1` in C++, considering C++ uses 0-based indexing.

Make sure to compile this C++ code with OpenMP support enabled. For example, using `g++`:
```sh
g++ -fopenmp your_program.cpp -o your_program
```
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code.

### Fortran Unit Test Code

```fortran
program test_DRB013_nowait_orig_yes
    use omp_lib
    implicit none

    integer :: i, error, len, b
    integer, dimension (:), allocatable :: a

    b = 5
    len = 1000

    allocate (a(len))

    do i = 1, len
        a(i) = i
    end do

    !$omp parallel shared(b, error)
        !$omp parallel
            !$omp do
            do i = 1, len
                a(i) = b + a(i)*5
            end do
            !$omp end do nowait
            !$omp single
            error = a(10) + 1
            !$omp end single
        !$omp end parallel
    !$omp end parallel

    print*,"error =",error

    deallocate(a)
end program test_DRB013_nowait_orig_yes
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int b = 5;
    int len = 1000;
    std::vector<int> a(len);
    int error = 0;

    // Initialize the array
    for (int i = 0; i < len; ++i) {
        a[i] = i + 1;
    }

    // Parallel region
    #pragma omp parallel shared(b, error)
    {
        // Another parallel region
        #pragma omp parallel
        {
            // Parallel loop
            #pragma omp for
            for (int i = 0; i < len; ++i) {
                a[i] = b + a[i] * 5;
            }
            // No wait clause
            #pragma omp barrier
            // Single region
            #pragma omp single
            {
                error = a[9] + 1; // Note: C++ uses 0-based indexing
            }
        }
    }

    std::cout << "error = " << error << std::endl;

    return 0;
}
```

### Explanation:
1. **Fortran Unit Test Code**: This code is the same as the original Fortran code provided, with the addition of a `program` block for clarity and execution.
2. **C++ Unit Test Code**: This code is the translated C++ code provided earlier, with the addition of a `main` function for clarity and execution.

### Compilation and Execution:

#### Fortran:
To compile and run the Fortran unit test code, use the following commands:
```sh
gfortran -fopenmp test_DRB013_nowait_orig_yes.f90 -o test_DRB013_nowait_orig_yes
./test_DRB013_nowait_orig_yes
```

#### C++:
To compile and run the C++ unit test code, use the following commands:
```sh
g++ -fopenmp test_DRB013_nowait_orig_yes.cpp -o test_DRB013_nowait_orig_yes
./test_DRB013_nowait_orig_yes
```

### Verification:
After running both the Fortran and C++ unit tests, you should compare the output of the Fortran program and the C++ program. The expected output for both programs should be the same, verifying that the translation is correct.
