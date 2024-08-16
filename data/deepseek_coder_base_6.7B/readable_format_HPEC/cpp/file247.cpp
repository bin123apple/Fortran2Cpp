To translate the given Fortran code to C++, we need to consider several differences between the two languages, such as array indexing, data types, and the way arrays are declared and used. In Fortran, arrays are 1-based, while in C++, they are 0-based. Also, Fortran passes arrays to functions/subroutines by reference automatically, while in C++, we need to explicitly use pointers or references. For simplicity and to maintain the original structure, I'll use pointers in C++ to represent the 3D and 2D arrays. Note that in C++, we need to include the necessary headers and use the correct data types.

Here's how the Fortran code can be translated to C++:

```cpp
#include <iostream>

// Assuming DATA_TYPE is a floating-point type (e.g., float, double)
using DATA_TYPE = double;

void init_array(int nr, int nq, int np, DATA_TYPE*** a, DATA_TYPE** cFour) {
    // Allocate memory for 3D array a
    a = new DATA_TYPE**[np];
    for (int i = 0; i < np; ++i) {
        a[i] = new DATA_TYPE*[nq];
        for (int j = 0; j < nq; ++j) {
            a[i][j] = new DATA_TYPE[nr];
        }
    }

    // Allocate memory for 2D array cFour
    cFour = new DATA_TYPE*[np];
    for (int i = 0; i < np; ++i) {
        cFour[i] = new DATA_TYPE[np];
    }

    // Initialize array a
    for (int i = 0; i < nr; ++i) {
        for (int j = 0; j < nq; ++j) {
            for (int k = 0; k < np; ++k) {
                a[k][j][i] = ((DATA_TYPE(i) * DATA_TYPE(j)) + DATA_TYPE(k)) / DATA_TYPE(np);
            }
        }
    }

    // Initialize array cFour
    for (int i = 0; i < np; ++i) {
        for (int j = 0; j < np; ++j) {
            cFour[j][i] = (DATA_TYPE(i) * DATA_TYPE(j)) / DATA_TYPE(np);
        }
    }

    // Remember to deallocate the memory if it's no longer needed
    // This is not done here to keep the example simple
}

int main() {
    int nr = 5, nq = 4, np = 3;
    DATA_TYPE*** a = nullptr;
    DATA_TYPE** cFour = nullptr;

    init_array(nr, nq, np, a, cFour);

    // Example: Print a value to verify the initialization
    std::cout << "a[0][0][0]: " << a[0][0][0] << std::endl;
    std::cout << "cFour[0][0]: " << cFour[0][0] << std::endl;

    // Deallocate memory if necessary
    // ...

    return 0;
}
```

This C++ code initializes two arrays, `a` and `cFour`, based on the given Fortran subroutine. Note that dynamic memory allocation is used for the 3D and 2D arrays, and it's the responsibility of the caller to deallocate this memory when it's no longer needed.
Let's write some test to verify if the translation is correct. 
To verify the correctness of both the original Fortran code and the translated C++ code, we can write simple unit tests. These tests will check if the arrays `a` and `cFour` are initialized correctly according to the specified logic.

### Fortran Unit Test

For the Fortran code, we can write a simple program that calls the `init_array` subroutine and checks the values of `a` and `cFour`.

```fortran
program test_init_array
    implicit none
    integer, parameter :: nr = 5, nq = 4, np = 3
    real, dimension(np, nq, nr) :: a
    real, dimension(np, np) :: cFour
    integer :: i, j, k

    call init_array(nr, nq, np, a, cFour)

    ! Check values of a
    do i = 1, nr
        do j = 1, nq
            do k = 1, np
                if (a(k, j, i) /= ((real(i - 1) * real(j - 1)) + real(k - 1)) / real(np)) then
                    print *, 'Test failed for a'
                    stop
                end if
            end do
        end do
    end do
    print *, 'All tests passed for a'

    ! Check values of cFour
    do i = 1, np
        do j = 1, np
            if (cFour(j, i) /= (real(i - 1) * real(j - 1)) / real(np)) then
                print *, 'Test failed for cFour'
                stop
            end if
        end do
    end do
    print *, 'All tests passed for cFour'
end program test_init_array
```

### C++ Unit Test

For the C++ code, we can use a simple main function to check the values of `a` and `cFour`.

```cpp
#include <iostream>
#include <cmath> // For fabs

// Assuming DATA_TYPE is a floating-point type (e.g., float, double)
using DATA_TYPE = double;

void init_array(int nr, int nq, int np, DATA_TYPE*** a, DATA_TYPE** cFour);

int main() {
    int nr = 5, nq = 4, np = 3;
    DATA_TYPE*** a = nullptr;
    DATA_TYPE** cFour = nullptr;

    init_array(nr, nq, np, a, cFour);

    // Check values of a
    for (int i = 0; i < nr; ++i) {
        for (int j = 0; j < nq; ++j) {
            for (int k = 0; k < np; ++k) {
                if (fabs(a[k][j][i] - ((DATA_TYPE(i) * DATA_TYPE(j)) + DATA_TYPE(k)) / DATA_TYPE(np)) > 1e-6) {
                    std::cerr << "Test failed for a" << std::endl;
                    return 1;
                }
            }
        }
    }
    std::cout << "All tests passed for a" << std::endl;

    // Check values of cFour
    for (int i = 0; i < np; ++i) {
        for (int j = 0; j < np; ++j) {
            if (fabs(cFour[j][i] - (DATA_TYPE(i) * DATA_TYPE(j)) / DATA_TYPE(np)) > 1e-6) {
                std::cerr << "Test failed for cFour" << std::endl;
                return 1;
            }
        }
    }
    std::cout << "All tests passed for cFour" << std::endl;

    return 0;
}
```

These unit tests will verify that the arrays `a` and `cFour` are initialized correctly according to the specified logic in both the Fortran and C++ implementations. Note that in the C++ code, `fabs` is used to compare floating-point numbers due to potential precision issues.
