To translate the given Fortran code to C++, we need to consider several differences between the two languages, such as array indexing (Fortran is 1-based, while C++ is 0-based), data types, and the way arrays are declared and passed to functions. Here's a C++ version of the Fortran subroutine:

```cpp
#include <vector>

// Assuming DATA_TYPE is a floating-point type, e.g., float or double
using DATA_TYPE = double;

void init_array(int m, int n, DATA_TYPE& float_n, std::vector<std::vector<DATA_TYPE>>& dat) {
    float_n = 1.2;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            dat[j][i] = static_cast<DATA_TYPE>((i * j) / static_cast<DATA_TYPE>(m));
        }
    }
}

int main() {
    int m = 5; // Example dimensions
    int n = 4;
    DATA_TYPE float_n;
    std::vector<std::vector<DATA_TYPE>> dat(n, std::vector<DATA_TYPE>(m));

    init_array(m, n, float_n, dat);

    // Optional: Print the array to verify the results
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << dat[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
```

Key points in the translation:

1. **Array Indexing:** C++ uses 0-based indexing, so the loops start from 0 and go up to `m-1` or `n-1`, respectively.

2. **Data Types:** The `DATA_TYPE` is defined as `double` in the C++ version, assuming it corresponds to the Fortran `DATA_TYPE`. You can change it to `float` if that's what you need.

3. **Arrays:** In C++, we use `std::vector` to represent 2D arrays. This choice provides flexibility and automatic memory management.

4. **Passing Arrays:** The array `dat` is passed as a reference to the function, allowing modifications to be reflected outside the function.

5. **Type Casting:** The division by `m` in the calculation is done using a `static_cast<DATA_TYPE>` to ensure the division result is of type `DATA_TYPE`.

6. **Implicit None:** In Fortran, `implicit none` is used to avoid implicit typing based on variable names. In C++, variables must be explicitly typed, so there's no direct equivalent needed.

This translation assumes that `DATA_TYPE` corresponds to a C++ floating-point type (`float` or `double`), which is a common practice in C++ code. If `DATA_TYPE` is meant to be an integer type, you should use `int` or `size_t` (for sizes) instead.
Let's write some test to verify if the translation is correct. 
Below are examples of how you could write unit tests for both the Fortran and C++ versions of the code. These tests will verify that the array `dat` is correctly initialized according to the specified logic.

### Fortran Unit Test

For the Fortran code, we'll write a simple program that calls the `init_array` subroutine and checks the results.

```fortran
program test_init_array
    implicit none
    integer, parameter :: m = 5, n = 4
    real(8) :: float_n
    real(8), dimension(n, m) :: dat
    integer :: i, j
    logical :: test_passed

    call init_array(m, n, float_n, dat)

    test_passed = .true.
    do i = 1, m
        do j = 1, n
            if (dat(j, i) /= (i - 1) * (j - 1) / real(m)) then
                test_passed = .false.
                exit
            end if
        end do
        if (.not. test_passed) exit
    end do

    if (test_passed) then
        print *, "Test passed."
    else
        print *, "Test failed."
    end if
end program test_init_array
```

### C++ Unit Test

For the C++ code, we'll use a simple approach with assertions to verify the correctness of the `init_array` function.

```cpp
#include <vector>
#include <cassert>
#include <cmath>
#include <iostream>

using DATA_TYPE = double;

void init_array(int m, int n, DATA_TYPE& float_n, std::vector<std::vector<DATA_TYPE>>& dat);

int main() {
    int m = 5; // Example dimensions
    int n = 4;
    DATA_TYPE float_n;
    std::vector<std::vector<DATA_TYPE>> dat(n, std::vector<DATA_TYPE>(m));

    init_array(m, n, float_n, dat);

    // Unit test
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            DATA_TYPE expected = static_cast<DATA_TYPE>((i * j) / static_cast<DATA_TYPE>(m));
            assert(std::fabs(dat[j][i] - expected) < 1e-6);
        }
    }

    std::cout << "Test passed." << std::endl;

    return 0;
}
```

In both tests, we're essentially checking that the elements of the `dat` array are initialized correctly according to the specified logic. The Fortran test uses a loop to iterate over the array and check each element, printing a message based on whether the test passed or failed. The C++ test uses `assert` to ensure that each element in the array matches the expected value, printing a success message if all assertions pass.

Please note, the C++ test uses `std::fabs` to compare floating-point numbers due to potential precision issues. The `1e-6` threshold is used to account for potential minor differences due to floating-point arithmetic.
