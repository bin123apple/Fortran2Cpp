Certainly! Below is the translated Fortran code to C++:

```cpp
#include <vector>

// Assuming DATA_TYPE is a float or double
using DATA_TYPE = double;

void kernel_gemver(int n, DATA_TYPE alpha, DATA_TYPE beta, 
                   std::vector<std::vector<DATA_TYPE>>& a, 
                   std::vector<DATA_TYPE>& u1, 
                   std::vector<DATA_TYPE>& v1, 
                   std::vector<DATA_TYPE>& u2, 
                   std::vector<DATA_TYPE>& v2, 
                   std::vector<DATA_TYPE>& w, 
                   std::vector<DATA_TYPE>& x, 
                   std::vector<DATA_TYPE>& y, 
                   std::vector<DATA_TYPE>& z) {
    // Loop indices
    int i, j;

    // First block
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            a[j][i] = a[j][i] + (u1[i] * v1[j]) + (u2[i] * v2[j]);
        }
    }

    // Second block
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            x[i] = x[i] + (beta * a[i][j] * y[j]);
        }
    }

    // Third block
    for (i = 0; i < n; ++i) {
        x[i] = x[i] + z[i];
    }

    // Fourth block
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            w[i] = w[i] + (alpha * a[j][i] * x[j]);
        }
    }
}

int main() {
    // Example usage
    int n = 10; // Example size
    DATA_TYPE alpha = 1.0, beta = 2.0;

    std::vector<std::vector<DATA_TYPE>> a(n, std::vector<DATA_TYPE>(n));
    std::vector<DATA_TYPE> u1(n), u2(n), v1(n), v2(n), w(n), x(n), y(n), z(n);

    // Initialize vectors with some values
    // ...

    kernel_gemver(n, alpha, beta, a, u1, v1, u2, v2, w, x, y, z);

    // Do something with the results
    // ...

    return 0;
}
```

### Explanation:
1. **Data Types and Dimensions**:
   - The `DATA_TYPE` is defined as `double`. You can change it to `float` if needed.
   - Arrays are represented using `std::vector` for dynamic arrays.

2. **Function Signature**:
   - The function `kernel_gemver` takes the size `n`, and the parameters by reference.

3. **Loops**:
   - The loops are translated directly from Fortran to C++. Note that Fortran arrays are 1-based, while C++ arrays are 0-based.

4. **Initialization**:
   - The example usage includes initializing some of the vectors with example values. You should initialize these vectors with appropriate values before calling the function.

5. **Calling the Function**:
   - The `kernel_gemver` function is called with the appropriate parameters.

This translation assumes that the arrays `a`, `u1`, `u2`, `v1`, `v2`, `w`, `x`, `y`, and `z` are properly initialized before calling the function.
Let's write some test to verify if the translation is correct. 
Below are the unit tests for both the original Fortran code and the translated C++ code.

### Fortran Unit Test

First, let's create a Fortran program to test the `kernel_gemver` subroutine.

```fortran
program test_kernel_gemver
    implicit none
    integer, parameter :: n = 4
    real(8) :: alpha, beta
    real(8), dimension(n, n) :: a
    real(8), dimension(n) :: u1, u2, v1, v2, w, x, y, z
    integer :: i, j

    ! Initialize variables
    alpha = 1.0d0
    beta = 2.0d0
    do i = 1, n
        do j = 1, n
            a(j, i) = 1.0d0
        end do
        u1(i) = 1.0d0
        u2(i) = 1.0d0
        v1(i) = 1.0d0
        v2(i) = 1.0d0
        w(i) = 0.0d0
        x(i) = 1.0d0
        y(i) = 1.0d0
        z(i) = 1.0d0
    end do

    ! Call the subroutine
    call kernel_gemver(n, alpha, beta, a, u1, v1, u2, v2, w, x, y, z)

    ! Print the results
    print *, 'w:', w
    print *, 'x:', x

end program test_kernel_gemver
```

### C++ Unit Test

Now, let's create a C++ program to test the `kernel_gemver` function.

```cpp
#include <iostream>
#include <vector>
#include <iomanip>

using DATA_TYPE = double;

void kernel_gemver(int n, DATA_TYPE alpha, DATA_TYPE beta, 
                   std::vector<std::vector<DATA_TYPE>>& a, 
                   std::vector<DATA_TYPE>& u1, 
                   std::vector<DATA_TYPE>& v1, 
                   std::vector<DATA_TYPE>& u2, 
                   std::vector<DATA_TYPE>& v2, 
                   std::vector<DATA_TYPE>& w, 
                   std::vector<DATA_TYPE>& x, 
                   std::vector<DATA_TYPE>& y, 
                   std::vector<DATA_TYPE>& z) {
    // Loop indices
    int i, j;

    // First block
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            a[j][i] = a[j][i] + (u1[i] * v1[j]) + (u2[i] * v2[j]);
        }
    }

    // Second block
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            x[i] = x[i] + (beta * a[i][j] * y[j]);
        }
    }

    // Third block
    for (i = 0; i < n; ++i) {
        x[i] = x[i] + z[i];
    }

    // Fourth block
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            w[i] = w[i] + (alpha * a[j][i] * x[j]);
        }
    }
}

int main() {
    // Example usage
    int n = 4; // Example size
    DATA_TYPE alpha = 1.0, beta = 2.0;

    std::vector<std::vector<DATA_TYPE>> a(n, std::vector<DATA_TYPE>(n, 1.0));
    std::vector<DATA_TYPE> u1(n, 1.0), u2(n, 1.0), v1(n, 1.0), v2(n, 1.0), w(n, 0.0), x(n, 1.0), y(n, 1.0), z(n, 1.0);

    kernel_gemver(n, alpha, beta, a, u1, v1, u2, v
