To translate the given Fortran code to C++, we need to consider several aspects, including the syntax differences between Fortran and C++, the array indexing, and the way functions (or subroutines in Fortran) are defined and called. Here's a C++ version of the Fortran code provided:

```cpp
#include <cmath>
#include <vector>

// Assuming bt_data is a header file containing the necessary declarations
#include "bt_data.h"

// Function prototypes
void error_norm(std::vector<double>& rms);
void rhs_norm(std::vector<double>& rms);

void error_norm(std::vector<double>& rms) {
    int i, j, k, m, d;
    double xi, eta, zeta, u_exact[5], add;

    // Initialize rms
    for (m = 1; m <= 5; ++m) {
        rms[m-1] = 0.0;
    }

    for (k = 0; k < grid_points[3] - 1; ++k) {
        zeta = static_cast<double>(k) * dnzm1;
        for (j = 0; j < grid_points[2] - 1; ++j) {
            eta = static_cast<double>(j) * dnym1;
            for (i = 0; i < grid_points[1] - 1; ++i) {
                xi = static_cast<double>(i) * dnxm1;
                exact_solution(xi, eta, zeta, u_exact);

                for (m = 1; m <= 5; ++m) {
                    add = u[m][i][j][k] - u_exact[m-1];
                    rms[m-1] += add * add;
                }
            }
        }
    }

    for (m = 1; m <= 5; ++m) {
        for (d = 1; d <= 3; ++d) {
            rms[m-1] /= static_cast<double>(grid_points[d] - 2);
        }
        rms[m-1] = std::sqrt(rms[m-1]);
    }
}

void rhs_norm(std::vector<double>& rms) {
    int i, j, k, d, m;
    double add;

    // Initialize rms
    for (m = 1; m <= 5; ++m) {
        rms[m-1] = 0.0;
    }

    for (k = 1; k < grid_points[3] - 2; ++k) {
        for (j = 1; j < grid_points[2] - 2; ++j) {
            for (i = 1; i < grid_points[1] - 2; ++i) {
                for (m = 1; m <= 5; ++m) {
                    add = rhs[m][i][j][k];
                    rms[m-1] += add * add;
                }
            }
        }
    }

    for (m = 1; m <= 5; ++m) {
        for (d = 1; d <= 3; ++d) {
            rms[m-1] /= static_cast<double>(grid_points[d] - 2);
        }
        rms[m-1] = std::sqrt(rms[m-1]);
    }
}

// Note: The exact_solution function and the global variables (grid_points, dnxm1, dnym1, dnzm1, u, rhs)
// must be defined in the "bt_data.h" header file and appropriately initialized or passed to these functions.
```

This C++ code assumes that `bt_data.h` contains the necessary declarations and definitions for the global variables and functions used in the Fortran code. The `exact_solution` function must be implemented according to your specific requirements. The arrays `u` and `rhs` are assumed to be 4-dimensional arrays (or at least 3-dimensional arrays if you're using a single index for the 4th dimension). The `grid_points` array is assumed to be a global variable that holds the dimensions of the grids. The `dnxm1`, `dnym1`, and `dnzm1` are also assumed to be global variables representing the step sizes in the x, y, and z directions, respectively.

Please adjust the function and variable names as necessary to match your actual implementation details.
Let's write some test to verify if the translation is correct. 
Creating unit tests for both the Fortran and C++ versions of the code requires a bit of setup. For simplicity, I'll provide a basic structure for unit testing in both languages, focusing on the `error_norm` subroutine/function. Note that for the `rhs_norm` function, the setup would be similar but would need to be adapted to the specifics of your implementation.

### Fortran Unit Test

For Fortran, we'll use a simple program that calls the `error_norm` subroutine and checks the results. This example assumes you have a Fortran compiler like `gfortran`.

```fortran
program test_error_norm
    use bt_data
    implicit none
    double precision rms(5)
    integer i

    ! Initialize global variables and arrays for testing
    ! This part is specific to your implementation, so you might need to adjust it.
    grid_points = (/10, 10, 10, 5/)
    dnxm1 = 1.0d0 / 9.0d0
    dnym1 = 1.0d0 / 9.0d0
    dnzm1 = 1.0d0 / 9.0d0
    ! Initialize u and rhs arrays with test data
    ! This part is also specific to your implementation.

    call error_norm(rms)

    print *, "RMS Norms:"
    do i = 1, 5
        print *, "RMS(", i, ") = ", rms(i)
    end do
end program test_error_norm
```

### C++ Unit Test

For C++, we'll use a simple test case similar to the Fortran one, but adapted to C++ conventions. This example assumes you have a C++ compiler like `g++`.

```cpp
#include <iostream>
#include <vector>
#include "bt_data.h" // Include your header file

void test_error_norm() {
    std::vector<double> rms(5);

    // Initialize global variables and arrays for testing
    // This part is specific to your implementation, so you might need to adjust it.
    grid_points = {10, 10, 10, 5};
    dnxm1 = 1.0 / 9.0;
    dnym1 = 1.0 / 9.0;
    dnzm1 = 1.0 / 9.0;
    // Initialize u and rhs arrays with test data
    // This part is also specific to your implementation.

    error_norm(rms);

    std::cout << "RMS Norms:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << "RMS(" << i+1 << ") = " << rms[i] << std::endl;
    }
}

int main() {
    test_error_norm();
    return 0;
}
```

### Notes

1. **Global Variables and Arrays Initialization**: The setup for global variables and arrays (`grid_points`, `dnxm1`, `dnym1`, `dnzm1`, `u`, `rhs`) needs to be adapted to match your specific use case. These include setting the dimensions of the grids and initializing the step sizes, as well as the `u` and `rhs` arrays with test data.

2. **Testing Frameworks**: For more comprehensive testing, consider using testing frameworks like `GoogleTest` for C++ or `FRUIT` for Fortran. These frameworks provide more features and better structure for writing and organizing tests.

3. **Precision and Comparison**: When comparing floating-point numbers, consider using a tolerance for equality checks, as direct comparison might not work due to precision differences.

4. **Functionality Coverage**: The provided tests are basic
