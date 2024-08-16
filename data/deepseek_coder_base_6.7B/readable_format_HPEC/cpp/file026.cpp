To translate the given Fortran code to C++, we need to understand the structure and functionality of the original code and then replicate it using C++ syntax and constructs. The Fortran code uses OpenMP for parallelization, which is a common practice in parallel programming for Fortran and C++. In C++, we can use OpenMP similarly.

Here is the translated C++ code:

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int len = 100;
    float getSum = 0.0f;
    std::vector<std::vector<float>> u(len, std::vector<float>(len));

    // Initialize the matrix
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            u[i][j] = 0.5f;
        }
    }

    // Parallel region
    #pragma omp parallel for reduction(+:getSum) private(i, j, temp)
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            float temp = u[i][j];
            getSum += temp * temp;
        }
    }

    std::cout << "sum = " << getSum << std::endl;

    return 0;
}
```

### Key Points of Translation:

1. **Data Structure:** The Fortran code uses a 2D array `u` with dimensions `len x len`. In C++, we use a `std::vector<std::vector<float>>` to achieve a similar 2D array.

2. **Parallelization:** The Fortran code uses OpenMP directives for parallelization. In C++, we use `#pragma omp parallel for` to parallelize the inner loops. The `reduction` clause is used to safely accumulate `getSum` across threads.

3. **Loop Indices:** Fortran uses 1-based indexing by default, while C++ uses 0-based indexing. Adjustments are made accordingly.

4. **Variable Declarations:** Variables are declared at the beginning of the C++ code, similar to the Fortran code. The `private` clause in the OpenMP directive ensures that each thread has its own instance of `i`, `j`, and `temp`.

5. **Output:** The `std::cout` is used for output in C++, similar to the `print*` statement in Fortran.

6. **Memory Management:** In C++, dynamic memory allocation (e.g., with `new` and `delete`) is not needed for such a small example, as `std::vector` manages its memory automatically.

7. **Precision:** The Fortran code uses `real` type, which typically corresponds to a single-precision floating-point number in C++ (`float`).

8. **Program Structure:** The C++ code follows a typical `main` function structure, which is the entry point of a C++ program.

This translation assumes that you have a C++ compiler that supports OpenMP, which is widely used and supported. You can compile this C++ code with an OpenMP-enabled compiler, such as `g++`, by using the `-fopenmp` flag:

```sh
g++ -fopenmp your_program.cpp -o your_program
```

This will enable OpenMP in your C++ program.
Let's write some test to verify if the translation is correct. 
Creating unit tests for both the Fortran and C++ codes involves checking that the sum calculated by each program matches the expected result. For simplicity, let's assume the expected result is known and is the sum of squares of all elements in the matrix `u`, which is `0.5 * 0.5 * len * len`.

### Fortran Unit Test

For the Fortran code, we can create a simple test by modifying the program to include a check for the expected sum.

```fortran
program DRB021_reductionmissing_orig_yes_test
    use omp_lib
    implicit none

    integer :: i, j, len
    real :: temp, getSum, expectedSum
    real, dimension (:,:), allocatable :: u

    len = 100
    getSum = 0.0
    expectedSum = 0.5 * 0.5 * len * len

    allocate (u(len, len))

    do i = 1, len
        do j = 1, len
            u(i,j) = 0.5
        end do
    end do

    !$omp parallel do private(temp, i, j)
    do i = 1, len
        do j = 1, len
            temp = u(i,j)
            getSum = getSum + temp * temp
        end do
    end do
    !$omp end parallel do

    print*,"sum =", getSum
    if (abs(getSum - expectedSum) < 0.0001) then
        print*, "Test Passed"
    else
        print*, "Test Failed"
    end if
    deallocate(u)
end program
```

### C++ Unit Test

For the C++ code, we can use a simple assertion to check if the sum matches the expected result.

```cpp
#include <iostream>
#include <vector>
#include <omp.h>
#include <cassert>
#include <cmath>

int main() {
    const int len = 100;
    float getSum = 0.0f;
    std::vector<std::vector<float>> u(len, std::vector<float>(len));
    float expectedSum = 0.5f * 0.5f * len * len;

    // Initialize the matrix
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            u[i][j] = 0.5f;
        }
    }

    // Parallel region
    #pragma omp parallel for reduction(+:getSum) private(i, j, temp)
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            float temp = u[i][j];
            getSum += temp * temp;
        }
    }

    std::cout << "sum = " << getSum << std::endl;

    // Check if the sum matches the expected result
    assert(std::abs(getSum - expectedSum) < 0.0001);
    std::cout << "Test Passed" << std::endl;

    return 0;
}
```

### Compilation and Execution

- **Fortran:** Use a Fortran compiler that supports OpenMP, such as `gfortran`:

```sh
gfortran -fopenmp DRB021_reductionmissing_orig_yes_test.f90 -o DRB021_reductionmissing_orig_yes_test
./DRB021_reductionmissing_orig_yes_test
```

- **C++:** Use a C++ compiler that supports OpenMP, such as `g++`:

```sh
g++ -fopenmp DRB021_reductionmissing_orig_yes_test.cpp -o DRB021_reductionmissing_orig_yes_test
./DRB021_reductionmissing_orig_yes_test
```

These tests will verify that the sum calculated by both programs matches the expected result, ensuring the correctness of the translation.
