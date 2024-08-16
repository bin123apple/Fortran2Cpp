Translating Fortran code to C++ involves several steps, including converting the Fortran subroutine to a C++ function, handling array indexing, and converting Fortran intrinsic functions and modules to their C++ equivalents. Below is the translated C++ code:

```cpp
#include <iostream>
#include <vector>
#include <cmath>

// Assuming the existence of these functions in C++
extern void sparse(std::vector<double>& a, std::vector<int>& colidx, std::vector<int>& rowstr, int n, int nz, int nonzer, std::vector<int>& arow, std::vector<std::vector<int>>& acol, std::vector<std::vector<double>>& aelt, int firstrow, int lastrow, std::vector<double>& v, int iv1, int ivnz1, double& rcond, double shift);
extern void sprnvc(int n, int& nzv, int nn1, std::vector<double>& vc, std::vector<int>& ivc);
extern void vecset(int n, std::vector<double>& vc, std::vector<int>& ivc, int nzv, int iouter, double value);

// Assuming these constants and variables are defined elsewhere
const int max_threads = 100;
int num_threads = 1;
int myid = 0;

void makea(int n, int nz, std::vector<double>& a, std::vector<int>& colidx, std::vector<int>& rowstr, int firstrow, int lastrow, int firstcol, int lastcol, std::vector<int>& arow, std::vector<std::vector<int>>& acol, std::vector<std::vector<double>>& aelt, std::vector<double>& v, std::vector<int>& iv) {
    int i, iouter, ivelt, nzv, nn1 = 1;
    std::vector<int> ivc(nonzer + 1);
    std::vector<double> vc(nonzer + 1);

    while (nn1 < 2 * n) {
        nn1 *= 2;
    }

    if (num_threads > max_threads) {
        if (myid == 0) {
            std::cout << " Warning: num_threads" << num_threads << " exceeded an internal limit" << max_threads << std::endl;
        }
        num_threads = max_threads;
    }

    int work = (n + num_threads - 1) / num_threads;
    int ilow = work * myid + 1;
    int ihigh = ilow + work - 1;
    if (ihigh > n) ihigh = n;

    for (iouter = 1; iouter <= ihigh; ++iouter) {
        nzv = nonzer;
        sprnvc(n, nzv, nn1, vc, ivc);
        if (iouter >= ilow) {
            vecset(n, vc, ivc, nzv, iouter, 0.5);
            arow[iouter - 1] = nzv;
            for (ivelt = 1; ivelt <= nzv; ++ivelt) {
                acol[ivelt - 1][iouter - 1] = ivc[ivelt - 1];
                aelt[ivelt - 1][iouter - 1] = vc[ivelt - 1];
            }
        }
    }

    sparse(a, colidx, rowstr, n, nz, nonzer, arow, acol, aelt, firstrow, lastrow, v, iv[0], iv[nz], rcond, shift);
}

// Placeholder for the external functions
void sparse(std::vector<double>& a, std::vector<int>& colidx, std::vector<int>& rowstr, int n, int nz, int nonzer, std::vector<int>& arow, std::vector<std::vector<int>>& acol, std::vector<std::vector<double>>& aelt, int firstrow, int lastrow, std::vector<double>& v, int iv1, int ivnz1, double& rcond, double shift) {
    // Implementation of sparse
}

void sprnvc(int n, int& nzv, int nn1, std::vector<double>& vc, std::vector<int>& ivc) {
    // Implementation of sprnvc
}

void vecset(int n, std::vector<double>& vc, std::vector<int>& ivc, int nzv, int iouter, double value) {
    // Implementation of vecset
}

// Assuming these constants and variables are defined elsewhere
const int kz = 8; // Example size, adjust as needed
double rcond = 0.0;
double shift = 0.0;
```

### Key Points:

1. **Array Handling**: Fortran arrays are 1-based, while C++ arrays are 0-based. Adjustments were made accordingly.
2. **External Functions**: The `sparse`, `sprnvc`, and `vecset` functions are assumed to be defined elsewhere. Their implementations are not provided here.
3. **Constants and Variables**: The constants `max_threads`, `num_threads`, and `myid` are assumed to be defined elsewhere.
4. **Data Types**: The Fortran `integer(kz)` is assumed to be equivalent to a standard integer type in C++. Adjust the size as needed.
5. **Implicit None**: Fortran's `implicit none` is not needed in C++ as variable types must be explicitly declared.
6. **Goto Statements**: The Fortran `goto` statements are replaced with while loops in C++.

This translation aims to preserve the logic and structure of the original Fortran code while adapting it to C++ conventions and types.
Let's write some test to verify if the translation is correct. 
Creating unit tests for both the Fortran and C++ code involves writing test cases that cover various scenarios and verify the correctness of the implementations. Below are the unit test codes for both languages.

### Fortran Unit Test

To test the Fortran code, we'll write a simple program that calls the `makea` subroutine with predefined inputs and checks the outputs.

```fortran
program test_makea
    implicit none
    integer, parameter :: n = 5, nz = 10, nonzer = 6
    integer :: colidx(nz), rowstr(n+1), arow(n), acol(nonzer+1,n), iv(n+nz)
    double precision :: a(nz), aelt(nonzer+1,n), v(nz)
    double precision :: rcond, shift
    integer :: i, j

    ! Initialize inputs
    colidx = (/1, 2, 3, 4, 5, 1, 2, 3, 4, 5/)
    rowstr = (/1, 3, 5, 7, 9, 11/)
    a = (/1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0/)
    v = (/1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0/)
    iv = (/1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11/)

    ! Call the subroutine
    call makea(n, nz, a, colidx, rowstr, 1, n, 1, n, arow, acol, aelt, v, iv)

    ! Output results for verification
    print *, 'arow:', arow
    print *, 'acol:', acol
    print *, 'aelt:', aelt
    print *, 'rcond:', rcond
    print *, 'shift:', shift

end program test_makea
```

### C++ Unit Test

For the C++ code, we'll use a simple test case similar to the Fortran one. We'll
