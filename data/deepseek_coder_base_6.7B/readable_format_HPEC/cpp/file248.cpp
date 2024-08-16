To translate the given Fortran code to C++, we need to consider several aspects, such as array indexing, I/O operations, and the loop structure. In Fortran, arrays are 1-based, while in C++, they are 0-based. Also, Fortran's `write` statement has a different syntax compared to C++'s `std::cout`. Here's how the Fortran code could be translated to C++:

```cpp
#include <iostream>
#include <iomanip>

// Assuming DATA_TYPE is a type that can be printed, e.g., int, double, etc.
// Replace DATA_TYPE with the actual data type you're using.
using DATA_TYPE = int;

void print_array(int n, DATA_TYPE** a) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // Adjusting for 0-based indexing in C++
            std::cout << std::setw(12) << a[j][i]; // Assuming DATA_TYPE is printable
            if (((i * n) + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
}

int main() {
    // Example usage
    const int n = 10; // Size of the array
    DATA_TYPE** a = new DATA_TYPE*[n];
    for (int i = 0; i < n; ++i) {
        a[i] = new DATA_TYPE[n];
        for (int j = 0; j < n; ++j) {
            // Initialize array elements here
            a[i][j] = (i * n) + j + 1; // Example initialization
        }
    }

    print_array(n, a);

    // Clean up
    for (int i = 0; i < n; ++i) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}
```

This C++ code defines a function `print_array` that takes the size of the array `n` and a pointer to a 2D array `a`. It then iterates over the array and prints each element, adjusting for C++'s 0-based indexing. The `std::setw(12)` is used to set the width of the next outputted item to 12 characters, mimicking the Fortran output formatting. The `if` statement checks if the current element is the 20th element of a row or column, and if so, it inserts a newline to match the Fortran behavior.

Note that in C++, dynamic memory allocation for multi-dimensional arrays is handled differently than in Fortran. The example uses `new` and `delete` to allocate and deallocate memory for the 2D array `a`.
Let's write some test to verify if the translation is correct. 
Creating unit tests for both the Fortran and C++ code involves checking that the output matches expected values for a predefined input. For simplicity, I'll provide a basic example of how you might write these tests, focusing on the output for a predefined input.

### Fortran Unit Test

For the Fortran code, we'll write a simple program that calls the `print_array` subroutine with a predefined array and checks the output manually. Fortran doesn't have a built-in unit testing framework like some other languages, so this will be a basic, manual test.

```fortran
program test_print_array
    implicit none
    integer, parameter :: n = 5
    integer :: a(n, n)
    integer :: i, j

    ! Initialize array
    do i = 1, n
        do j = 1, n
            a(j, i) = (i-1)*n + j
        end do
    end do

    ! Call the subroutine
    call print_array(n, a)

end program test_print_array
```

To test, you would compile and run this program, then manually verify the output against the expected values.

### C++ Unit Test

For C++, we can use a testing framework like Google Test for more automated testing. However, for simplicity, I'll provide a basic example that mirrors the Fortran test, focusing on manual verification.

```cpp
#include <iostream>
#include <iomanip>
#include <sstream> // For std::stringstream

using DATA_TYPE = int;

void print_array(int n, DATA_TYPE** a, std::ostringstream& out) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            out << std::setw(12) << a[j][i];
            if (((i * n) + j) % 20 == 0) {
                out << std::endl;
            }
        }
    }
}

int main() {
    const int n = 5;
    DATA_TYPE** a = new DATA_TYPE*[n];
    for (int i = 0; i < n; ++i) {
        a[i] = new DATA_TYPE[n];
        for (int j = 0; j < n; ++j) {
            a[i][j] = (i * n) + j + 1;
        }
    }

    std::ostringstream out;
    print_array(n, a, out);

    // Output the string stream to verify
    std::cout << out.str();

    // Clean up
    for (int i = 0; i < n; ++i) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}
```

This C++ program now includes a `std::ostringstream` object `out` that captures the output of the `print_array` function. You can then compare the `out.str()` with the expected output manually.

### Verifying Correctness

For both tests, you would:
1. Compile and run the program.
2. Manually verify that the output matches the expected values.

For the Fortran test, this might involve checking the output manually or using a script to compare the output against expected values. For the C++ test, you would manually compare the output against expected values or use a script to automate this process.

Remember, these tests are quite basic and primarily serve to illustrate how you might begin to test the functionality of the provided code snippets. In a real-world scenario, especially for more complex functions, you would likely use a testing framework and include a wider variety of test cases to thoroughly verify correctness.
