To translate the given Fortran code to C++, we need to consider the differences in syntax and conventions between the two languages. Here's a C++ version of the Fortran subroutine:

```cpp
#include <iostream>
#include <iomanip>

// Assuming DATA_TYPE is a placeholder for a specific data type (e.g., float, double, int)
// and DATA_PRINTF_MODIFIER is a format string for printing the data.
// For simplicity, we'll use a placeholder for DATA_PRINTF_MODIFIER.

template<typename T>
void print_array(T** d, int ni, int nl) {
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nl; ++j) {
            // Assuming DATA_PRINTF_MODIFIER is a format string for printing the data.
            // For simplicity, we'll just print the data without formatting.
            std::cout << d[j][i] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    const int ni = 5; // Number of columns
    const int nl = 4; // Number of rows

    // Dynamically allocate 2D array
    int** d = new int*[nl];
    for(int i = 0; i < nl; ++i) {
        d[i] = new int[ni];
    }

    // Initialize the array with some values (example initialization)
    for(int i = 0; i < nl; ++i) {
        for(int j = 0; j < ni; ++j) {
            d[i][j] = (i * ni) + j + 1; // Example initialization
        }
    }

    // Call the print_array function
    print_array(d, ni, nl);

    // Clean up the dynamically allocated memory
    for(int i = 0; i < nl; ++i) {
        delete[] d[i];
    }
    delete[] d;

    return 0;
}
```

### Explanation:
1. **Template Function**: The `print_array` function is templated to accept any data type `T`. This is a common practice in C++ to handle different data types similarly to how Fortran's `DATA_TYPE` is used.
2. **Dynamic 2D Array**: The 2D array `d` is dynamically allocated to accommodate the specified dimensions `ni` and `nl`.
3. **Initialization**: An example initialization is provided to fill the array with some values.
4. **Printing**: The array elements are printed to the standard output. The nested loops iterate over the array and print each element.
5. **Cleanup**: The dynamically allocated memory is cleaned up to avoid memory leaks.

This C++ code should provide a similar functionality to the provided Fortran subroutine. Adjust the data types and formatting as needed for your specific use case.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the translation by comparing the output of both implementations.

### Fortran Unit Test Code

```fortran
program test_print_array
    implicit none
    integer, parameter :: ni = 5, nl = 4
    real, dimension(nl, ni) :: d
    integer :: i, j

    ! Initialize the array with some values
    do i = 1, ni
        do j = 1, nl
            d(j, i) = real(i * nl + j)
        end do
    end do

    ! Call the subroutine
    call print_array(d, ni, nl)

contains

    subroutine print_array(d, ni, nl)
        implicit none
        real, dimension(nl, ni) :: d
        integer :: nl, ni
        integer :: i, j

        do i = 1, ni
            do j = 1, nl
                write(*, '(F6.2)') d(j, i)
            end do
            write(*, *)
        end do
        write(*, *)
    end subroutine print_array

end program test_print_array
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <iomanip>

template<typename T>
void print_array(T** d, int ni, int nl) {
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nl; ++j) {
            std::cout << std::setw(6) << std::setprecision(2) << std::fixed << d[j][i] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    const int ni = 5; // Number of columns
    const int nl = 4; // Number of rows

    // Dynamically allocate 2D array
    float** d = new float*[nl];
    for(int i = 0; i < nl; ++i) {
        d[i] = new float[ni];
    }

    // Initialize the array with some values
    for(int i = 0; i < nl; ++i) {
        for(int j = 0; j < ni; ++j) {
            d[i][j] = static_cast<float>((i * ni) + j + 1); // Example initialization
        }
    }

    // Call the print_array function
    print_array(d, ni, nl);

    // Clean up the dynamically allocated memory
    for(int i = 0; i < nl; ++i) {
        delete[] d[i];
    }
    delete[] d;

    return 0;
}
```

### Explanation:
1. **Fortran Unit Test Code**:
    - The `test_print_array` program initializes a 2D array `d` with values.
    - It calls the `print_array` subroutine to print the array.
    - The subroutine prints the array elements with a format specifier `(F6.2)` to match the output format of the C++ code.

2. **C++ Unit Test Code**:
    - The `main` function dynamically allocates a 2D array `d` with `float` elements.
    - It initializes the array with values similar to the Fortran code.
    - The `print_array` function prints the array elements with `std::setw(6)` and `std::setprecision(2)` to match the Fortran output format.

### Running the Tests:
1. **Fortran**:
    - Save the Fortran code in a file, e.g., `test_print_array.f90`.
    - Compile the code using a Fortran compiler, e.g., `gfortran -o test_print_array test_print_array.f90`.
    - Run the executable, e.g., `./test_print_array`.

2. **C++**:
    - Save the C++ code in a file, e.g., `test_print_array.cpp`.
    - Compile the code using a C++ compiler, e.g., `g++ -o test_print_array test_print_array.cpp`.
    - Run the executable, e.g., `./test_print_array`.

### Verifying Correctness:
By comparing the output of both programs, you can verify that the translation is correct. The output of both programs should be identical, showing the same array values formatted similarly.
