Certainly! Below is the translated Fortran code to C++:

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int len = 100;
    std::vector<double> a(len), b(len), c(len);

    for (int i = 0; i < len; ++i) {
        a[i] = (i + 1) / 2.0;
        b[i] = (i + 1) / 3.0;
        c[i] = (i + 1) / 7.0;
    }

    #pragma omp parallel for
    for (int i = 0; i < len; ++i) {
        c[i] = c[i] + a[i] * b[i];
    }

    std::cout << "c[49] = " << c[49] << std::endl;

    return 0;
}
```

### Explanation:
1. **Include necessary headers**:
   - `<iostream>` for input/output operations.
   - `<vector>` for dynamic array support.
   - `<omp.h>` for OpenMP support.

2. **Define constants and vectors**:
   - `const int len = 100;` defines the length of the arrays.
   - `std::vector<double> a(len), b(len), c(len);` declares three vectors `a`, `b`, and `c` with `len` elements each.

3. **Initialization of vectors**:
   - The `for` loop initializes the vectors `a`, `b`, and `c`.

4. **Parallel computation**:
   - The `#pragma omp parallel for` directive is used to parallelize the loop.
   - The loop updates the elements of vector `c` based on the elements of vectors `a` and `b`.

5. **Printing the result**:
   - `std::cout` is used to print the value of `c[49]`, which corresponds to the 50th element in Fortran (1-based indexing).

6. **Return statement**:
   - The `main` function returns `0` to indicate successful execution.

This C++ code should perform the same operations as the provided Fortran code and produce the same output.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code to verify the correctness of the translation.

### Fortran Unit Test Code

```fortran
program test_DRB111_linearmissing_orig_yes
    use omp_lib
    implicit none

    integer :: len, i, j
    integer, parameter :: dp = kind(1.0d0)
    real(dp), dimension(:), allocatable :: a, b, c
    real(dp) :: expected_value

    len = 100
    i = 0
    j = 0

    allocate(a(len))
    allocate(b(len))
    allocate(c(len))

    do i = 1, len
        a(i) = (real(i, dp)) / 2.0
        b(i) = (real(i, dp)) / 3.0
        c(i) = (real(i, dp)) / 7.0
    end do

    !$omp parallel do
    do i = 1, len
        c(j) = c(j) + a(i) * b(i)
        j = j + 1
    end do
    !$omp end parallel do

    expected_value = (50.0_dp / 2.0_dp) * ((50.0_dp / 3.0_dp) * (50.0_dp / 7.0_dp))
    if (abs(c(50) - expected_value) < 1.0e-6_dp) then
        print *, "Test Passed"
    else
        print *, "Test Failed"
    end if

    if (allocated(a)) deallocate(a)
    if (allocated(b)) deallocate(b)
    if (allocated(c)) deallocate(c)

end program test_DRB111_linearmissing_orig_yes
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <vector>
#include <omp.h>
#include <cmath>

int main() {
    const int len = 100;
    std::vector<double> a(len), b(len), c(len);
    double expected_value;

    for (int i = 0; i < len; ++i) {
        a[i] = (i + 1) / 2.0;
        b[i] = (i + 1) / 3.0;
        c[i] = (i + 1) / 7.0;
    }

    #pragma omp parallel for
    for (int i = 0; i < len; ++i) {
        c[i] = c[i] + a[i] * b[i];
    }

    expected_value = (50.0 / 2.0) * ((50.0 / 3.0) * (50.0 / 7.0));
    if (std::abs(c[49] - expected_value) < 1.0e-6) {
        std::cout << "Test Passed" << std::endl;
    } else {
        std::cout << "Test Failed" << std::endl;
    }

    return 0;
}
```

### Explanation:

1. **Fortran Unit Test Code**:
   - The `expected_value` is calculated using the formula `(50 / 2) * ((50 / 3) * (50 / 7))`.
   - The `abs` function is used to calculate the absolute difference between the computed value and the expected value.
   - If the difference is less than `1.0e-6`, the test passes; otherwise, it fails.

2. **C++ Unit Test Code**:
   - The `expected_value` is calculated using the same formula.
   - The `std::abs` function is used to calculate the absolute difference between the computed value and the expected value.
   - If the difference is less than `1.0e-6`, the test passes; otherwise, it fails.

These unit tests will help verify the correctness of the translation by comparing the output of the Fortran and C++ programs.
