To translate the given Fortran code to C++, we need to consider several aspects, including the data types, array indexing, and the loop constructs. Fortran arrays are 1-based, while C++ arrays are 0-based. Also, the Fortran subroutine can be translated to a C++ function. Here's a C++ version of the provided Fortran code:

```cpp
#include <vector>

// Assuming DATA_TYPE is a floating-point type (e.g., float or double)
using DATA_TYPE = double;

void kernel_mvt(int n, std::vector<DATA_TYPE>& x1, std::vector<DATA_TYPE>& x2, const std::vector<DATA_TYPE>& y1, const std::vector<DATA_TYPE>& y2, const std::vector<std::vector<DATA_TYPE>>& a) {
    // Adjusting for 0-based indexing in C++
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            x1[i] += a[j][i] * y1[j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            x2[i] += a[i][j] * y2[j];
        }
    }
}

int main() {
    // Example usage
    int n = 5; // Size of the matrices
    std::vector<DATA_TYPE> x1(n, 0), x2(n, 0), y1(n, 1), y2(n, 2); // Initialize vectors
    std::vector<std::vector<DATA_TYPE>> a(n, std::vector<DATA_TYPE>(n, 3)); // Initialize matrix a

    kernel_mvt(n, x1, x2, y1, y2, a);

    // Output results for verification
    for (int i = 0; i < n; ++i) {
        std::cout << "x1[" << i << "] = " << x1[i] << ", x2[" << i << "] = " << x2[i] << std::endl;
    }

    return 0;
}
```

### Key Points:

1. **Data Types**: The `DATA_TYPE` is assumed to be a floating-point type (`float` or `double`). You can change the type as per your requirements.

2. **Arrays**: The Fortran arrays are translated to `std::vector` in C++ for dynamic sizing and ease of use.

3. **Indexing**: Adjusted the loop indices to start from 0, as C++ uses 0-based indexing.

4. **Function Signature**: The Fortran subroutine is translated to a C++ function. The parameters are passed by reference to allow modifications within the function.

5. **Example Usage**: Included a `main` function to demonstrate how to initialize the vectors and call the `kernel_mvt` function.

This translation assumes that the size of the arrays (`n`) is known and fixed before the function is called. If the size of the arrays is not known at compile time, you might consider using `std::vector` or other dynamic data structures.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will help verify the correctness of the translation by comparing the output of both implementations.

### Fortran Unit Test

```fortran
program test_kernel_mvt
    implicit none
    integer, parameter :: n = 5
    real(kind=8) :: x1(n), x2(n), y1(n), y2(n)
    real(kind=8) :: a(n, n)
    integer :: i

    ! Initialize vectors and matrix
    x1 = 0.0
    x2 = 0.0
    y1 = (/1.0, 1.0, 1.0, 1.0, 1.0/)
    y2 = (/2.0, 2.0, 2.0, 2.0, 2.0/)
    a = reshape((/3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0/), shape(a))

    ! Call the subroutine
    call kernel_mvt(n, x1, x2, y1, y2, a)

    ! Print results
    print *, 'x1:', x1
    print *, 'x2:', x2

contains

    subroutine kernel_mvt(n, x1, x2, y1, y2, a)
        implicit none
        integer, intent(in) :: n
        real(kind=8), intent(inout) :: x1(n), x2(n)
        real(kind=8), intent(in) :: y1(n), y2(n)
        real(kind=8), intent(in) :: a(n, n)
        integer :: i, j

        !$pragma scop
        do i = 1, n
            do j = 1, n
                x1(i) = x1(i) + (a(j, i) * y1(j))
            end do
        end do

        do i = 1, n
            do j = 1, n
                x2(i) = x2(i) + (a(i, j) * y2(j))
            end do
        end do
        !$pragma endscop
    end subroutine kernel_mvt

end program test_kernel_mvt
```

### C++ Unit Test

```cpp
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using DATA_TYPE = double;

void kernel_mvt(int n, std::vector<DATA_TYPE>& x1, std::vector<DATA_TYPE>& x2, const std::vector<DATA_TYPE>& y1, const std::vector<DATA_TYPE>& y2, const std::vector<std::vector<DATA_TYPE>>& a) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            x1[i] += a[j][i] * y1[j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            x2[i] += a[i][j] * y2[j];
        }
    }
}

void test_kernel_mvt() {
    int n = 5;
    std::vector<DATA_TYPE> x1(n, 0), x2(n, 0), y1(n, 1), y2(n, 2);
    std::vector<std::vector<DATA_TYPE>> a(n, std::vector<DATA_TYPE>(n, 3));

    kernel_mvt(n, x1, x2, y1, y2, a);

    // Expected results
    std::vector<DATA_TYPE> expected_x1 = {15, 15, 15, 15, 15};
    std::vector<DATA_TYPE> expected_x2 = {30, 30, 30, 30, 30};

    for (int i = 0; i < n; ++i) {
        assert(std::fabs(x1[i] - expected_x1[i]) < 1e-6);
        assert(std::fabs(x2[i] - expected_x2[i]) < 1e-6);
    }

    std::cout << "All tests passed." << std::endl;
}

int main() {
    test_kernel_mvt();
    return 0;
}
```

### Explanation:

1. **Fortran Unit Test**:
   - The `test_kernel_mvt` program initializes the vectors and matrix `a`.
