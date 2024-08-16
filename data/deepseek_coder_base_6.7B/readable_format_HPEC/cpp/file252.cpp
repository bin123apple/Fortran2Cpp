To translate the given Fortran code to C++, we need to consider several aspects, including the array indexing, I/O operations, and the loop structures. In Fortran, arrays are 1-based, while in C++, they are 0-based. Also, Fortran's `write` statement has a different syntax compared to C++'s `std::cout`. Here's how the Fortran code could be translated to C++:

```cpp
#include <iostream>
#include <iomanip> // For std::setprecision

// Assuming DATA_TYPE is a float or double, adjust accordingly
using DATA_TYPE = double;

void print_array(int ni, int nl, DATA_TYPE** g) {
    // Set precision for floating-point output
    std::cout << std::fixed << std::setprecision(6);

    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nl; ++j) {
            std::cout << g[j][i] << " ";
            if (((i * ni) + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    const int ni = 5; // Number of columns
    const int nl = 4; // Number of rows

    // Dynamically allocate the 2D array
    DATA_TYPE** g = new DATA_TYPE*[nl];
    for (int i = 0; i < nl; ++i) {
        g[i] = new DATA_TYPE[ni];
    }

    // Initialize the array with some values (example initialization)
    for (int i = 0; i < nl; ++i) {
        for (int j = 0; j < ni; ++j) {
            g[i][j] = static_cast<DATA_TYPE>(i * ni + j);
        }
    }

    print_array(ni, nl, g);

    // Clean up the dynamically allocated memory
    for (int i = 0; i < nl; ++i) {
        delete[] g[i];
    }
    delete[] g;

    return 0;
}
```

This C++ code attempts to closely mirror the functionality of the original Fortran code. Note the following:

1. **Array Indexing**: Adjusted to 0-based indexing as per C++ conventions.
2. **I/O Operations**: Used `std::cout` for output, and `std::fixed` and `std::setprecision` for formatting the floating-point output.
3. **Dynamic Memory Allocation**: Used dynamic allocation for the 2D array to mimic the Fortran array behavior.
4. **Loop Structures**: Translated the Fortran `do` loops to C++ `for` loops.

Make sure to adjust the `DATA_TYPE` and other parts of the code according to your specific requirements and data types.
Let's write some test to verify if the translation is correct. 
To verify the correctness of both the original Fortran code and the translated C++ code, we can create simple unit tests. These tests will involve initializing the arrays with specific values and then printing them to ensure the output matches expectations.

### Fortran Unit Test

For the Fortran code, we'll write a simple program that calls the `print_array` subroutine and checks the output.

```fortran
program test_print_array
    implicit none
    integer, parameter :: ni = 5, nl = 4
    real, dimension(nl, ni) :: g
    integer :: i, j

    ! Initialize the array
    do i = 1, nl
        do j = 1, ni
            g(i, j) = real(i * ni + j)
        end do
    end do

    ! Call the subroutine
    call print_array(ni, nl, g)

end program test_print_array

subroutine print_array(ni, nl, g)
    implicit none
    integer, intent(in) :: ni, nl
    real, dimension(nl, ni), intent(in) :: g
    integer :: i, j

    do i = 1, ni
        do j = 1, nl
            write(*, '(F6.2)') g(j, i)
            if (mod(((i - 1) * ni) + j - 1, 20) == 0) then
                write(*, *)
            end if
        end do
    end do
    write(*, *)
end subroutine print_array
```

### C++ Unit Test

For the C++ code, we'll write a simple main function that initializes the array, calls the `print_array` function, and checks the output.

```cpp
#include <iostream>
#include <iomanip>

using DATA_TYPE = double;

void print_array(int ni, int nl, DATA_TYPE** g) {
    std::cout << std::fixed << std::setprecision(6);

    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nl; ++j) {
            std::cout << g[j][i] << " ";
            if (((i * ni) + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

int main() {
    const int ni = 5;
    const int nl = 4;

    DATA_TYPE** g = new DATA_TYPE*[nl];
    for (int i = 0; i < nl; ++i) {
        g[i] = new DATA_TYPE[ni];
    }

    // Initialize the array
    for (int i = 0; i < nl; ++i) {
        for (int j = 0; j < ni; ++j) {
            g[i][j] = static_cast<DATA_TYPE>(i * ni + j + 1); // +1 to match Fortran's 1-based indexing
        }
    }

    // Call the function
    print_array(ni, nl, g);

    // Clean up
    for (int i = 0; i < nl; ++i) {
        delete[] g[i];
    }
    delete[] g;

    return 0;
}
```

### Explanation

- **Fortran Test**:
  - The `test_print_array` program initializes a 2D array `g` with values `i * ni + j`.
  - It then calls the `print_array` subroutine and prints the array.
  - The output should match the expected values, considering Fortran's 1-based indexing.

- **C++ Test**:
  - The `main` function initializes a 2D array `g` with values `i * ni + j + 1` to match the Fortran initialization.
  - It then calls the `print_array` function and prints the array.
  - The output should match the expected values, considering C++'s 0-based indexing.

To run these tests, you'll need a Fortran compiler for the Fortran code (e.g., `gfortran`) and a C++ compiler for the C++ code (e.g., `g++`). Compile and run each program to verify that the outputs match.
