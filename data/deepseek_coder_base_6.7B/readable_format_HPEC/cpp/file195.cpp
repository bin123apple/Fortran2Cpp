To translate the given Fortran code to C++, we need to consider several differences between the two languages, such as array indexing, array storage order, and the way functions (or subroutines in Fortran) are defined. In Fortran, arrays are 1-based by default, while in C++, they are 0-based. Also, Fortran passes arrays and other arguments by reference by default, while in C++, we need to explicitly use pointers or references.

Given these considerations, here is a C++ translation of the provided Fortran code. Note that in C++, we typically use multi-dimensional arrays with the dimensions in reverse order to match the memory layout of Fortran arrays. Also, we'll use pointers for the arrays to mimic the Fortran behavior of passing arrays by reference.

```cpp
#include <vector>

// Assuming DATA_TYPE is a floating-point type (e.g., double)
using DATA_TYPE = double;

void kernel_doitgen(int nr, int nq, int np, DATA_TYPE*** a, DATA_TYPE*** cFour, DATA_TYPE*** sumA) {
    // Assuming the arrays are allocated with dimensions [np][nq][nr]
    // and [np][np] for cFour and sumA, respectively.

    // Loop indices
    int r, s, p, q;

    // Initialize sumA to 0
    for (r = 0; r < nr; ++r) {
        for (q = 0; q < nq; ++q) {
            for (p = 0; p < np; ++p) {
                sumA[p][q][r] = 0.0;
            }
        }
    }

    // Compute sumA
    for (r = 0; r < nr; ++r) {
        for (q = 0; q < nq; ++q) {
            for (p = 0; p < np; ++p) {
                for (s = 0; s < np; ++s) {
                    sumA[p][q][r] += a[s][q][r] * cFour[p][s];
                }
            }
        }
    }

    // Copy sumA back to a
    for (r = 0; r < nr; ++r) {
        for (q = 0; q < nq; ++q) {
            for (p = 0; p < np; ++p) {
                a[p][q][r] = sumA[p][q][r];
            }
        }
    }
}

int main() {
    // Example usage
    const int nr = 10;
    const int nq = 10;
    const int np = 10;

    // Allocate and initialize arrays
    DATA_TYPE*** a = new DATA_TYPE**[np];
    DATA_TYPE** cFour = new DATA_TYPE*[np];
    DATA_TYPE*** sumA = new DATA_TYPE**[np];

    for (int i = 0; i < np; ++i) {
        a[i] = new DATA_TYPE*[nq];
        sumA[i] = new DATA_TYPE*[nq];
        for (int j = 0; j < nq; ++j) {
            a[i][j] = new DATA_TYPE[nr];
            sumA[i][j] = new DATA_TYPE[nr];
        }
    }

    // Initialize arrays with some values
    // ...

    // Call the kernel
    kernel_doitgen(nr, nq, np, a, cFour, sumA);

    // Clean up
    for (int i = 0; i < np; ++i) {
        for (int j = 0; j < nq; ++j) {
            delete[] a[i][j];
            delete[] sumA[i][j];
        }
        delete[] a[i];
        delete[] sumA[i];
    }
    delete[] a;
    delete[] cFour;
    delete[] sumA;

    return 0;
}
```

This C++ code assumes that the arrays `a`, `cFour`, and `sumA` are dynamically allocated with dimensions matching those used in the Fortran code. The example usage demonstrates how to allocate and initialize these arrays, call the `kernel_doitgen` function, and then clean up the allocated memory. Adjust the dimensions and initialization as necessary to match your specific use case.
Let's write some test to verify if the translation is correct. 
To verify the correctness of both the original Fortran code and the translated C++ code, we can create simple unit tests. These tests will involve initializing the input arrays with known values, calling the respective kernels, and then checking if the output arrays match the expected results.

### Fortran Unit Test

First, let's create a Fortran program that includes the original subroutine and a test subroutine.

```fortran
program test_kernel_doitgen
    implicit none
    integer, parameter :: nr = 2, nq = 2, np = 2
    double precision, dimension(np, nq, nr) :: a
    double precision, dimension(np, nq, nr) :: sumA
    double precision, dimension(np, np) :: cFour
    integer :: i, j, k

    ! Initialize arrays
    a = reshape([1.0d0, 2.0d0, 3.0d0, 4.0d0, 5.0d0, 6.0d0, 7.0d0, 8.0d0], [np, nq, nr])
    cFour = reshape([1.0d0, 0.0d0, 0.0d0, 1.0d0], [np, np])
    sumA = 0.0d0

    ! Call the kernel
    call kernel_doitgen(nr, nq, np, a, cFour, sumA)

    ! Output results for verification
    print *, 'sumA:'
    do i = 1, np
        do j = 1, nq
            do k = 1, nr
                print *, 'sumA(', i, ',', j, ',', k, ') = ', sumA(i, j, k)
            end do
        end do
    end do

contains

    subroutine kernel_doitgen(nr, nq, np, a, cFour, sumA)
        implicit none
        integer :: nr, nq, np, r, s, p, q
        double precision, dimension(np, nq, nr) :: a
        double precision, dimension(np, nq, nr) :: sumA
        double precision, dimension(np, np) :: cFour

        !$pragma scop
        do r = 1, nr
            do q = 1, nq
                do p = 1, np
                    sumA(p, q, r) = 0.0d0
                    do s = 1, np
                        sumA(p, q, r) = sumA(p, q, r) + (a(s, q, r) * cFour(p, s))
                    end do
                end do
            end do
        end do
        do p = 1, np
            do q = 1, nq
                do r = 1, nr
                    a(p, q, r) = sumA(p, q, r)
                end do
            end do
        end do
        !$pragma endscop
    end subroutine kernel_doitgen

end program test_kernel_doitgen
```

### C++ Unit Test

Now, let's create a C++ program that includes the translated function and a test function.

```cpp
#include <iostream>
#include <vector>

using DATA_TYPE = double;

void kernel_doitgen(int nr, int nq, int np, DATA_TYPE*** a, DATA_TYPE*** cFour, DATA_TYPE*** sumA) {
    int r, s, p, q;

    for (r = 0; r < nr; ++r) {
        for (q = 0; q < nq; ++q) {
            for (p = 0; p < np; ++p) {
                sumA[p][q][r] = 0.0;
            }
        }
    }

    for (r = 0; r < nr; ++r) {
        for (q = 0; q
