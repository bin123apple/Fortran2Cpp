To translate the given Fortran code to C++, we need to consider several differences between the two languages, such as array indexing, function calling conventions, and the way arrays are passed to functions. In Fortran, arrays are 1-based and passed by reference by default, while in C++, arrays (or more generally, data structures) are 0-based and must be explicitly passed by reference or by pointer. Also, Fortran's `implicit none` is similar to C++'s explicit type declaration. Here's how the Fortran code could be translated to C++:

```cpp
#include <cmath> // For sqrt
#include <algorithm> // For std::max

// Assuming mg_data.h or similar contains the timer_start and timer_stop functions
#include "mg_data.h"

void norm2u3(double** r, int n1, int n2, int n3, double& rnm2, double& rnmu, int nx, int ny, int nz) {
    double s = 0.0;
    double a = 0.0;
    double dn = 1.0 * nx * ny * nz;

    int T_norm2 = 9;

    if (timeron) timer_start(T_norm2);

    for (int i3 = 2; i3 < n3 - 1; ++i3) {
        for (int i2 = 2; i2 < n2 - 1; ++i2) {
            for (int i1 = 2; i1 < n1 - 1; ++i1) {
                s += r[i1][i2][i3] * r[i1][i2][i3];
                a = std::abs(r[i1][i2][i3]);
                rnmu = std::max(rnmu, a);
            }
        }
    }

    rnm2 = std::sqrt(s / dn);

    if (timeron) timer_stop(T_norm2);
}
```

Key Points in the Translation:

1. **Array Indexing**: Adjusted to start from 2 to match Fortran's 1-based indexing.
2. **Array Parameters**: In C++, arrays are typically represented as pointers to pointers, or more idiomatically, as `std::vector` or `std::array`. Here, I've used a 3D array represented as a pointer to pointers, which is a bit unconventional but straightforward for the given context.
3. **Function Arguments**: The `rnm2` and `rnmu` are passed by reference (`double&`) to allow modification within the function, similar to how they are modified in the Fortran subroutine.
4. **Math Functions**: Used `std::sqrt` from `<cmath>` for square root calculation and `std::abs` from `<algorithm>` for absolute value calculation.
5. **Timer Functions**: Assuming `timeron` is a global variable or similar, and `timer_start` and `timer_stop` are functions defined elsewhere, they are called similarly to the Fortran version.

This translation assumes that `mg_data.h` contains the definitions for `timeron` and `timer_start`/`timer_stop` functions, which are used similarly to the Fortran version. Adjustments might be needed depending on the specifics of your project setup and how `timeron`, `timer_start`, and `timer_stop` are implemented.
Let's write some test to verify if the translation is correct. 
Below are simple unit tests for both the original Fortran code and the translated C++ code. These tests will help verify the correctness of the translation by comparing the outputs of both implementations.

### Fortran Unit Test

First, let's create a Fortran program that includes the original subroutine and a test case.

```fortran
program test_norm2u3
    use mg_data, only : timeron
    implicit none

    integer, parameter :: n1=4, n2=4, n3=4, nx=4, ny=4, nz=4
    double precision, allocatable :: r(:,:,:)
    double precision :: rnm2, rnmu
    integer :: i, j, k

    ! Allocate and initialize the array
    allocate(r(n1,n2,n3))
    do k = 1, n3
        do j = 1, n2
            do i = 1, n1
                r(i,j,k) = i + j + k
            end do
        end do
    end do

    ! Call the subroutine
    call norm2u3(r, n1, n2, n3, rnm2, rnmu, nx, ny, nz)

    ! Print results
    print *, 'rnm2:', rnm2
    print *, 'rnmu:', rnmu

    ! Deallocate the array
    deallocate(r)

contains

    subroutine norm2u3(r,n1,n2,n3,rnm2,rnmu,nx,ny,nz)
        use mg_data, only : timeron
        implicit none
        integer n1, n2, n3, nx, ny, nz
        double precision rnm2, rnmu, r(n1,n2,n3)
        double precision s, a
        integer i3, i2, i1
        double precision dn
        integer T_norm2
        parameter (T_norm2=9)

        if (timeron) call timer_start(T_norm2)
        dn = 1.0d0*nx*ny*nz

        s=0.0D0
        rnmu = 0.0D0
        do  i3=2,n3-1
            do  i2=2,n2-1
                do  i1=2,n1-1
                    s=s+r(i1,i2,i3)**2
                    a=abs(r(i1,i2,i3))
                    rnmu=dmax1(rnmu,a)
                enddo
            enddo
        enddo

        rnm2=sqrt( s / dn )
        if (timeron) call timer_stop(T_norm2)

        return
    end subroutine norm2u3

end program test_norm2u3
```

### C++ Unit Test

Next, let's create a C++ program that includes the translated function and a test case.

```cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "mg_data.h" // Assuming this file contains the timer_start and timer_stop functions

void norm2u3(std::vector<std::vector<std::vector<double>>>& r, int n1, int n2, int n3, double& rnm2, double& rnmu, int nx, int ny, int nz) {
    double s = 0.0;
    double a = 0.0;
    double dn = 1.0 * nx * ny * nz;

    int T_norm2 = 9;

    if (timeron) timer_start(T_norm2);

    for (int i3 = 2; i3 < n3 - 1; ++i3) {
        for (int i2 = 2; i2 < n2 - 1; ++i2) {
            for (int i1 = 2; i1 < n1 - 1; ++i1) {
                s += r[i1][i2][i3] * r[i1][i2][i3];
                a = std::abs(r[i1][i2][i3]);
                rnmu = std::max(rnmu, a);
            }
        }
    }

    rnm2 = std::sqrt(s / dn);

    if (timeron) timer_stop(T_norm2);
}

int main() {
    const int n1 = 4, n2 = 4, n3 = 4, nx = 4, ny = 4, nz = 4;
    std::vector<std::vector<std::vector<double>>> r(n1, std::vector<std::vector<double>>(n2, std::vector<double>(n3)));
    double rnm2, rnmu;

    // Initialize the array
    for (int k = 0; k < n3
