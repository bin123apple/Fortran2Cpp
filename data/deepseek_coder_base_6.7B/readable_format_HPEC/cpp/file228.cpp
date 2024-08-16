To translate the given Fortran code to C++, we need to understand the structure and functionality of the original code. The Fortran code defines a subroutine named `print_array` that prints a 2D array `path` of size `maxgrid x maxgrid`. The `DATA_TYPE` and `DATA_PRINTF_MODIFIER` are placeholders for the data type and format specifier used for printing the array elements. In Fortran, `write` statements are used for output, and the `if` statement checks if the current element index is a multiple of 20, which is used for formatting the output.

Here's how you can translate the given Fortran code to C++:

```cpp
#include <iostream>
#include <iomanip> // For std::setw

// Assuming DATA_TYPE is a data type like int, float, double, etc.
// Replace DATA_TYPE with the actual data type you're using.
using DATA_TYPE = int;

void print_array(int maxgrid, DATA_TYPE** path) {
    for (int i = 0; i < maxgrid; ++i) {
        for (int j = 0; j < maxgrid; ++j) {
            // Assuming DATA_PRINTF_MODIFIER is a format specifier like "%d"
            // Replace DATA_PRINTF_MODIFIER with the actual format specifier you're using.
            std::cout << std::setw(DATA_PRINTF_MODIFIER) << path[j][i];
        }
        std::cout << std::endl;
        if ((i * maxgrid + j) % 20 == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    const int maxgrid = 10;
    DATA_TYPE** path = new DATA_TYPE*[maxgrid];
    for (int i = 0; i < maxgrid; ++i) {
        path[i] = new DATA_TYPE[maxgrid];
        for (int j = 0; j < maxgrid; ++j) {
            // Initialize the array with some values
            path[i][j] = (i * maxgrid) + j;
        }
    }

    print_array(maxgrid, path);

    // Clean up
    for (int i = 0; i < maxgrid; ++i) {
        delete[] path[i];
    }
    delete[] path;

    return 0;
}
```

Key points in the translation:

1. **Array Declaration and Initialization**: In C++, dynamic 2D arrays are typically handled using pointers to pointers. The `new` operator is used to allocate memory for the 2D array.

2. **Printing the Array**: The nested `for` loops iterate over the array elements, similar to the Fortran code. The `std::setw` function from the `<iomanip>` header is used to set the width of the output, similar to the Fortran `write` statement with a format specifier.

3. **Formatting Output**: The `if` statement checks if the current element index is a multiple of 20, and if so, it prints a newline, effectively formatting the output similar to the Fortran code.

4. **Cleanup**: Memory allocated for the 2D array is cleaned up using `delete[]` to avoid memory leaks.

This translation assumes that `DATA_TYPE` and `DATA_PRINTF_MODIFIER` are placeholders for the actual data type and format specifier used in the Fortran code. You should replace these with the appropriate types and format specifiers in your C++ code.
Let's write some test to verify if the translation is correct. 
Creating unit tests for both the Fortran and C++ code involves checking that the output matches the expected results for a given input. For simplicity, I'll provide a basic framework for unit testing in both languages, focusing on the `print_array` function.

### Fortran Unit Test

For Fortran, we'll write a simple program that calls the `print_array` subroutine and checks its output manually. Fortran doesn't have a built-in unit testing framework like some other languages, so we'll do a basic manual check.

```fortran
program test_print_array
    implicit none
    integer, parameter :: maxgrid = 10
    integer :: i, j
    integer, dimension(maxgrid, maxgrid) :: path

    ! Initialize the array
    do i = 1, maxgrid
        do j = 1, maxgrid
            path(j, i) = (i - 1) * maxgrid + j
        end do
    end do

    ! Call the subroutine
    call print_array(maxgrid, path)

end program test_print_array
```

To test this, you would manually verify that the output matches the expected results. This is a very basic form of testing and might not cover all edge cases or the full range of inputs.

### C++ Unit Test

For C++, we can use a unit testing framework like Google Test. This example assumes you have Google Test set up in your environment.

```cpp
#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include <iomanip>

// Assuming DATA_TYPE is int for this example
using DATA_TYPE = int;

// Function to be tested
void print_array(int maxgrid, DATA_TYPE** path) {
    for (int i = 0; i < maxgrid; ++i) {
        for (int j = 0; j < maxgrid; ++j) {
            std::cout << std::setw(2) << path[j][i];
        }
        std::cout << std::endl;
        if ((i * maxgrid + j) % 20 == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

// Test fixture for print_array
class PrintArrayTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code, if needed
    }

    void TearDown() override {
        // Cleanup code, if needed
    }
};

TEST_F(PrintArrayTest, PrintsCorrectly) {
    const int maxgrid = 10;
    DATA_TYPE** path = new DATA_TYPE*[maxgrid];
    for (int i = 0; i < maxgrid; ++i) {
        path[i] = new DATA_TYPE[maxgrid];
        for (int j = 0; j < maxgrid; ++j) {
            path[i][j] = (i * maxgrid) + j;
        }
    }

    // Redirect std::cout to a stringstream
    std::stringstream buffer;
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    // Call the function
    print_array(maxgrid, path);

    // Restore original buffer before assertions (to see test results)
    std::cout.rdbuf(prevcoutbuf);

    // Define the expected output
    std::string expected = " 1 11 21 31 41 51 61 71 81 91
"
                           "10 20 30 40 50 60 70 80 90

"
                           " 2 12 22 32 42 52 62 72 82 92
"
                           "10 20 30 40 50 60 70 80 90

"
                           " 3 13 23 33 43 53 63 73 83 93
"
                           "10 20 30 40 50 60 70 80 90

"
                           " 4 14 24 34 44 54 64 74 84 94
"
                           "10 20 30 40 50 60 70 80 90

"
                           " 5 15 25 35 45
