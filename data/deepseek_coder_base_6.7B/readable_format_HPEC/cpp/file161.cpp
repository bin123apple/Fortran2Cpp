To translate the given Fortran code to C++, we need to consider several differences between the two languages, such as array indexing, data types, and the way functions are called. The Fortran code uses a specific module `ft_data` for some constants and functions, which we will assume are available in C++ as well. The Fortran code also uses complex numbers, which we will represent in C++ using the `<complex>` header. Here's a C++ translation of the provided Fortran code:

```cpp
#include <complex>
#include <cmath>
#include "ft_data.h" // Assuming this header file exists and contains necessary declarations

void cffts3(int is, int d1, int d2, int d3, std::complex<double> x[], std::complex<double> xout[], std::complex<double> y1[], std::complex<double> y2[]) {
    int logd3 = std::log2(d3);
    int fftblock = FFTBLOCK; // Assuming FFTBLOCK is defined in "ft_data.h"
    int fftblockpad = FFTBLOCKPAD; // Assuming FFTBLOCKPAD is defined in "ft_data.h"

    if (timers_enabled) timer_start(T_fftz);

    for (int j = 0; j < d2; ++j) {
        for (int in = 0; in < d1 / fftblock; ++in) {
            int ii = in * fftblock;
            for (int k = 0; k < d3; ++k) {
                for (int i = 0; i < fftblock; ++i) {
                    y1[i + ii * d3 + k * fftblock * (d1 + 1)] = x[i + ii + j * (d1 + 1) * d2 + k * (d1 + 1) * d2 * d3];
                }
            }
        }
    }

    cfftz(is, logd3, d3, y1, y2);

    for (int k = 0; k < d3; ++k) {
        for (int i = 0; i < fftblock; ++i) {
            xout[i + ii + j * (d1 + 1) * d2 + k * (d1 + 1) * d2 * d3] = y1[i + k * fftblock];
        }
    }

    if (timers_enabled) timer_stop(T_fftz);
}
```

### Key Points:
1. **Array Indexing:** Fortran arrays are 1-based, while C++ arrays are 0-based. Adjustments are made accordingly.
2. **Complex Numbers:** The `std::complex<double>` type is used to represent complex numbers.
3. **Function Calls:** The `cfftz` function is assumed to be available in C++, and its parameters are passed as they are.
4. **Constants:** The constants `FFTBLOCK` and `FFTBLOCKPAD` are assumed to be defined in a header file `ft_data.h`.
5. **Timer Functions:** If `timers_enabled` is true, `timer_start` and `timer_stop` are called with the same arguments as in the Fortran code.

### Assumptions:
- The `ft_data` module and its functions are available in C++.
- The sizes of arrays `x`, `xout`, `y1`, and `y2` are correctly allocated and passed to the function.
- The constants `FFTBLOCK` and `FFTBLOCKPAD` are defined in `ft_data.h`.
- The `timer_start` and `timer_stop` functions are available and correctly implemented.

This translation assumes that the rest of the necessary code (e.g., the `cfftz` function) is correctly implemented and available in C++.
Let's write some test to verify if the translation is correct. 
To verify the correctness of the translation, we can create unit tests for both the original Fortran code and the translated C++ code. These tests will involve a simple scenario where we perform a basic operation and then verify the results.

### Fortran Unit Test

First, let's create a simple Fortran program that calls the `cffts3` subroutine and checks the results.

```fortran
program test_cffts3
    use ft_data
    implicit none

    integer, parameter :: d1 = 4, d2 = 4, d3 = 4
    double complex :: x(d1+1, d2, d3), xout(d1+1, d2, d3)
    double complex :: y1(fftblockpad, d3), y2(fftblockpad, d3)
    integer :: i, j, k

    ! Initialize x with some values
    do k = 1, d3
        do j = 1, d2
            do i = 1, d1+1
                x(i, j, k) = cmplx(i, j)
            end do
        end do
    end do

    ! Call the subroutine
    call cffts3(1, d1, d2, d3, x, xout, y1, y2)

    ! Check the results
    do k = 1, d3
        do j = 1, d2
            do i = 1, d1+1
                if (xout(i, j, k) /= cmplx(i, j)) then
                    print *, "Test failed at: ", i, j, k
                    stop
                end if
            end do
        end do
    end do

    print *, "Fortran test passed."
end program test_cffts3
```

### C++ Unit Test

Next, let's create a simple C++ program that calls the `cffts3` function and checks the results.

```cpp
#include <iostream>
#include <complex>
#include "ft_data.h" // Assuming this header file exists and contains necessary declarations

void cffts3(int is, int d1, int d2, int d3, std::complex<double> x[], std::complex<double> xout[], std::complex<double> y1[], std::complex<double> y2[]);

int main() {
    const int d1 = 4, d2 = 4, d3 = 4;
    std::complex<double> x[d1+1][d2][d3], xout[d1+1][d2][d3];
    std::complex<double> y1[FFTBLOCKPAD][d3], y2[FFTBLOCKPAD][d3];

    // Initialize x with some values
    for (int k = 0; k < d3; ++k) {
        for (int j = 0; j < d2; ++j) {
            for (int i = 0; i < d1 + 1; ++i) {
                x[i][j][k] = std::complex<double>(i, j);
            }
        }
    }

    // Call the function
    cffts3(1, d1, d2, d3, x, xout, y1, y2);

    // Check the results
    for (int k = 0; k < d3; ++k) {
        for (int j = 0; j < d2; ++j) {
            for (int i = 0; i < d1 + 1; ++i) {
                if (xout[i][j][k] != std::complex<double>(i, j)) {
                    std::cout << "Test failed at: " << i << " " << j << " " << k << std::endl;
                    return 1;
                }
            }
        }
    }

    std::cout << "C++ test passed." << std::endl;
    return 0;
}
```

### Notes:
- The `ft_data.h` header file should contain the necessary declarations for the constants and functions used in the C++ test.
- Ensure that the `cfftz` function is correctly implemented in C++ and linked.
- The `cfftz` function is not provided here, so you'll need to implement or link it according to your project setup.
- The `ilog2` function used in the Fortran code is assumed to be equivalent to `std::log2` in C++.
- The `timer_start` and `timer_stop` functions are not implemented here, but they should be part of your project setup.
