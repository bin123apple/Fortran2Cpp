Certainly! Below is the translated Fortran code to C++. Note that in C++, arrays are zero-indexed, unlike Fortran which is one-indexed. Also, C++ does not have a direct equivalent of Fortran's `write` statement for standard output, so we use `std::cout` for output. Additionally, the translation assumes that `DATA_TYPE` is a valid C++ data type (e.g., `int`, `float`, `double`, etc.) and `DATA_PRINTF_MODIFIER` is a format specifier for `std::cout`.

```cpp
#include <iostream>
#include <vector>

// Assuming DATA_TYPE is a valid C++ data type
using DATA_TYPE = int; // Example: int, float, double

void print_array(int n, const std::vector<DATA_TYPE>& x1, const std::vector<DATA_TYPE>& x2) {
    // Assuming DATA_PRINTF_MODIFIER is a format specifier for std::cout
    const char* DATA_PRINTF_MODIFIER = "%d"; // Example: "%d", "%f", "%lf"

    for (int i = 0; i < n; ++i) {
        std::cout << DATA_PRINTF_MODIFIER << x1[i] << std::endl;
        std::cout << DATA_PRINTF_MODIFIER << x2[i] << std::endl;
        if (i % 20 == 19) { // Adjusted for zero-based indexing
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    int n = 100; // Size of arrays
    std::vector<DATA_TYPE> x1(n), x2(n);

    // Initialize x1 and x2 with some values (example initialization)
    for (int i = 0; i < n; ++i) {
        x1[i] = i; // Example initialization
        x2[i] = i * 2; // Example initialization
    }

    print_array(n, x1, x2);

    return 0;
}
```

This C++ code defines a function `print_array` that takes the size of the arrays (`n`), and two vectors (`x1` and `x2`) as arguments. It iterates through the arrays, printing each element of `x1` and `x2` on a new line, and inserting a blank line after every 20 elements (adjusted for zero-based indexing). The `main` function demonstrates how to use this `print_array` function with example data.
Let's write some test to verify if the translation is correct. 
Below are examples of how you could write unit tests for both the Fortran and C++ code to verify their correctness. These tests will check the functionality of the `print_array` subroutine/function by comparing their outputs against expected values.

### Fortran Unit Test

For the Fortran code, we'll create a simple test program that calls the `print_array` subroutine with predefined arrays and checks the output. Note that capturing the output to stdout in Fortran for comparison is not as straightforward as in C++, so this example will focus on demonstrating the subroutine's functionality rather than its output correctness.

```fortran
program test_print_array
    implicit none
    integer, parameter :: n = 5
    integer :: x1(n), x2(n)
    integer :: i

    ! Initialize test arrays
    do i = 1, n
        x1(i) = i
        x2(i) = i * 2
    end do

    ! Call the subroutine
    call print_array(n, x1, x2)

end program test_print_array
```

To compile and run this Fortran test, assuming your Fortran code is in a file named `print_array.f90` and your test code is in `test_print_array.f90`, you could use:

```sh
gfortran -o test_print_array print_array.f90 test_print_array.f90
./test_print_array
```

### C++ Unit Test

For the C++ code, we can use a simple test framework like Google Test or just write a basic test function. Here's a simple example without a framework:

```cpp
#include <iostream>
#include <vector>
#include <sstream> // For std::stringstream
#include <cassert> // For assert

// Include or copy the print_array function here

void test_print_array() {
    int n = 5;
    std::vector<DATA_TYPE> x1 = {1, 2, 3, 4, 5};
    std::vector<DATA_TYPE> x2 = {2, 4, 6, 8, 10};

    // Redirect std::cout to a stringstream
    std::stringstream buffer;
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    // Call the function
    print_array(n, x1, x2);

    // Restore original buffer before assertions (to see test results)
    std::cout.rdbuf(prevcoutbuf);

    // Example assertion (replace with actual checks)
    // This is a placeholder since we're not capturing the output for comparison
    assert(buffer.str().size() > 0); // Check if output is not empty

    std::cout << "Test passed." << std::endl;
}

int main() {
    test_print_array();
    return 0;
}
```

To compile and run this C++ test, assuming your C++ code is in a file named `print_array.cpp` and your test code is in `test_print_array.cpp`, you could use:

```sh
g++ -o test_print_array print_array.cpp test_print_array.cpp
./test_print_array
```

### Note

For both Fortran and C++, the "tests" above are quite basic. They mainly demonstrate the subroutine/function's ability to run without errors and to produce output. In a real-world scenario, especially for C++, you would likely use a testing framework that allows for more sophisticated output comparison and assertion handling. For Fortran, frameworks like `FRUIT` can be used for similar purposes. Additionally, for both languages, you would likely want to compare the output against expected values to ensure correctness, which would require a more sophisticated approach, possibly involving file I/O and comparing files.
