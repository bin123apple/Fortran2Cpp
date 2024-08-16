To translate the given Fortran code to C++, we need to consider several aspects, including array indexing, data types, and loop constructs. Fortran arrays are 1-based, while C++ arrays are 0-based. Also, Fortran passes arrays to functions/subroutines by reference automatically, while in C++, we need to explicitly use pointers or references. For simplicity and to maintain the spirit of the original code, I'll use pointers for the arrays in the C++ translation.

Here's how the Fortran code can be translated to C++:

```cpp
#include <cmath>

// Assuming DATA_TYPE is a floating-point type (e.g., double)
using DATA_TYPE = double;

void kernel_gramschmidt(int ni, int nj, DATA_TYPE** a, DATA_TYPE** r, DATA_TYPE** q) {
    DATA_TYPE nrm;
    int i, j, k;

    // Loop over columns of a
    for (k = 0; k < nj; ++k) {
        nrm = 0.0;
        // Compute the norm of the k-th column of a
        for (i = 0; i < ni; ++i) {
            nrm += a[k][i] * a[k][i];
        }
        r[k][k] = sqrt(nrm);
        // Normalize the k-th column of a
        for (i = 0; i < ni; ++i) {
            q[k][i] = a[k][i] / r[k][k];
        }
        // Update the remaining columns of a and r
        for (j = k + 1; j < nj; ++j) {
            r[j][k] = 0.0;
            for (i = 0; i < ni; ++i) {
                r[j][k] += q[k][i] * a[j][i];
            }
            for (i = 0; i < ni; ++i) {
                a[j][i] -= q[k][i] * r[j][k];
            }
        }
    }
}
```

Key Points in the Translation:

1. **Array Indexing**: Adjusted to start from 0 in C++, as opposed to 1 in Fortran.
2. **Data Types**: The `DATA_TYPE` is assumed to be a floating-point type (e.g., `double`). You can change it to `float` if needed.
3. **Pointers**: Used pointers for the arrays `a`, `r`, and `q` to mimic the behavior of Fortran's passing arrays by reference.
4. **Loops**: Translated Fortran loops to C++ for loops.
5. **Math Functions**: Used `sqrt` from `<cmath>` for computing the square root.

Note: The original Fortran code uses OpenACC directives for parallelism, which are not directly translatable to C++. If parallel execution is a requirement, consider using OpenACC in the C++ code or exploring parallel computing libraries in C++ for a more idiomatic approach.
Let's write some test to verify if the translation is correct. 
Below are simple unit tests for both the Fortran and C++ versions of the Gram-Schmidt orthogonalization code. These tests will verify that the implementations produce the same results for a given input.

### Fortran Unit Test

First, let's create a Fortran program that calls the `kernel_gramschmidt` subroutine and prints the results for verification.

```fortran
program test_gramschmidt
    implicit none
    integer, parameter :: ni = 3, nj = 3
    double precision, dimension(nj, ni) :: a, q
    double precision, dimension(nj, nj) :: r
    integer :: i, j

    ! Initialize matrix a
    a = reshape([1.0d0, 2.0d0, 3.0d0, &
                 2.0d0, 3.0d0, 4.0d0, &
                 3.0d0, 4.0d0, 5.0d0], shape(a))

    call kernel_gramschmidt(ni, nj, a, r, q)

    ! Print results
    print *, 'Matrix a:'
    do i = 1, nj
        print '(3F6.2)', (a(i, j), j=1, ni)
    end do

    print *, 'Matrix r:'
    do i = 1, nj
        print '(3F6.2)', (r(i, j), j=1, nj)
    end do

    print *, 'Matrix q:'
    do i = 1, nj
        print '(3F6.2)', (q(i, j), j=1, ni)
    end do
end program test_gramschmidt
```

Compile and run this Fortran program to test the `kernel_gramschmidt` subroutine.

### C++ Unit Test

Now, let's create a C++ program that includes the `kernel_gramschmidt` function and tests it similarly.

```cpp
#include <iostream>
#include <iomanip>

using namespace std;

// Assuming DATA_TYPE is a floating-point type (e.g., double)
using DATA_TYPE = double;

// Function prototype
void kernel_gramschmidt(int ni, int nj, DATA_TYPE** a, DATA_TYPE** r, DATA_TYPE** q);

int main() {
    const int ni = 3, nj = 3;
    DATA_TYPE** a = new DATA_TYPE*[nj];
    DATA_TYPE** r = new DATA_TYPE*[nj];
    DATA_TYPE** q = new DATA_TYPE*[nj];

    // Initialize matrix a
    for (int i = 0; i < nj; ++i) {
        a[i] = new DATA_TYPE[ni];
        r[i] = new DATA_TYPE[nj];
        q[i] = new DATA_TYPE[ni];
        for (int j = 0; j < ni; ++j) {
            a[i][j] = (i * ni + j + 1);
        }
    }

    kernel_gramschmidt(ni, nj, a, r, q);

    // Print results
    cout << "Matrix a:" << endl;
    for (int i = 0; i < nj; ++i) {
        for (int j = 0; j < ni; ++j) {
            cout << setw(6) << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Matrix r:" << endl;
    for (int i = 0; i < nj; ++i) {
        for (int j = 0; j < nj; ++j) {
            cout << setw(6) << r[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Matrix q:" << endl;
    for (int i = 0; i < nj; ++i) {
        for (int j = 0; j < ni; ++j) {
            cout << setw(6) << q[i][j] << " ";
        }
        cout << endl;
    }

    // Clean up
    for (int i = 0; i < nj; ++i) {
        delete[] a[i];
        delete[] r[i];
        delete[] q[i];
    }
    delete[] a;
    delete[] r;
    delete[] q;

    return 0;
}
```

Compile and run this C++ program to test the `kernel_gramschmidt` function.

### Verifying Correctness

To verify the correctness of both implementations, you should compare the output matrices `a`, `r`, and `q` from both implementations. The matrices `a` and `q` should be orthogonal and the matrix `r` should be the upper triangular matrix of the Cholesky decomposition of `a`. The values in `a` and `q` should be close to each other, and the values in `r` should be the square roots of the diagonal elements of `a`.

These tests are basic and designed to verify the functionality of the Gram-Schmidt orthogonalization algorithm in both
