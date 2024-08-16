Certainly! Below is the translated Fortran code to C++. Note that in C++, arrays are zero-indexed, unlike Fortran which is one-indexed. Also, the `write` statement in Fortran is equivalent to `std::cout` in C++ for output.

```cpp
#include <iostream>
#include <iomanip> // For std::setw

// Assuming DATA_TYPE is a placeholder for the actual data type, we'll use 'double' as an example.
// You should replace 'double' with the actual data type you're using.

void print_array(int n, double** a) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << std::setw(12) << a[j][i] << " "; // Adjust the width as per your requirement
            if ((i * n + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    const int n = 10; // Size of the array
    double** a = new double*[n];
    for(int i = 0; i < n; ++i) {
        a[i] = new double[n];
        for(int j = 0; j < n; ++j) {
            // Initialize the array with some values
            a[i][j] = i * n + j; // Example initialization
        }
    }

    print_array(n, a);

    // Clean up
    for(int i = 0; i < n; ++i) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}
```

This C++ code defines a function `print_array` that takes the size of the square array `n` and a pointer to a pointer `a` to a 2D array. It then iterates over the array and prints each element, adjusting the width of the output using `std::setw`. It also inserts a newline after every 20th element to mimic the Fortran behavior.

Remember to replace `double` with the actual data type you're using (e.g., `int`, `float`, etc.) and adjust the initialization and other parts of the code as necessary.
Let's write some test to verify if the translation is correct. 
Below are examples of unit tests for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the array printing functionality.

### Fortran Unit Test

For the Fortran code, we'll create a simple program that calls the `print_array` subroutine with a predefined array.

```fortran
program test_print_array
    implicit none
    integer, parameter :: n = 10
    real, dimension(n, n) :: a
    integer :: i, j

    ! Initialize the array
    do i = 1, n
        do j = 1, n
            a(i, j) = i * n + j
        end do
    end do

    ! Call the subroutine
    call print_array(n, a)

end program test_print_array

subroutine print_array(n, a)
    implicit none
    integer, parameter :: DATA_PRINTF_MODIFIER = '(F6.2)'
    integer :: n, i, j
    real, dimension(n, n) :: a

    do i = 1, n
        do j = 1, n
            write(*, DATA_PRINTF_MODIFIER) a(j, i)
            if (mod((i - 1) * n + j - 1, 20) == 0) then
                write(*, *)
            end if
        end do
    end do
    write(*, *)
end subroutine print_array
```

### C++ Unit Test

For the C++ code, we'll create a simple test function that initializes a 2D array and calls the `print_array` function.

```cpp
#include <iostream>
#include <iomanip>

void print_array(int n, double** a) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << std::setw(12) << a[j][i] << " ";
            if ((i * n + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

void test_print_array() {
    const int n = 10;
    double** a = new double*[n];
    for(int i = 0; i < n; ++i) {
        a[i] = new double[n];
        for(int j = 0; j < n; ++j) {
            a[i][j] = i * n + j; // Example initialization
        }
    }

    print_array(n, a);

    // Clean up
    for(int i = 0; i < n; ++i) {
        delete[] a[i];
    }
    delete[] a;
}

int main() {
    test_print_array();
    return 0;
}
```

### Explanation

- **Fortran Test Program**:
  - The `test_print_array` program initializes a 2D array `a` with values `i * n + j`.
  - It then calls the `print_array` subroutine to print the array.
  - The `print_array` subroutine prints the array elements with a format specifier `'(F6.2)'` to format the floating-point numbers.

- **C++ Test Function**:
  - The `test_print_array` function initializes a 2D array `a` with values `i * n + j`.
  - It then calls the `print_array` function to print the array.
  - The `print_array` function uses `std::setw(12)` to set the width of each output field to 12 characters, mimicking the Fortran output format.

These tests should help verify that the array printing functionality works as expected in both the Fortran and C++ implementations.
