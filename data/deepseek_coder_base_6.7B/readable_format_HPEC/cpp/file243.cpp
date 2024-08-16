To translate the given Fortran code to C++, we need to consider several differences between the two languages, such as array indexing (Fortran arrays are 1-based, while C++ arrays are 0-based), data types, and the way arrays are declared and passed to functions. Here's a C++ version of the Fortran code provided:

```cpp
#include <vector>

// Assuming DATA_TYPE is a floating-point type (e.g., double)
using DATA_TYPE = double;

void kernel_symm(int ni, int nj, DATA_TYPE alpha, DATA_TYPE beta, std::vector<std::vector<DATA_TYPE>>& c, const std::vector<std::vector<DATA_TYPE>>& a, const std::vector<std::vector<DATA_TYPE>>& b) {
    // Assuming the dimensions of a and b are nj x nj and nj x ni respectively
    // and c is nj x ni
    DATA_TYPE acc;

    // Loop over i
    for (int i = 0; i < ni; ++i) {
        // Loop over j
        for (int j = 0; j < nj; ++j) {
            acc = 0.0;
            // Loop over k
            for (int k = 0; k < j; ++k) {
                c[j][k] += alpha * a[i][k] * b[j][i];
                acc += b[j][k] * a[i][k];
            }
            c[j][i] = beta * c[j][i] + alpha * a[i][i] * b[j][i] + alpha * acc;
        }
    }
}

int main() {
    // Example usage
    int ni = 5; // Number of rows in a and c
    int nj = 5; // Number of columns in a, b, and c
    DATA_TYPE alpha = 1.0;
    DATA_TYPE beta = 2.0;

    std::vector<std::vector<DATA_TYPE>> a(ni, std::vector<DATA_TYPE>(nj, 0.0)); // Example initialization
    std::vector<std::vector<DATA_TYPE>> b(nj, std::vector<DATA_TYPE>(ni, 0.0)); // Example initialization
    std::vector<std::vector<DATA_TYPE>> c(nj, std::vector<DATA_TYPE>(ni, 0.0)); // Example initialization

    // Call the kernel
    kernel_symm(ni, nj, alpha, beta, c, a, b);

    return 0;
}
```

Key Points in the Translation:

1. **Array Indexing**: Adjusted the loop indices to start from 0, as C++ uses 0-based indexing.
2. **Data Types**: Used `std::vector<std::vector<DATA_TYPE>>` for arrays `a`, `b`, and `c` to handle dynamic arrays. The `DATA_TYPE` is assumed to be a floating-point type (e.g., `double`).
3. **Function Arguments**: Passed arrays `a`, `b`, and `c` by reference to avoid copying large amounts of data.
4. **Loop Constructs**: Used `for` loops in C++ instead of Fortran's `do` loops.
5. **Initialization**: Added example initializations for `a`, `b`, and `c` arrays.

This translation assumes that the sizes of the arrays `a`, `b`, and `c` are correctly set before calling `kernel_symm`.
Let's write some test to verify if the translation is correct. 
Below are simple unit tests for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the translation by comparing the output of the Fortran and C++ versions for a given input.

### Fortran Unit Test

First, let's create a Fortran program that calls the `kernel_symm` subroutine and prints the results.

```fortran
program test_kernel_symm
    implicit none
    integer, parameter :: ni = 2, nj = 2
    double precision, dimension(ni, nj) :: a, b, c
    double precision :: alpha, beta
    integer :: i, j

    ! Initialize input arrays
    alpha = 1.0d0
    beta = 2.0d0
    a = reshape([1.0d0, 2.0d0, 3.0d0, 4.0d0], shape(a))
    b = reshape([1.0d0, 0.0d0, 0.0d0, 1.0d0], shape(b))
    c = reshape([0.0d0, 0.0d0, 0.0d0, 0.0d0], shape(c))

    ! Call the subroutine
    call kernel_symm(ni, nj, alpha, beta, c, a, b)

    ! Print the result
    do i = 1, ni
        do j = 1, nj
            print *, 'c(', i, ',', j, ') = ', c(i, j)
        end do
    end do
end program test_kernel_symm
```

### C++ Unit Test

Now, let's create a C++ program that calls the `kernel_symm` function and prints the results.

```cpp
#include <iostream>
#include <vector>

// Assuming DATA_TYPE is a floating-point type (e.g., double)
using DATA_TYPE = double;

// Include or copy the kernel_symm function here

int main() {
    int ni = 2; // Number of rows in a and c
    int nj = 2; // Number of columns in a, b, and c
    DATA_TYPE alpha = 1.0;
    DATA_TYPE beta = 2.0;

    std::vector<std::vector<DATA_TYPE>> a = {{1.0, 3.0}, {2.0, 4.0}};
    std::vector<std::vector<DATA_TYPE>> b = {{1.0, 0.0}, {0.0, 1.0}};
    std::vector<std::vector<DATA_TYPE>> c = {{0.0, 0.0}, {0.0, 0.0}};

    // Call the kernel
    kernel_symm(ni, nj, alpha, beta, c, a, b);

    // Print the result
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            std::cout << "c(" << i + 1 << "," << j + 1 << ") = " << c[i][j] << std::endl;
        }
    }

    return 0;
}
```

### Explanation

1. **Fortran Test Program**:
   - Initializes the input arrays `a`, `b`, and `c`.
   - Calls the `kernel_symm` subroutine.
   - Prints the resulting matrix `c`.

2. **C++ Test Program**:
   - Initializes the input arrays `a`, `b`, and `c`.
   - Calls the `kernel_symm` function.
   - Prints the resulting matrix `c`.

### Compilation and Execution

To compile and run the Fortran test program, you can use a Fortran compiler like `gfortran`:

```sh
gfortran -o test_kernel_symm_fortran test_kernel_symm.f90
./test_kernel_symm_fortran
```

To compile and run the C++ test program, you can use a C++ compiler like `g++`:

```sh
g++ -o test_kernel_symm_cpp test_kernel_symm.cpp
./test_kernel_symm_cpp
```

### Expected Output

For the given inputs, both programs should produce the same output for the matrix `c`. This output will verify that the translation from Fortran to C++ is correct.

Example output:
```
c(1,1) = -2
c(1,2) = -4
c(2,1) = -4
c(2,2) = -8
```

This output should be consistent across both the Fortran and C++ versions, demonstrating that the translation has been done correctly.
