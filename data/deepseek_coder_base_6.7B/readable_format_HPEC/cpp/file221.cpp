Certainly! Below is the translated version of the provided Fortran code to C++. Note that in C++, array indexing starts from 0, unlike Fortran which starts from 1. Therefore, adjustments in the loop indices are necessary. Also, the data types are handled differently, and we use `std::vector` to represent the matrices for dynamic sizing.

```cpp
#include <vector>

// Assuming DATA_TYPE is a float or double, we use float for simplicity.
// If you need more precision, you can use double.
using DATA_TYPE = float;

void kernel_syr2k(int ni, int nj, DATA_TYPE alpha, DATA_TYPE beta, std::vector<std::vector<DATA_TYPE>>& c, const std::vector<std::vector<DATA_TYPE>>& a, const std::vector<std::vector<DATA_TYPE>>& b) {
    // Initialize the matrix c with beta
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < ni; ++j) {
            c[j][i] *= beta;
        }
    }

    // Perform the computation as per the original Fortran code
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < ni; ++j) {
            for (int k = 0; k < ni; ++k) {
                c[j][i] += alpha * a[k][i] * b[k][j];
                c[j][i] += alpha * b[k][i] * a[k][j];
            }
        }
    }
}

int main() {
    // Example usage
    int ni = 4; // Number of rows and columns for the matrices
    int nj = 4; // Number of rows and columns for the matrices
    DATA_TYPE alpha = 1.0;
    DATA_TYPE beta = 2.0;

    // Initialize matrices a, b, and c
    std::vector<std::vector<DATA_TYPE>> a(ni, std::vector<DATA_TYPE>(ni, 1.0)); // Example initialization
    std::vector<std::vector<DATA_TYPE>> b(ni, std::vector<DATA_TYPE>(ni, 1.0)); // Example initialization
    std::vector<std::vector<DATA_TYPE>> c(ni, std::vector<DATA_TYPE>(ni, 0.0)); // Example initialization

    kernel_syr2k(ni, nj, alpha, beta, c, a, b);

    // Output the result for verification
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < ni; ++j) {
            std::cout << c[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
```

This C++ code performs the same operations as the provided Fortran code. Note that the initialization of matrices `a` and `b` with example values is just for demonstration; you should replace these with actual values as needed.
Let's write some test to verify if the translation is correct. 
Below are the unit tests for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the translation by comparing the outputs of both implementations.

### Fortran Unit Test

First, let's create a Fortran program that calls the `kernel_syr2k` subroutine and prints the result for verification.

```fortran
program test_syr2k
    implicit none
    integer, parameter :: ni = 4, nj = 4
    real :: alpha, beta
    real, dimension(ni, ni) :: c, a, b
    integer :: i, j

    ! Initialize matrices
    alpha = 1.0
    beta = 2.0
    do i = 1, ni
        do j = 1, ni
            a(j, i) = 1.0
            b(j, i) = 1.0
            c(j, i) = 0.0
        end do
    end do

    ! Call the subroutine
    call kernel_syr2k(ni, nj, alpha, beta, c, a, b)

    ! Print the result
    do i = 1, ni
        do j = 1, ni
            print *, 'c(', j, ',', i, ') = ', c(j, i)
        end do
    end do
end program test_syr2k

subroutine kernel_syr2k(ni, nj, alpha, beta, c, a, b)
    implicit none
    real, dimension(nj, ni) :: a
    real, dimension(nj, ni) :: b
    real, dimension(ni, ni) :: c
    real :: alpha, beta
    integer :: ni, nj
    integer :: i, j, k

    !$pragma scop
    do i = 1, ni
        do j = 1, ni
            c(j, i) = c(j, i) * beta
        end do
    end do

    do i = 1, ni
        do j = 1, ni
            do k = 1, ni
                c(j, i) = c(j, i) + (alpha * a(k, i) * b(k, j))
                c(j, i) = c(j, i) + (alpha * b(k, i) * a(k, j))
            end do
        end do
    end do
    !$pragma endscop
end subroutine
```

### C++ Unit Test

Now, let's create a C++ program that calls the `kernel_syr2k` function and prints the result for verification.

```cpp
#include <iostream>
#include <vector>

using DATA_TYPE = float;

void kernel_syr2k(int ni, int nj, DATA_TYPE alpha, DATA_TYPE beta, std::vector<std::vector<DATA_TYPE>>& c, const std::vector<std::vector<DATA_TYPE>>& a, const std::vector<std::vector<DATA_TYPE>>& b) {
    // Initialize the matrix c with beta
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < ni; ++j) {
            c[j][i] *= beta;
        }
    }

    // Perform the computation as per the original Fortran code
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < ni; ++j) {
            for (int k = 0; k < ni; ++k) {
                c[j][i] += alpha * a[k][i] * b[k][j];
                c[j][i] += alpha * b[k][i] * a[k][j];
            }
        }
    }
}

int main() {
    int ni = 4; // Number of rows and columns for the matrices
    int nj = 4; // Number of rows and columns for the matrices
    DATA_TYPE alpha = 1.0;
    DATA_TYPE beta = 2.0;

    // Initialize matrices a, b, and c
    std::vector<std::vector<DATA_TYPE>> a(ni, std::vector<DATA_TYPE>(ni, 1.0));
    std::vector<std::vector<DATA_TYPE>> b(ni, std::vector<DATA_TYPE>(ni, 1.0));
    std::vector<std::vector<DATA_TYPE>> c(ni, std::vector<DATA_TYPE>(ni, 0.0));

    kernel_syr2k(ni, nj, alpha, beta, c, a, b);

    // Output the result for verification
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < ni; ++j) {
            std::cout << "c(" << j << "," << i << ") = " << c[i][j] << std::endl;
        }
    }

    return 0;
}
```

### Running the Tests

To run the Fortran test, you can compile and execute the Fortran program using a Fortran compiler like `gfortran`:

```sh
gfortran -o test_syr2k test_syr2k.f90
./test_syr2k
```

To run the C
