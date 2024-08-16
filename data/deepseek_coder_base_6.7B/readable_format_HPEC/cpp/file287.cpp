To translate the given Fortran code to C++, we need to consider several aspects, such as the array indexing, I/O operations, and the loop constructs. In Fortran, arrays are 1-based, while in C++, they are 0-based. Also, Fortran's `write` statement for output is somewhat different from C++'s `std::cout`. Here's a C++ version of the given Fortran subroutine:

```cpp
#include <iostream>
#include <iomanip> // For std::setw

// Assuming DATA_TYPE is a type that can be printed, e.g., int, double, etc.
// You need to define it according to your specific use case.
using DATA_TYPE = int;

void print_array(int m, DATA_TYPE** symmat) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << std::setw(12) << symmat[j][i]; // Adjust width as needed
            if (((i * m) + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    const int m = 5; // Example size
    DATA_TYPE** symmat = new DATA_TYPE*[m];
    for (int i = 0; i < m; ++i) {
        symmat[i] = new DATA_TYPE[m];
        for (int j = 0; j < m; ++j) {
            symmat[i][j] = i * m + j; // Example initialization
        }
    }

    print_array(m, symmat);

    // Clean up
    for (int i = 0; i < m; ++i) {
        delete[] symmat[i];
    }
    delete[] symmat;

    return 0;
}
```

This C++ code defines a function `print_array` that takes the size `m` of the square matrix and a pointer to a pointer (`symmat`) to a 2D array of `DATA_TYPE`. It then iterates over the matrix and prints each element, adjusting for the 0-based indexing of C++. The `std::setw(12)` is used to set the width of each printed item to 12 characters, which is somewhat analogous to the `DATA_PRINTF_MODIFIER` in Fortran, though the exact formatting might need to be adjusted based on the actual output requirements.

Note that in C++, dynamic memory allocation for multi-dimensional arrays is handled differently than in Fortran. The example provided uses heap allocation for simplicity, but in a real application, consider using `std::vector` or other container classes for better memory management and safety.
Let's write some test to verify if the translation is correct. 
To verify the correctness of both the original Fortran code and the translated C++ code, we can write simple unit tests. These tests will involve creating a small matrix and passing it to the respective functions, then checking the output.

### Fortran Unit Test

First, let's create a Fortran program that includes the subroutine and a test case.

```fortran
program test_print_array
    implicit none
    integer, parameter :: m = 3
    integer :: i, j
    real, dimension(m, m) :: symmat

    ! Initialize the matrix
    do i = 1, m
        do j = 1, m
            symmat(j, i) = i * 10.0 + j
        end do
    end do

    ! Call the subroutine
    call print_array(m, symmat)

contains

    subroutine print_array(m, symmat)
        implicit none
        integer, parameter :: DATA_PRINTF_MODIFIER = '(3F6.2)'
        integer, intent(in) :: m
        real, dimension(m, m), intent(in) :: symmat
        integer :: i, j

        do i = 1, m
            do j = 1, m
                write(*, DATA_PRINTF_MODIFIER) symmat(j, i)
                if (mod(((i - 1) * m) + j - 1, 20) == 0) then
                    write(*, *)
                end if
            end do
        end do
        write(*, *)
    end subroutine print_array

end program test_print_array
```

This Fortran program initializes a 3x3 matrix with values `i * 10.0 + j`, where `i` and `j` are the indices, and then calls the `print_array` subroutine. The subroutine prints the matrix in a formatted manner, and the test case prints the matrix to the standard output.

### C++ Unit Test

Now, let's create a C++ program that includes the `print_array` function and a test case.

```cpp
#include <iostream>
#include <iomanip>

using DATA_TYPE = double;

void print_array(int m, DATA_TYPE** symmat) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << std::setw(12) << symmat[j][i];
            if (((i * m) + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

int main() {
    const int m = 3;
    DATA_TYPE** symmat = new DATA_TYPE*[m];
    for (int i = 0; i < m; ++i) {
        symmat[i] = new DATA_TYPE[m];
        for (int j = 0; j < m; ++j) {
            symmat[i][j] = i * 10.0 + j;
        }
    }

    print_array(m, symmat);

    // Clean up
    for (int i = 0; i < m; ++i) {
        delete[] symmat[i];
    }
    delete[] symmat;

    return 0;
}
```

This C++ program does essentially the same thing as the Fortran test case. It initializes a 3x3 matrix with values `i * 10.0 + j`, calls the `print_array` function, and prints the matrix to the standard output.

### Running the Tests

To run these tests, you'll need a Fortran compiler for the Fortran code (e.g., `gfortran`) and a C++ compiler for the C++ code (e.g., `g++`).

- For the Fortran code, compile and run it using:
  ```sh
  gfortran -o test_print_array test_print_array.f90
  ./test_print_array
  ```
- For the C++ code, compile and run it using:
  ```sh
  g++ -o test_print_array test_print_array.cpp
  ./test_print_array
  ```

These tests should produce similar output for the given matrix, verifying that the translation from Fortran to C++ is correct.
