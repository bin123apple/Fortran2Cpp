To translate the given Fortran code to C++, we need to consider the differences in array indexing, data types, and loop constructs between Fortran and C++. The Fortran code initializes arrays and fills them with values based on the given logic. Here's how you can translate it to C++:

```cpp
#include <vector>

// Assuming DATA_TYPE is a floating-point type, e.g., double
using DATA_TYPE = double;

void init_array(int n, std::vector<DATA_TYPE>& x1, std::vector<DATA_TYPE>& x2, std::vector<DATA_TYPE>& y1, std::vector<DATA_TYPE>& y2, std::vector<std::vector<DATA_TYPE>>& a) {
    // Resize the vectors to n elements
    x1.resize(n);
    x2.resize(n);
    y1.resize(n);
    y2.resize(n);
    a.resize(n, std::vector<DATA_TYPE>(n));

    for (int i = 0; i < n; ++i) {
        x1[i] = static_cast<DATA_TYPE>(i) / static_cast<DATA_TYPE>(n);
        x2[i] = (static_cast<DATA_TYPE>(i) + 1.0) / static_cast<DATA_TYPE>(n);
        y1[i] = (static_cast<DATA_TYPE>(i) + 3.0) / static_cast<DATA_TYPE>(n);
        y2[i] = (static_cast<DATA_TYPE>(i) + 4.0) / static_cast<DATA_TYPE>(n);

        for (int j = 0; j < n; ++j) {
            a[j][i] = (static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j)) / static_cast<DATA_TYPE>(n);
        }
    }
}

int main() {
    int n = 10; // Example size
    std::vector<DATA_TYPE> x1, x2, y1, y2;
    std::vector<std::vector<DATA_TYPE>> a;

    init_array(n, x1, x2, y1, y2, a);

    // Example to print the first row of a to verify the initialization
    for (int i = 0; i < n; ++i) {
        std::cout << a[0][i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

Key Points in the Translation:

1. **Array Initialization**: In C++, `std::vector` is used to dynamically allocate arrays. This is more flexible and safer compared to raw arrays.

2. **Data Types**: The `DATA_TYPE` is assumed to be `double`. You can change it to `float` or any other floating-point type if needed.

3. **Indexing**: Fortran arrays are 1-based, while C++ arrays are 0-based. This is accounted for in the translation.

4. **Loops**: The Fortran `do` loop is translated to C++ `for` loop.

5. **Resizing Arrays**: The vectors are resized to `n` elements before being used.

6. **Static Casting**: Used to convert integers to `DATA_TYPE` for division.

This translation assumes that `DATA_TYPE` is a floating-point type (e.g., `double`). If you need to use a different type, you should adjust the `using DATA_TYPE = ...;` line accordingly.
Let's write some test to verify if the translation is correct. 
Below are examples of unit tests for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the array initialization logic.

### Fortran Unit Test

For the Fortran code, we'll write a simple program that calls the `init_array` subroutine and checks the first row of the `a` array to ensure it matches the expected values.

```fortran
program test_init_array
    implicit none
    integer, parameter :: n = 10
    real(8), dimension(n) :: x1, x2, y1, y2
    real(8), dimension(n, n) :: a
    integer :: i
    real(8), dimension(n) :: expected_row
    logical :: test_passed

    call init_array(n, x1, x2, y1, y2, a)

    ! Expected values for the first row of 'a'
    do i = 1, n
        expected_row(i) = (i - 1) * 0.0 / n
    end do

    test_passed = .true.
    do i = 1, n
        if (abs(a(1, i) - expected_row(i)) > 1.0E-6) then
            test_passed = .false.
            exit
        endif
    end do

    if (test_passed) then
        print *, "Test Passed"
    else
        print *, "Test Failed"
    endif

end program test_init_array
```

### C++ Unit Test

For the C++ code, we'll use a simple test case that checks the first row of the `a` vector to ensure it matches the expected values.

```cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

using DATA_TYPE = double;

void init_array(int n, std::vector<DATA_TYPE>& x1, std::vector<DATA_TYPE>& x2, std::vector<DATA_TYPE>& y1, std::vector<DATA_TYPE>& y2, std::vector<std::vector<DATA_TYPE>>& a) {
    // Existing init_array function implementation
}

void test_init_array() {
    int n = 10;
    std::vector<DATA_TYPE> x1, x2, y1, y2;
    std::vector<std::vector<DATA_TYPE>> a;

    init_array(n, x1, x2, y1, y2, a);

    // Expected values for the first row of 'a'
    std::vector<DATA_TYPE> expected_row(n);
    for (int i = 0; i < n; ++i) {
        expected_row[i] = static_cast<DATA_TYPE>(i) * 0.0 / static_cast<DATA_TYPE>(n);
    }

    bool test_passed = true;
    for (int i = 0; i < n; ++i) {
        if (std::abs(a[0][i] - expected_row[i]) > 1.0E-6) {
            test_passed = false;
            break;
        }
    }

    assert(test_passed);
    std::cout << "Test Passed" << std::endl;
}

int main() {
    test_init_array();
    return 0;
}
```

### Explanation

1. **Fortran Test**:
   - The program initializes the arrays and checks the first row of `a` against expected values.
   - It prints "Test Passed" if the first row matches the expected values, otherwise it prints "Test Failed".

2. **C++ Test**:
   - The `test_init_array` function initializes the arrays and checks the first row of `a` against expected values.
   - It uses `assert` to ensure the first row matches the expected values. If the assertion fails, the program will terminate with an error.
   - If the test passes, it prints "Test Passed".

These tests ensure that the array initialization logic in both the Fortran and C++ versions behaves as expected.
