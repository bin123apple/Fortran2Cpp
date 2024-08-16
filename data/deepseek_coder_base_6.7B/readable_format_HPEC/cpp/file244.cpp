To translate the given Fortran code to C++, we need to consider several aspects, including the data types, array indexing, and loop constructs. Fortran arrays are 1-based, while C++ arrays are 0-based. Also, Fortran passes arrays to functions/subroutines by reference by default, so we'll mimic this behavior in C++ by using pointers or references.

Here's the translated C++ code:

```cpp
#include <iostream>

// Assuming DATA_TYPE is a floating-point type (e.g., double)
using DATA_TYPE = double;

void kernel_atax(int nx, int ny, DATA_TYPE** a, DATA_TYPE* x, DATA_TYPE* y, DATA_TYPE* tmp) {
    // Initialize y to zero
    for (int i = 0; i < ny; ++i) {
        y[i] = 0.0;
    }

    // Compute tmp = A * x
    for (int i = 0; i < nx; ++i) {
        tmp[i] = 0.0;
        for (int j = 0; j < ny; ++j) {
            tmp[i] += a[j][i] * x[j];
        }
    }

    // Update y = y + A * tmp
    for (int j = 0; j < ny; ++j) {
        y[j] += a[j][i] * tmp[i];
    }
}

int main() {
    // Example usage
    int nx = 5; // Number of columns
    int ny = 4; // Number of rows

    // Allocate and initialize arrays
    DATA_TYPE** a = new DATA_TYPE*[ny];
    for (int i = 0; i < ny; ++i) {
        a[i] = new DATA_TYPE[nx];
        for (int j = 0; j < nx; ++j) {
            a[i][j] = static_cast<DATA_TYPE>(i + j); // Example initialization
        }
    }

    DATA_TYPE* x = new DATA_TYPE[ny];
    for (int i = 0; i < ny; ++i) {
        x[i] = static_cast<DATA_TYPE>(i); // Example initialization
    }

    DATA_TYPE* y = new DATA_TYPE[ny];
    DATA_TYPE* tmp = new DATA_TYPE[nx];

    // Call the kernel
    kernel_atax(nx, ny, a, x, y, tmp);

    // Clean up
    for (int i = 0; i < ny; ++i) {
        delete[] a[i];
    }
    delete[] a;
    delete[] x;
    delete[] y;
    delete[] tmp;

    return 0;
}
```

### Key Points:
- The `DATA_TYPE` is assumed to be `double` in the C++ code. You can change it to any other floating-point type if needed.
- The arrays `a`, `x`, `y`, and `tmp` are passed as pointers to pointers, arrays, and arrays, respectively. This mimics Fortran's behavior of passing arrays to subroutines/functions by reference.
- The loops in C++ are 0-based, consistent with C++'s array indexing.
- The `kernel_atax` function performs the same operations as the Fortran subroutine.
- The `main` function demonstrates how to allocate and initialize arrays, call the `kernel_atax` function, and then clean up the allocated memory.

This translation assumes that the arrays `a`, `x`, `y`, and `tmp` are properly allocated and deallocated outside this function, as shown in the `main` function.
Let's write some test to verify if the translation is correct. 
Below are simple unit tests for both the Fortran and C++ versions of the `kernel_atax` function. These tests will verify that the implementations produce the same results for a given set of inputs.

### Fortran Unit Test

First, let's create a Fortran program that includes the original subroutine and a test subroutine.

```fortran
program test_atax
    implicit none
    integer, parameter :: nx = 5, ny = 4
    double precision, dimension(ny, nx) :: a
    double precision, dimension(ny) :: x, y, tmp
    integer :: i, j

    ! Initialize arrays
    do i = 1, ny
        do j = 1, nx
            a(i, j) = i + j
        end do
        x(i) = i
        y(i) = 0.0d0
        tmp(i) = 0.0d0
    end do

    ! Call the kernel
    call kernel_atax(nx, ny, a, x, y, tmp)

    ! Print results for verification
    print *, 'y:'
    print *, y

contains

    subroutine kernel_atax(nx, ny, a, x, y, tmp)
        implicit none
        integer, intent(in) :: nx, ny
        double precision, dimension(ny, nx), intent(in) :: a
        double precision, dimension(ny), intent(in) :: x
        double precision, dimension(ny), intent(out) :: y
        double precision, dimension(nx), intent(out) :: tmp
        integer :: i, j

        !$pragma scop
        do i = 1, ny
            y(i) = 0.0d0
        end do

        do i = 1, nx
            tmp(i) = 0.0d0
            do j = 1, ny
                tmp(i) = tmp(i) + (a(j, i) * x(j))
            end do
        end do

        do j = 1, ny
            y(j) = y(j) + a(j, i) * tmp(i)
        end do
        !$pragma endscop
    end subroutine kernel_atax

end program test_atax
```

### C++ Unit Test

Next, let's create a C++ program that includes the translated function and a test function.

```cpp
#include <iostream>
#include <cmath>

using DATA_TYPE = double;

void kernel_atax(int nx, int ny, DATA_TYPE** a, DATA_TYPE* x, DATA_TYPE* y, DATA_TYPE* tmp) {
    for (int i = 0; i < ny; ++i) {
        y[i] = 0.0;
    }

    for (int i = 0; i < nx; ++i) {
        tmp[i] = 0.0;
        for (int j = 0; j < ny; ++j) {
            tmp[i] += a[j][i] * x[j];
        }
    }

    for (int j = 0; j < ny; ++j) {
        y[j] += a[j][i] * tmp[i];
    }
}

void test_atax() {
    const int nx = 5;
    const int ny = 4;

    DATA_TYPE** a = new DATA_TYPE*[ny];
    for (int i = 0; i < ny; ++i) {
        a[i] = new DATA_TYPE[nx];
        for (int j = 0; j < nx; ++j) {
            a[i][j] = static_cast<DATA_TYPE>(i + j + 2); // Adjusted for 0-based indexing
        }
    }

    DATA_TYPE* x = new DATA_TYPE[ny];
    for (int i = 0; i < ny; ++i) {
        x[i] = static_cast<DATA_TYPE>(i + 1); // Adjusted for 0-based indexing
    }

    DATA_TYPE* y = new DATA_TYPE[ny];
    DATA_TYPE* tmp = new DATA_TYPE[nx];

    kernel_atax(nx, ny, a, x, y, tmp);

    std::cout << "y:" << std::endl;
    for (int i = 0; i < ny; ++i) {
        std::cout << y
