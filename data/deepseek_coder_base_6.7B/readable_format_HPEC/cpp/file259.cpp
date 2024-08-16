To translate the given Fortran code to C++, we need to consider several aspects, including the syntax differences between Fortran and C++, the handling of arrays, and the I/O operations. The Fortran code defines a subroutine that prints elements of a 3D array in a specific order. Here's how you can translate it to C++:

```cpp
#include <iostream>
#include <iomanip>

// Assuming DATA_TYPE is a float or double, adjust accordingly.
using DATA_TYPE = double;

void print_array(DATA_TYPE*** a, int nr, int nq, int np) {
    for (int i = 0; i < nr; ++i) {
        for (int j = 0; j < nq; ++j) {
            for (int k = 0; k < np; ++k) {
                // Assuming DATA_PRINTF_MODIFIER is a format string, adjust accordingly.
                std::cout << std::setprecision(10) << a[k][j][i] << " ";
            }
            if ((i + 1) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    const int nr = 2;
    const int nq = 3;
    const int np = 4;

    // Allocate and initialize the 3D array
    DATA_TYPE*** a = new DATA_TYPE**[np];
    for (int k = 0; k < np; ++k) {
        a[k] = new DATA_TYPE*[nq];
        for (int j = 0; j < nq; ++j) {
            a[k][j] = new DATA_TYPE[nr];
            for (int i = 0; i < nr; ++i) {
                // Example initialization
                a[k][j][i] = static_cast<DATA_TYPE>(i + j + k);
            }
        }
    }

    // Call the print_array function
    print_array(a, nr, nq, np);

    // Clean up the 3D array
    for (int k = 0; k < np; ++k) {
        for (int j = 0; j < nq; ++j) {
            delete[] a[k][j];
        }
        delete[] a[k];
    }
    delete[] a;

    return 0;
}
```

Key Points:
- The `DATA_TYPE` is assumed to be `double` in the C++ code. You can change it to `float` if needed.
- The `DATA_PRINTF_MODIFIER` format string is not provided in the original Fortran code, so it's assumed to be a simple format for floating-point numbers. In the C++ code, `std::setprecision(10)` is used to control the precision of the floating-point output.
- The Fortran arrays are 1-based, while C++ arrays are 0-based. This difference is accounted for in the loop indices.
- The Fortran `write` statements for output are replaced with `std::cout` in C++.
- Memory management for the 3D array is handled dynamically using pointers.
- The example usage demonstrates how to allocate, initialize, and print a 3D array.
Let's write some test to verify if the translation is correct. 
Below are examples of how you could write unit tests for both the original Fortran code and the translated C++ code. These tests will verify that the output of the array printing functions matches the expected results.

### Fortran Unit Test

For the Fortran code, you can write a simple program that calls the `print_array` subroutine and checks the output manually. Fortran doesn't have a built-in unit testing framework like some other languages, so the test will be somewhat manual.

```fortran
program test_print_array
    implicit none
    integer, parameter :: nr = 2, nq = 3, np = 4
    real, dimension(np, nq, nr) :: a
    integer :: i, j, k

    ! Initialize the array
    do k = 1, np
        do j = 1, nq
            do i = 1, nr
                a(k, j, i) = real(i + j + k)
            end do
        end do
    end do

    ! Call the subroutine
    call print_array(a, nr, nq, np)

end program test_print_array

subroutine print_array(a, nr, nq, np)
    implicit none
    real, dimension(np, nq, nr) :: a
    integer :: nr, nq, np
    integer :: i, j, k

    do i = 1, nr
        do j = 1, nq
            do k = 1, np
                write(*, '(F6.2)') a(k, j, i)
            end do
            if (mod((i - 1), 20) == 0) then
                write(*, *)
            end if
        end do
    end do
    write(*, *)
end subroutine print_array
```

### C++ Unit Test

For the C++ code, you can use a testing framework like Google Test for more automated testing. Below is an example of how you might write a test case using Google Test.

First, ensure you have Google Test installed and set up in your project. Then, create a test file:

```cpp
#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include <iomanip>

// Assuming the print_array function is defined in print_array.h
#include "print_array.h"

TEST(PrintArrayTest, CorrectOutput) {
    const int nr = 2;
    const int nq = 3;
    const int np = 4;

    // Allocate and initialize the 3D array
    DATA_TYPE*** a = new DATA_TYPE**[np];
    for (int k = 0; k < np; ++k) {
        a[k] = new DATA_TYPE*[nq];
        for (int j = 0; j < nq; ++j) {
            a[k][j] = new DATA_TYPE[nr];
            for (int i = 0; i < nr; ++i) {
                a[k][j][i] = static_cast<DATA_TYPE>(i + j + k + 1); // +1 to match Fortran initialization
            }
        }
    }

    // Redirect std::cout to a stringstream
    std::stringstream buffer;
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    // Call the print_array function
    print_array(a, nr, nq, np);

    // Restore original buffer before assertions (to see test results)
    std::cout.rdbuf(prevcoutbuf);

    // Expected output
    std::string expected = "1.0 2.0 3.0 4.0 5.0 6.0 7.0 8.0 9.0 10.0 11.0 12.0 
"
                           "13.0 14.0 15.0 16.0 17.0 18.0 19.0 20.0 21.0 22.0 23.0 24.0 

";

    // Check if the output matches the expected output
    EXPECT_EQ(buffer.str(), expected);

    // Clean up the 3D array
    for (int k = 0; k < np; ++k) {
        for (int j = 0; j < nq; ++j) {
            delete[] a[k][j];
        }
        delete[] a[k];
    }
    delete[] a;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

This test initializes a 3D array, redirects `std::cout` to a `stringstream`, calls the `print_array` function, and then compares the output to an expected string.

To
