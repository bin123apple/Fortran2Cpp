To translate the given Fortran code to C++, we need to consider several aspects, such as array indexing (Fortran is 1-based, while C++ is 0-based), data types, and the loop constructs. The Fortran code performs a matrix multiplication and an update operation on matrices `a` and `c`, with scaling factors `alpha` and `beta`.

Here's how you can translate the Fortran code to C++:

```cpp
#include <vector>

// Assuming DATA_TYPE is a floating-point type (e.g., float or double)
using DATA_TYPE = double;

void kernel_syrk(int ni, int nj, DATA_TYPE alpha, DATA_TYPE beta, std::vector<std::vector<DATA_TYPE>>& c, const std::vector<std::vector<DATA_TYPE>>& a) {
    // Initialize the matrix c with beta
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < ni; ++j) {
            c[j][i] *= beta;
        }
    }

    // Update c with the matrix multiplication result
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < ni; ++j) {
            for (int k = 0; k < nj; ++k) {
                c[j][i] += alpha * a[k][i] * a[k][j];
            }
        }
    }
}

int main() {
    // Example usage
    int ni = 3, nj = 3; // Matrix dimensions
    DATA_TYPE alpha = 1.0, beta = 2.0; // Scaling factors

    // Initialize matrices a and c
    std::vector<std::vector<DATA_TYPE>> a(nj, std::vector<DATA_TYPE>(ni, 1.0)); // Example initialization
    std::vector<std::vector<DATA_TYPE>> c(ni, std::vector<DATA_TYPE>(ni, 0.0)); // Example initialization

    // Call the kernel
    kernel_syrk(ni, nj, alpha, beta, c, a);

    // Output the result
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < ni; ++j) {
            std::cout << c[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
```

Key Points in the Translation:

1. **Array Indexing**: C++ uses 0-based indexing, so loops are adjusted accordingly.
2. **Data Types**: The `DATA_TYPE` is assumed to be a floating-point type (`float` or `double`). You can change it as needed.
3. **Matrices Representation**: In C++, we use `std::vector<std::vector<DATA_TYPE>>` to represent matrices. This choice provides flexibility and ease of use, but it's important to note that it's more memory-intensive compared to specialized matrix libraries.
4. **Loops**: The loops are directly translated from Fortran to C++, with adjustments for 0-based indexing.
5. **Function Signature**: The function `kernel_syrk` takes the matrices `a` and `c` by reference, ensuring that changes to `c` within the function are reflected outside it.

This translation assumes that the matrices `a` and `c` are properly initialized before calling `kernel_syrk`.
Let's write some test to verify if the translation is correct. 
Below are examples of unit tests for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the matrix operations.

### Fortran Unit Test

First, let's create a Fortran program that includes the original subroutine and a test case.

```fortran
program test_syrk
    implicit none
    integer, parameter :: ni = 3, nj = 3
    real :: alpha, beta
    real, dimension(ni, ni) :: c
    real, dimension(nj, ni) :: a
    integer :: i, j

    ! Initialize matrices
    alpha = 1.0
    beta = 2.0
    do i = 1, ni
        do j = 1, ni
            c(j, i) = 0.0
        end do
    end do
    do i = 1, nj
        do j = 1, ni
            a(j, i) = 1.0
        end do
    end do

    ! Call the subroutine
    call kernel_syrk(ni, nj, alpha, beta, c, a)

    ! Print the result
    print *, 'Resulting matrix C:'
    do i = 1, ni
        print *, (c(j, i), j=1, ni)
    end do

contains

    subroutine kernel_syrk(ni, nj, alpha, beta, c, a)
        implicit none
        integer :: ni, nj, i, j, k
        real :: alpha, beta
        real, dimension(ni, ni) :: c
        real, dimension(nj, ni) :: a

        !$pragma scop
        do i = 1, ni
            do j = 1, ni
                c(j, i) = c(j, i) * beta
            end do
        end do
        do i = 1, ni
            do j = 1, ni
                do k = 1, nj
                    c(j, i) = c(j, i) + (alpha * a(k, i) * a(k, j))
                end do
            end do
        end do
        !$pragma endscop
    end subroutine kernel_syrk

end program test_syrk
```

### C++ Unit Test

Now, let's create a C++ program that includes the translated function and a test case.

```cpp
#include <iostream>
#include <vector>
#include <cassert>

using DATA_TYPE = double;

void kernel_syrk(int ni, int nj, DATA_TYPE alpha, DATA_TYPE beta, std::vector<std::vector<DATA_TYPE>>& c, const std::vector<std::vector<DATA_TYPE>>& a) {
    // Initialize the matrix c with beta
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < ni; ++j) {
            c[j][i] *= beta;
        }
    }

    // Update c with the matrix multiplication result
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < ni; ++j) {
            for (int k = 0; k < nj; ++k) {
                c[j][i] += alpha * a[k][i] * a[k][j];
            }
        }
    }
}

void test_syrk() {
    int ni = 3, nj = 3; // Matrix dimensions
    DATA_TYPE alpha = 1.0, beta = 2.0; // Scaling factors

    // Initialize matrices a and c
    std::vector<std::vector<DATA_TYPE>> a(nj, std::vector<DATA_TYPE>(ni, 1.0)); // Example initialization
    std::vector<std::vector<DATA_TYPE>> c(ni, std::vector<DATA_TYPE>(ni, 0.0)); // Example initialization

    // Call the kernel
    kernel_syrk(ni, nj, alpha, beta, c, a);

    // Output the result
    std::cout << "Resulting matrix C:" << std::endl;
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < ni; ++j) {
            std::cout << c[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Verify the result
    // Example verification (this should be replaced with actual verification logic)
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < ni; ++j) {
            assert(c[i][j] == /* expected value */);
        }
    }
}

int main() {
    test_syrk();
    return 0;
}
```
