To translate the given Fortran code to C++, we need to consider several differences between the two languages, such as array indexing, data types, and the way arrays are passed to functions. Fortran arrays are 1-based, while C++ arrays are 0-based. Additionally, Fortran passes arrays to functions by reference by default, while in C++, we need to explicitly use pointers or references. Here's how the Fortran code can be translated to C++:

```cpp
#include <cmath>
#include <vector>

// Assuming DATA_TYPE is a floating-point type (e.g., float, double)
using DATA_TYPE = double;

void kernel_correlation(int m, int n, DATA_TYPE float_n, std::vector<std::vector<DATA_TYPE>>& dat, std::vector<std::vector<DATA_TYPE>>& symmat, std::vector<DATA_TYPE>& mean, std::vector<DATA_TYPE>& stddev) {
    const DATA_TYPE EPS = 0.1;

    // Determine mean of column vectors of input data matrix
    for (int j = 0; j < m; ++j) {
        mean[j] = 0.0;
        for (int i = 0; i < n; ++i) {
            mean[j] += dat[j][i];
        }
        mean[j] /= float_n;
    }

    // Determine standard deviations of column vectors of data matrix.
    for (int j = 0; j < m; ++j) {
        stddev[j] = 0.0;
        for (int i = 0; i < n; ++i) {
            stddev[j] += (dat[j][i] - mean[j]) * (dat[j][i] - mean[j]);
        }
        stddev[j] /= float_n;
        stddev[j] = sqrt(stddev[j]);
        if (stddev[j] <= EPS) {
            stddev[j] = 1.0;
        }
    }

    // Center and reduce the column vectors.
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dat[j][i] -= mean[j];
            dat[j][i] /= (sqrt(float_n) * stddev[j]);
        }
    }

    // Calculate the m * m correlation matrix.
    for (int j1 = 0; j1 < m - 1; ++j1) {
        symmat[j1][j1] = 1.0;
        for (int j2 = j1 + 1; j2 < m; ++j2) {
            symmat[j2][j1] = 0.0;
            for (int i = 0; i < n; ++i) {
                symmat[j2][j1] += dat[j1][i] * dat[j2][i];
            }
        }
        symmat[j1][j2] = symmat[j2][j1];
    }
    symmat[m-1][m-1] = 1.0;
}

int main() {
    // Example usage
    int m = 5; // Number of rows
    int n = 10; // Number of columns
    DATA_TYPE float_n = static_cast<DATA_TYPE>(n);

    std::vector<std::vector<DATA_TYPE>> dat(m, std::vector<DATA_TYPE>(n)); // Data matrix
    std::vector<std::vector<DATA_TYPE>> symmat(m, std::vector<DATA_TYPE>(m)); // Correlation matrix
    std::vector<DATA_TYPE> mean(m); // Mean vector
    std::vector<DATA_TYPE> stddev(m); // Standard deviation vector

    // Initialize dat with some values
    // For example, fill with random numbers
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            dat[i][j] = static_cast<DATA_TYPE>(rand()) / RAND_MAX;
        }
    }

    kernel_correlation(m, n, float_n, dat, symmat, mean, stddev);

    // Output results
    // For example, print the correlation matrix
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << symmat[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
```

This C++ code assumes that `dat`, `symmat`, `mean`, and `stddev` are properly initialized and sized before calling `kernel_correlation`. The example usage initializes `dat` with random values and then prints the resulting correlation matrix. Adjust the data initialization as needed for your specific use case.
Let's write some test to verify if the translation is correct. 
Below are examples of how you could write unit tests for both the Fortran and C++ versions of the code. These tests will verify that the implementations produce the same results for a given set of inputs.

### Fortran Unit Test

For the Fortran version, you can write a simple program that calls the `kernel_correlation` subroutine with predefined inputs and then checks the outputs against expected values.

```fortran
program test_kernel_correlation
    implicit none
    integer, parameter :: m = 3, n = 4
    real(8) :: dat(m, n) = reshape([1.0d0, 2.0d0, 3.0d0, &
                                    2.0d0, 3.0d0, 4.0d0, &
                                    3.0d0, 4.0d0, 5.0d0, &
                                    4.0d0, 5.0d0, 6.0d0], [m, n])
    real(8) :: symmat(m, m)
    real(8) :: mean(m)
    real(8) :: stddev(m)
    real(8) :: float_n
    integer :: i, j

    float_n = real(n, 8)
    call kernel_correlation(m, n, float_n, dat, symmat, mean, stddev)

    ! Print results for manual verification
    print *, 'Mean:'
    print *, mean
    print *, 'Standard Deviation:'
    print *, stddev
    print *, 'Correlation Matrix:'
    do i = 1, m
        print *, (symmat(i, j), j = 1, m)
    end do
end program test_kernel_correlation
```

### C++ Unit Test

For the C++ version, you can use a testing framework like Google Test for more comprehensive testing. However, for simplicity, the example below will just print the results for manual verification.

```cpp
#include <iostream>
#include <vector>
#include <cmath>

// Include or copy the kernel_correlation function here

void print_matrix(const std::vector<std::vector<double>>& mat) {
    for (const auto& row : mat) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

void print_vector(const std::vector<double>& vec) {
    for (double val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    int m = 3, n = 4;
    std::vector<std::vector<double>> dat = {
        {1.0, 2.0, 3.0, 4.0},
        {2.0, 3.0, 4.0, 5.0},
        {3.0, 4.0, 5.0, 6.0}
    };
    std::vector<std::vector<double>> symmat(m, std::vector<double>(m));
    std::vector<double> mean(m), stddev(m);
    double float_n = static_cast<double>(n);

    kernel_correlation(m, n, float_n, dat, symmat, mean, stddev);

    std::c
