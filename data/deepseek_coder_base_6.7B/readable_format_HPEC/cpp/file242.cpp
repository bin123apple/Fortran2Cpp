To translate the given Fortran code to C++, we need to consider several aspects, such as array indexing, data types, and loop constructs. In Fortran, arrays are 1-based, while in C++, they are 0-based. Also, Fortran passes arrays to functions/subroutines by reference automatically, while in C++, we need to explicitly use pointers or references. For simplicity and to maintain the original structure, I'll use raw pointers in the C++ translation. Note that the data type `DATA_TYPE` in the Fortran code is not specified, so I'll assume it's a floating-point type (e.g., `float` or `double`).

Here's the C++ translation:

```cpp
#include <iostream>

// Assuming DATA_TYPE is float or double
using DATA_TYPE = double;

void init_array(int ni, int nj, int nk, DATA_TYPE& alpha, DATA_TYPE& beta, DATA_TYPE** c, DATA_TYPE** a, DATA_TYPE** b) {
    // Allocate memory for the arrays
    c = new DATA_TYPE*[nj];
    for(int i = 0; i < nj; ++i) {
        c[i] = new DATA_TYPE[ni];
    }

    a = new DATA_TYPE*[nk];
    for(int i = 0; i < nk; ++i) {
        a[i] = new DATA_TYPE[ni];
    }

    b = new DATA_TYPE*[nj];
    for(int i = 0; i < nj; ++i) {
        b[i] = new DATA_TYPE[nk];
    }

    alpha = 32412.0;
    beta = 2123.0;

    // Fill array c
    for(int i = 0; i < ni; ++i) {
        for(int j = 0; j < nj; ++j) {
            c[j][i] = ((static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j)) / static_cast<DATA_TYPE>(ni));
        }
    }

    // Fill array a
    for(int i = 0; i < ni; ++i) {
        for(int j = 0; j < nk; ++j) {
            a[j][i] = ((static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j)) / static_cast<DATA_TYPE>(ni));
        }
    }

    // Fill array b
    for(int i = 0; i < nk; ++i) {
        for(int j = 0; j < nj; ++j) {
            b[j][i] = ((static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j)) / static_cast<DATA_TYPE>(ni));
        }
    }
}

int main() {
    int ni = 10, nj = 10, nk = 10;
    DATA_TYPE alpha, beta;
    DATA_TYPE** c = nullptr;
    DATA_TYPE** a = nullptr;
    DATA_TYPE** b = nullptr;

    init_array(ni, nj, nk, alpha, beta, c, a, b);

    // Example: Print a value to verify
    std::cout << "c[0][0]: " << c[0][0] << std::endl;
    std::cout << "a[0][0]: " << a[0][0] << std::endl;
    std::cout << "b[0][0]: " << b[0][0] << std::endl;

    // Clean up
    for(int i = 0; i < nj; ++i) {
        delete[] c[i];
    }
    delete[] c;

    for(int i = 0; i < nk; ++i) {
        delete[] a[i];
    }
    delete[] a;

    for(int i = 0; i < nj; ++i) {
        delete[] b[i];
    }
    delete[] b;

    return 0;
}
```

This C++ code initializes the arrays `a`, `b`, and `c` based on the given Fortran subroutine. Note that dynamic memory allocation is used for the arrays, and the `main` function demonstrates how to use the `init_array` function and then cleans up the allocated memory.
Let's write some test to verify if the translation is correct. 
Below are simple unit tests for both the Fortran and C++ codes. These tests will verify the correctness of the initialization of the arrays `a`, `b`, and `c`.

### Fortran Unit Test

For the Fortran code, we'll add a simple program that calls the `init_array` subroutine and checks the values of the arrays.

```fortran
program test_init_array
    implicit none
    integer, parameter :: ni = 10, nj = 10, nk = 10
    real, allocatable :: a(:,:), b(:,:), c(:,:)
    real :: alpha, beta
    integer :: i, j

    allocate(a(nk, ni), b(nj, nk), c(nj, ni))

    call init_array(ni, nj, nk, alpha, beta, c, a, b)

    ! Check values
    print *, 'alpha:', alpha
    print *, 'beta:', beta
    print *, 'c(1,1):', c(1,1)
    print *, 'a(1,1):', a(1,1)
    print *, 'b(1,1):', b(1,1)

    ! Clean up
    deallocate(a, b, c)
end program test_init_array
```

### C++ Unit Test

For the C++ code, we'll use a simple test within the `main` function to verify the initialization.

```cpp
#include <iostream>
#include <cmath> // For fabs

// Assuming DATA_TYPE is float or double
using DATA_TYPE = double;

void init_array(int ni, int nj, int nk, DATA_TYPE& alpha, DATA_TYPE& beta, DATA_TYPE** c, DATA_TYPE** a, DATA_TYPE** b);

int main() {
    int ni = 10, nj = 10, nk = 10;
    DATA_TYPE alpha, beta;
    DATA_TYPE** c = nullptr;
    DATA_TYPE** a = nullptr;
    DATA_TYPE** b = nullptr;

    init_array(ni, nj, nk, alpha, beta, c, a, b);

    // Check values
    std::cout << "alpha: " << alpha << std::endl;
    std::cout << "beta: " << beta << std::endl;
    std::cout << "c[0][0]: " << c[0][0] << std::endl;
    std::cout << "a[0][0]: " << a[0][0] << std::endl;
    std::cout << "b[0][0]: " << b[0][0] << std::endl;

    // Clean up
    for(int i = 0; i < nj; ++i) {
        delete[] c[i];
    }
    delete[] c;

    for(int i = 0; i < nk; ++i) {
        delete[] a[i];
    }
    delete[] a;

    for(int i = 0; i < nj; ++i) {
        delete[] b[i];
    }
    delete[] b;

    return 0;
}
```

### Compilation and Execution

#### Fortran

To compile and run the Fortran code, you can use a Fortran compiler like `gfortran`:

```sh
gfortran -o test_init_array test_init_array.f90
./test_init_array
```

#### C++

To compile and run the C++ code, you can use a C++ compiler like `g++`:

```sh
g++ -o test_init_array test_init_array.cpp
./test_init_
