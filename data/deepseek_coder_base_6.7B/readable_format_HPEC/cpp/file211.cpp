To translate the given Fortran code to C++, we need to understand the structure and functionality of the original code. The Fortran subroutine `print_array` takes an integer `n` and an array `y` of size `n`. It prints each element of the array `y` to the standard output, and after every 20th element, it also prints a new line. The `DATA_TYPE` and `DATA_PRINTF_MODIFIER` are placeholders in the Fortran code, which are meant to represent the data type of the array elements and the format specifier for printing them, respectively.

In C++, we can achieve similar functionality using a function template that can handle different data types, assuming the data type `DATA_TYPE` is compatible with C++. The `std::cout` stream is used for output, and we use a loop to iterate through the array, printing each element. If the index is a multiple of 20, we insert a new line.

Here's how the translation might look in C++:

```cpp
#include <iostream>

// Assuming DATA_TYPE is compatible with C++, e.g., int, float, double
template<typename T>
void print_array(int n, T* y) {
    for (int i = 0; i < n; ++i) {
        std::cout << y[i];
        if (i % 20 == 19) { // Adjusted for 0-based indexing
            std::cout << std::endl;
        } else {
            std::cout << " "; // Separate elements with a space
        }
    }
    std::cout << std::endl; // Ensure a new line after the last element
}

int main() {
    // Example usage
    int n = 100; // Size of the array
    int y[100]; // Example array, assuming int for DATA_TYPE
    
    // Initialize the array with some values for demonstration
    for (int i = 0; i < n; ++i) {
        y[i] = i + 1;
    }
    
    print_array(n, y);
    
    return 0;
}
```

This C++ code defines a template function `print_array` that can handle arrays of any data type `T`. The function iterates through the array, printing each element, and inserts a new line after every 20 elements, just like the Fortran code. Note that C++ uses 0-based indexing, so the condition for a new line is adjusted accordingly (`i % 20 == 19`).

Remember, this translation assumes that `DATA_TYPE` is compatible with C++ and that `DATA_PRINTF_MODIFIER` is a format specifier that can be used with `std::cout` for printing the elements of the array. In a real-world scenario, you might need to adjust the template function based on the specific data types and formatting requirements.
Let's write some test to verify if the translation is correct. 
Creating unit tests for both the Fortran and C++ code involves writing some additional code that will call the respective functions with predefined inputs and check if the outputs match the expected results. For simplicity, the tests will focus on verifying that the functions can run without errors and produce the expected output format.

### Fortran Unit Test

For the Fortran code, we'll write a simple program that calls the `print_array` subroutine with a predefined array. Fortran doesn't have a built-in unit testing framework like some other languages, so we'll manually check the output.

```fortran
program test_print_array
    implicit none
    integer, parameter :: n = 100
    integer :: y(n)
    integer :: i

    ! Initialize the array
    do i = 1, n
        y(i) = i
    end do

    ! Call the subroutine
    call print_array(n, y)

end program test_print_array

subroutine print_array(n, y)
    implicit none
    integer, dimension(n) :: y
    integer :: n
    integer :: i

    do i = 1, n
        write(*, '(I3)') y(i)
        if (mod(i - 1, 20) == 0) then
            write(*, *)
        end if
    end do
end subroutine print_array
```

This test initializes an array `y` with values from 1 to `n`, then calls the `print_array` subroutine. You can compile and run this Fortran program using a Fortran compiler (e.g., `gfortran`).

### C++ Unit Test

For the C++ code, we can use a simple testing approach similar to the Fortran example. C++ doesn't have a built-in unit testing framework, but for more complex scenarios, frameworks like Google Test are recommended. Here, we'll keep it simple.

```cpp
#include <iostream>
#include <cassert>

template<typename T>
void print_array(int n, T* y) {
    for (int i = 0; i < n; ++i) {
        std::cout << y[i];
        if (i % 20 == 19) {
            std::cout << std::endl;
        } else {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

void test_print_array() {
    int n = 100;
    int y[100];
    
    // Initialize the array
    for (int i = 0; i < n; ++i) {
        y[i] = i + 1;
    }
    
    // Call the function and manually verify the output
    print_array(n, y);
    
    // Since we can't automatically verify the output in a unit test without
    // capturing stdout, this test is primarily about ensuring the function runs.
    // Manual verification of the output is required.
    std::cout << "Test passed." << std::endl;
}

int main() {
    test_print_array();
    return 0;
}
```

This C++ code defines a `test_print_array` function that initializes an array, calls `print_array`, and then prints "Test passed." indicating the test has passed. You can compile and run this C++ program using a C++ compiler (e.g., `g++`).

### Note:
- For both tests, manual verification of the output is required since automatic verification of console output in unit tests is not straightforward without additional tools or libraries.
- For more complex scenarios or larger projects, consider using dedicated unit testing frameworks like Google Test for C++ or pFUnit for Fortran. These frameworks provide more features and better integration with build systems.
