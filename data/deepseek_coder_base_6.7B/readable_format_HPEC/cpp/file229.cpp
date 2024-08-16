Certainly! Below is the translated Fortran code to C++:

```cpp
#include <vector>
#include <iostream>

// Assuming DATA_TYPE is a floating-point type, e.g., double
using DATA_TYPE = double;

void init_array(int n, DATA_TYPE& alpha, std::vector<std::vector<DATA_TYPE>>& a, std::vector<std::vector<DATA_TYPE>>& b) {
    alpha = 32412.0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[j][i] = static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j) / static_cast<DATA_TYPE>(n);
            b[j][i] = static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j) / static_cast<DATA_TYPE>(n);
        }
    }
}

int main() {
    int n = 10; // Example size
    DATA_TYPE alpha;
    std::vector<std::vector<DATA_TYPE>> a(n, std::vector<DATA_TYPE>(n));
    std::vector<std::vector<DATA_TYPE>> b(n, std::vector<DATA_TYPE>(n));

    init_array(n, alpha, a, b);

    // Optional: Print alpha and the first element of a and b for verification
    std::cout << "alpha: " << alpha << std::endl;
    std::cout << "a[0][0]: " << a[0][0] << std::endl;
    std::cout << "b[0][0]: " << b[0][0] << std::endl;

    return 0;
}
```

### Explanation:
1. **Data Types**: The `DATA_TYPE` is assumed to be `double` in C++.
2. **Matrices**: `a` and `b` are represented as `std::vector<std::vector<DATA_TYPE>>`.
3. **Initialization**: The `init_array` function initializes `alpha` and the matrices `a` and `b`.
4. **Loops**: The nested loops iterate over the matrices, similar to the Fortran code.

### Notes:
- The `static_cast<DATA_TYPE>()` is used to ensure the division result is of type `DATA_TYPE`.
- The `main` function demonstrates how to call `init_array` and print the results for verification.
Let's write some test to verify if the translation is correct. 
Below are the unit tests for both the original Fortran code and the translated C++ code.

### Fortran Unit Test

First, let's create a Fortran program to test the subroutine:

```fortran
program test_init_array
    implicit none
    integer, parameter :: n = 10
    real(8) :: alpha
    real(8), dimension(n, n) :: a, b
    integer :: i, j

    call init_array(n, alpha, a, b)

    print *, 'alpha:', alpha
    print *, 'a(1,1):', a(1,1)
    print *, 'b(1,1):', b(1,1)

    contains

    subroutine init_array(n, alpha, a, b)
        implicit none
        real(8), dimension(n, n) :: a, b
        real(8) :: alpha
        integer :: n, i, j

        alpha = 32412D0
        do i = 1, n
            do j = 1, n
                a(j, i) = (real(i - 1) * real(j - 1)) / real(n)
                b(j, i) = ((real(i - 1) * real(j - 1))) / real(n)
            end do
        end do
    end subroutine init_array

end program test_init_array
```

### C++ Unit Test

Next, let's create a C++ program to test the function:

```cpp
#include <vector>
#include <iostream>
#include <cmath> // For fabs()

using DATA_TYPE = double;

void init_array(int n, DATA_TYPE& alpha, std::vector<std::vector<DATA_TYPE>>& a, std::vector<std::vector<DATA_TYPE>>& b) {
    alpha = 32412.0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[j][i] = static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j) / static_cast<DATA_TYPE>(n);
            b[j][i] = static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j) / static_cast<DATA_TYPE>(n);
        }
    }
}

bool are_matrices_equal(const std::vector<std::vector<DATA_TYPE>>& a, const std::vector<std::vector<DATA_TYPE>>& b, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (std::fabs(a[i][j] - b[i][j]) > 1e-6) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n = 10; // Example size
    DATA_TYPE alpha;
    std::vector<std::vector<DATA_TYPE>> a(n, std::vector<DATA_TYPE>(n));
    std::vector<std::vector<DATA_TYPE>> b(n, std::vector<DATA_TYPE>(n));
    std::vector<std::vector<DATA_TYPE>> expected_a(n, std::vector<DATA_TYPE>(n));
    std::vector<std::vector<DATA_TYPE>> expected_b(n, std::vector<DATA_TYPE>(n));

    // Expected values for verification
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            expected_a[i][j] = static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j) / static_cast<DATA_TYPE>(n);
            expected_b[i][j] = static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j) / static_cast<DATA_TYPE>(n);
        }
    }

    init_array(n, alpha, a, b);

    std::cout << "alpha: " << alpha << std::endl;
    std::cout << "a[0][0]: " << a[0][0] << std::endl;
    std::cout << "b[0][0]: " << b[0][0] << std::endl;

    if (are_matrices_equal(a, expected_a, n) && are_matrices_equal(b, expected_b, n)) {
        std::cout << "Test passed!" << std::endl;
    } else {
        std::cout << "Test failed!" << std::endl;
    }

    return 0;
}
```

### Explanation:

1. **Fortran Test**:
   - The `test_init_array` program calls the `init_array` subroutine.
   - It prints the values of `alpha` and the first element of `a` and `b` to verify the correctness.

2. **C++ Test**:
   - The `main` function initializes the matrices `a` and `b` using the `init_array` function.
   - It prints the values of `alpha` and the first element of `a` and `b` to verify the correctness.
   - It compares the computed matrices `a` and `b` with the expected matrices `expected_a` and `expected_b` using the `are_matrices_equal` function.
   - If the matrices are equal, it prints "Test passed!"; otherwise, it prints "Test failed!"
