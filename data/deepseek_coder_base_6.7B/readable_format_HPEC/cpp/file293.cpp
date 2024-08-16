To translate the given Fortran code to C++, we need to consider several differences between the two languages, such as array indexing (Fortran arrays are 1-based, while C++ arrays are 0-based), the way arrays are declared and passed to functions, and the data types. In Fortran, arrays are passed by reference by default, which is a bit different in C++. We'll use `std::vector` from the C++ Standard Library to represent the arrays for dynamic sizing and ease of use.

Here's the translated C++ code:

```cpp
#include <vector>
#include <iostream>

// Assuming DATA_TYPE is a floating-point type, e.g., double
using DATA_TYPE = double;

void init_array(int tmax, int nx, int ny, std::vector<std::vector<DATA_TYPE>>& ex, std::vector<std::vector<DATA_TYPE>>& ey, std::vector<std::vector<DATA_TYPE>>& hz, std::vector<DATA_TYPE>& fict) {
    // Resize the vectors to match the dimensions
    ex.resize(ny, std::vector<DATA_TYPE>(nx));
    ey.resize(ny, std::vector<DATA_TYPE>(nx));
    hz.resize(ny, std::vector<DATA_TYPE>(nx));
    fict.resize(tmax);

    // Initialize fict
    for (int i = 0; i < tmax; ++i) {
        fict[i] = static_cast<DATA_TYPE>(i);
    }

    // Initialize ex, ey, hz
    for (int i = 0; i < nx; ++i) {
        for (int j = 0; j < ny; ++j) {
            ex[j][i] = static_cast<DATA_TYPE>((i * j) / static_cast<DATA_TYPE>(nx));
            ey[j][i] = static_cast<DATA_TYPE>((i * (j + 1)) / static_cast<DATA_TYPE>(ny));
            hz[j][i] = static_cast<DATA_TYPE>((i * (j + 2)) / static_cast<DATA_TYPE>(nx));
        }
    }
}

int main() {
    int tmax = 10; // Example value
    int nx = 5; // Example value
    int ny = 3; // Example value

    std::vector<std::vector<DATA_TYPE>> ex, ey, hz;
    std::vector<DATA_TYPE> fict;

    init_array(tmax, nx, ny, ex, ey, hz, fict);

    // Example: Print the first element of fict to verify initialization
    std::cout << "fict[0] = " << fict[0] << std::endl;

    return 0;
}
```

Key Points:
- The `std::vector` is used to represent the arrays, which allows for dynamic sizing and easy memory management.
- The `resize` method is used to set the dimensions of the arrays.
- The `static_cast<DATA_TYPE>()` is used to ensure the division operation results in the correct type, matching the Fortran code's use of `DBLE()`.
- The loop indices start from 0 in C++, reflecting C++'s 0-based indexing.
- This example includes a `main` function to demonstrate how to call `init_array` and print an element of `fict` to verify the initialization.
Let's write some test to verify if the translation is correct. 
Below are examples of how you could write unit tests for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the array initialization.

### Fortran Unit Test

For the Fortran code, we'll write a simple program that calls the `init_array` subroutine and checks the values of the arrays.

```fortran
program test_init_array
    implicit none
    integer, parameter :: tmax = 10, nx = 5, ny = 3
    real, dimension(tmax) :: fict
    real, dimension(ny, nx) :: ex, ey, hz
    integer :: i, j

    call init_array(tmax, nx, ny, ex, ey, hz, fict)

    ! Test fict
    do i = 1, tmax
        if (fict(i) /= real(i - 1)) then
            print *, "Test failed for fict at index", i
            stop
        endif
    end do
    print *, "All tests passed for fict"

    ! Test ex
    do i = 1, nx
        do j = 1, ny
            if (ex(j, i) /= real((i - 1) * j) / real(nx)) then
                print *, "Test failed for ex at indices", i, j
                stop
            endif
        end do
    end do
    print *, "All tests passed for ex"

    ! Test ey
    do i = 1, nx
        do j = 1, ny
            if (ey(j, i) /= real((i - 1) * (j + 1)) / real(ny)) then
                print *, "Test failed for ey at indices", i, j
                stop
            endif
        end do
    end do
    print *, "All tests passed for ey"

    ! Test hz
    do i = 1, nx
        do j = 1, ny
            if (hz(j, i) /= real((i - 1) * (j + 2)) / real(nx)) then
                print *, "Test failed for hz at indices", i, j
                stop
            endif
        end do
    end do
    print *, "All tests passed for hz"

end program test_init_array
```

### C++ Unit Test

For the C++ code, we'll use the Google Test framework for unit testing. First, ensure you have Google Test installed and set up in your project.

```cpp
#include <gtest/gtest.h>
#include <vector>

// Assuming DATA_TYPE is a floating-point type, e.g., double
using DATA_TYPE = double;

// Function prototype
void init_array(int tmax, int nx, int ny, std::vector<std::vector<DATA_TYPE>>& ex, std::vector<std::vector<DATA_TYPE>>& ey, std::vector<std::vector<DATA_TYPE>>& hz, std::vector<DATA_TYPE>& fict);

TEST(InitArrayTest, TestFict) {
    int tmax = 10;
    std::vector<DATA_TYPE> fict(tmax);
    init_array(tmax, 5, 3, {}, {}, {}, fict);
    for (int i = 0; i < tmax; ++i) {
        EXPECT_DOUBLE_EQ(fict[i], static_cast<DATA_TYPE>(i));
    }
}

TEST(InitArrayTest, TestEx) {
    std::vector<std::vector<DATA_TYPE>> ex(3, std::vector<DATA_TYPE>(5));
    init_array(10, 5, 3, ex, {}, {}, {});
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 3; ++j) {
            EXPECT_DOUBLE_EQ(ex[j][i], static_cast<DATA_TYPE>((i * j) / 5.0));
        }
    }
}

TEST(InitArrayTest, TestEy) {
    std::vector<std::vector<DATA_TYPE>> ey(3, std::vector<DATA_TYPE>(5));
    init_array(10, 5, 3, {}, ey, {}, {});
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 3; ++j) {
            EXPECT_DOUBLE_EQ(ey[j][i], static_cast<DATA_TYPE>((i * (j + 1)) / 3.0));
        }
    }
}

TEST(InitArrayTest, TestHz) {
    std::vector<std::vector<DATA_TYPE>> hz(3, std::vector<DATA_TYPE>(5));
    init_array(10, 5, 3
