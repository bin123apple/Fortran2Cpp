Sure, here's the equivalent C++ code for the provided Fortran subroutine. Note that in C++, array indices start from 0, unlike Fortran where they start from 1. Also, multidimensional arrays in C++ are typically stored in row-major order, unlike Fortran which uses column-major order. This translation assumes that the arrays `rho_i`, `us`, `vs`, `ws`, `speed`, `qs`, and `rhs` are all 3D arrays with dimensions `nx2`, `ny2`, and `nz2`, respectively.

```cpp
#include <vector>

// Assuming the existence of these functions or variables
extern bool timeron;
extern void timer_start(double& t_txinvr);
extern void timer_stop(double& t_txinvr);

// Assuming these are defined somewhere
const double c2 = 0.0; // Example value, replace with actual value
const double bt = 0.0; // Example value, replace with actual value

void txinvr(std::vector<std::vector<std::vector<double>>>& rho_i,
            std::vector<std::vector<std::vector<double>>>& us,
            std::vector<std::vector<std::vector<double>>>& vs,
            std::vector<std::vector<std::vector<double>>>& ws,
            std::vector<std::vector<std::vector<double>>>& speed,
            std::vector<std::vector<std::vector<double>>>& qs,
            std::vector<std::vector<std::vector<std::vector<double>>>>& rhs,
            int nx2, int ny2, int nz2) {
    double t1, t2, t3, ac, ru1, uu, vv, ww, r1, r2, r3, r4, r5, ac2inv;

    if (timeron) {
        double t_txinvr;
        timer_start(t_txinvr);
        for (int k = 0; k < nz2; ++k) {
            for (int j = 0; j < ny2; ++j) {
                for (int i = 0; i < nx2; ++i) {
                    ru1 = rho_i[i][j][k];
                    uu = us[i][j][k];
                    vv = vs[i][j][k];
                    ww = ws[i][j][k];
                    ac = speed[i][j][k];
                    ac2inv = ac * ac;

                    r1 = rhs[0][i][j][k];
                    r2 = rhs[1][i][j][k];
                    r3 = rhs[2][i][j][k];
                    r4 = rhs[3][i][j][k];
                    r5 = rhs[4][i][j][k];

                    t1 = c2 / ac2inv * (qs[i][j][k] * r1 - uu * r2 - vv * r3 - ww * r4 + r5);
                    t2 = bt * ru1 * (uu * r1 - r2);
                    t3 = (bt * ru1 * ac) * t1;

                    rhs[0][i][j][k] = r1 - t1;
                    rhs[1][i][j][k] = -ru1 * (ww * r1 - r4);
                    rhs[2][i][j][k] = ru1 * (vv * r1 - r3);
                    rhs[3][i][j][k] = -t2 + t3;
                    rhs[4][i][j][k] = t2 + t3;
                }
            }
        }
        if (timeron) {
            timer_stop(t_txinvr);
        }
    }
}
```

This code assumes that the arrays `rho_i`, `us`, `vs`, `ws`, `speed`, `qs`, and `rhs` are all 4D arrays in C++. The `timer_start` and `timer_stop` functions are placeholders for actual timer functionality, which you might need to implement based on your specific requirements.
Let's write some test to verify if the translation is correct. 
To verify the correctness of both the original Fortran code and the translated C++ code, we can write unit tests for each. These tests will involve initializing the necessary arrays with specific values, calling the subroutine/function, and then checking the results against expected values.

### Fortran Unit Test

First, let's create a Fortran program that includes the subroutine `txinvr` and a simple test case.

```fortran
program test_txinvr
    implicit none
    integer, parameter :: nx2 = 2, ny2 = 2, nz2 = 2
    double precision :: rho_i(nx2, ny2, nz2), us(nx2, ny2, nz2), vs(nx2, ny2, nz2), ws(nx2, ny2, nz2)
    double precision :: speed(nx2, ny2, nz2), qs(nx2, ny2, nz2), rhs(5, nx2, ny2, nz2)
    integer :: i, j, k

    ! Initialize arrays with test values
    do k = 1, nz2
        do j = 1, ny2
            do i = 1, nx2
                rho_i(i, j, k) = 1.0
                us(i, j, k) = 0.5
                vs(i, j, k) = 0.5
                ws(i, j, k) = 0.5
                speed(i, j, k) = 1.0
                qs(i, j, k) = 1.0
                rhs(1, i, j, k) = 1.0
                rhs(2, i, j, k) = 1.0
                rhs(3, i, j, k) = 1.0
                rhs(4, i, j, k) = 1.0
                rhs(5, i, j, k) = 1.0
            end do
        end do
    end do

    ! Call the subroutine
    call txinvr(rho_i, us, vs, ws, speed, qs, rhs, nx2, ny2, nz2)

    ! Output the results for verification
    do k = 1, nz2
        do j = 1, ny2
            do i = 1, nx2
                print *, 'rhs(1,', i, ',', j, ',', k, ') = ', rhs(1, i, j, k)
                print *, 'rhs(2,', i, ',', j, ',', k, ') = ', rhs(2, i, j, k)
                print *, 'rhs(3,', i, ',', j, ',', k, ') = ', rhs(3, i, j, k)
                print *, 'rhs(4,', i, ',', j, ',', k, ') = ', rhs(4, i, j, k)
                print *, 'rhs(5,', i, ',', j, ',', k, ') = ', rhs(5, i, j, k)
            end do
        end do
    end do
end program test_txinvr
```

### C++ Unit Test

Now, let's create a C++ program that includes the `txinvr` function and a simple test case.

```cpp
#include <iostream>
#include <vector>

// Include or define the txinvr function here

int main() {
    const int nx2 = 2, ny2 = 2, nz2 = 2;
    std::vector<std::vector<std::vector<double>>> rho_i(nx2, std::vector<std::vector<double>>(ny2, std::vector<double>(nz2, 1.0)));
    std::vector<std::vector<std::vector<double>>> us(nx2, std::vector<std::vector<double>>(ny2, std::vector<double>(nz2, 0.5)));
    std::vector<std::vector<std::vector<double>>> vs(nx2, std::vector<std::vector<double>>(ny2
