Certainly! Below is the translated Fortran code to C++. Note that in C++, arrays are zero-indexed, unlike Fortran which is one-indexed. Also, C++ does not have a direct equivalent of Fortran's `write` statement for formatted output, but we can use `std::cout` with formatting.

```cpp
#include <iostream>
#include <iomanip>

// Assuming DATA_TYPE is a placeholder for the actual data type, e.g., float, double, int, etc.
// Replace DATA_TYPE with the actual data type you're using.
using DATA_TYPE = float;

void print_array(int ni, int nj, DATA_TYPE** c) {
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            // Assuming DATA_PRINTF_MODIFIER is a placeholder for the format specifier, e.g., "%f" for floating-point numbers.
            // Replace DATA_PRINTF_MODIFIER with the actual format specifier you want to use.
            std::cout << std::setprecision(6) << std::fixed << c[j][i] << " ";
            if (((i * ni) + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    const int ni = 5;
    const int nj = 5;

    // Dynamically allocate 2D array
    DATA_TYPE** c = new DATA_TYPE*[nj];
    for (int i = 0; i < nj; ++i) {
        c[i] = new DATA_TYPE[ni];
    }

    // Initialize array with some values (example initialization)
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            c[j][i] = static_cast<DATA_TYPE>(i * j); // Example initialization
        }
    }

    print_array(ni, nj, c);

    // Clean up dynamically allocated memory
    for (int i = 0; i < nj; ++i) {
        delete[] c[i];
    }
    delete[] c;

    return 0;
}
```

This C++ code defines a function `print_array` that takes the dimensions of the array and a pointer to the array itself. It then iterates over the array and prints each element, formatted according to the specified precision and format specifier. The `std::setprecision` and `std::fixed` manipulators are used to control the precision of floating-point output. The `main` function demonstrates how to allocate, initialize, and use the `print_array` function. Remember to replace `DATA_TYPE` and `DATA_PRINTF_MODIFIER` with the actual data type and format specifier you're using.
Let's write some test to verify if the translation is correct. 
Below are examples of how you could write unit tests for both the Fortran and C++ versions of the code. These tests will verify that the output of the `print_array` function matches the expected results for a predefined input array.

### Fortran Unit Test

For Fortran, we'll use a simple program that calls the `print_array` subroutine with a predefined array and checks the output manually. Fortran doesn't have a built-in unit testing framework like some other languages, so this will be a basic implementation.

```fortran
program test_print_array
    implicit none
    integer, parameter :: ni = 5, nj = 5
    real, dimension(nj, ni) :: c
    integer :: i, j

    ! Initialize array with some values
    do i = 1, ni
        do j = 1, nj
            c(j, i) = real(i * j)
        end do
    end do

    ! Call the subroutine
    call print_array(ni, nj, c)

end program test_print_array

subroutine print_array(ni, nj, c)
    implicit none
    integer, intent(in) :: ni, nj
    real, dimension(nj, ni), intent(in) :: c
    integer :: i, j

    do i = 1, ni
        do j = 1, nj
            write(*, '(F6.2)') c(j, i)
            if (mod(((i - 1) * ni) + j - 1, 20) == 0) then
                write(*, *)
            end if
        end do
    end do
    write(*, *)
end subroutine print_array
```

### C++ Unit Test

For C++, we can use the Google Test framework for unit testing. This example assumes you have Google Test set up in your environment.

```cpp
#include <gtest/gtest.h>
#include <sstream>
#include <iomanip>

// Assuming the print_array function is defined in print_array.h
#include "print_array.h"

TEST(PrintArrayTest, CorrectOutput) {
    const int ni = 5;
    const int nj = 5;

    // Dynamically allocate 2D array
    DATA_TYPE** c = new DATA_TYPE*[nj];
    for (int i = 0; i < nj; ++i) {
        c[i] = new DATA_TYPE[ni];
    }

    // Initialize array with some values
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            c[j][i] = static_cast<DATA_TYPE>(i * j); // Example initialization
        }
    }

    // Redirect std::cout to a stringstream
    std::stringstream buffer;
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    // Call the function
    print_array(ni, nj, c);

    // Restore original buffer before assertions (to see test results)
    std::cout.rdbuf(prevcoutbuf);

    // Define the expected output
    std::string expected = "0.00 0.00 0.00 0.00 0.00 
"
                           "0.00 1.00 2.00 3.00 4.00 
"
                           "0.00 2.00 4.00 6.00 8.00 
"
                           "0.00 3.00 6.00 9.00 12.00 
"
                           "0.00 4.00 8.00 12.00 16.00 

";

    // Compare the output
    EXPECT_EQ(buffer.str(), expected);

    // Clean up dynamically allocated memory
    for (int i = 0; i < nj; ++i) {
        delete[] c[i];
    }
    delete[] c;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

To run the C++ unit test, you'll need to have Google Test installed and properly set up in your project. The test redirects `std::cout` to a `stringstream` to capture the output, then compares it to the expected output.

These tests are basic and assume that the output formatting is consistent between the Fortran and C++ implementations. Adjustments might be necessary depending on the exact output formatting requirements.
