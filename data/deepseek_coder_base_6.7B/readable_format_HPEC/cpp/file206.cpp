To translate the given Fortran code to C++, we need to consider several aspects, including the syntax differences between Fortran and C++, the array indexing, and the way arrays are passed to functions. The Fortran code defines a subroutine that prints a 2D array in a specific format, with a newline after every 20 elements.

Here's how you can translate the given Fortran code to C++:

```cpp
#include <iostream>
#include <iomanip> // For std::setw

// Assuming DATA_TYPE is a fundamental type (e.g., int, float, double)
// and DATA_PRINTF_MODIFIER is a format specifier for that type (e.g., "%d", "%f", "%e")

template<typename T>
void print_array(int n, T** a) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // Printing elements with a specific format
            std::cout << std::setw(12) << a[j][i]; // Adjust width as needed
            if (((i * n) + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    const int n = 10; // Size of the array
    int** a = new int*[n];
    for (int i = 0; i < n; ++i) {
        a[i] = new int[n];
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

### Key Points:

1. **Array Initialization**: The example initializes the array `a` with values from 1 to `n^2`. You can replace this with your actual initialization logic.

2. **Array Representation**: In C++, arrays are typically represented as pointers to pointers. The example dynamically allocates memory for the 2D array `a`.

3. **Printing Elements**: The `std::setw(12)` is used to set the width of the next outputted item to 12 characters, which is similar to the `write(0, DATA_PRINTF_MODIFIER)` in Fortran. Adjust the width as needed.

4. **Newline Logic**: The `if` statement inside the nested loops checks if the current element is the 20th element of a row or a column, and inserts a newline accordingly.

5. **Cleanup**: The example includes cleanup code to free the dynamically allocated memory.

This C++ code should provide similar functionality to the provided Fortran subroutine. Adjust the types and formatting as necessary for your specific use case.
Let's write some test to verify if the translation is correct. 
Below are examples of how you could write unit tests for both the Fortran and C++ versions of the code to verify their correctness. These tests will check the functionality of printing the array elements in a specific format and ensuring the newline logic works as expected.

### Fortran Unit Test

For the Fortran code, we'll write a simple program that calls the `print_array` subroutine and checks the output manually since Fortran lacks a built-in unit testing framework similar to those available in C++.

```fortran
program test_print_array
    implicit none
    integer, parameter :: n = 10
    integer :: a(n, n)
    integer :: i, j

    ! Initialize array
    do i = 1, n
        do j = 1, n
            a(j, i) = (i - 1) * n + j
        end do
    end do

    ! Call the subroutine
    call print_array(n, a)

end program test_print_array
```

To test the output, you would manually verify that the output matches the expected format and newline behavior.

### C++ Unit Test

For C++, we can use a simple testing approach similar to the Fortran example, or we can use a unit testing framework like Google Test. Here, I'll show a simple manual test similar to the Fortran example for consistency.

```cpp
#include <iostream>
#include <iomanip>
#include <sstream> // For std::stringstream
#include <cassert> // For assert()

template<typename T>
void print_array(int n, T** a, std::stringstream& ss) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ss << std::setw(12) << a[j][i];
            if (((i * n) + j) % 20 == 0) {
                ss << std::endl;
            }
        }
    }
    ss << std::endl;
}

int main() {
    const int n = 10;
    int** a = new int*[n];
    for (int i = 0; i < n; ++i) {
        a[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            a[i][j] = (i * n) + j + 1;
        }
    }

    std::stringstream ss;
    print_array(n, a, ss);

    // Example assertion to check the output
    // This is a very basic check. In a real test, you would compare the output against expected values.
    assert(ss.str().length() > 0); // Ensure the stringstream is not empty

    // Clean up
    for (int i = 0; i < n; ++i) {
        delete[] a[i];
    }
    delete[] a;

    std::cout << "Test passed." << std::endl;

    return 0;
}
```

### Testing Notes

- **Fortran Test**: The Fortran test is quite manual and relies on visual inspection of the output.
- **C++ Test**: The C++ test uses a `std::stringstream` to capture the output, which is then compared against expected values. This is a basic form of testing. In a real-world scenario, you would compare the output against expected values and possibly use a unit testing framework for more comprehensive testing.

### Running the Tests

- **Fortran**: Compile and run the Fortran test program as you would with any Fortran code. The output will need to be manually verified.
- **C++**: Compile the C++ test code with a C++ compiler (e.g., `g++ -o test_print_array test_print_array.cpp`) and run the resulting executable. The assertion in the main function will ensure the program does not terminate abnormally.

These tests are quite basic and primarily ensure that the code runs without errors and produces output. For more comprehensive testing, especially in C++, consider using a dedicated unit testing framework like Google Test, which provides a rich set of assertions and testing utilities.
