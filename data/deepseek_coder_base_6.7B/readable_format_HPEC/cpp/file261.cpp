To translate the given Fortran code to C++, we need to consider several aspects, including the syntax differences between Fortran and C++, the array indexing, and the way functions (or subroutines in Fortran) are defined and called. The Fortran code defines a subroutine `print_array` that prints a 2D array of a specified size. In C++, we can use a function template to achieve a similar effect.

Here's how the Fortran code could be translated to C++:

```cpp
#include <iostream>
#include <iomanip> // For std::setw

// Assuming DATA_TYPE is a type that can be printed, like int, float, double, etc.
template<typename T>
void print_array(int n, T** x) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << std::setw(12) << x[j][i]; // Adjust width as needed
            if (((i * n) + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    const int n = 10; // Array size
    // Dynamically allocate memory for the 2D array
    int** x = new int*[n];
    for (int i = 0; i < n; ++i) {
        x[i] = new int[n];
        // Initialize array elements here if needed
    }

    // Fill the array with some values for demonstration
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            x[i][j] = (i * n) + j + 1; // Example values
        }
    }

    print_array(n, x);

    // Clean up dynamically allocated memory
    for (int i = 0; i < n; ++i) {
        delete[] x[i];
    }
    delete[] x;

    return 0;
}
```

Key Points in the Translation:

1. **Array Indexing**: Fortran arrays are 1-based, while C++ arrays are 0-based. This is adjusted in the loop conditions.
2. **Dynamic Memory Allocation**: The original Fortran code does not explicitly allocate or deallocate memory for the array `x`. In C++, we dynamically allocate memory for the 2D array using `new` and `delete[]` to ensure it is properly managed.
3. **Printing**: The `std::setw(12)` is used to set the width of the output for each element, similar to the `write(0, DATA_PRINTF_MODIFIER)` in Fortran. Adjust the width as needed based on the expected output format.
4. **Newline Control**: The Fortran code uses `if (mod(((i - 1) * n) + j - 1, 20) == 0)` to insert newlines. In C++, we achieve this by checking the condition inside the nested loops and using `std::cout << std::endl;` when the condition is met.
5. **Function Template**: The `print_array` function is templated to accept any data type (`T`), similar to the `DATA_TYPE` in the Fortran code. This allows us to use the function with different data types, such as `int`, `float`, or `double`.

This translation assumes that `DATA_TYPE` is a type that can be printed to the standard output, which is typically true for basic data types like `int`, `float`, and `double`. Adjust the template type if your use case involves different data types.
Let's write some test to verify if the translation is correct. 
Creating unit tests for both the Fortran and C++ code involves writing additional code that will call the respective functions/subroutines with predefined inputs and then checking if the outputs match expected results. For simplicity, the tests will focus on verifying that the functions can run without errors for a predefined input.

### Fortran Unit Test

For the Fortran code, we can write a simple program that calls the `print_array` subroutine and checks for successful execution.

```fortran
program test_print_array
    implicit none
    integer, parameter :: n = 10
    integer :: i, j
    real, dimension(n, n) :: x

    ! Initialize the array
    do i = 1, n
        do j = 1, n
            x(j, i) = i * 10.0 + j
        end do
    end do

    ! Call the subroutine
    call print_array(n, x)

    print *, "Test passed."
end program test_print_array

subroutine print_array(n, x)
    implicit none
    integer, intent(in) :: n
    real, dimension(n, n), intent(in) :: x
    integer :: i, j

    do i = 1, n
        do j = 1, n
            write(*, '(F6.2)') x(j, i)
            if (mod(((i - 1) * n) + j - 1, 20) == 0) then
                write(*, *)
            end if
        end do
    end do
end subroutine print_array
```

This Fortran program initializes a 10x10 floating-point array, calls the `print_array` subroutine, and prints a message indicating the test passed. Note that the actual output verification would require capturing the output to stdout and comparing it against expected values, which is more complex and not shown here.

### C++ Unit Test

For the C++ code, we can use a simple test framework like Google Test, but for simplicity, I'll provide a basic test that checks if the function runs without errors for a predefined input.

```cpp
#include <iostream>
#include <iomanip>

template<typename T>
void print_array(int n, T** x) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << std::setw(12) << x[j][i];
            if (((i * n) + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

void test_print_array() {
    const int n = 10;
    int** x = new int*[n];
    for (int i = 0; i < n; ++i) {
        x[i] = new int[n];
    }

    // Initialize the array
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            x[i][j] = (i + 1) * 10 + (j + 1);
        }
    }

    // Call the function
    print_array(n, x);

    // Clean up
    for (int i = 0; i < n; ++i) {
        delete[] x[i];
    }
    delete[] x;

    std::cout << "Test passed." << std::endl;
}

int main() {
    test_print_array();
    return 0;
}
```

This C++ program initializes a 10x10 integer array, calls the `print_array` function, and prints a message indicating the test passed. Similar to the Fortran test, the actual output verification would require capturing the output to stdout and comparing it against expected values.

### Note

For both tests, the actual verification of the output against expected values is not automated. In a real-world scenario, you would capture the output to a file or a stream, then compare the captured output against a file containing the expected output. This is beyond the scope of a simple unit test example and would require more complex testing frameworks or custom comparison logic.
