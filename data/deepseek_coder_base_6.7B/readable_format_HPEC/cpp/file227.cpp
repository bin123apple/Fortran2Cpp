Certainly! Below is the translated C++ code for the provided Fortran subroutine. Note that in C++, array indexing starts from 0, unlike Fortran where it starts from 1. Also, the data types and the loop constructs have been adapted to C++ syntax.

```cpp
#include <vector>

// Assuming DATA_TYPE is a float or double, depending on the precision required.
// For simplicity, we'll use double here.
using DATA_TYPE = double;

void kernel_gemm(int ni, int nj, int nk, DATA_TYPE alpha, DATA_TYPE beta, std::vector<std::vector<DATA_TYPE>>& c, const std::vector<std::vector<DATA_TYPE>>& a, const std::vector<std::vector<DATA_TYPE>>& b) {
    // Check if the dimensions of the matrices are compatible for multiplication
    if (a[0].size() != b.size()) {
        throw std::invalid_argument("Matrix dimensions are not compatible for multiplication.");
    }

    // Ensure the dimensions of the matrices C and A match the given dimensions
    if (c.size() != nj || c[0].size() != ni) {
        c.resize(nj);
        for (auto& row : c) {
            row.resize(ni);
        }
    }

    // Initialize or reset matrix C to beta
    for (int j = 0; j < nj; ++j) {
        for (int i = 0; i < ni; ++i) {
            c[j][i] *= beta;
        }
    }

    // Perform the matrix multiplication
    for (int j = 0; j < nj; ++j) {
        for (int i = 0; i < ni; ++i) {
            for (int k = 0; k < nk; ++k) {
                c[j][i] += alpha * a[k][i] * b[j][k];
            }
        }
    }
}
```

### Explanation:
1. **Data Types and Dimensions:**
   - The `DATA_TYPE` is defined as `double`, assuming double precision. You can change it to `float` if single precision is needed.
   - Matrices `a`, `b`, and `c` are represented as `std::vector<std::vector<DATA_TYPE>>`.

2. **Matrix Multiplication:**
   - The function checks if the dimensions of the matrices `a` and `b` are compatible for multiplication.
   - It initializes or resizes matrix `c` to have dimensions `nj` by `ni`.
   - It multiplies matrix `c` by `beta`.
   - Nested loops iterate over the dimensions specified by `ni`, `nj`, and `nk`, performing the matrix multiplication as per the original Fortran code.

3. **Indexing:**
   - Fortran arrays are 1-based, while C++ arrays are 0-based. Adjustments are made accordingly.

This C++ function can be called with appropriate parameters to perform the matrix multiplication as intended in the original Fortran code.
Let's write some test to verify if the translation is correct. 
Below are the unit tests for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the matrix multiplication operations.

### Fortran Unit Test

First, let's create a Fortran program that tests the `kernel_gemm` subroutine.

```fortran
program test_kernel_gemm
    implicit none
    integer, parameter :: ni = 2, nj = 2, nk = 2
    real(kind=8) :: alpha, beta
    real(kind=8), dimension(nk, ni) :: a
    real(kind=8), dimension(nj, nk) :: b
    real(kind=8), dimension(nj, ni) :: c
    integer :: i, j

    ! Initialize matrices
    alpha = 1.0
    beta = 0.5
    a = reshape([1.0, 2.0, 3.0, 4.0], shape(a))
    b = reshape([1.0, 0.0, 0.0, 1.0], shape(b))
    c = reshape([0.0, 0.0, 0.0, 0.0], shape(c))

    ! Call the subroutine
    call kernel_gemm(ni, nj, nk, alpha, beta, c, a, b)

    ! Print the result
    do j = 1, nj
        do i = 1, ni
            print *, 'c(', j, ',', i, ') = ', c(j, i)
        end do
    end do
end program test_kernel_gemm
```

### C++ Unit Test

Now, let's create a C++ program that tests the `kernel_gemm` function.

```cpp
#include <iostream>
#include <vector>
#include <stdexcept>

// Assuming DATA_TYPE is a float or double, depending on the precision required.
// For simplicity, we'll use double here.
using DATA_TYPE = double;

// Function prototype
void kernel_gemm(int ni, int nj, int nk, DATA_TYPE alpha, DATA_TYPE beta, std::vector<std::vector<DATA_TYPE>>& c, const std::vector<std::vector<DATA_TYPE>>& a, const std::vector<std::vector<DATA_TYPE>>& b);

int main() {
    int ni = 2, nj = 2, nk = 2;
    DATA_TYPE alpha = 1.0, beta = 0.5;
    std::vector<std::vector<DATA_TYPE>> a = {{1.0, 3.0}, {2.0, 4.0}};
    std::vector<std::vector<DATA_TYPE>> b = {{1.0, 0.0}, {0.0, 1.0}};
    std::vector<std::vector<DATA_TYPE>> c = {{0.0, 0.0}, {0.0, 0.0}};

    // Call the function
    kernel_gemm(ni, nj, nk, alpha, beta, c, a, b);

    // Print the result
    for (int j = 0; j < nj; ++j) {
        for (int i = 0; i < ni; ++i) {
            std::cout << "c(" << j+1 << "," << i+1 << ") = " << c[j][i] << std::endl;
        }
    }

    return 0;
}
```

### Explanation:

1. **Fortran Unit Test:**
   - The program initializes matrices `a`, `b`, and `c`.
   - It calls the `kernel_gemm` subroutine.
   - It prints the resulting matrix `c`.

2. **C++ Unit Test:**
   - The program initializes matrices `a`, `b`, and `c`.
   - It calls the `kernel_gemm` function.
   - It prints the resulting matrix `c`.

### Compilation and Execution:

- **Fortran:**
  - Compile the Fortran program using a Fortran compiler, e.g., `gfortran`:
    ```sh
    gfortran -o test_kernel_gemm test_kernel_gemm.f90
    ./test_kernel_gemm
    ```

- **C++:**
  - Compile the C++ program using a C++ compiler, e.g., `g++`:
    ```sh
    g++ -o test_kernel_gemm test_kernel_gemm.cpp
    ./test_kernel_gemm
    ```

These tests should produce the same output for the matrix `c`, verifying the correctness of the translation.
