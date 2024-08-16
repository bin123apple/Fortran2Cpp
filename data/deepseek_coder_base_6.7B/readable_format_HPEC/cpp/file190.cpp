To translate the given Fortran code to C++, we need to consider several aspects, such as array indexing, data types, and loop structures. In Fortran, arrays are 1-based, while in C++, they are 0-based. Also, Fortran passes arrays to functions/subroutines by reference automatically, while in C++, we need to explicitly use pointers or references. For simplicity and closer alignment with the original code, I'll use pointers for the 2D arrays in C++. Note that in Fortran, `DATA_TYPE` is used to define a specific data type, which we'll assume is equivalent to `double` in C++.

Here's the translated C++ code:

```cpp
#include <iostream>

void init_array(int ni, int nj, double alpha, double beta, double** c, double** a) {
    // Allocate memory for the 2D arrays
    a = new double*[ni];
    for(int i = 0; i < ni; ++i) {
        a[i] = new double[ni];
    }

    c = new double*[nj];
    for(int i = 0; i < nj; ++i) {
        c[i] = new double[ni];
    }

    alpha = 32412.0;
    beta = 2123.0;

    for(int i = 0; i < ni; ++i) {
        for(int j = 0; j < ni; ++j) {
            a[j][i] = static_cast<double>(i) * static_cast<double>(j) / static_cast<double>(ni);
        }
    }

    for(int j = 0; j < ni; ++j) {
        for(int i = 0; i < nj; ++i) {
            c[j][i] = static_cast<double>(i) * static_cast<double>(j) / static_cast<double>(ni);
        }
    }

    // Remember to deallocate the memory if it's no longer needed
    for(int i = 0; i < ni; ++i) {
        delete[] a[i];
    }
    delete[] a;

    for(int i = 0; i < nj; ++i) {
        delete[] c[i];
    }
    delete[] c;
}

int main() {
    int ni = 100, nj = 100; // Example dimensions
    double alpha, beta;
    double** a = nullptr;
    double** c = nullptr;

    init_array(ni, nj, alpha, beta, c, a);

    // Example: Print a value to verify
    std::cout << "a[0][0]: " << a[0][0] << std::endl;
    std::cout << "c[0][0]: " << c[0][0] << std::endl;

    return 0;
}
```

This C++ code does the following:
- It initializes the arrays `a` and `c` with dimensions `ni` and `nj`, respectively.
- It assigns values to `alpha` and `beta`.
- It fills the arrays `a` and `c` with the specified formulas.
- It deallocates the memory allocated for the arrays.

Please note that in a real-world scenario, you might want to use `std::vector` or other safer data structures, and you might also want to add error checking and more sophisticated memory management techniques.
Let's write some test to verify if the translation is correct. 
Below are examples of unit tests for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the array initialization and the values assigned to `alpha` and `beta`.

### Fortran Unit Test

For the Fortran code, we'll write a simple program that calls the `init_array` subroutine and checks the values of `alpha`, `beta`, and a few elements of the arrays `a` and `c`.

```fortran
program test_init_array
    implicit none
    integer, parameter :: ni = 100, nj = 100
    double precision, allocatable :: a(:,:), c(:,:)
    double precision :: alpha, beta
    integer :: i, j

    allocate(a(ni,ni), c(nj,ni))

    call init_array(ni, nj, alpha, beta, c, a)

    ! Check alpha and beta
    if (alpha == 32412.0d0 .and. beta == 2123.0d0) then
        print *, "Test alpha and beta: PASS"
    else
        print *, "Test alpha and beta: FAIL"
    end if

    ! Check a few values of a
    if (a(1,1) == 0.0d0 .and. a(ni,ni) == (ni-1)*(ni-1)/ni) then
        print *, "Test a: PASS"
    else
        print *, "Test a: FAIL"
    end if

    ! Check a few values of c
    if (c(1,1) == 0.0d0 .and. c(nj,ni) == (ni-1)*(nj-1)/ni) then
        print *, "Test c: PASS"
    else
        print *, "Test c: FAIL"
    end if

    deallocate(a, c)
end program test_init_array
```

### C++ Unit Test

For the C++ code, we'll use a simple test framework like Google Test, but for simplicity, I'll provide a basic example without external dependencies.

```cpp
#include <iostream>
#include <cmath>

void init_array(int ni, int nj, double& alpha, double& beta, double** c, double** a);

bool test_init_array() {
    int ni = 100, nj = 100;
    double alpha, beta;
    double** a = nullptr;
    double** c = nullptr;

    init_array(ni, nj, alpha, beta, c, a);

    // Check alpha and beta
    if (alpha == 32412.0 && beta == 2123.0) {
        std::cout << "Test alpha and beta: PASS" << std::endl;
    } else {
        std::cout << "Test alpha and beta: FAIL" << std::endl;
        return false;
    }

    // Check a few values of a
    if (a[0][0] == 0.0 && a[ni-1][ni-1] == (ni-1)*(ni-1)/ni) {
        std::cout << "Test a: PASS" << std::endl;
    } else {
        std::cout << "Test a: FAIL" << std::endl;
        return false;
    }

    // Check a few values of c
    if (c[0][0] == 0.0 && c[nj-1][ni-1] == (ni-1)*(nj-1)/ni) {
        std::cout << "Test c: PASS" << std::endl;
    } else {
        std::cout << "Test c: FAIL" << std::endl;
        return false;
    }

    return true;
}

int main() {
    if (test_init_array()) {
        std::cout << "All tests passed." << std::endl;
    } else {
        std::cout << "Some tests failed." << std::endl;
    }

    return 0;
}
```

These unit tests will help ensure that the translated C++ code behaves similarly to the original Fortran code by checking the correctness of the array initialization and the values assigned to `alpha` and `beta`.
