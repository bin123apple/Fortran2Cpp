To translate the given Fortran code to C++, we need to consider several aspects, including the array indexing, data types, and loop structures. Fortran arrays are 1-based, while C++ arrays are 0-based. Also, Fortran passes arrays to functions/subroutines by reference automatically, whereas in C++, we need to explicitly use pointers or references. For simplicity and to maintain the original structure, I'll use pointers for the arrays in the C++ translation. Note that Fortran's `DBLE` function converts its argument to a double precision floating-point number, which corresponds to `double` in C++.

Here's the translated C++ code:

```cpp
#include <iostream>

// Assuming DATA_TYPE is a floating-point type, e.g., float or double
using DATA_TYPE = double;

// Function prototype
void init_array(DATA_TYPE& alpha, DATA_TYPE& beta, DATA_TYPE** a, DATA_TYPE** b, DATA_TYPE** c, DATA_TYPE** d, int ni, int nj, int nk, int nl);

int main() {
    // Example usage
    int ni = 10, nj = 10, nk = 10, nl = 10;
    DATA_TYPE alpha, beta;
    DATA_TYPE** a = new DATA_TYPE*[nk];
    DATA_TYPE** b = new DATA_TYPE*[nj];
    DATA_TYPE** c = new DATA_TYPE*[nl];
    DATA_TYPE** d = new DATA_TYPE*[nl];

    for(int i = 0; i < nk; ++i) {
        a[i] = new DATA_TYPE[ni];
    }
    for(int i = 0; i < nj; ++i) {
        b[i] = new DATA_TYPE[nk];
    }
    for(int i = 0; i < nl; ++i) {
        c[i] = new DATA_TYPE[nj];
        d[i] = new DATA_TYPE[ni];
    }

    init_array(alpha, beta, a, b, c, d, ni, nj, nk, nl);

    // Clean up dynamically allocated memory
    for(int i = 0; i < nk; ++i) {
        delete[] a[i];
    }
    for(int i = 0; i < nj; ++i) {
        delete[] b[i];
    }
    for(int i = 0; i < nl; ++i) {
        delete[] c[i];
        delete[] d[i];
    }
    delete[] a;
    delete[] b;
    delete[] c;
    delete[] d;

    return 0;
}

void init_array(DATA_TYPE& alpha, DATA_TYPE& beta, DATA_TYPE** a, DATA_TYPE** b, DATA_TYPE** c, DATA_TYPE** d, int ni, int nj, int nk, int nl) {
    alpha = 32412.0;
    beta = 2123.0;

    for(int i = 0; i < ni; ++i) {
        for(int j = 0; j < nk; ++j) {
            a[j][i] = static_cast<DATA_TYPE>((i) * (j)) / ni;
        }
    }

    for(int i = 0; i < nk; ++i) {
        for(int j = 0; j < nj; ++j) {
            b[j][i] = static_cast<DATA_TYPE>((i) * (j)) / nj;
        }
    }

    for(int i = 0; i < nl; ++i) {
        for(int j = 0; j < nj; ++j) {
            c[j][i] = static_cast<DATA_TYPE>(i * (j + 2)) / nl;
        }
    }

    for(int i = 0; i < ni; ++i) {
        for(int j = 0; j < nl; ++j) {
            d[j][i] = static_cast<DATA_TYPE>(i * (j + 1)) / nk;
        }
    }
}
```

This C++ code attempts to closely follow the structure and logic of the original Fortran code, including the initialization of the arrays and the assignment of values to the elements based on the provided formulas. Note that dynamic memory allocation is used for the arrays to mimic the behavior of Fortran's array handling. Remember to include proper error checking and clean up resources when using this code in a production environment.
Let's write some test to verify if the translation is correct. 
To verify the correctness of both the original Fortran code and the translated C++ code, we can write unit tests. For Fortran, we'll use a simple approach to demonstrate testing, as Fortran lacks a built-in unit testing framework similar to those available in C++. For C++, we'll use Google Test, a widely used C++ testing framework.

### Fortran Unit Test

Since Fortran lacks a built-in unit testing framework, we'll write a simple test procedure within the program. This test will check the values of the arrays after the `init_array` subroutine is called.

```fortran
program test_init_array
    implicit none
    integer, parameter :: ni = 10, nj = 10, nk = 10, nl = 10
    real(kind=8) :: alpha, beta
    real(kind=8), dimension(nk, ni) :: a
    real(kind=8), dimension(nj, nk) :: b
    real(kind=8), dimension(nl, nj) :: c
    real(kind=8), dimension(nl, ni) :: d
    integer :: i, j

    call init_array(alpha, beta, a, b, c, d, ni, nj, nk, nl)

    ! Test alpha and beta
    if (alpha /= 32412.0 .or. beta /= 2123.0) then
        print *, "Test failed for alpha and beta."
    else
        print *, "Test passed for alpha and beta."
    end if

    ! Test array a
    do i = 1, ni
        do j = 1, nk
            if (a(j, i) /= (i-1) * (j-1) / ni) then
                print *, "Test failed for array a."
                stop
            end if
        end do
    end do
    print *, "Test passed for array a."

    ! Test array b
    do i = 1, nk
        do j = 1, nj
            if (b(j, i) /= (i-1) * j / nj) then
                print *, "Test failed for array b."
                stop
            end if
        end do
    end do
    print *, "Test passed for array b."

    ! Test array c
    do i = 1, nl
        do j = 1, nj
            if (c(j, i) /= (i-1) * (j+2) / nl) then
                print *, "Test failed for array c."
                stop
            end if
        end do
    end do
    print *, "Test passed for array c."

    ! Test array d
    do i = 1, ni
        do j = 1, nl
            if (d(j, i) /= (i-1) * (j+1) / nk) then
                print *, "Test failed for array d."
                stop
            end if
        end do
    end do
    print *, "Test passed for array d."

end program test_init_array
```

### C++ Unit Test with Google Test

First, ensure you have Google Test installed and set up in your project. The following C++ code demonstrates how to write unit tests using Google Test.

```cpp
#include <gtest/gtest.h>
#include "init_array.hpp" // Assume the translated function is declared in this header

TEST(InitArrayTest, TestAlphaBeta) {
    DATA_TYPE alpha, beta;
    DATA_TYPE** a = new DATA_TYPE*[nk];
    DATA_TYPE** b = new DATA_TYPE*[nj];
    DATA_TYPE** c = new DATA_TYPE*[nl
