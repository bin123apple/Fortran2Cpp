To translate the given Fortran code to C++, we need to understand the structure and functionality of the original code. The Fortran code defines a subroutine named `print_array` that takes three arguments: `ni`, `nj`, and `c`. It then declares a 2D array `c` of dimensions `nj` by `ni`, and iterates through the array printing each element. If the current element is the 20th element in a row or column, it prints a newline.

Here's how you can translate the given Fortran code to C++:

```cpp
#include <iostream>
#include <iomanip>

// Assuming DATA_TYPE is a placeholder for the actual data type,
// we'll use double for this example. You should replace it with the actual data type.
using DATA_TYPE = double;

void print_array(int ni, int nj, DATA_TYPE** c) {
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            // Assuming DATA_PRINTF_MODIFIER is a formatting string,
            // we'll use a simple output format for demonstration.
            std::cout << std::setw(12) << c[j][i] << " ";
            if (((i * ni) + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    const int ni = 5; // Number of rows
    const int nj = 5; // Number of columns

    // Dynamically allocate the 2D array
    DATA_TYPE** c = new DATA_TYPE*[nj];
    for (int i = 0; i < nj; ++i) {
        c[i] = new DATA_TYPE[ni];
    }

    // Initialize the array with some values
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            c[j][i] = static_cast<DATA_TYPE>((i * ni) + j); // Example initialization
        }
    }

    // Call the print_array function
    print_array(ni, nj, c);

    // Clean up the dynamically allocated memory
    for (int i = 0; i < nj; ++i) {
        delete[] c[i];
    }
    delete[] c;

    return 0;
}
```

This C++ code does the following:
1. Defines a function `print_array` that takes the dimensions of the array (`ni` and `nj`) and a pointer to a pointer (`c`) to a 2D array.
2. Iterates through the array, printing each element. It uses `std::setw(12)` to format the output similar to the Fortran code's `write(0, DATA_PRINTF_MODIFIER)`.
3. Checks if the current element is the 20th element in a row or column, and prints a newline if true.
4. In the `main` function, it demonstrates how to dynamically allocate a 2D array, initialize it, and then call the `print_array` function.
5. Finally, it cleans up the dynamically allocated memory.

Please note that this translation assumes `DATA_TYPE` is a placeholder for the actual data type used in the Fortran code. You should replace `double` with the actual data type used in your Fortran code. Also, `DATA_PRINTF_MODIFIER` is a placeholder for the format string used in the Fortran `write` statement. You should replace it with the actual format string or formatting code in C++.
Let's write some test to verify if the translation is correct. 
Creating unit tests for both the Fortran and C++ code involves checking the functionality of the `print_array` subroutine/function under various conditions. Below are examples of how you might write these tests.

### Fortran Unit Test

For the Fortran code, we'll write a simple program that calls the `print_array` subroutine with predefined inputs. Fortran doesn't have a built-in unit testing framework, so we'll do this in a straightforward procedural manner.

```fortran
program test_print_array
    implicit none
    integer, parameter :: ni = 5, nj = 5
    real, dimension(nj, ni) :: c
    integer :: i, j

    ! Initialize the array
    do i = 1, ni
        do j = 1, nj
            c(j, i) = real(i * ni + j)
        end do
    end do

    ! Call the subroutine
    call print_array(ni, nj, c)

end program test_print_array
```

To compile and run this Fortran test, you would use a Fortran compiler like `gfortran`:

```sh
gfortran -o test_print_array test_print_array.f90
./test_print_array
```

### C++ Unit Test

For the C++ code, we can use a simple testing approach similar to the Fortran example or use a unit testing framework like Google Test. Here, I'll show a simple example without a framework for consistency with the Fortran example.

```cpp
#include <iostream>
#include <iomanip>
#include <cassert>

// Assuming DATA_TYPE is a placeholder for the actual data type,
// we'll use double for this example. You should replace it with the actual data type.
using DATA_TYPE = double;

void print_array(int ni, int nj, DATA_TYPE** c) {
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            std::cout << std::setw(12) << c[j][i] << " ";
            if (((i * ni) + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

void test_print_array() {
    const int ni = 5; // Number of rows
    const int nj = 5; // Number of columns

    // Dynamically allocate the 2D array
    DATA_TYPE** c = new DATA_TYPE*[nj];
    for (int i = 0; i < nj; ++i) {
        c[i] = new DATA_TYPE[ni];
    }

    // Initialize the array with some values
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            c[j][i] = static_cast<DATA_TYPE>((i * ni) + j); // Example initialization
        }
    }

    // Call the print_array function
    print_array(ni, nj, c);

    // Clean up the dynamically allocated memory
    for (int i = 0; i < nj; ++i) {
        delete[] c[i];
    }
    delete[] c;
}

int main() {
    test_print_array();
    std::cout << "Test passed." << std::endl;
    return 0;
}
```

To compile and run this C++ test, you would use a C++ compiler like `g++`:

```sh
g++ -o test_print_array test_print_array.cpp
./test_print_array
```

These tests are quite basic and primarily serve to demonstrate the functionality of the `print_array` subroutine/function. For more comprehensive testing, especially in C++, consider using a unit testing framework like Google Test, which provides a rich set of assertions and testing utilities.
