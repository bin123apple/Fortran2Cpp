To translate the given Fortran code to C++, we need to consider several aspects, including the differences in array indexing, I/O operations, and the loop structure. Fortran arrays are 1-based, while C++ arrays are 0-based. Also, Fortran's `write` statement for arrays is somewhat different from C++'s stream output. Here's a C++ translation that aims to preserve the functionality of the original Fortran code:

```cpp
#include <iostream>
#include <iomanip> // For std::setprecision

// Assuming DATA_TYPE is a floating-point type (e.g., float or double)
using DATA_TYPE = double;

// Assuming DATA_PRINTF_MODIFIER is a format string for outputting DATA_TYPE values
// For simplicity, we'll use a fixed-width format for demonstration purposes
const char* DATA_PRINTF_MODIFIER = "%.6f"; // Example format, adjust as needed

void print_array(int cz, int cxm, int cym, DATA_TYPE*** bza, DATA_TYPE*** ex, DATA_TYPE*** ey, DATA_TYPE*** hz) {
    // Set precision for floating-point output
    std::cout << std::fixed << std::setprecision(6);

    for (int i = 1; i <= cz + 1; ++i) {
        for (int j = 1; j <= cym + 1; ++j) {
            for (int k = 1; k <= cxm + 1; ++k) {
                // Adjusting for 0-based indexing in C++
                std::cout << bza[k-1][j-1][i-1] << std::endl;
                std::cout << ex[k-1][j-1][i-1] << std::endl;
                std::cout << ey[k-1][j-1][i-1] << std::endl;
                std::cout << hz[k-1][j-1][i-1] << std::endl;

                if ((((i - 1) * cxm) + j - 1) % 20 == 0) {
                    std::cout << std::endl;
                }
            }
        }
    }
    std::cout << std::endl;
}

int main() {
    // Example dimensions
    int cz = 10, cxm = 20, cym = 20;

    // Allocate 3D arrays (bza, ex, ey, hz) dynamically
    DATA_TYPE*** bza = new DATA_TYPE**[cxm + 1];
    DATA_TYPE*** ex = new DATA_TYPE**[cxm + 1];
    DATA_TYPE*** ey = new DATA_TYPE**[cxm + 1];
    DATA_TYPE*** hz = new DATA_TYPE**[cxm + 1];

    for (int i = 0; i <= cxm; ++i) {
        bza[i] = new DATA_TYPE*[cym + 1];
        ex[i] = new DATA_TYPE*[cym + 1];
        ey[i] = new DATA_TYPE*[cym + 1];
        hz[i] = new DATA_TYPE*[cym + 1];

        for (int j = 0; j <= cym; ++j) {
            bza[i][j] = new DATA_TYPE[cz + 1];
            ex[i][j] = new DATA_TYPE[cz + 1];
            ey[i][j] = new DATA_TYPE[cz + 1];
            hz[i][j] = new DATA_TYPE[cz + 1];
        }
    }

    // Initialize arrays with some values for demonstration
    // Note: In a real application, you would populate these arrays with actual data
    for (int i = 0; i <= cxm; ++i) {
        for (int j = 0; j <= cym; ++j) {
            for (int k = 0; k <= cz; ++k) {
                bza[i][j][k] = 1.0; // Example initialization
                ex[i][j][k] = 2.0;
                ey[i][j][k] = 3.0;
                hz[i][j][k] = 4.0;
            }
        }
    }

    // Call the function to print the arrays
    print_array(cz, cxm, cym, bza, ex, ey, hz);

    // Clean up dynamically allocated memory
    for (int i = 0; i <= cxm; ++i) {
        for (int j = 0; j <= cym; ++j) {
            delete[] bza[i][j];
            delete[] ex[i][j];
            delete[] ey[i][j];
            delete[] hz[i][j];
        }
        delete[] bza[i];
        delete[] ex[i];
        delete[] ey[i];
        delete[] hz[i];
    }
    delete[] bza;
    delete[] ex;
    delete[] ey;
    delete[] hz;

    return 0;
}
```

This C++ code attempts to closely mirror the functionality of the original Fortran code. Note that dynamic memory allocation is used to mimic the 3D array dimensions as in the Fortran code. The `std::setprecision(6)` line sets the precision for floating-point output, matching the `DATA_PRINTF_MODIFIER` format specified in the Fortran code. Remember to adjust the `DATA_TYPE` and `DATA_PRINTF_MODIFIER` as per your specific requirements.
Let's write some test to verify if the translation is correct. 
Creating unit tests for both the Fortran and C++ code involves checking the functionality of the `print_array` subroutine/function with a predefined set of inputs. For simplicity, I'll provide a basic framework for unit testing in both languages, focusing on the output verification aspect.

### Fortran Unit Test

Fortran lacks a built-in unit testing framework similar to what's available in other languages. However, you can write a simple test by redirecting output to a file and comparing the file content with expected results. Here's an example of how you might do it:

```fortran
program test_print_array
    implicit none
    integer, parameter :: cz = 2, cxm = 2, cym = 2
    real, dimension(cxm + 1, cym + 1, cz + 1) :: bza, ex, ey, hz
    integer :: i, j, k

    ! Initialize arrays with some values for testing
    do i = 1, cz + 1
        do j = 1, cym + 1
            do k = 1, cxm + 1
                bza(k, j, i) = real(i * j * k)
                ex(k, j, i) = real(i + j + k)
                ey(k, j, i) = real(i - j + k)
                hz(k, j, i) = real(i + j - k)
            end do
        end do
    end do

    ! Redirect output to a file
    open(unit=10, file='output.txt', status='replace')
    call print_array(cz, cxm, cym, bza, ex, ey, hz)
    close(10)

    ! Compare output.txt with expected results
    ! This part is manual and depends on the expected output
    ! For automated testing, you might consider using external tools or scripts

end program test_print_array
```

### C++ Unit Test

For C++, you can use a unit testing framework like Google Test for more sophisticated testing. Here's a simple example assuming Google Test is set up:

```cpp
#include <gtest/gtest.h>
#include <fstream>
#include <sstream>
#include <string>

// Assuming print_array function is declared in print_array.h
#include "print_array.h"

TEST(PrintArrayTest, OutputTest) {
    int cz = 2, cxm = 2, cym = 2;
    DATA_TYPE*** bza = new DATA_TYPE**[cxm + 1];
    DATA_TYPE*** ex = new DATA_TYPE**[cxm + 1];
    DATA_TYPE*** ey
