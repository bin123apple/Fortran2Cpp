Certainly! Below is the translated Fortran code to C++. Note that in the translation, I'm assuming that the `sp_data` module contains the necessary variables and functions that are used in the Fortran code. You will need to ensure that these are properly defined in your C++ code as well.

```cpp
#include <cmath>
#include <array>

// Assuming sp_data module contains the necessary variables and functions
extern std::array<int, 3> grid_points; // Example declaration, replace with actual declaration from sp_data
extern std::array<double, 5> u; // Example declaration, replace with actual declaration from sp_data
extern std::array<double, 5> rhs; // Example declaration, replace with actual declaration from sp_data
extern double dnxm1, dnym1, dnzm1; // Example declaration, replace with actual declaration from sp_data

// Assuming exact_solution function is defined elsewhere
extern void exact_solution(double xi, double eta, double zeta, std::array<double, 5>& u_exact);

void error_norm(std::array<double, 5>& rms) {
    int i, j, k, m;
    double xi, eta, zeta, add;
    std::array<double, 5> u_exact;

    for (m = 1; m <= 5; ++m) {
        rms[m-1] = 0.0;
    }

    for (k = 0; k < grid_points[2] - 1; ++k) {
        for (j = 0; j < grid_points[1] - 1; ++j) {
            zeta = static_cast<double>(k) * dnzm1;
            eta = static_cast<double>(j) * dnym1;
            for (i = 0; i < grid_points[0] - 1; ++i) {
                xi = static_cast<double>(i) * dnxm1;
                exact_solution(xi, eta, zeta, u_exact);

                for (m = 1; m <= 5; ++m) {
                    add = u[m-1][i][j][k] - u_exact[m-1];
                    rms[m-1] += add * add;
                }
            }
        }
    }

    for (m = 1; m <= 5; ++m) {
        for (int d = 1; d <= 3; ++d) {
            rms[m-1] /= static_cast<double>(grid_points[d-1] - 2);
        }
        rms[m-1] = std::sqrt(rms[m-1]);
    }
}

void rhs_norm(std::array<double, 5>& rms) {
    int i, j, k, m;
    double add;

    for (m = 1; m <= 5; ++m) {
        rms[m-1] = 0.0;
    }

    for (k = 1; k <= nz2; ++k) {
        for (j = 1; j <= ny2; ++j) {
            for (i = 1; i <= nx2; ++i) {
                for (m = 1; m <= 5; ++m) {
                    add = rhs[m-1][i][j][k];
                    rms[m-1] += add * add;
                }
            }
        }
    }

    for (m = 1; m <= 5; ++m) {
        for (int d = 1; d <= 3; ++d) {
            rms[m-1] /= static_cast<double>(grid_points[d-1] - 2);
        }
        rms[m-1] = std::sqrt(rms[m-1]);
    }
}
```

This translation assumes that the `u` array and `rhs` array are defined with the correct dimensions and that the `exact_solution` function is properly declared and defined elsewhere in your C++ code. The `grid_points` array and the other variables (`dnxm1`, `dnym1`, `dnzm1`) should also be defined and initialized appropriately.
Let's write some test to verify if the translation is correct. 
Below are examples of unit tests for both the original Fortran code and the translated C++ code. These tests will help verify that the translation is correct by comparing the outputs of both implementations.

### Fortran Unit Test

For the Fortran code, you can create a simple program that calls the `error_norm` and `rhs_norm` subroutines and prints the results. Here's an example:

```fortran
program test_norms
    use sp_data
    implicit none

    double precision rms(5)

    ! Initialize variables as needed
    ! For example:
    grid_points = (/10, 10, 10/)
    dnxm1 = 0.1
    dnym1 = 0.1
    dnzm1 = 0.1

    ! Call the subroutines
    call error_norm(rms)
    print *, 'Error norm:', rms

    call rhs_norm(rms)
    print *, 'RHS norm:', rms

end program test_norms
```

### C++ Unit Test

For the C++ code, you can use a simple main function to call the `error_norm` and `rhs_norm` functions and print the results. Here's an example:

```cpp
#include <iostream>
#include <array>

// Include or define the necessary variables and functions
// For example:
std::array<int, 3> grid_points = {10, 10, 10};
double dnxm1 = 0.1, dnym1 = 0.1, dnzm1 = 0.1;
std::array<std::array<std::array<std::array<double, 5>, 10>, 10>, 10> u;
std::array<std::array<std::array<std::array<double, 5>, 10>, 10>, 10> rhs;

// Assuming the error_norm and rhs_norm functions are defined as shown in the previous response

int main() {
    std::array<double, 5> rms;

    // Initialize u and rhs arrays as needed
    // For example:
    // Initialize u and rhs arrays with some values

    error_norm(rms);
    std::cout << "Error norm: ";
    for (auto val : rms) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    rhs_norm(rms);
    std::cout << "RHS norm: ";
    for (auto val : rms) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

### Notes:

1. **Initialization**: Ensure that the `grid_points`, `dnxm1`, `dnym1`, `dnzm1`, and `u` arrays are initialized with appropriate values before calling the `error_norm` and `rhs_norm` functions.

2. **Comparison**: After running both the Fortran and C++ tests, compare the output of the `error_norm` and `rhs_norm` functions. They should be very close, allowing for minor differences due to floating-point arithmetic differences.

3. **Precision**: The precision of floating-point arithmetic can lead to very minor differences, but these should be negligible for practical purposes.

4. **Implementation Details**: The actual implementation details of the `exact_solution` function and the initialization of the `u` and `rhs` arrays are not provided here, so ensure they are correctly implemented and initialized in your test environment.

This approach provides a basic framework for testing the correctness of the translation by comparing the outputs of both implementations.
