To translate the given Fortran code to C++, we need to understand the structure and functionality of the original code and then implement similar logic in C++. The Fortran code defines a subroutine that prints the elements of three 2D arrays (`a`, `r`, and `q`) with dimensions `ni` and `nj`. It prints elements in a specific format and includes conditional checks to insert new lines after every 20 elements.

Here's how you can translate the Fortran code to C++:

```cpp
#include <iostream>
#include <iomanip>

// Assuming DATA_TYPE is a floating-point type (e.g., float, double)
using DATA_TYPE = double;

void print_array(int ni, int nj, DATA_TYPE** a, DATA_TYPE** r, DATA_TYPE** q) {
    // Set precision for floating-point output
    std::cout << std::fixed << std::setprecision(2);

    // Print array a
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            std::cout << a[j][i] << " ";
            if ((i + 1) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;

    // Print array r
    for (int i = 0; i < nj; ++i) {
        for (int j = 0; j < nj; ++j) {
            std::cout << r[j][i] << " ";
            if ((i + 1) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;

    // Print array q
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            std::cout << q[j][i] << " ";
            if ((i + 1) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    const int ni = 10; // Number of rows in a, q
    const int nj = 10; // Number of columns in a, r, q

    // Dynamically allocate 2D arrays
    DATA_TYPE** a = new DATA_TYPE*[nj];
    DATA_TYPE** r = new DATA_TYPE*[nj];
    DATA_TYPE** q = new DATA_TYPE*[nj];

    for (int i = 0; i < nj; ++i) {
        a[i] = new DATA_TYPE[ni];
        r[i] = new DATA_TYPE[nj];
        q[i] = new DATA_TYPE[ni];
    }

    // Initialize arrays with some values (example initialization)
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            a[j][i] = static_cast<DATA_TYPE>(i * j);
            r[j][i] = static_cast<DATA_TYPE>(i + j);
            q[j][i] = static_cast<DATA_TYPE>(i - j);
        }
    }

    print_array(ni, nj, a, r, q);

    // Clean up dynamically allocated memory
    for (int i = 0; i < nj; ++i) {
        delete[] a[i];
        delete[] r[i];
        delete[] q[i];
    }
    delete[] a;
    delete[] r;
    delete[] q;

    return 0;
}
```

This C++ code does the following:
1. Defines a function `print_array` that takes the dimensions `ni` and `nj`, and pointers to the 2D arrays `a`, `r`, and `q`.
2. Sets the precision for floating-point output to 2 decimal places.
3. Iterates through the arrays and prints the elements, inserting a new line after every 20 elements.
4. Demonstrates how to dynamically allocate 2D arrays and initialize them with example values.
5. Cleans up the dynamically allocated memory at the end of the program.

Please note that in C++, dynamic memory allocation (using `new`) and deallocation (using `delete`) is essential for managing arrays. The example provided is a simple illustration; in real applications, consider using containers like `std::vector` for automatic memory management.
Let's write some test to verify if the translation is correct. 
To verify the correctness of both the original Fortran code and the translated C++ code, we can create unit tests for each. These tests will involve initializing the arrays with specific values and then checking if the output matches the expected results.

### Fortran Unit Test

For the Fortran code, we'll write a simple program that calls the `print_array` subroutine and checks the output manually. Fortran doesn't have a built-in unit testing framework like some other languages, so we'll do a basic manual check.

```fortran
program test_print_array
    implicit none
    integer, parameter :: ni = 2, nj = 2
    real, dimension(nj, ni) :: a, q
    real, dimension(nj, nj) :: r
    integer :: i, j

    ! Initialize arrays
    do i = 1, ni
        do j = 1, nj
            a(j, i) = real(i * j)
            r(j, i) = real(i + j)
            q(j, i) = real(i - j)
        end do
    end do

    ! Call the subroutine
    call print_array(ni, nj, a, r, q)

end program test_print_array
```

Compile and run this Fortran program. You should manually verify that the output matches the expected values.

### C++ Unit Test

For the C++ code, we can use a simple testing approach similar to the Fortran example. However, for more complex scenarios or larger projects, consider using a unit testing framework like Google Test.

```cpp
#include <iostream>
#include <iomanip>
#include <cassert>

// Assuming DATA_TYPE is a floating-point type (e.g., float, double)
using DATA_TYPE = double;

void print_array(int ni, int nj, DATA_TYPE** a, DATA_TYPE** r, DATA_TYPE** q);

int main() {
    const int ni = 2; // Number of rows in a, q
    const int nj = 2; // Number of columns in a, r, q

    // Dynamically allocate 2D arrays
    DATA_TYPE** a = new DATA_TYPE*[nj];
    DATA_TYPE** r = new DATA_TYPE*[nj];
    DATA_TYPE** q = new DATA_TYPE*[nj];

    for (int i = 0; i < nj; ++i) {
        a[i] = new DATA_TYPE[ni];
        r[i] = new DATA_TYPE[nj];
        q[i] = new DATA_TYPE[ni];
    }

    // Initialize arrays with some values
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            a[j][i] = static_cast<DATA_TYPE>(i * j);
            r[j][i] = static_cast<DATA_TYPE>(i + j);
            q[j][i] = static_cast<DATA_TYPE>(i - j);
        }
    }

    // Call the function
    print_array(ni, nj, a, r, q);

    // Clean up dynamically allocated memory
    for (int i = 0; i < nj; ++i) {
        delete[] a[i];
        delete[] r[i];
        delete[] q[i];
    }
    delete[] a;
    delete[] r;
    delete[] q;

    return 0
