To translate the given Fortran code to C++, we need to consider several aspects, including array indexing, memory allocation, and OpenMP directives. Fortran arrays are 1-based, while C++ arrays are 0-based. We'll use `std::vector` from the C++ Standard Library for dynamic arrays, and OpenMP will be used similarly to the Fortran code.

Here's the translated C++ code:

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

const double dp = 1.0; // Assuming double precision

class DRB057 {
public:
    int MSIZE;
    int n, m, mits;
    double dx, dy, tol, relax, alpha;
    std::vector<std::vector<double>> u, f, uold;

    void initialize() {
        MSIZE = 200;
        mits = 1000;
        relax = 1.0;
        alpha = 0.0543;
        n = MSIZE;
        m = MSIZE;

        u.resize(MSIZE, std::vector<double>(MSIZE));
        f.resize(MSIZE, std::vector<double>(MSIZE));
        uold.resize(MSIZE, std::vector<double>(MSIZE));

        dx = 2.0 / static_cast<double>(n - 1);
        dy = 2.0 / static_cast<double>(m - 1);

        // Initialize initial condition and RHS
        #pragma omp parallel for collapse(2)
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int xx = static_cast<int>(-1.0 + dx * i);
                int yy = static_cast<int>(-1.0 + dy * j);
                u[i][j] = 0.0;
                f[i][j] = -1.0 * alpha * (1.0 - xx * xx) * (1.0 - yy * yy) - 2.0 * (1.0 - xx * xx) - 2.0 * (1.0 - yy * yy);
            }
        }
    }
};

int main() {
    DRB057 drb057;
    drb057.initialize();

    return 0;
}
```

Key Points:
- We use `std::vector<std::vector<double>>` to represent the 2D arrays `u`, `f`, and `uold`.
- The `#pragma omp parallel for collapse(2)` directive is used to parallelize the nested loops, similar to the Fortran code.
- The `static_cast<double>()` and `static_cast<int>()` are used to convert between integer and double types, respectively.
- The `dx` and `dy` calculations are adjusted to match C++'s 0-based indexing.
- The `MSIZE`, `n`, `m`, `mits`, `dx`, `dy`, `tol`, `relax`, and `alpha` variables are initialized within the `initialize` method.
- The `main` function creates an instance of `DRB057` and calls the `initialize` method.

This C++ code should provide similar functionality to the original Fortran code, with adjustments for C++ syntax and conventions.
Let's write some test to verify if the translation is correct. 
To verify the correctness of both the original Fortran code and the translated C++ code, we can create simple unit tests. These tests will check if the initialization of the arrays `u`, `f`, and `uold` is performed correctly.

### Fortran Unit Test

For the Fortran code, we'll add a simple test procedure within the same module or in a separate module and call it from the main program.

```fortran
module DRB057_test
    use DRB057
    implicit none
contains
    subroutine test_initialize()
        integer :: i, j
        logical :: test_passed

        call initialize()

        test_passed = .true.
        do i = 1, n
            do j = 1, m
                if (u(i, j) /= 0.0 .or. f(i, j) /= -1.0 * alpha * (1.0 - (-1.0 + dx * (i - 1))**2) * (1.0 - (-1.0 + dy * (j - 1))**2) - 2.0 * (1.0 - (-1.0 + dx * (i - 1))**2) - 2.0 * (1.0 - (-1.0 + dy * (j - 1))**2)) then
                    test_passed = .false.
                    exit
                endif
            end do
            if (.not. test_passed) exit
        end do

        if (test_passed) then
            print *, "Test passed."
        else
            print *, "Test failed."
        endif
    end subroutine
end module

program test
    use DRB057_test
    implicit none

    call test_initialize()
end program
```

### C++ Unit Test

For the C++ code, we'll use a simple test function within the `main` function.

```cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <omp.h>

const double dp = 1.0; // Assuming double precision

class DRB057 {
public:
    int MSIZE;
    int n, m, mits;
    double dx, dy, tol, relax, alpha;
    std::vector<std::vector<double>> u, f, uold;

    void initialize() {
        MSIZE = 200;
        mits = 1000;
        relax = 1.0;
        alpha = 0.0543;
        n = MSIZE;
        m = MSIZE;

        u.resize(MSIZE, std::vector<double>(MSIZE));
        f.resize(MSIZE, std::vector<double>(MSIZE));
        uold.resize(MSIZE, std::vector<double>(MSIZE));

        dx = 2.0 / static_cast<double>(n - 1);
        dy = 2.0 / static_cast<double>(m - 1);

        #pragma omp parallel for collapse(2)
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int xx = static_cast<int>(-1.0 + dx * i);
                int yy = static_cast<int>(-1.0 + dy * j);
                u[i][j] = 0.0;
                f[i][j] = -1.0 * alpha * (1.0 - xx * xx) * (1.0 - yy * yy) - 2.0 * (1.0 - xx * xx) - 2.0 * (1.0 - yy * yy);
            }
        }
    }
};

bool test_initialize() {
    DRB057 drb057;
    drb057.initialize();

    for (int i = 0; i < drb057.n; ++i) {
        for (int j = 0; j < drb057.m; ++j) {
            double xx = -1.0 + drb057.dx * i;
            double yy = -1.0 + drb057.dy * j;
            if (drb057.u[i][j] != 0.0 || drb057.f[i][j] != -1.0 * drb057.alpha * (1.0 - xx * xx) * (1.0 - yy * yy) - 2.0 * (1.0 - xx * xx) - 2.0 * (1.0 - yy * yy)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    if (test_initialize()) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::
