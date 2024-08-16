To translate the given Fortran code to C++, we need to consider several aspects, including the data types, array indexing, and the loop constructs. In Fortran, arrays are 1-based, while in C++, they are 0-based. Also, Fortran passes arrays to functions/subroutines by reference automatically, while in C++, we need to explicitly use pointers or references. For simplicity and to maintain the spirit of the original code, I'll use raw pointers for the 2D arrays in C++.

Here's how the Fortran code can be translated to C++:

```cpp
#include <iostream>

// Assuming DATA_TYPE is a floating-point type (e.g., float or double)
using DATA_TYPE = double;

void init_array(int ni, int nj, DATA_TYPE& alpha, DATA_TYPE& beta, DATA_TYPE** c, DATA_TYPE** a, DATA_TYPE** b) {
    // Allocate memory for the 2D arrays
    c = new DATA_TYPE*[nj];
    for(int i = 0; i < nj; ++i) {
        c[i] = new DATA_TYPE[ni];
    }

    a = new DATA_TYPE*[nj];
    for(int i = 0; i < nj; ++i) {
        a[i] = new DATA_TYPE[nj];
    }

    b = new DATA_TYPE*[nj];
    for(int i = 0; i < nj; ++i) {
        b[i] = new DATA_TYPE[ni];
    }

    alpha = 32412.0;
    beta = 2123.0;

    // Filling the arrays
    for(int i = 0; i < ni; ++i) {
        for(int j = 0; j < nj; ++j) {
            c[j][i] = static_cast<DATA_TYPE>((i * j) / static_cast<DATA_TYPE>(ni));
            b[j][i] = static_cast<DATA_TYPE>((i * j) / static_cast<DATA_TYPE>(ni));
        }
    }

    for(int i = 0; i < nj; ++i) {
        for(int j = 0; j < nj; ++j) {
            a[j][i] = static_cast<DATA_TYPE>((i * j) / static_cast<DATA_TYPE>(ni));
        }
    }

    // Remember to deallocate the memory if it's no longer needed
    // for(int i = 0; i < nj; ++i) {
    //     delete[] c[i];
    //     delete[] a[i];
    //     delete[] b[i];
    // }
    // delete[] c;
    // delete[] a;
    // delete[] b;
}

int main() {
    int ni = 10; // Example values
    int nj = 10;
    DATA_TYPE alpha, beta;
    DATA_TYPE** c = nullptr;
    DATA_TYPE** a = nullptr;
    DATA_TYPE** b = nullptr;

    init_array(ni, nj, alpha, beta, c, a, b);

    // Example: Printing the arrays to verify the values
    std::cout << "alpha: " << alpha << ", beta: " << beta << std::endl;
    for(int i = 0; i < nj; ++i) {
        for(int j = 0; j < ni; ++j) {
            std::cout << "c[" << i << "][" << j << "]: " << c[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for(int i = 0; i < nj; ++i) {
        for(int j = 0; j < nj; ++j) {
            std::cout << "a[" << i << "][" << j << "]: " << a[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for(int i = 0; i < nj; ++i) {
        for(int j = 0; j < ni; ++j) {
            std::cout << "b[" << i << "][" << j << "]: " << b[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
```

This C++ code attempts to closely mimic the behavior of the original Fortran code. Note that in real applications, especially for larger arrays, it's advisable to use more efficient data structures (like `std::vector` for dynamic arrays) and possibly consider using a library designed for numerical computations, such as Eigen or Armadillo, which offer more functionality and better performance.
Let's write some test to verify if the translation is correct. 
Below are examples of how you might write unit tests for both the Fortran and C++ versions of the code. These tests will verify the correctness of the array initialization and the values assigned to `alpha` and `beta`.

### Fortran Unit Test

For Fortran, we'll use a simple program that calls the subroutine and checks the results. Fortran doesn't have a built-in unit testing framework like some other languages, so we'll do a basic manual check.

```fortran
program test_init_array
    implicit none
    integer, parameter :: nj = 10, ni = 10
    real(8) :: alpha, beta
    real(8), dimension(nj, ni) :: c
    real(8), dimension(nj, nj) :: a
    real(8), dimension(nj, ni) :: b
    integer :: i, j

    call init_array(ni, nj, alpha, beta, c, a, b)

    ! Check alpha and beta
    if (alpha /= 32412.0d0 .or. beta /= 2123.0d0) then
        print *, "Test failed for alpha and beta."
    else
        print *, "Test passed for alpha and beta."
    endif

    ! Check c and b
    do i = 1, ni
        do j = 1, nj
            if (c(j, i) /= ((i - 1) * (j - 1)) / ni .or. b(j, i) /= ((i - 1) * (j - 1)) / ni) then
                print *, "Test failed for c and b at ", i, j
                stop
            endif
        end do
    end do
    print *, "Test passed for c and b."

    ! Check a
    do i = 1, nj
        do j = 1, nj
            if (a(j, i) /= ((i - 1) * (j - 1)) / ni) then
                print *, "Test failed for a at ", i, j
                stop
            endif
        end do
    end do
    print *, "Test passed for a."

end program test_init_array
```

### C++ Unit Test

For C++, we can use the Google Test framework for unit testing. First, you need to install Google Test. Then, you can write the following test code:

```cpp
#include <gtest/gtest.h>
#include "init_array.h" // Assume the translated function is in this header

TEST(InitArrayTest, CheckValues) {
    int ni = 10, nj = 10;
    DATA_TYPE alpha, beta;
    DATA_TYPE** c = nullptr;
    DATA_TYPE** a = nullptr;
    DATA_TYPE** b = nullptr;

    init_array(ni, nj, alpha, beta, c, a, b);

    // Check alpha and beta
    EXPECT_DOUBLE_EQ(alpha, 32412.0);
    EXPECT_DOUBLE_EQ(beta, 2123.0);

    // Check c and b
    for(int i = 0; i < ni; ++i) {
        for(int j = 0; j < nj; ++j) {
            EXPECT_DOUBLE_EQ(c[j][i], static_cast<DATA_TYPE>((i * j) / static_cast<DATA_TYPE>(ni)));
            EXPECT_DOUBLE_EQ(b[
