To translate the given Fortran code to C++, we need to consider several aspects, including the data types, array indexing, and the loop structure. In Fortran, arrays are 1-based, while in C++, they are 0-based. Also, Fortran passes arrays to functions/subroutines by reference automatically, while in C++, we need to explicitly use pointers or references. For this translation, I'll use a 2D array represented by a pointer to pointers, which is a common approach in C++ for dynamically allocating 2D arrays.

Here's the translated C++ code:

```cpp
#include <iostream>

// Assuming DATA_TYPE is a float or double, depending on the precision required.
// For simplicity, we'll use double here.
using DATA_TYPE = double;

void init_array(int m, int n, DATA_TYPE& float_n, DATA_TYPE** dat) {
    // Allocate memory for the 2D array
    dat = new DATA_TYPE*[n];
    for(int i = 0; i < n; ++i) {
        dat[i] = new DATA_TYPE[m];
    }

    float_n = 1.2;

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            dat[j][i] = static_cast<DATA_TYPE>((i - 1) * (j - 1)) / static_cast<DATA_TYPE>(m);
        }
    }
}

int main() {
    int m = 5; // Example dimensions
    int n = 5;
    DATA_TYPE float_n;
    DATA_TYPE** dat = nullptr;

    init_array(m, n, float_n, dat);

    // Example to print the array
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            std::cout << dat[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Clean up the dynamically allocated memory
    for(int i = 0; i < n; ++i) {
        delete[] dat[i];
    }
    delete[] dat;

    return 0;
}
```

This C++ code does the following:
1. Defines a `DATA_TYPE` as `double`, which is equivalent to `1.2D0` in Fortran.
2. Implements the `init_array` function, which dynamically allocates a 2D array of `DATA_TYPE` and initializes it based on the given dimensions `m` and `n`.
3. Demonstrates how to use the `init_array` function in the `main` function, including printing the array to verify the initialization.
4. Cleans up the dynamically allocated memory to avoid memory leaks.

Note: The original Fortran code uses `DBLE` to convert integers to double precision, which is redundant in C++ as `static_cast<DATA_TYPE>()` is used for type conversion. Also, the division by `m` in the loop is done explicitly to ensure floating-point division is used, matching the original Fortran code's intent.
Let's write some test to verify if the translation is correct. 
Below are examples of how you could write unit tests for both the Fortran and C++ versions of the code. These tests will verify that the array initialization functions as expected.

### Fortran Unit Test

For the Fortran version, we'll write a simple program that calls the `init_array` subroutine and checks the results. Fortran doesn't have a built-in unit testing framework like some other languages, so we'll do a basic manual check.

```fortran
program test_init_array
    implicit none
    integer, parameter :: m = 5, n = 5
    real(8), allocatable :: dat(:,:)
    real(8) :: float_n
    integer :: i, j
    logical :: test_passed

    allocate(dat(n, m))

    call init_array(m, n, float_n, dat)

    test_passed = .true.
    do i = 1, m
        do j = 1, n
            if (dat(j, i) /= ((i - 1) * (j - 1)) / m) then
                test_passed = .false.
                exit
            endif
        enddo
        if (.not. test_passed) exit
    enddo

    if (test_passed) then
        print *, "Test passed."
    else
        print *, "Test failed."
    endif

    deallocate(dat)
end program test_init_array
```

This program tests the `init_array` subroutine by checking if the array `dat` is correctly initialized according to the specified logic.

### C++ Unit Test

For C++, we can use a testing framework like Google Test for more comprehensive testing. Below is an example of how you might write a test for the `init_array` function using Google Test.

First, ensure you have Google Test installed and set up in your project. Then, create a test file:

```cpp
#include <gtest/gtest.h>
#include "init_array.h" // Assume the function is declared in this header

TEST(InitArrayTest, CorrectInitialization) {
    int m = 5;
    int n = 5;
    DATA_TYPE float_n;
    DATA_TYPE** dat = nullptr;

    init_array(m, n, float_n, dat);

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            EXPECT_DOUBLE_EQ(((i - 1) * (j - 1)) / static_cast<DATA_TYPE>(m), dat[j][i]);
        }
    }

    // Clean up the dynamically allocated memory
    for(int i = 0; i < n; ++i) {
        delete[] dat[i];
    }
    delete[] dat;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

This test checks that the array `dat` is correctly initialized according to the specified logic. It uses `EXPECT_DOUBLE_EQ` to compare each element of the array with the expected value, which is `((i - 1) * (j - 1)) / m`.

To compile and run the C++ test, you would typically use a command similar to this, assuming you have Google Test properly set up:

```sh
g++ -std=c++11 -isystem ${GTEST_DIR}/include -pthread test_init_array.cpp init_array.cpp ${GTEST_DIR}/src/gtest_main.cc libgtest.a -o test_init_array
./test_init_array
```

Replace `${GTEST_DIR}` with the path to your Google Test installation.

These tests should help ensure that both the Fortran and C++ implementations of the array initialization logic are correct.
