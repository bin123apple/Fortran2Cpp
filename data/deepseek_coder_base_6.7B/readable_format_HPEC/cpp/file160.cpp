To translate the given Fortran code to C++, we need to consider several aspects, including the syntax differences between Fortran and C++, the data types, and the loop structures. Here's a C++ version of the Fortran code:

```cpp
#include <cmath>
#include <iostream>
#include <iomanip>

// Assuming the existence of a header file for the data and the exact function declaration
#include "lu_data.h"

void error() {
    int i, j, k, m;
    double tmp;
    double u000ijk[5];

    // Initializing errnm array
    for (m = 1; m <= 5; ++m) {
        errnm[m-1] = 0.0;
    }

    // Main loop
    for (k = 2; k <= nz-1; ++k) {
        for (j = jst; j <= jend; ++j) {
            for (i = ist; i <= iend; ++i) {
                exact(i, j, k, u000ijk); // Assuming this function is defined elsewhere
                for (m = 1; m <= 5; ++m) {
                    tmp = (u000ijk[m-1] - u[m-1][i-1][j-1][k-1]); // Adjusting indices for 0-based indexing
                    errnm[m-1] += tmp * tmp;
                }
            }
        }
    }

    // Final step to compute the RMS norm
    for (m = 1; m <= 5; ++m) {
        errnm[m-1] = sqrt(errnm[m-1] / (static_cast<double>(nx0-2) * (ny0-2) * (nz0-2)));
    }

    // Printing the results
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "RMS-norm of error in soln. to first pde  = " << errnm[0] << std::endl;
    std::cout << "RMS-norm of error in soln. to second pde = " << errnm[1] << std::endl;
    std::cout << "RMS-norm of error in soln. to third pde  = " << errnm[2] << std::endl;
    std::cout << "RMS-norm of error in soln. to fourth pde = " << errnm[3] << std::endl;
    std::cout << "RMS-norm of error in soln. to fifth pde  = " << errnm[4] << std::endl;
}

```

### Key Points:

1. **Data Types and Arrays**: The Fortran code uses 1-based indexing for arrays and variables. In C++, we use 0-based indexing, so adjustments are made accordingly.

2. **Function Calls**: The `exact` function is assumed to be defined elsewhere in the C++ codebase. You might need to include or define this function based on its Fortran counterpart.

3. **Loops**: The Fortran `do` loops are translated to C++ `for` loops.

4. **Output**: The results are printed to the standard output using `std::cout` and formatted using `std::fixed` and `std::setprecision` for better readability.

5. **Math Functions**: The `sqrt` function from the `<cmath>` library is used to compute the square root.

6. **Header File**: The `lu_data.h` header file is assumed to contain declarations for the global variables and the `exact` function. You might need to adjust or add these declarations based on your actual implementation.

This translation assumes that the global variables and the `exact` function are correctly defined and accessible in the C++ code. Adjustments may be necessary depending on the specifics of your project's implementation.
Let's write some test to verify if the translation is correct. 
To verify the correctness of both the original Fortran code and the translated C++ code, we can create simple unit tests. These tests will execute the `error` subroutine/function and check if the output matches expected values.

### Fortran Unit Test

For the Fortran code, we can write a simple program that calls the `error` subroutine and prints the results. We'll need to include the necessary modules and define some global variables for the test.

```fortran
program test_error
    use lu_data
    implicit none

    ! Define global variables for the test
    integer :: nx0, ny0, nz0, ist, jst, iend, jend, nz
    double precision :: errnm(5)
    double precision :: u(5, 5, 5, 5) ! Example dimensions

    ! Initialize variables
    nx0 = 5
    ny0 = 5
    nz0 = 5
    ist = 1
    jst = 1
    iend = 5
    jend = 5
    nz = 5

    ! Assuming the exact function is defined elsewhere
    ! For this test, we'll just fill u with some values
    u(1, 1, 1, 1) = 1.0d0
    u(2, 1, 1, 1) = 2.0d0
    u(3, 1, 1, 1) = 3.0d0
    u(4, 1, 1, 1) = 4.0d0
    u(5, 1, 1, 1) = 5.0d0

    ! Call the error subroutine
    call error()

    ! Print the results
    print *, 'Error Norms:'
    print *, errnm

end program test_error
```

### C++ Unit Test

For the C++ code, we can write a similar test. We'll include the necessary headers and define some global variables for the test.

```cpp
#include <iostream>
#include <cmath>
#include <iomanip>
#include "lu_data.h" // Assuming this header file exists

// Global variables for the test
int nx0 = 5, ny0 = 5, nz0 = 5, ist = 1, jst = 1, iend = 5, jend = 5, nz = 5;
double errnm[5];
double u[5][5][5][5]; // Example dimensions

void error(); // Assuming the error function is declared here

int main() {
    // Initialize u with some values
    for (int m = 1; m <= 5; ++m) {
        for (int i = 1; i <= 5; ++i) {
            for (int j = 1; j <= 5; ++j) {
                for (int k = 1; k <= 5; ++k) {
                    u[m-1][i-1][j-1][k-1] = static_cast<double>(m);
                }
            }
        }
    }

    // Call the error function
    error();

    // Print the results
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Error Norms:" << std::endl;
    for (int m = 1; m <= 5; ++m) {
        std::cout << "errnm(" << m << ") = " << errnm[m-1] << std::endl;
    }

    return 0;
}
```

### Explanation

1. **Initialization**: Both tests initialize the necessary variables and the `u` array with some values.
2. **Calling the Error Function**: The tests call the `error` subroutine/function.
3. **Printing the Results**: The tests print the `errnm` array to verify the correctness of the computation.

### Running the Tests

To run the Fortran test, you'll need a Fortran compiler like `gfortran`. Compile and run the Fortran test program using:

```sh
gfortran -o test_error test_error.f90
./test_error
```

For the C++ test, you'll need a C++ compiler like `g++`. Compile and run the C++ test program using:

```sh
g++ -o test_error test_error.cpp
./test_error
```

### Note

These tests are very basic and assume that the `exact` function and the global variables are correctly defined and
