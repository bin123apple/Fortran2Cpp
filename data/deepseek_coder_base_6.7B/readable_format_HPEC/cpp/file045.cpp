Certainly! Below is the translated Fortran code to C++. Note that in C++, arrays are typically zero-indexed, unlike Fortran which is one-indexed. Also, C++ does not have built-in array allocation and deallocation like Fortran, so we use dynamic memory allocation with `new` and `delete`.

```cpp
#include <iostream>
#include <omp.h>

// Assuming the existence of a header file for the foo1 function
// #include "DRB050.h"

// Function prototype for foo1
void foo1(double* o1, double* c, int size);

int main() {
    // Allocate arrays
    double* o1 = new double[100];
    double* c = new double[100];

    // Call the function
    foo1(o1, c, 100);

    // Deallocate arrays
    delete[] o1;
    delete[] c;

    return 0;
}

// Assuming the definition of foo1 is provided elsewhere
// For demonstration, let's assume it simply fills the arrays with some values
void foo1(double* o1, double* c, int size) {
    for (int i = 0; i < size; ++i) {
        o1[i] = i; // Example operation
        c[i] = i * 2; // Example operation
    }
}
```

This C++ code does the following:
1. Allocates two arrays `o1` and `c` of size 100.
2. Calls the function `foo1`, which is assumed to be defined elsewhere (as indicated by the comment).
3. Deallocates the arrays.

Please note that in a real-world scenario, you would need to define the actual functionality of `foo1` and any necessary headers (`#include "DRB050.h"`). Also, ensure that the OpenMP library is correctly set up in your project for parallel execution if `foo1` is intended to be parallelized.
Let's write some test to verify if the translation is correct. 
Below are simple unit tests for both the original Fortran code and the translated C++ code. These tests will verify that the `foo1` function correctly modifies the arrays `o1` and `c`.

### Fortran Unit Test

For the Fortran code, we'll add a simple test procedure within the program. Fortran doesn't have a built-in unit testing framework like some other languages, so we'll do a basic check.

```fortran
program DRB050_functionparameter_orig_no
    use omp_lib
    implicit none

    double precision, allocatable :: o1(:), c(:)
    integer :: i
    logical :: test_passed

    allocate (o1(100), c(100))

    call foo1(o1, c, 100)

    test_passed = .true.
    do i = 1, 100
        if (o1(i) /= i .or. c(i) /= i * 2) then
            test_passed = .false.
            exit
        endif
    end do

    if (test_passed) then
        print *, "Test Passed"
    else
        print *, "Test Failed"
    endif

end program

subroutine foo1(o1, c, size)
    double precision, intent(out) :: o1(*), c(*)
    integer, intent(in) :: size
    integer :: i

    do i = 1, size
        o1(i) = i
        c(i) = i * 2
    end do
end subroutine
```

### C++ Unit Test

For the C++ code, we can use a simple testing approach similar to the Fortran example. C++ also doesn't have a built-in unit testing framework, but for a simple case like this, we don't necessarily need one.

```cpp
#include <iostream>
#include <cassert>

void foo1(double* o1, double* c, int size);

int main() {
    double* o1 = new double[100];
    double* c = new double[100];

    foo1(o1, c, 100);

    bool test_passed = true;
    for (int i = 0; i < 100; ++i) {
        if (o1[i] != i + 1 || c[i] != (i + 1) * 2) { // +1 to match Fortran 1-indexing
            test_passed = false;
            break;
        }
    }

    if (test_passed) {
        std::cout << "Test Passed" << std::endl;
    } else {
        std::cout << "Test Failed" << std::endl;
    }

    delete[] o1;
    delete[] c;

    return 0;
}

void foo1(double* o1, double* c, int size) {
    for (int i = 0; i < size; ++i) {
        o1[i] = i + 1; // +1 to match Fortran 1-indexing
        c[i] = (i + 1) * 2; // +1 to match Fortran 1-indexing
    }
}
```

These tests simply check if the `foo1` function correctly modifies the arrays `o1` and `c` according to the specified logic. If the test passes, it prints "Test Passed"; otherwise, it prints "Test Failed". These are very basic tests and in a real-world scenario, you might want to use a more sophisticated testing framework like Google Test for C++ or a dedicated Fortran testing framework.
