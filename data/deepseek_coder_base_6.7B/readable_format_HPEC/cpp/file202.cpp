To translate the given Fortran code to C++, we need to consider several aspects, such as array indexing, I/O operations, and the loop constructs. In Fortran, arrays are 1-based, while in C++, they are 0-based. Also, Fortran's `write` statement has a different syntax compared to C++'s `std::cout`. Here's how the Fortran code could be translated to C++:

```cpp
#include <iostream>
#include <iomanip> // For std::setw

// Assuming DATA_TYPE is a type that can be printed, e.g., int, float, double
#define DATA_TYPE int

void print_array(int n, DATA_TYPE** b) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << std::setw(12) << b[j][i]; // Adjust width as needed
            if (((i * n) + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    const int n = 10; // Size of the square array
    DATA_TYPE** b = new DATA_TYPE*[n];
    for (int i = 0; i < n; ++i) {
        b[i] = new DATA_TYPE[n];
        for (int j = 0; j < n; ++j) {
            // Initialize array with some values for demonstration
            b[i][j] = (i * n) + j + 1;
        }
    }

    print_array(n, b);

    // Clean up
    for (int i = 0; i < n; ++i) {
        delete[] b[i];
    }
    delete[] b;

    return 0;
}
```

Key points in the translation:
- The `print_array` function in C++ takes a 2D array `b` of size `n x n` and prints its elements.
- The nested loops in C++ iterate over the array, similar to the Fortran code.
- The `std::setw(12)` is used to set the width of the next outputted item to 12 characters, adjust this as needed for your specific output format.
- The `if` statement checks if the current element is the 20th element in a row/column, and if so, it inserts a newline.
- Memory management is handled using dynamic allocation for the 2D array `b`.
- The example usage demonstrates how to initialize and print a 10x10 array.

Please note that this translation assumes `DATA_TYPE` is a type that can be printed to the standard output, which is typically the case for numeric types like `int`, `float`, and `double`. If `DATA_TYPE` is a custom type, you might need to overload the `<<` operator for output to work correctly.
Let's write some test to verify if the translation is correct. 
Creating unit tests for both the Fortran and C++ code involves checking that the output of the `print_array` function matches the expected results for a given input. For simplicity, I'll provide a basic framework for unit testing in both languages, focusing on the functionality of printing the array.

### Fortran Unit Test

For Fortran, we'll use a simple approach to test the subroutine by comparing its output against an expected result. This example assumes the use of a file to capture the output for comparison.

```fortran
program test_print_array
    implicit none
    integer, parameter :: n = 4
    integer :: i, j
    integer, dimension(n, n) :: b
    character(len=100) :: line
    character(len=100), dimension(n*n) :: expected_lines

    ! Initialize array
    do i = 1, n
        do j = 1, n
            b(j, i) = (i-1)*n + j
        end do
    end do

    ! Expected output
    expected_lines = [ &
        '           1           5           9          13', &
        '           2           6          10          14', &
        '           3           7          11          15', &
        '           4           8          12          16' &
    ]

    ! Redirect output to a file
    open(unit=10, file='output.txt', status='replace')
    call print_array(n, b)
    close(10)

    ! Read output and compare
    open(unit=10, file='output.txt', status='old')
    do i = 1, n*n
        read(10, '(A)') line
        if (trim(adjustl(line)) /= trim(adjustl(expected_lines(i)))) then
            print *, 'Test failed at line', i
            stop
        end if
    end do
    close(10)

    print *, 'All tests passed.'
end program test_print_array
```

### C++ Unit Test

For C++, we can use a similar approach, comparing the output against expected values. This example uses a simple string comparison for simplicity.

```cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

// Assuming the print_array function is defined as shown in the previous C++ translation

void test_print_array() {
    const int n = 4;
    DATA_TYPE** b = new DATA_TYPE*[n];
    for (int i = 0; i < n; ++i) {
        b[i] = new DATA_TYPE[n];
        for (int j = 0; j < n; ++j) {
            b[i][j] = (i * n) + j + 1;
        }
    }

    // Redirect output to a stringstream
    std::stringstream buffer;
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    print_array(n, b);

    // Restore original buffer before comparison
    std::cout.rdbuf(prevcoutbuf);

    // Expected output
    std::vector<std::string> expected_lines = {
        "           1           5           9          13",
        "           2           6          10          14",
        "           3           7          11          15",
        "           4           8          12          16"
    };

    // Read output and compare
    std::string line;
    std::getline(buffer, line); // Skip the first empty line
    for (int i = 0; i < n*n; ++i) {
        std::getline(buffer, line);
        if (line != expected_lines[i]) {
            std::cerr << "Test failed at line " << i << std::endl;
            exit(1);
        }
    }

    std::cout << "All tests passed." << std::endl;
}

int main() {
    test_print_array();
    return 0;
}
```

These tests are basic and assume that the output of the `print_array` function can be captured and compared against an expected result. For more comprehensive testing, especially in real-world applications, you might consider using a testing framework like Google Test for C++ or a similar framework for Fortran, which provides more features and better output formatting for debugging.
