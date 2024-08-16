To translate the given Fortran code to C++, we need to consider several aspects, including the array indexing, data types, and the loop constructs. In Fortran, arrays are 1-based, whereas in C++, they are 0-based. Also, Fortran passes arrays to functions/subroutines by reference automatically, whereas in C++, we need to explicitly use pointers or references. For simplicity and to maintain the 1-based indexing, we'll use static arrays in C++. Note that the data type `DATA_TYPE` in the Fortran code is not specified, so I'll assume it's a floating-point type (e.g., `double` in C++).

Here's how the Fortran subroutine could be translated to a C++ function:

```cpp
#include <iostream>

void init_array(int ni, int nj, double& alpha, double& beta, double** c, double** a, double** b) {
    // Assuming DATA_TYPE is double, we use double** for the 2D arrays.
    // Allocate memory for the 2D arrays a and b.
    a = new double*[nj];
    b = new double*[nj];
    for(int i = 0; i < nj; ++i) {
        a[i] = new double[ni];
        b[i] = new double[ni];
    }

    // Allocate memory for the 2D array c.
    c = new double*[ni];
    for(int i = 0; i < ni; ++i) {
        c[i] = new double[ni];
    }

    alpha = 32412.0;
    beta = 2123.0;

    for(int i = 0; i < ni; ++i) {
        for(int j = 0; j < nj; ++j) {
            a[j][i] = static_cast<double>(i) * static_cast<double>(j) / static_cast<double>(ni);
            b[j][i] = static_cast<double>(i) * static_cast<double>(j) / static_cast<double>(ni);
        }
    }

    for(int i = 0; i < ni; ++i) {
        for(int j = 0; j < ni; ++j) {
            c[j][i] = static_cast<double>(i) * static_cast<double>(j) / static_cast<double>(ni);
        }
    }
}

int main() {
    int ni = 10, nj = 10; // Example dimensions
    double alpha, beta;
    double** c = nullptr;
    double** a = nullptr;
    double** b = nullptr;

    init_array(ni, nj, alpha, beta, c, a, b);

    // Example: Print alpha and beta to verify
    std::cout << "alpha: " << alpha << ", beta: " << beta << std::endl;

    // Clean up
    for(int i = 0; i < nj; ++i) {
        delete[] a[i];
        delete[] b[i];
    }
    delete[] a;
    delete[] b;
    for(int i = 0; i < ni; ++i) {
        delete[] c[i];
    }
    delete[] c;

    return 0;
}
```

This C++ code does the following:
- It initializes the arrays `a`, `b`, and `c` with the specified dimensions `ni` and `nj`.
- It fills the arrays `a` and `b` with the values `((i - 1) * (j - 1)) / ni`, and the array `c` with `((i - 1) * (j - 1)) / ni`.
- It sets the values of `alpha` and `beta`.
- It demonstrates how to use dynamic memory allocation for 2D arrays in C++.
- It includes a main function to demonstrate the usage of `init_array` and clean up the allocated memory.

Please note that this translation assumes the use of `double` for `DATA_TYPE`, which is a common choice for floating-point numbers in C++. If `DATA_TYPE` is of a different type, you should adjust the code accordingly.
Let's write some test to verify if the translation is correct. 
Below are simple unit tests for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the array initialization and the values of `alpha` and `beta`.

### Fortran Unit Test

To test the Fortran subroutine, we'll write a simple program that calls the subroutine and checks the results.

```fortran
program test_init_array
    implicit none
    integer, parameter :: ni = 10, nj = 10
    double precision :: alpha, beta
    double precision, dimension(ni, nj) :: a, b
    double precision, dimension(ni, ni) :: c
    integer :: i, j

    call init_array(ni, nj, alpha, beta, c, a, b)

    ! Check alpha and beta
    if (alpha == 32412.0d0 .and. beta == 2123.0d0) then
        print *, "Test alpha and beta PASS"
    else
        print *, "Test alpha and beta FAIL"
    end if

    ! Check values in arrays a and b
    do i = 1, ni
        do j = 1, nj
            if (a(j, i) /= ((i - 1) * (j - 1)) / ni .or. b(j, i) /= ((i - 1) * (j - 1)) / ni) then
                print *, "Test array values FAIL"
                stop
            end if
        end do
    end do
    print *, "Test array values PASS"

    ! Check values in array c
    do i = 1, ni
        do j = 1, ni
            if (c(j, i) /= ((i - 1) * (j - 1)) / ni) then
                print *, "Test array c values FAIL"
                stop
            end if
        end do
    end do
    print *, "Test array c values PASS"

end program test_init_array
```

### C++ Unit Test

For the C++ code, we'll use a simple test framework like Google Test, but for simplicity, I'll provide a basic test similar to the Fortran one.

```cpp
#include <iostream>
#include <cmath> // For fabs

void init_array(int ni, int nj, double& alpha, double& beta, double** c, double** a, double** b);

bool test_init_array() {
    int ni = 10, nj = 10;
    double alpha, beta;
    double** c = nullptr;
    double** a = nullptr;
    double** b = nullptr;

    init_array(ni, nj, alpha, beta, c, a, b);

    // Check alpha and beta
    if (alpha == 32412.0 && beta == 2123.0) {
        std::cout << "Test alpha and beta PASS" << std::endl;
    } else {
        std::cout << "Test alpha and beta FAIL" << std::endl;
        return false;
    }

    // Check values in arrays a and b
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            double expected = static_cast<double>(i) * static_cast<double>(j) / static_cast<double>(ni);
            if (std::fabs(a[j][i] - expected) > 1e-9 || std::fabs(b[j][i] - expected) > 1e-9) {
                std::cout << "Test array values FAIL" << std::endl;
                return false;
            }
        }
    }
    std::cout << "Test array values PASS" << std::endl;

    // Check values in array c
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < ni; ++j) {
            double expected = static_cast<double>(i) * static_cast<double>(j) / static_cast<
