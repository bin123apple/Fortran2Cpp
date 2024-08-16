To translate the given Fortran code to C++, we need to consider several aspects such as data types, array indexing, and parallelization. Fortran arrays are 1-based, while C++ arrays are 0-based. Also, Fortran's `real(dp)` type is equivalent to `double` in C++. Here's a C++ translation that maintains the structure and functionality of the original Fortran code:

```cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <omp.h>

class DRB058 {
public:
    static const int MSIZE = 200;
    static int n, m, mits;
    static double dx, dy, tol, relax, alpha;
    static std::vector<std::vector<double>> u, f, uold;

    static void initialize() {
        int i, j, xx, yy;

        n = MSIZE;
        m = MSIZE;
        tol = 0.0000000001;
        relax = 1.0;
        alpha = 0.0543;

        u.resize(MSIZE, std::vector<double>(MSIZE));
        f.resize(MSIZE, std::vector<double>(MSIZE));
        uold.resize(MSIZE, std::vector<double>(MSIZE));

        dx = 2.0 / static_cast<double>(n - 1);
        dy = 2.0 / static_cast<double>(m - 1);

        for (i = 0; i < n; ++i) {
            for (j = 0; j < m; ++j) {
                xx = static_cast<int>(-1.0 + dx * i);
                yy = static_cast<int>(-1.0 + dy * j);
                u[i][j] = 0.0;
                f[i][j] = -1.0 * alpha * (1.0 - xx * xx) * (1.0 - yy * yy) - 2.0 * (1.0 - xx * xx) - 2.0 * (1.0 - yy * yy);
            }
        }
    }

    static void jacobi() {
        double omega;
        int i, j, k;
        double error, resid, ax, ay, b;

        omega = relax;
        dx = 2.0 / static_cast<double>(n - 1);
        dy = 2.0 / static_cast<double>(m - 1);

        ax = 1.0 / (dx * dx); // X-direction coef
        ay = 1.0 / (dy * dy); // Y-direction coef
        b = -2.0 / (dx * dx) - 2.0 / (dy * dy) - alpha;

        error = 10.0 * tol;
        k = 1;

        while (k <= mits && error > tol) {
            error = 0.0;

            // Copy new solution into old
            #pragma omp parallel for collapse(2)
            for (i = 0; i < n; ++i) {
                for (j = 0; j < m; ++j) {
                    uold[i][j] = u[i][j];
                }
            }

            // Compute new solution
            #pragma omp parallel for collapse(2) reduction(+:error)
            for (i = 1; i < n - 1; ++i) {
                for (j = 1; j < m - 1; ++j) {
                    resid = (ax * (uold[i - 1][j] + uold[i + 1][j]) + ay * (uold[i][j - 1] + uold[i][j + 1]) + b * uold[i][j] - f[i][j]) / b;
                    u[i][j] = uold[i][j] - omega * resid;
                    error += resid * resid;
                }
            }

            // Error check
            error = sqrt(error) / (n * m);
            ++k;
        }

        std::cout << "Total number of iterations: " << k << std::endl;
        std::cout << "Residual: " << error << std::endl;
    }
};

int DRB058::n = 0;
int DRB058::m = 0;
int DRB058::mits = 1000;
double DRB058::dx = 0.0;
double DRB058::dy = 0.0;
double DRB058::tol = 0.0;
double DRB058::relax = 0.0;
double DRB058::alpha = 0.0;
std::vector<std::vector<double>> DRB058::u;
std::vector<std::vector<double>> DRB058::f;
std::vector<std::vector<double>> DRB058::uold;

int main() {
    DRB058::initialize();
    DRB058::jacobi();
    return 0;
}
```

Key Points in the Translation:

1. **Module to Class**: The Fortran module `DRB058` is translated to a C++ class `DRB058`. This encapsulates the variables and functions within a single cohesive unit.

2. **Arrays**: Fortran's array handling is replaced with C++'s `std::vector`. This provides dynamic array capabilities and is more idiomatic in C++.

3. **Data Types**: The Fortran `real(dp)` type is translated to `double` in C++.

4. **Parallelization**: The OpenMP directives are used in C++ to parallelize the loops. This is a direct translation of the Fortran code's parallelization.

5. **Indexing**: Adjusted to C++'s 0-based indexing.

6. **I/O Operations**: Uses `std::cout` for output.

7. **Math Functions**: Uses `sqrt` from `<cmath>` for the square root calculation.

8. **Program Structure**: The `main` function initializes the class and calls the `initialize` and `jacobi` methods, mimicking the Fortran program's structure.

This translation aims to maintain the original code's logic and structure while adapting it to C++ conventions and practices.
Let's write some test to verify if the translation is correct. 
To verify the correctness of both the original Fortran code and the translated C++ code, we can create simple unit tests. These tests will run the `initialize` and `jacobi` methods and check if the residual is within an acceptable tolerance.

### Fortran Unit Test

For the Fortran code, we can add a test subroutine in the module and call it from the main program.

```fortran
! Add this inside the module DRB058
subroutine test()
    call initialize()
    call jacobi()
    ! Here you would typically check the results and print a success message if the test passes
    ! For simplicity, we'll just print the residual for manual verification
    print *, "Residual: ", error
    ! Here you would check if error < tolerance and print a success message if true
end subroutine

! Main program
program DRB058_jacobikernel_orig_no
    use omp_lib
    use DRB058
    implicit none

    call test()
end program
```

### C++ Unit Test

For the C++ code, we can use a simple test function that calls the `initialize` and `jacobi` methods and checks the residual.

```cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <omp.h>

// Include the DRB058 class definition here

void test() {
    DRB058::initialize();
    DRB058::jacobi();
    // Here you would typically check the results and print a success message if the test passes
    // For simplicity, we'll just print the residual for manual verification
    std::cout << "Residual: " << error << std::endl;
    // Here you would check if error < tolerance and print a success message if true
}

int main() {
    test();
    return
