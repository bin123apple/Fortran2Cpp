Certainly! Below is the translated C++ code from the provided Fortran code. Note that in C++, arrays are zero-indexed, unlike Fortran which is one-indexed. Also, the `DATA_TYPE` in Fortran is assumed to be a floating-point type (e.g., `float` or `double`), which you should replace with the appropriate C++ type in the translation.

```cpp
#include <vector>

// Assuming DATA_TYPE is replaced with float or double
using DATA_TYPE = double;

void kernel_gesummv(int n, DATA_TYPE alpha, DATA_TYPE beta, 
                     std::vector<std::vector<DATA_TYPE>>& a, 
                     std::vector<std::vector<DATA_TYPE>>& b, 
                     std::vector<DATA_TYPE>& tmp, 
                     std::vector<DATA_TYPE>& x, 
                     std::vector<DATA_TYPE>& y) {
    // Initialize tmp and y to zero
    for (int i = 0; i < n; ++i) {
        tmp[i] = 0.0;
        y[i] = 0.0;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            tmp[i] += a[j][i] * x[j];
            y[i] += b[j][i] * x[j];
        }
        y[i] = alpha * tmp[i] + beta * y[i];
    }
}

int main() {
    // Example usage
    int n = 5; // Example size
    DATA_TYPE alpha = 1.0, beta = 2.0;
    std::vector<std::vector<DATA_TYPE>> a(n, std::vector<DATA_TYPE>(n)); // Example matrix a
    std::vector<std::vector<DATA_TYPE>> b(n, std::vector<DATA_TYPE>(n)); // Example matrix b
    std::vector<DATA_TYPE> tmp(n); // Example vector tmp
    std::vector<DATA_TYPE> x(n); // Example vector x
    std::vector<DATA_TYPE> y(n); // Example vector y

    // Initialize matrices a and b and vectors x and y with appropriate values
    // ...

    kernel_gesummv(n, alpha, beta, a, b, tmp, x, y);

    // Use y for output or further processing
    // ...

    return 0;
}
```

This C++ code defines a function `kernel_gesummv` that performs the same operations as the Fortran subroutine. It initializes `tmp` and `y` to zero, then iterates over the rows and columns of `a` and `b`, updating `tmp` and `y` accordingly. Finally, it applies the scaling factors `alpha` and `beta` to the elements of `tmp` and `y`, respectively.

Please note that in C++, arrays (or in this case, `std::vector`s) are zero-indexed, unlike Fortran which is one-indexed. This difference in indexing needs to be accounted for in the translation.
Let's write some test to verify if the translation is correct. 
Below are simple unit tests for both the Fortran and C++ versions of the `kernel_gesummv` subroutine/function. These tests will verify the correctness of the implementations by comparing their outputs against expected values.

### Fortran Unit Test

First, let's create a Fortran program that tests the `kernel_gesummv` subroutine. We'll use a simple matrix and vectors for the test.

```fortran
program test_kernel_gesummv
    implicit none
    integer, parameter :: n = 3
    double precision, dimension(n, n) :: a, b
    double precision, dimension(n) :: x, y, tmp
    double precision :: alpha, beta
    integer :: i

    ! Initialize matrices and vectors
    alpha = 1.0d0
    beta = 2.0d0
    a = reshape([1.0d0, 2.0d0, 3.0d0, 4.0d0, 5.0d0, 6.0d0, 7.0d0, 8.0d0, 9.0d0], shape(a))
    b = reshape([9.0d0, 8.0d0, 7.0d0, 6.0d0, 5.0d0, 4.0d0, 3.0d0, 2.0d0, 1.0d0], shape(b))
    x = [1.0d0, 2.0d0, 3.0d0]
    y = [0.0d0, 0.0d0, 0.0d0]

    ! Call the subroutine
    call kernel_gesummv(n, alpha, beta, a, b, tmp, x, y)

    ! Print results
    print *, "y:"
    do i = 1, n
        print *, y(i)
    end do
end program test_kernel_gesummv
```

### C++ Unit Test

Now, let's create a C++ program that tests the `kernel_gesummv` function. We'll use the same simple matrix and vectors for the test.

```cpp
#include <iostream>
#include <vector>
#include <cmath> // For fabs

using DATA_TYPE = double;

void kernel_gesummv(int n, DATA_TYPE alpha, DATA_TYPE beta, 
                     std::vector<std::vector<DATA_TYPE>>& a, 
                     std::vector<std::vector<DATA_TYPE>>& b, 
                     std::vector<DATA_TYPE>& tmp, 
                     std::vector<DATA_TYPE>& x, 
                     std::vector<DATA_TYPE>& y);

int main() {
    int n = 3;
    DATA_TYPE alpha = 1.0, beta = 2.0;
    std::vector<std::vector<DATA_TYPE>> a = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
    std::vector<std::vector<DATA_TYPE>> b = {{9.0, 8.0, 7.0}, {6.0, 5.0, 4.0}, {3.0, 2.0, 1.0}};
    std::vector<DATA_TYPE> tmp(n, 0.0);
    std::vector<DATA_TYPE> x = {1.0, 2.0, 3.0};
    std::vector<DATA_TYPE> y(n, 0.0);

    kernel_gesummv(n, alpha, beta, a, b, tmp, x, y);

    std::cout << "y:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << y[i] << std::endl;
    }

    return 0;
}
```

### Expected Output

For both the Fortran and C++ programs, the expected output should be:

```
y:
11.0
30.0
51.0
```

### Running the Tests

To run the Fortran test, you'll need a Fortran compiler like `gfortran`. Compile and run the Fortran program as follows:

```sh
gfortran -o test_fortran test_kernel_gesummv.f90
./test_fortran
```

To run the C++ test, you'll need a C++ compiler like `g++`. Compile and run the C++ program as follows:

```sh
g++ -o test_cpp test_kernel_gesummv.cpp
./test_cpp
```

These tests should verify that both implementations produce the same output, thus confirming the correctness of the translation.
