To translate the given Fortran code to C++, we need to consider several aspects, including array indexing, function calls, and the loop structures. Fortran arrays are 1-based, while C++ arrays are 0-based. Also, Fortran passes arrays to functions/subroutines by reference automatically, while in C++ we need to explicitly use pointers or references. Given the nature of the Fortran code, we'll use a 4D array (or a pointer to a 4D array) to represent the `rhs` array, assuming it's accessible in the same way in C++.

Here's a C++ version of the code, assuming `rhs` is a 4D array with dimensions `[5][nx2][ny2][nz2]`:

```cpp
#include <iostream>

// Assuming sp_data.h or similar includes the necessary definitions
#include "sp_data.h"

// Assuming timer_start and timer_stop are functions defined elsewhere
extern void timer_start(int t_ninvr);
extern void timer_stop(int t_ninvr);

// Assuming rhs is a 4D array accessible in the same way in C++
extern double*** rhs;

// Assuming nx2, ny2, nz2, bt, and timeron are defined somewhere
extern int nx2, ny2, nz2;
extern double bt;
extern bool timeron;

void ninvr() {
    double r1, r2, r3, r4, r5, t1, t2;

    if (timeron) timer_start(t_ninvr);

    for (int k = 0; k < nz2; ++k) {
        for (int j = 0; j < ny2; ++j) {
            for (int i = 0; i < nx2; ++i) {
                r1 = rhs[0][i][j][k];
                r2 = rhs[1][i][j][k];
                r3 = rhs[2][i][j][k];
                r4 = rhs[3][i][j][k];
                r5 = rhs[4][i][j][k];

                t1 = bt * r3;
                t2 = 0.5 * (r4 + r5);

                rhs[0][i][j][k] = -r2;
                rhs[1][i][j][k] = r1;
                rhs[2][i][j][k] = bt * (r4 - r5);
                rhs[3][i][j][k] = -t1 + t2;
                rhs[4][i][j][k] = t1 + t2;
            }
        }
    }

    if (timeron) timer_stop(t_ninvr);
}

int main() {
    // Example usage of ninvr
    ninvr();
    return 0;
}
```

This C++ code assumes that `sp_data.h` contains the necessary definitions for `nx2`, `ny2`, `nz2`, `bt`, and `timeron`. The `rhs` array is assumed to be accessible in the same way as in the Fortran code, with dimensions `[5][nx2][ny2][nz2]`. The `timer_start` and `timer_stop` functions are assumed to be defined elsewhere, possibly in another file.
Let's write some test to verify if the translation is correct. 
To verify the correctness of both the original Fortran code and the translated C++ code, we can write unit tests for each. These tests will involve setting up a specific scenario and then checking if the output matches the expected results.

### Fortran Unit Test

For the Fortran code, we'll write a simple program that calls the `ninvr` subroutine and checks the results. We'll use a predefined scenario for simplicity.

```fortran
program test_ninvr
    use sp_data
    implicit none

    ! Define test scenario
    nx2 = 2
    ny2 = 2
    nz2 = 2
    bt = 1.0
    timeron = .true.

    ! Allocate and initialize rhs array
    allocate(rhs(5, nx2, ny2, nz2))
    rhs(1, 1, 1, 1) = 1.0
    rhs(2, 1, 1, 1) = 2.0
    rhs(3, 1, 1, 1) = 3.0
    rhs(4, 1, 1, 1) = 4.0
    rhs(5, 1, 1, 1) = 5.0

    ! Call the subroutine
    call ninvr

    ! Output results for manual verification
    print *, 'rhs(1,1,1,1) = ', rhs(1, 1, 1, 1)
    print *, 'rhs(2,1,1,1) = ', rhs(2, 1, 1, 1)
    print *, 'rhs(3,1,1,1) = ', rhs(3, 1, 1, 1)
    print *, 'rhs(4,1,1,1) = ', rhs(4, 1, 1, 1)
    print *, 'rhs(5,1,1,1) = ', rhs(5, 1, 1, 1)

    ! Clean up
    deallocate(rhs)
end program test_ninvr
```

### C++ Unit Test

For the C++ code, we'll write a similar test that initializes a scenario and checks the results.

```cpp
#include <iostream>
#include <cassert>
#include <cmath>

// Include or define the necessary variables and functions
#include "sp_data.h"
#include "ninvr.h" // Assuming the translated function is in this header

void test_ninvr() {
    // Define test scenario
    nx2 = 2;
    ny2 = 2;
    nz2 = 2;
    bt = 1.0;
    timeron = true;

    // Allocate and initialize rhs array
    rhs = new double***[5];
    for (int i = 0; i < 5; ++i) {
        rhs[i] = new double**[nx2];
        for (int j = 0; j < nx2; ++j) {
            rhs[i][j] = new double*[ny2];
            for (int k = 0; k < ny2; ++k) {
                rhs[i][j][k] = new double[nz2];
            }
        }
    }

    rhs[0][0][0][0] = 1.0;
    rhs[1][0][0][0] = 2.0;
    rhs[2][0][0][0] = 3.0;
    rhs[3][0][0][0] = 4.0;
    rhs[4][0][0][0] = 5.0;

    // Call the function
    ninvr();

    // Output results for manual verification
    std::cout << "rhs[0][0][0][0] = " << rhs[0][0][0][0] << std::endl;
    std::cout << "rhs[1][0][0][0] = " << rhs[1][0][0][0] << std::endl;
    std::cout << "rhs[2][0][0][0] = " << rhs[2][0][0][0] << std::endl;
    std::cout << "rhs[3][0][0][0] = " << rhs[3][0][0][0] << std::endl;
    std::cout << "rhs[4][0][0][0] = " << rhs[4][0][0][0] << std::endl;

    // Clean up
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < nx2; ++j) {
            for (int k = 0; k < ny2; ++k) {
                delete[] rhs[i][j][k];
            }
            delete[] rhs[i][j];
