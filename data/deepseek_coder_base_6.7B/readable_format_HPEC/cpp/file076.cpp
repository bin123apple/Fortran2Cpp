Certainly! Below is the translated version of the provided Fortran code into C++. This translation takes into account the OpenMP directives and array indexing differences between Fortran (1-based) and C++ (0-based).

#include <iostream>
#include <omp.h>

int main() {
    const int len = 20;
    float a[len][len];

    // Initialize the array
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            a[i][j] = 0.5f;
        }
    }

    // Parallel region
    #pragma omp parallel for private(j)
    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len; ++j) {
            a[i][j] = a[i][j] + a[i + 1][j];
        }
    }

    // Print a(10,10)
    std::cout << "a(10,10) = " << a[9][9] << std::endl;

    return 0;
}

Key Points:
- The `#pragma omp parallel for` directive is used to parallelize the inner loop.
- The array `a` is declared with `float` elements, which corresponds to the `real` type in Fortran.
- The loop indices `i` and `j` start from 0 in C++, reflecting the 0-based indexing of C++ arrays.
- The `std::cout` is used for output, similar to the `write(*,*)` statement in Fortran.
- The OpenMP library is included via the `omp.h` header.
- The `const int len = 20;` declaration defines the array dimensions.

This C++ code should perform the same operations as the original Fortran code, utilizing the OpenMP parallelization for the inner loop.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the translation by comparing the output of both programs.

### Fortran Unit Test Code

To compile and run this Fortran code, you need a Fortran compiler that supports OpenMP, such as `gfortran`. Save the following code in a file named `test_drb003_antidep2_orig_yes.f90`:

```fortran
program test_DRB003_antidep2_orig_yes
    use omp_lib
    implicit none

    integer :: i, j, len
    real :: a(20,20)
    real :: expected_value

    len = 20
    expected_value = 0.5 * (len - 1)

    ! Initialize the array
    do i = 1, len
        do j = 1, len
            a(i,j) = 0.5
        end do
    end do

    ! Parallel region
    !$omp parallel do private(j)
    do i = 1, len-1
        do j = 1, len
            a(i,j) = a(i,j) + a(i+1,j)
        end do
    end do
    !$omp end parallel do

    ! Check the result
    if (abs(a(10,10) - expected_value) < 0.0001) then
        print *, 'Test passed: a(10,10) =', a(10,10)
    else
        print *, 'Test failed: a(10,10) =', a(10,10)
    end if

end program test_DRB003_antidep2_orig_yes
```

Compile and run the Fortran code using:

```sh
gfortran -fopenmp test_drb003_antidep2_orig_yes.f90 -o test_drb003
./test_drb003
```

### C++ Unit Test Code

To compile and run this C++ code, you need a C++ compiler that supports OpenMP, such as `g++`. Save the following code in a file named `test_drb003_antidep2_orig_yes.cpp`:

```cpp
#include <iostream>
#include <omp.h>
#include <cmath>

int main() {
    const int len = 20;
    float a[len][len];
    float expected_value = 0.5f * (len - 1);

    // Initialize the array
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            a[i][j] = 0.5f;
        }
    }

    // Parallel region
    #pragma omp parallel for private(j)
    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len; ++j) {
            a[i][j] = a[i][j] + a[i + 1][j];
        }
    }

    // Check the result
    if (std::abs(a[9][9] - expected_value) < 0.0001f) {
        std::cout << "Test passed: a(10,10) = " << a[9][9] << std::endl;
    } else {
        std::cout << "Test failed: a(10,10) = " << a[9][9] << std::endl;
    }

    return 0;
}
```

Compile and run the C++ code using:

```sh
g++ -fopenmp test_drb003_antidep2_orig_yes.cpp -o test_drb003
./test_drb003
```

### Explanation

- Both unit test codes initialize the 2D array `a` with `0.5` and then perform the same computation as in the original code.
- After the computation, they check if the value of `a(10,10)` (Fortran) or `a(10,10)` (C++) is as expected. The expected value is calculated as `0.5 * (len - 1)`.
- If the value is as expected, the test passes; otherwise, it fails.
- The `abs` function in Fortran and `std::abs` in C++ are used to compute the absolute value.

By running these unit tests, you can verify the correctness of the translation by comparing the output of both programs.
