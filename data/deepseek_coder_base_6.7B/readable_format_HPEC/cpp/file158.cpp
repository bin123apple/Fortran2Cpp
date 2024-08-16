To translate the given Fortran code to C++, we need to consider several aspects, including array indexing, loop structures, and function calls. Fortran arrays are 1-based, while C++ arrays are 0-based. Also, Fortran passes arrays to functions and subroutines by reference by default, while in C++, we need to explicitly use pointers or references. For simplicity and to maintain the logic of the original Fortran code, we'll use pointers for the 4D array `rhs`. Note that the original Fortran code uses a specific data structure (`sp_data`) which is not provided, so we'll assume it's a global variable or passed as an argument.

Here's a C++ translation of the Fortran code:

```cpp
#include <iostream>

// Assuming sp_data is a global variable or passed as an argument
extern "C" void sp_data;

// Assuming timer_start and timer_stop are functions that start and stop a timer
extern "C" void timer_start(void* t_pinvr);
extern "C" void timer_stop(void* t_pinvr);

// Assuming rhs is a 4D array with dimensions nx2, ny2, nz2, 5
extern "C" double*** rhs;

// Assuming nx2, ny2, nz2, bt, and timeron are defined somewhere
extern "C" int nx2, ny2, nz2;
extern "C" double bt;
extern "C" bool timeron;

void pinvr() {
    double r1, r2, r3, r4, r5, t1, t2;

    if (timeron) timer_start(nullptr); // Assuming t_pinvr is a pointer or identifier

    for (int k = 1; k <= nz2; ++k) {
        for (int j = 1; j <= ny2; ++j) {
            for (int i = 1; i <= nx2; ++i) {
                r1 = rhs[0][i-1][j-1][k-1]; // Adjusting for 0-based indexing
                r2 = rhs[1][i-1][j-1][k-1];
                r3 = rhs[2][i-1][j-1][k-1];
                r4 = rhs[3][i-1][j-1][k-1];
                r5 = rhs[4][i-1][j-1][k-1];

                t1 = bt * r1;
                t2 = 0.5 * (r4 + r5);

                rhs[0][i-1][j-1][k-1] = bt * (r4 - r5);
                rhs[1][i-1][j-1][k-1] = -r3;
                rhs[2][i-1][j-1][k-1] = r2;
                rhs[3][i-1][j-1][k-1] = -t1 + t2;
                rhs[4][i-1][j-1][k-1] = t1 + t2;
            }
        }
    }

    if (timeron) timer_stop(nullptr);
}

int main() {
    // Example usage
    pinvr();
    return 0;
}
```

This translation assumes that `rhs`, `nx2`, `ny2`, `nz2`, `bt`, and `timeron` are defined and initialized elsewhere in your C++ code. The `extern "C"` linkage specification is used here to indicate that the functions `timer_start` and `timer_stop` are defined elsewhere, possibly in a library or in a different translation unit. Adjust the function and variable names as necessary to match your actual implementation.
Let's write some test to verify if the translation is correct. 
To verify the correctness of both the original Fortran code and the translated C++ code, we can write unit tests for each. These tests will involve setting up a specific scenario, calling the respective functions/subroutines, and then checking if the outputs are as expected.

### Fortran Unit Test

For the Fortran code, we'll write a simple program that calls `pinvr` and checks the results. We'll use a predefined set of inputs and compare the outputs against expected values.

```fortran
program test_pinvr
    use sp_data
    implicit none

    ! Test variables
    integer :: i, j, k
    double precision :: expected(5), actual(5)
    logical :: test_passed

    ! Initialize test data
    nx2 = 2
    ny2 = 2
    nz2 = 2
    bt = 1.0d0
    timeron = .true.

    ! Initialize rhs with some values
    do k = 1, nz2
        do j = 1, ny2
            do i = 1, nx2
                rhs(1, i, j, k) = 1.0d0
                rhs(2, i, j, k) = 2.0d0
                rhs(3, i, j, k) = 3.0d0
                rhs(4, i, j, k) = 4.0d0
                rhs(5, i, j, k) = 5.0d0
            end do
        end do
    end do

    ! Call the subroutine
    call pinvr

    ! Check results
    test_passed = .true.
    do k = 1, nz2
        do j = 1, ny2
            do i = 1, nx2
                ! Define expected values based on the Fortran code logic
                expected(1) = 1.0d0 * (4.0d0 - 5.0d0)
                expected(2) = -3.0d0
                expected(3) = 2.0d0
                expected(4) = -0.5d0 * (4.0d0 + 5.0d0) + 0.5d0 * (4.0d0 - 5.0d0)
                expected(5) = 0.5d0 * (4.0d0 + 5.0d0) + 0.5d0 * (4.0d0 - 5.0d0)

                actual(1) = rhs(1, i, j, k)
                actual(2) = rhs(2, i, j, k)
                actual(3) = rhs(3, i, j, k)
                actual(4) = rhs(4, i, j, k)
                actual(5) = rhs(5, i, j, k)

                do i = 1, 5
                    if (abs(actual(i) - expected(i)) > 1.0d-6) then
                        test_passed = .false.
                        exit
                    end if
                end do
                if (.not. test_passed) exit
            end do
            if (.not. test_passed) exit
        end do
        if (.not. test_passed) exit
    end do

    if (test_passed) then
        print *, "Test passed."
    else
        print *, "Test failed."
    end if

end program test_pinvr
```

### C++ Unit Test

For the C++ code, we'll use a similar approach, setting up a scenario, calling `pinvr`, and then checking the results.

```cpp
#include <iostream>
#include <cmath>
#include <vector>

// Assuming sp_data and the necessary functions are defined as in the previous C++ translation

bool test_pinvr() {
    // Initialize test data
    nx2 = 2;
    ny2 = 2;
    nz2 = 2;
    bt = 1.0;
    timeron = true;

    // Allocate and initialize rhs
    rhs = new double***[5];
    for (int i = 0; i < 5; ++i) {
        rhs[i] = new double**[nx2];
        for (int j = 0; j < nx2; ++j) {
            rhs[i][j] = new double*[ny2];
            for (int k = 0; k < ny2; ++k) {
                rhs[i][j][k] = new double[nz2];
                for (int l = 0; l < nz2; ++l) {
