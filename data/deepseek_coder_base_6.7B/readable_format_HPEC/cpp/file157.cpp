To translate the given Fortran code to C++, we need to consider several aspects, including array indexing, function calls, and I/O formatting. Fortran arrays are 1-based, while C++ arrays are 0-based. Also, Fortran passes arrays and other arguments by reference by default, while in C++, we need to explicitly use pointers or references. Here's a C++ version of the code, assuming the use of a 3D array and the `norm2u3` function is defined elsewhere:

```cpp
#include <iostream>
#include <iomanip> // For std::setprecision

// Assuming mg_data.h contains the definitions of nx, ny, nz, and norm2u3
#include "mg_data.h"

// Assuming the definition of norm2u3 is something like this:
// void norm2u3(double*** u, int n1, int n2, int n3, double& rnm2, double& rnmu, int nx, int ny, int nz);

void rep_nrm(double*** u, int n1, int n2, int n3, const char* title, int kk) {
    double rnm2, rnmu;

    // Call the function with the correct parameters
    norm2u3(u, n1, n2, n3, rnm2, rnmu, nx[kk-1], ny[kk-1], nz[kk-1]); // Adjusting for 0-based indexing

    // Output the results
    std::cout << " Level" << std::setw(2) << kk << " in " << std::left << std::setw(8) << title << ": norms = "
              << std::setprecision(14) << rnm2 << std::setprecision(14) << rnmu << std::endl;
}

// Note: The definition of nx, ny, nz, and norm2u3 must be available in the context of this translation.
```

This translation assumes that `mg_data.h` contains the definitions for `nx`, `ny`, `nz`, and `norm2u3`. The `norm2u3` function is assumed to be a C++ function that operates on a 3D array and computes two norms, storing them in `rnm2` and `rnmu`. The `nx`, `ny`, and `nz` arrays are assumed to be accessible globally or passed as additional parameters to `rep_nrm`.

Please adjust the `#include "mg_data.h"` and the function signature of `norm2u3` according to your actual implementation details. Also, ensure that the `nx`, `ny`, and `nz` arrays are correctly defined and accessible in your C++ code.
Let's write some test to verify if the translation is correct. 
To verify the correctness of both the original Fortran code and the translated C++ code, we can create simple unit tests. These tests will execute the `rep_nrm` subroutine/function with a predefined set of inputs and check if the outputs match expected values.

### Fortran Unit Test

For the Fortran code, we'll write a simple program that calls `rep_nrm` with a predefined set of parameters. We'll assume that `norm2u3` is a function that we can mock for testing purposes.

First, let's define a mock version of `norm2u3` in a separate module for testing purposes:

```fortran
! mock_norm2u3.f90
module mock_norm2u3_mod
    implicit none
contains
    subroutine norm2u3(u, n1, n2, n3, rnm2, rnmu, nx, ny, nz)
        integer, intent(in) :: n1, n2, n3, nx, ny, nz
        double precision, intent(in) :: u(n1, n2, n3)
        double precision, intent(out) :: rnm2, rnmu

        ! Mock implementation - just set values for testing
        rnm2 = 1.0
        rnmu = 2.0
    end subroutine norm2u3
end module mock_norm2u3_mod
```

Now, let's write the test program:

```fortran
! test_rep_nrm.f90
program test_rep_nrm
    use mock_norm2u3_mod
    implicit none

    double precision, allocatable :: u(:,:,:)
    integer :: n1, n2, n3, kk
    character(len=8) :: title

    ! Initialize test parameters
    n1 = 2; n2 = 2; n3 = 2
    allocate(u(n1,n2,n3))
    u = 0.0
    kk = 1
    title = 'TestTitle'

    ! Call the subroutine
    call rep_nrm(u, n1, n2, n3, title, kk)

    ! Clean up
    deallocate(u)
end program test_rep_nrm
```

To compile and run the Fortran test (assuming your Fortran compiler is `gfortran` and your files are named appropriately):

```sh
gfortran -o test_rep_nrm mock_norm2u3.f90 test_rep_nrm.f90
./test_rep_nrm
```

### C++ Unit Test

For the C++ code, we can use a simple testing framework like Google Test. However, for simplicity, I'll provide a basic example without a framework.

First, let's define a mock version of `norm2u3` in a separate file for testing purposes:

```cpp
// mock_norm2u3.cpp
#include <iostream>

void norm2u3(double*** u, int n1, int n2, int n3, double& rnm2, double& rnmu, int nx, int ny, int nz) {
    // Mock implementation - just set values for testing
    rnm2 = 1.0;
    rnmu = 2.0;
}
```

Now, let's write the test program:

```cpp
// test_rep_nrm.cpp
#include <iostream>
#include <iomanip>
#include <cassert>
#include "mock_norm2u3.cpp" // Include the mock implementation

// Assuming the definition of rep_nrm is available here
void rep_nrm(double*** u, int n1, int n2, int n3, const char* title, int kk);

int main() {
    double*** u; // Mock 3D array
    int n1 = 2, n2 = 2, n3 = 2;
    const char* title = "TestTitle";
    int kk = 1;

    // Initialize the 3D array (mock)
    u = new double**[n1];
    for (int i = 0; i < n1; ++i) {
        u[i] = new double*[n2];
        for (int j = 0; j < n2; ++j) {
            u[i][j] = new double[n3];
            for (int k = 0; k < n3; ++k) {
                u[i][j][k] = 0.0;
            }
        }
    }

    // Call the function
    rep_nrm(u, n1, n2, n3, title, kk);

    // Clean up
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            delete[] u[i][j];
        }
        delete[] u[i];
    }
    delete[] u;

    return 0;
}
```

To compile and run the C++ test (assuming your compiler is `g++` and your files are named appropriately):

```sh
g++ -o test_rep_nrm test_rep_nrm.cpp
./test_rep_nrm
```

### Note

These tests are very basic and primarily check if the program runs without errors. In a real-world scenario, you would want to verify the correctness of the output against expected values, which would require more sophisticated testing frameworks and possibly mocking of external dependencies.
