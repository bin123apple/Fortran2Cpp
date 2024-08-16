To translate the given Fortran code to C++, we need to consider several differences between the two languages, such as array indexing, data types, and the way arrays are passed to functions. Fortran arrays are 1-based, while C++ arrays are 0-based. Also, Fortran passes arrays to functions by reference by default, while in C++, we need to explicitly use pointers or references. For the given Fortran code, we'll use a 2D array representation in C++ using pointers to pointers. Here's how the translation might look:

```cpp
#include <cmath>

// Assuming DATA_TYPE is a float or double, depending on the precision required.
// For simplicity, we'll use double here.
using DATA_TYPE = double;

void kernel_cholesky(int n, DATA_TYPE* p, DATA_TYPE** a) {
    DATA_TYPE x;
    int i, j, k;

    for (i = 0; i < n; ++i) {
        x = a[i][i];
        for (j = 0; j < i; ++j) {
            x = x - a[j][i] * a[j][i];
        }
        p[i] = 1.0 / std::sqrt(x);
        for (j = i + 1; j < n; ++j) {
            x = a[j][i];
            for (k = 0; k < i; ++k) {
                x = x - (a[k][j] * a[k][i]);
            }
            a[i][j] = x * p[i];
        }
    }
}
```

Key Points in the Translation:

1. **Array Indexing:** Adjusted the indexing to start from 0 in C++, as opposed to 1 in Fortran.
2. **Data Types:** Used `double` for `DATA_TYPE` to match the Fortran `DATA_TYPE`. You can change this to `float` if lower precision is required.
3. **Array Representation:** Used a pointer to a pointer (`**a`) to represent a 2D array in C++. This requires careful memory management to avoid memory leaks.
4. **Math Functions:** Used `std::sqrt` from the `<cmath>` header for square root calculations.
5. **Loop Constructs:** Translated the Fortran loops to C++ for-loops.

This translation assumes that the caller of `kernel_cholesky` properly allocates and initializes the arrays `p` and `a` before calling the function. The function does not perform bounds checking, so ensure that the passed arrays are correctly sized.
Let's write some test to verify if the translation is correct. 
To verify the correctness of both the original Fortran code and the translated C++ code, we can write unit tests. For simplicity, I'll provide a basic example of how you might write these tests, focusing on a specific case.

### Fortran Unit Test

First, let's create a Fortran program that tests the `kernel_cholesky` subroutine. This example assumes you have a Fortran compiler like gfortran.

```fortran
program test_cholesky
    implicit none
    integer, parameter :: n = 3
    double precision :: p(n)
    double precision, dimension(n, n) :: a
    integer :: i, j

    ! Initialize matrix A
    a(1, 1) = 2.0d0; a(1, 2) = 1.0d0; a(1, 3) = 0.0d0
    a(2, 1) = 1.0d0; a(2, 2) = 2.0d0; a(2, 3) = 1.0d0
    a(3, 1) = 0.0d0; a(3, 2) = 1.0d0; a(3, 3) = 2.0d0

    ! Call the subroutine
    call kernel_cholesky(n, p, a)

    ! Print the results
    print *, "Cholesky decomposition of A:"
    do i = 1, n
        print *, (a(i, j), j = 1, n)
    end do
    print *, "P vector:"
    print *, (p(i), i = 1, n)

end program test_cholesky
```

### C++ Unit Test

For the C++ version, we'll use a simple main function to test the `kernel_cholesky` function. This example assumes you have a C++ compiler like g++.

```cpp
#include <iostream>
#include <iomanip>

// Include or copy the kernel_cholesky function here

int main() {
    const int n = 3;
    double p[n];
    double* a[n];
    for (int i = 0; i < n; ++i) {
        a[i] = new double[n];
    }

    // Initialize matrix A
    a[0][0] = 2.0; a[0][1] = 1.0; a[0][2] = 0.0;
    a[1][0] = 1.0; a[1][1] = 2.0; a[1][2] = 1.0;
    a[2][0] = 0.0; a[2][1] = 1.0; a[2][2] = 2.0;

    // Call the function
    kernel_cholesky(n, p, a);

    // Print the results
    std::cout << "Cholesky decomposition of A:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << std::setw(10) << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "P vector:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << std::setw(10) << p[i] << " ";
    }
    std::cout << std::endl;

    // Clean up
    for (int i = 0; i < n; ++i) {
        delete[] a[i];
    }

    return 0;
}
```

### Running the Tests

- **Fortran:** Compile and run the Fortran test program using a command like `gfortran -o test_cholesky test_cholesky.f90 && ./test_cholesky`.
- **C++:** Compile and run the C++ test program using a command like `g++ -o test_cholesky test_cholesky.cpp && ./test_cholesky`.

These tests initialize a specific matrix `A` and then print the results of the Cholesky decomposition, which you can manually verify against the expected results. For a more rigorous verification, you could compare the output against known correct results or implement a comparison function in both Fortran and C++ that checks if the output matches the expected values within a certain tolerance.
