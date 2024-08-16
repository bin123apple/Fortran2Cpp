To translate the given Fortran code to C++, we need to consider several aspects, including the differences in array indexing, the way functions and subroutines are defined, and the way external functions are handled. Here's a C++ version of the Fortran code:

```cpp
#include <cstdlib> // For rand()
#include <iostream>
#include <vector>

// Assuming the existence of these functions in the Fortran code
extern "C" double randlc(double tran, double amult);
extern "C" int icnvrt(double vecloc, int nn1);

// Assuming the existence of these global variables in the Fortran code
extern "C" double tran;
extern "C" double amult;

void sprnvc(int n, int nz, int nn1, std::vector<double>& v, std::vector<int>& iv) {
    int nzv = 0;

    while (nzv < nz) {
        double vecelt = randlc(tran, amult);
        double vecloc = randlc(tran, amult);
        int i = icnvrt(vecloc, nn1) + 1;

        if (i > n) continue;

        bool found = false;
        for (int ii = 0; ii < nzv; ++ii) {
            if (iv[ii] == i) {
                found = true;
                break;
            }
        }

        if (!found) {
            v[nzv] = vecelt;
            iv[nzv] = i;
            ++nzv;
        }
    }
}

// Example usage
int main() {
    int n = 10; // Example size
    int nz = 5; // Example number of elements
    int nn1 = 1; // Example parameter
    std::vector<double> v(nz);
    std::vector<int> iv(nz);

    // Initialize global variables
    tran = 0.0;
    amult = 1.0;

    // Call the subroutine
    sprnvc(n, nz, nn1, v, iv);

    // Print the results
    for (int i = 0; i < nz; ++i) {
        std::cout << "v[" << i << "] = " << v[i] << ", iv[" << i << "] = " << iv[i] << std::endl;
    }

    return 0;
}
```

### Key Points in the Translation:

1. **Array Handling**: Fortran arrays are 1-based, while C++ arrays (or vectors) are 0-based. This translation assumes that the vectors `v` and `iv` are correctly sized before calling `sprnvc`.

2. **External Functions**: The `randlc` and `icnvrt` functions are assumed to be defined elsewhere, possibly in Fortran or elsewhere. They are declared with `extern "C"` to prevent C++ name mangling issues if they are implemented in C or Fortran.

3. **Global Variables**: The `tran` and `amult` variables are assumed to be defined globally, similar to the Fortran code. They are declared with `extern "C"` to ensure linkage.

4. **Looping Constructs**: The `do` loop in Fortran is translated to a `while` loop in C++. The `goto` statements are replaced with more structured control flow constructs in C++.

5. **Subroutine to Function Translation**: The Fortran subroutine is translated into a C++ function. The parameters are passed by reference to allow modifications within the function to be reflected outside.

6. **Implicit None**: In Fortran, `implicit none` is used to avoid implicit typing based on variable names. In C++, variables must be explicitly typed, so there's no direct equivalent needed.

This translation assumes that the external functions `randlc` and `icnvrt` are correctly implemented and linked. Adjustments might be necessary depending on the actual implementations of these functions and the global variables `tran` and `amult`.
Let's write some test to verify if the translation is correct. 
To verify the correctness of both the original Fortran code and the translated C++ code, we can create simple unit tests. These tests will execute the subroutine/function with predefined inputs and compare the outputs against expected results.

### Fortran Unit Test

First, let's create a Fortran program that includes the subroutine and a simple test case.

```fortran
program test_sprnvc
    implicit none

    ! Declare variables
    integer, parameter :: n = 10, nz = 5, nn1 = 1
    double precision :: v(nz)
    integer :: iv(nz)
    double precision :: tran, amult
    integer :: i

    ! Initialize global variables
    tran = 0.0
    amult = 1.0

    ! Call the subroutine
    call sprnvc(n, nz, nn1, v, iv)

    ! Print the results
    do i = 1, nz
        print *, 'v(', i, ') = ', v(i), ', iv(', i, ') = ', iv(i)
    end do

contains

    subroutine sprnvc(n, nz, nn1, v, iv)
        implicit none
        integer, intent(in) :: n, nz, nn1
        double precision, intent(inout) :: v(*)
        integer, intent(inout) :: iv(*)
        double precision :: randlc
        integer :: icnvrt
        double precision :: vecelt, vecloc
        integer :: nzv, ii, i, icnvrt

        nzv = 0

        do while (nzv < nz)
            vecelt = randlc(tran, amult)
            vecloc = randlc(tran, amult)
            i = icnvrt(vecloc, nn1) + 1

            if (i > n) then
                cycle
            endif

            do ii = 1, nzv
                if (iv(ii) == i) then
                    cycle
                endif
            end do

            nzv = nzv + 1
            v(nzv) = vecelt
            iv(nzv) = i
        end do
    end subroutine sprnvc

    ! Mock implementations of randlc and icnvrt for testing
    double precision function randlc(tran, amult)
        double precision, intent(in) :: tran, amult
        randlc = rand() * amult + tran
    end function randlc

    integer function icnvrt(vecloc, nn1)
        double precision, intent(in) :: vecloc
        integer, intent(in) :: nn1
        icnvrt = int(vecloc)
    end function icnvrt

end program test_sprnvc
```

### C++ Unit Test

Now, let's create a C++ program that includes the translated function and a simple test case.

```cpp
#include <iostream>
#include <vector>
#include <cstdlib> // For rand()

// Assuming the existence of these functions in the Fortran code
extern "C" double randlc(double tran, double amult);
extern "C" int icnvrt(double vecloc, int nn1);

// Assuming the existence of these global variables in the Fortran code
extern "C" double tran;
extern "C" double amult;

void sprnvc(int n, int nz, int nn1, std::vector<double>& v, std::vector<int>& iv);

int main() {
    int n = 10; // Example size
    int nz = 5; // Example number of elements
    int nn1 = 1; // Example parameter
    std::vector<double> v(nz);
    std::vector<int> iv(nz);

    // Initialize global variables
    tran = 0.0;
    amult = 1.0;

    // Call the function
    sprnvc(n, nz, nn1, v, iv);

    // Print the results
    for (int i = 0; i < nz; ++i) {
        std::cout << "v[" << i << "] = " << v[
