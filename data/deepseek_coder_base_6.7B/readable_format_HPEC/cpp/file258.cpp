To translate the given Fortran code to C++, we need to consider several aspects, including array indexing, I/O operations, and the loop structure. In Fortran, arrays are 1-based, while in C++, they are 0-based. Also, Fortran's `write` statement for arrays prints the entire array, while in C++, we need to iterate over the elements manually. Here's a C++ version of the code:

```cpp
#include <iostream>
#include <iomanip>

// Assuming DATA_TYPE is a floating-point type (e.g., float or double)
using DATA_TYPE = double;

void print_array(int nx, int ny, DATA_TYPE** ex, DATA_TYPE** ey, DATA_TYPE** hz) {
    for (int i = 0; i < nx; ++i) {
        for (int j = 0; j < ny; ++j) {
            // Adjusting for 0-based indexing in C++
            std::cout << std::setprecision(6) << ex[j][i] << " ";
            std::cout << std::setprecision(6) << ey[j][i] << " ";
            std::cout << std::setprecision(6) << hz[j][i] << " ";
            if (((i * nx) + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    const int nx = 5, ny = 5;
    DATA_TYPE** ex = new DATA_TYPE*[ny];
    DATA_TYPE** ey = new DATA_TYPE*[ny];
    DATA_TYPE** hz = new DATA_TYPE*[ny];

    // Initialize arrays with some values
    for (int i = 0; i < ny; ++i) {
        ex[i] = new DATA_TYPE[nx];
        ey[i] = new DATA_TYPE[nx];
        hz[i] = new DATA_TYPE[nx];
        for (int j = 0; j < nx; ++j) {
            ex[i][j] = static_cast<DATA_TYPE>(i + j);
            ey[i][j] = static_cast<DATA_TYPE>(i - j);
            hz[i][j] = static_cast<DATA_TYPE>(i * j);
        }
    }

    print_array(nx, ny, ex, ey, hz);

    // Clean up
    for (int i = 0; i < ny; ++i) {
        delete[] ex[i];
        delete[] ey[i];
        delete[] hz[i];
    }
    delete[] ex;
    delete[] ey;
    delete[] hz;

    return 0;
}
```

This C++ code defines a function `print_array` that takes the dimensions of the arrays and pointers to the arrays `ex`, `ey`, and `hz`. It then iterates over the arrays, printing the values of `ex`, `ey`, and `hz` at each position. The `if` statement checks if the current element is the 20th element in a row/column, and if so, it prints a newline. The `main` function demonstrates how to allocate and initialize the arrays, then call `print_array` to print their contents. Finally, it cleans up the dynamically allocated memory.

Note: This example assumes `DATA_TYPE` is a floating-point type (e.g., `float` or `double`). If `DATA_TYPE` is an integer type, you might need to adjust the formatting (e.g., using `std::setw` for spacing) to match the expected output format.
Let's write some test to verify if the translation is correct. 
To verify the correctness of both the original Fortran code and the translated C++ code, we can write unit tests. For Fortran, we'll use a simple approach to test the subroutine, as Fortran doesn't have a built-in unit testing framework like some other languages. For C++, we'll use Google Test, a widely used C++ testing framework.

### Fortran Unit Test

Since Fortran doesn't have a built-in unit testing framework, we'll write a simple test program that calls the subroutine with predefined inputs and checks the outputs manually. This is a basic approach and not a substitute for proper unit testing.

```fortran
program test_print_array
    implicit none
    integer, parameter :: nx = 3, ny = 3
    real, dimension(ny, nx) :: ex, ey, hz
    integer :: i, j

    ! Initialize arrays
    do i = 1, nx
        do j = 1, ny
            ex(j, i) = real(i + j)
            ey(j, i) = real(i - j)
            hz(j, i) = real(i * j)
        end do
    end do

    ! Call the subroutine
    call print_array(nx, ny, ex, ey, hz)

end program test_print_array
```

To compile and run this Fortran program, you would typically use a Fortran compiler like `gfortran`. For example:

```sh
gfortran -o test_print_array test_print_array.f90
./test_print_array
```

### C++ Unit Test with Google Test

First, ensure you have Google Test installed and set up in your C++ environment. The following example assumes you have Google Test set up correctly.

```cpp
#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include <iomanip>

// Assuming DATA_TYPE is a floating-point type (e.g., float or double)
using DATA_TYPE = double;

void print_array(int nx, int ny, DATA_TYPE** ex, DATA_TYPE** ey, DATA_TYPE** hz, std::ostringstream& oss) {
    for (int i = 0; i < nx; ++i) {
        for (int j = 0; j < ny; ++j) {
            oss << std::setprecision(6) << ex[j][i] << " ";
            oss << std::setprecision(6) << ey[j][i] << " ";
            oss << std::setprecision(6) << hz[j][i] << " ";
            if (((i * nx) + j) % 20 == 0) {
                oss << std::endl;
            }
        }
    }
    oss << std::endl;
}

TEST(PrintArrayTest, CorrectOutput) {
    const int nx = 3, ny = 3;
    DATA_TYPE** ex = new DATA_TYPE*[ny];
    DATA_TYPE** ey = new DATA_TYPE*[ny];
    DATA_TYPE** hz = new DATA_TYPE*[ny];

    // Initialize arrays with some values
    for (int i = 0; i < ny; ++i) {
        ex[i] = new DATA_TYPE[nx];
        ey[i] = new DATA_TYPE[nx];
        hz[i] = new DATA_TYPE[nx];
        for (int j = 0; j < nx; ++j) {
            ex[i][j] = static_cast<DATA_TYPE>(i + j + 1);
            ey[i][j] = static_cast<DATA_TYPE>(i - j + 1);
            hz[i][j] = static_cast<DATA_TYPE>(i * j + 1);
        }
    }

    std::ostringstream oss;
    print_array(nx, ny, ex, ey, hz, oss);

    // Expected output
    std::string expected = "1.000000 2.000000 3.000000 
2.000000 0.000000 4.000000 
3.000000 4.000000 9.000000 
";
    EXPECT_EQ(
