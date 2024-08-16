To translate the given Fortran code to C++, we need to consider a few key differences between the two languages, such as array indexing, data types, and the way arrays are declared and used. Fortran arrays are 1-based, while C++ arrays are 0-based. Also, Fortran passes arrays to functions/subroutines by reference by default, while in C++, we need to explicitly use pointers or references. For simplicity and to maintain the original structure, I'll use pointers for the arrays in the C++ translation.

Here's the C++ translation of the provided Fortran code:

```cpp
#include <iostream>

// Assuming DATA_TYPE is a float or double, we'll use double for the translation.
// If you need a specific precision, you can change the type accordingly.
using DATA_TYPE = double;

void init_array(int n, DATA_TYPE** x, DATA_TYPE** a, DATA_TYPE** b) {
    // Allocate memory for the 2D arrays
    x = new DATA_TYPE*[n];
    a = new DATA_TYPE*[n];
    b = new DATA_TYPE*[n];

    for (int i = 0; i < n; ++i) {
        x[i] = new DATA_TYPE[n];
        a[i] = new DATA_TYPE[n];
        b[i] = new DATA_TYPE[n];
    }

    // Initialize the arrays
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            x[j][i] = (static_cast<DATA_TYPE>((i) * (j + 1)) + 1.0) / static_cast<DATA_TYPE>(n);
            a[j][i] = (static_cast<DATA_TYPE>((i) * (j + 2)) + 2.0) / static_cast<DATA_TYPE>(n);
            b[j][i] = (static_cast<DATA_TYPE>((i) * (j + 3)) + 3.0) / static_cast<DATA_TYPE>(n);
        }
    }
}

int main() {
    int n = 5; // Example size
    DATA_TYPE** x, **a, **b;

    init_array(n, x, a, b);

    // Example: Printing the first element of array x
    std::cout << "x[0][0]: " << x[0][0] << std::endl;

    // Clean up
    for (int i = 0; i < n; ++i) {
        delete[] x[i];
        delete[] a[i];
        delete[] b[i];
    }
    delete[] x;
    delete[] a;
    delete[] b;

    return 0;
}
```

This C++ code initializes three 2D arrays (`x`, `a`, and `b`) based on the given Fortran subroutine. Note that dynamic memory allocation is used to create the arrays, and they are deallocated in the `main` function to avoid memory leaks. The example usage includes printing the first element of the `x` array to demonstrate the initialization process.
Let's write some test to verify if the translation is correct. 
Below are examples of how you could write unit tests for both the Fortran and C++ versions of the code to verify their correctness. These tests will check the initialization of the arrays `x`, `a`, and `b`.

### Fortran Unit Test

For the Fortran code, we'll write a simple program that calls the `init_array` subroutine and checks the values of the arrays. Fortran doesn't have a built-in unit testing framework like some other languages, so we'll do a basic manual check.

```fortran
program test_init_array
    implicit none
    integer, parameter :: n = 5
    real(kind=8), allocatable :: x(:,:), a(:,:), b(:,:)
    integer :: i, j
    logical :: test_passed

    allocate(x(n,n), a(n,n), b(n,n))

    call init_array(n, x, a, b)

    test_passed = .true.
    do i = 1, n
        do j = 1, n
            if (x(j, i) /= (1.0D0 + (i - 1) * j) / n .or. &
                a(j, i) /= (2.0D0 + (i - 1) * (j + 1)) / n .or. &
                b(j, i) /= (3.0D0 + (i - 1) * (j + 2)) / n) then
                test_passed = .false.
                exit
            endif
        end do
        if (.not. test_passed) exit
    end do

    if (test_passed) then
        print *, "Fortran Test Passed"
    else
        print *, "Fortran Test Failed"
    endif

    deallocate(x, a, b)
end program test_init_array
```

### C++ Unit Test

For C++, we can use a simple testing approach similar to the Fortran example, or we can use a unit testing framework like Google Test. Here, I'll provide a basic manual check similar to the Fortran example.

```cpp
#include <iostream>
#include <cmath> // For fabs

// Assuming DATA_TYPE is a float or double, we'll use double for the translation.
// If you need a specific precision, you can change the type accordingly.
using DATA_TYPE = double;

void init_array(int n, DATA_TYPE** x, DATA_TYPE** a, DATA_TYPE** b);

int main() {
    int n = 5; // Example size
    DATA_TYPE** x, **a, **b;
    bool test_passed = true;

    init_array(n, x, a, b);

    // Check the values of the arrays
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (fabs(x[j][i] - ((1.0 + i * (j + 1)) / n)) > 1e-6 ||
                fabs(a[j][i] - ((2.0 + i * (j + 2)) / n)) > 1e-6 ||
                fabs(b[j][i] - ((3.0 + i * (j + 3)) / n)) > 1e-6) {
                test_passed = false;
                break;
            }
        }
        if (!test_passed) break;
    }

    if (test_passed) {
        std::cout << "C++ Test Passed" << std::endl;
    } else {
        std::cout << "C++ Test Failed" << std::endl;
    }

    // Clean up
    for (int i = 0; i < n; ++i) {
        delete[] x[i];
        delete[] a[i];
        delete[] b[i];
    }
    delete[] x;
    delete[] a;
    delete[] b;

    return 0;
}
```

These tests manually check if the arrays `x`, `a`, and `b` are initialized correctly according to the specified formulas. Note that in a real-world scenario, especially for more complex functions, you might want to use a proper unit testing framework for more comprehensive testing capabilities.
