To translate the given Fortran code to C++, we need to understand the structure and functionality of the original code. The Fortran code defines a subroutine named `print_array` that takes an array `y` and its size `ny` as input, iterates over the array, prints each element of the array, and prints a newline every 20 iterations. The `implicit none` statement in Fortran specifies that all variables must be explicitly declared, which is a good practice in C++ as well. The `DATA_TYPE`, `DATA_PRINTF_MODIFIER`, and `*` in the Fortran code are placeholders for specific data types and format strings. In the C++ translation, we'll need to replace these with actual C++ types and format specifiers.

Here's a C++ version of the code, assuming `DATA_TYPE` is a type like `int` or `double`, and `DATA_PRINTF_MODIFIER` is a format string like `%d` for integers or `%f` for floating-point numbers. Note that C++ uses `std::cout` for output, and formatting is handled with stream manipulators like `std::endl` for newlines or `std::setw`, `std::setprecision`, etc., for more complex formatting.

```cpp
#include <iostream>
#include <iomanip> // For std::setw, std::setprecision, etc.

// Assuming DATA_TYPE is some type like int, double, etc.
// and DATA_PRINTF_MODIFIER is a format string like "%d" for integers.

void print_array(DATA_TYPE* y, int ny) {
    for (int i = 0; i < ny; ++i) {
        // Assuming DATA_PRINTF_MODIFIER is used for formatting y[i].
        std::cout << std::setw(DATA_PRINTF_MODIFIER) << y[i];
        if ((i + 1) % 20 == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    DATA_TYPE y[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int ny = sizeof(y) / sizeof(y[0]);
    print_array(y, ny);
    return 0;
}
```

This C++ code defines a function `print_array` that takes a pointer to an array of `DATA_TYPE` and its size as arguments. It iterates over the array, prints each element using the specified format, and inserts a newline every 20 elements. The `main` function demonstrates how to call `print_array` with an example array.

Please replace `DATA_TYPE` and `DATA_PRINTF_MODIFIER` with the actual data type and format specifier you're using in your Fortran code. Also, note that C++ uses 0-based indexing, so adjustments are made accordingly in the loop and array access.
Let's write some test to verify if the translation is correct. 
Creating unit tests for both the Fortran and C++ code involves writing some additional code that will call the `print_array` subroutine/function with predefined inputs and then checking the output against expected results. For simplicity, we'll focus on testing with a small array and manually verifying the output. For more comprehensive testing, especially with larger arrays, you might consider using a testing framework like Google Test for C++ or a similar framework for Fortran.

### Fortran Unit Test

For the Fortran code, we'll write a simple program that calls the `print_array` subroutine with a predefined array. Fortran doesn't have a built-in unit testing framework, so we'll manually check the output.

```fortran
program test_print_array
    implicit none
    integer, parameter :: ny = 5
    integer :: y(ny) = [1, 2, 3, 4, 5]

    call print_array(y, ny)
end program test_print_array

subroutine print_array(y, ny)
    implicit none
    integer, dimension(ny) :: y
    integer :: ny
    integer :: i
    do i = 1, ny
        write(*, '(I3)') y(i)
        if (mod(i - 1, 20) == 0) then
            write(*, *)
        end if
    end do
    write(*, *)
end subroutine print_array
```

Compile and run this Fortran program. You should manually verify that the output matches the expected sequence of numbers and newlines.

### C++ Unit Test

For the C++ code, we can use a simple testing approach similar to the Fortran example. For more comprehensive testing, consider using a testing framework like Google Test.

```cpp
#include <iostream>
#include <iomanip>

void print_array(int* y, int ny) {
    for (int i = 0; i < ny; ++i) {
        std::cout << std::setw(3) << y[i];
        if ((i + 1) % 20 == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

int main() {
    int y[] = {1, 2, 3, 4, 5};
    int ny = sizeof(y) / sizeof(y[0]);
    print_array(y, ny);
    return 0;
}
```

Compile and run this C++ program. Again, manually verify the output against the expected sequence of numbers and newlines.

### Verifying Correctness

For both tests, you should manually verify that the output matches the expected sequence of numbers and newlines. For the Fortran code, this might involve checking the program's output in a terminal or command prompt. For the C++ code, you can use a similar approach or redirect the output to a file and then compare the file's contents with an expected output file.

### Note

For more comprehensive testing, especially with larger arrays, consider using a testing framework and automated ways to check the output against expected results. This might involve redirecting the output to a string or file, then comparing the string or file contents against expected values programmatically.
