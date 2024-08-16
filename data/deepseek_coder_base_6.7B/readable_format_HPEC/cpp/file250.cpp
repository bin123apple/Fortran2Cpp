To translate the given Fortran code to C++, we need to consider several aspects, such as array indexing, data types, and loop constructs. Fortran arrays are 1-based, while C++ arrays are 0-based. Also, Fortran passes arrays to functions/subroutines by reference automatically, whereas in C++ we need to explicitly use pointers or references. For simplicity and to maintain the original structure, I'll use pointers in C++.

Here's how the Fortran code can be translated to C++:

```cpp
#include <iostream>

// Assuming DATA_TYPE is a floating-point type, e.g., double
using DATA_TYPE = double;

// Function prototype
void init_array(int n, DATA_TYPE** a, DATA_TYPE** b);

int main() {
    int n = 4; // Example size
    DATA_TYPE** a = new DATA_TYPE*[n];
    DATA_TYPE** b = new DATA_TYPE*[n];

    for(int i = 0; i < n; ++i) {
        a[i] = new DATA_TYPE[n];
        b[i] = new DATA_TYPE[n];
    }

    init_array(n, a, b);

    // Example: Printing the arrays to verify the initialization
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            std::cout << "a[" << i << "][" << j << "] = " << a[i][j] << ", ";
            std::cout << "b[" << i << "][" << j << "] = " << b[i][j] << std::endl;
        }
    }

    // Clean up
    for(int i = 0; i < n; ++i) {
        delete[] a[i];
        delete[] b[i];
    }
    delete[] a;
    delete[] b;

    return 0;
}

void init_array(int n, DATA_TYPE** a, DATA_TYPE** b) {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            a[j][i] = (static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j + 1) + 2.0) / n;
            b[j][i] = (static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j + 2) + 3.0) / n;
        }
    }
}
```

This C++ code initializes two 2D arrays `a` and `b` with the specified formulas, similar to the Fortran subroutine. Note that dynamic memory allocation is used for the arrays to mimic the Fortran behavior. Also, the `DATA_TYPE` is assumed to be `double`, but you can change it to any other floating-point type if needed.
Let's write some test to verify if the translation is correct. 
To verify the correctness of both the original Fortran code and the translated C++ code, we can write simple unit tests. These tests will check if the arrays `a` and `b` are initialized correctly according to the specified formulas.

### Fortran Unit Test

For the Fortran code, we can write a simple program that calls the `init_array` subroutine and checks the results.

```fortran
program test_init_array
    implicit none
    integer, parameter :: n = 4
    real(8), dimension(n, n) :: a, b
    integer :: i, j
    logical :: test_passed

    call init_array(n, a, b)

    test_passed = .true.
    do i = 1, n
        do j = 1, n
            if (a(j, i) /= (real(i - 1) * real(j + 1) + 2.0d0) / n .or. &
                b(j, i) /= (real(i - 1) * real(j + 2) + 3.0d0) / n) then
                test_passed = .false.
                exit
            endif
        end do
        if (.not. test_passed) exit
    end do

    if (test_passed) then
        print *, "Test Passed"
    else
        print *, "Test Failed"
    endif
end program test_init_array
```

### C++ Unit Test

For the C++ code, we can use a simple main function to check the results. This example does not use a testing framework for simplicity.

```cpp
#include <iostream>
#include <cmath> // For fabs

using DATA_TYPE = double;

void init_array(int n, DATA_TYPE** a, DATA_TYPE** b);

int main() {
    int n = 4; // Example size
    DATA_TYPE** a = new DATA_TYPE*[n];
    DATA_TYPE** b = new DATA_TYPE*[n];

    for(int i = 0; i < n; ++i) {
        a[i] = new DATA_TYPE[n];
        b[i] = new DATA_TYPE[n];
    }

    init_array(n, a, b);

    bool test_passed = true;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            DATA_TYPE expected_a = (static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j + 1) + 2.0) / n;
            DATA_TYPE expected_b = (static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j + 2) + 3.0) / n;
            if (fabs(a[j][i] - expected_a) > 1e-6 || fabs(b[j][i] - expected_b) > 1e-6) {
                test_passed = false;
                break;
            }
        }
        if (!test_passed) break;
    }

    if (test_passed) {
        std::cout << "Test Passed" << std::endl;
    } else {
        std::cout << "Test Failed" << std::endl;
    }

    // Clean up
    for(int i = 0; i < n; ++i) {
        delete[] a[i];
        delete[] b[i];
    }
    delete[] a;
    delete[] b;

    return 0;
}

void init_array(int n, DATA_TYPE** a, DATA_TYPE** b) {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            a[j][i] = (static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j + 1) + 2.0) / n;
            b[j][i] = (static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j + 2) + 3.0) / n;
        }
    }
}
```

These unit tests simply check if the arrays `a` and `b` are initialized correctly according to the specified formulas. They print "Test Passed" if the arrays are initialized correctly, and "Test Failed" otherwise. Note that in the C++ code, `fabs` is used to compare floating-point numbers due to potential minor differences in precision.
