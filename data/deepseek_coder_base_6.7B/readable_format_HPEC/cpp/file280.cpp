Certainly! Below is the translated Fortran code to C++:

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int len = 100;
    std::vector<std::vector<double>> a(len, std::vector<double>(len));
    std::vector<std::vector<double>> b(len, std::vector<double>(len));
    std::vector<std::vector<double>> c(len, std::vector<double>(len));

    // Initialize matrices a and b
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            a[i][j] = static_cast<double>(i + 1) / 2.0;
            b[i][j] = static_cast<double>(i + 1) / 3.0;
            c[i][j] = static_cast<double>(i + 1) / 7.0;
        }
    }

    // SIMD loop
    #pragma omp simd collapse(2)
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            c[i][j] = a[i][j] * b[i][j];
        }
    }

    // Print the value of c at the center
    std::cout << "c(50,50) = " << c[49][49] << std::endl;

    return 0;
}
```

### Explanation:
1. **Headers and Namespaces:**
   - `#include <iostream>` for input and output operations.
   - `#include <vector>` for dynamic arrays.
   - `#include <omp.h>` for OpenMP support.

2. **Constants and Variables:**
   - `const int len = 100;` defines the length of the matrices.
   - `std::vector<std::vector<double>> a, b, c;` declares 3 matrices of size `len x len`.

3. **Matrix Initialization:**
   - Nested loops are used to initialize matrices `a` and `b`.

4. **SIMD Loop:**
   - `#pragma omp simd collapse(2)` is used to parallelize the inner loop.
   - Nested loops are used to multiply corresponding elements of `a` and `b` and store the result in `c`.

5. **Printing the Result:**
   - `std::cout` is used to print the value of `c[49][49]` which corresponds to the center of the matrix.

### Compilation:
To compile this C++ code with OpenMP support, you can use a command like:
```sh
g++ -fopenmp your_program.cpp -o your_program
```

This command tells the compiler to enable OpenMP support.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code.

### Fortran Unit Test Code

```fortran
program test_DRB098_simd2_orig_no
    use omp_lib
    implicit none

    integer, parameter :: dp = kind(1.0d0)
    real(dp), dimension(:,:), allocatable :: a,b,c
    integer :: len, i, j
    real(dp) :: expected_value, tolerance

    len = 100
    allocate (a(len,len))
    allocate (b(len,len))
    allocate (c(len,len))

    do i = 1, len
        do j = 1, len
            a(i,j) = real(i,dp)/2.0
            b(i,j) = real(i,dp)/3.0
            c(i,j) = real(i,dp)/7.0
        end do
    end do

    !$omp simd collapse(2)
    do i = 1, len
        do j = 1, len
            c(i,j)=a(i,j)*b(i,j)
        end do
    end do
    !$omp end simd

    expected_value = (50.0_dp / 2.0_dp) * (50.0_dp / 3.0_dp) * (50.0_dp / 7.0_dp)
    tolerance = 1.0e-6_dp

    if (abs(c(50,50) - expected_value) < tolerance) then
        print*, 'Test Passed'
    else
        print*, 'Test Failed'
    end if

    deallocate(a,b,c)
end program test_DRB098_simd2_orig_no
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <vector>
#include <omp.h>
#include <cmath>

int main() {
    const int len = 100;
    std::vector<std::vector<double>> a(len, std::vector<double>(len));
    std::vector<std::vector<double>> b(len, std::vector<double>(len));
    std::vector<std::vector<double>> c(len, std::vector<double>(len));

    double expected_value = std::pow(50.0 / 2.0, 2) * std::pow(50.0 / 3.0, 2) * std::pow(50.0 / 7.0, 2);
    double tolerance = 1.0e-6;

    // Initialize matrices a and b
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            a[i][j] = static_cast<double>(i + 1) / 2.0;
            b[i][j] = static_cast<double>(i + 1) / 3.0;
            c[i][j] = static_cast<double>(i + 1) / 7.0;
        }
    }

    // SIMD loop
    #pragma omp simd collapse(2)
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            c[i][j] = a[i][j] * b[i][j];
        }
    }

    if (std::abs(c[49][49] - expected_value) < tolerance) {
        std::cout << "Test Passed" << std::endl;
    } else {
        std::cout << "Test Failed" << std::endl;
    }

    return 0;
}
```

### Explanation:

1. **Fortran Unit Test Code:**
   - The expected value is calculated using the formula `(50 / 2) * (50 / 3) * (50 / 7)`.
   - The tolerance is set to `1.0e-6`.
   - The test checks if the computed value of `c(50,50)` is within the tolerance of the expected value.

2. **C++ Unit Test Code:**
   - The expected value is calculated using the formula `(50 / 2)^2 * (50 / 3)^2 * (50 / 7)^2`.
   - The tolerance is set to `1.0e-6`.
   - The test checks if the computed value of `c[49][49]` is within the tolerance of the expected value.

### Compilation:

- **Fortran:**
  ```sh
  gfortran -fopenmp test_DRB098_simd2_orig_no.f90 -o test_DRB098_simd2_orig_no
  ./test_DRB098_simd2_orig_no
  ```

- **C++:**
  ```sh
  g++ -fopenmp test_DRB098_simd2_orig_no.cpp -o test_DRB098_simd2_orig_no
  ./test_DRB098_simd2_orig
