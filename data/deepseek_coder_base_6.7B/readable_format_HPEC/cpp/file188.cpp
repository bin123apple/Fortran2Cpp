Certainly! Below is the translated Fortran code to C++:

```cpp
#include <vector>

// Assuming DATA_TYPE is a floating-point type (e.g., float or double)
using DATA_TYPE = double;

void kernel_durbin(int n, std::vector<std::vector<DATA_TYPE>>& y, std::vector<std::vector<DATA_TYPE>>& sumArray, std::vector<DATA_TYPE>& alpha, std::vector<DATA_TYPE>& beta, const std::vector<DATA_TYPE>& r, std::vector<DATA_TYPE>& outArray) {
    // Initialize beta and alpha arrays
    beta[0] = 1;
    alpha[0] = r[0];

    for (int k = 1; k < n; ++k) {
        beta[k] = beta[k - 1] - (alpha[k - 1] * alpha[k - 1] * beta[k - 1]);
        sumArray[k][0] = r[k];

        for (int i = 0; i < k; ++i) {
            sumArray[k][i + 1] = sumArray[k][i] + (r[k - i - 1] * y[k - 1][i]);
        }

        alpha[k] = alpha[k] - (sumArray[k][k] * beta[k]);

        for (int i = 0; i < k; ++i) {
            y[k][i] = y[k - 1][i] + (alpha[k] * y[k - 1][k - i - 1]);
        }

        y[k][k] = alpha[k];
    }

    for (int i = 0; i < n; ++i) {
        outArray[i] = y[n - 1][i];
    }
}

int main() {
    // Example usage
    int n = 5; // Size of the arrays
    std::vector<std::vector<DATA_TYPE>> y(n, std::vector<DATA_TYPE>(n));
    std::vector<std::vector<DATA_TYPE>> sumArray(n, std::vector<DATA_TYPE>(n));
    std::vector<DATA_TYPE> alpha(n);
    std::vector<DATA_TYPE> beta(n);
    std::vector<DATA_TYPE> r = {1.0, 2.0, 3.0, 4.0, 5.0}; // Example input
    std::vector<DATA_TYPE> outArray(n);

    kernel_durbin(n, y, sumArray, alpha, beta, r, outArray);

    // Output results
    for (int i = 0; i < n; ++i) {
        std::cout << "outArray[" << i << "] = " << outArray[i] << std::endl;
    }

    return 0;
}
```

### Explanation:
1. **Initialization**:
   - The `beta` and `alpha` arrays are initialized with the first element of the `r` array.

2. **Computation Loops**:
   - The nested loops are translated directly from Fortran to C++.

3. **Output**:
   - The results are copied from the `y` array to the `outArray` vector.

This C++ code should provide equivalent functionality to the provided Fortran code.
Let's write some test to verify if the translation is correct. 
Below are the unit tests for both the original Fortran code and the translated C++ code.

### Fortran Unit Test

First, let's create a Fortran program to test the `kernel_durbin` subroutine.

```fortran
program test_kernel_durbin
    implicit none
    integer, parameter :: n = 5
    real, dimension(n, n) :: y
    real, dimension(n, n) :: sumArray
    real, dimension(n) :: beta
    real, dimension(n) :: alpha
    real, dimension(n) :: r = [1.0, 2.0, 3.0, 4.0, 5.0]
    real, dimension(n) :: outArray
    integer :: i

    call kernel_durbin(n, y, sumArray, alpha, beta, r, outArray)

    print *, 'outArray:'
    do i = 1, n
        print *, outArray(i)
    end do
end program test_kernel_durbin

subroutine kernel_durbin(n, y, sumArray, alpha, beta, r, outArray)
    implicit none
    integer, intent(in) :: n
    real, dimension(n, n), intent(inout) :: y
    real, dimension(n, n), intent(inout) :: sumArray
    real, dimension(n), intent(inout) :: beta
    real, dimension(n), intent(inout) :: alpha
    real, dimension(n), intent(in) :: r
    real, dimension(n), intent(out) :: outArray
    integer :: i, k

    !$pragma scop
    y(1, 1) = r(1)
    beta(1) = 1
    alpha(1) = r(1)
    do k = 2, n
        beta(k) = beta(k - 1) - (alpha(k - 1) * alpha(k - 1) * beta(k - 1))
        sumArray(k, 1) = r(k)
        do i = 1, k - 1
            sumArray(k, i + 1) = sumArray(k, i) + (r(k - i) * y(k - 1, i))
        end do
        alpha(k) = alpha(k) - (sumArray(k, k) * beta(k))
        do i = 1, k - 1
            y(k, i) = y(k - 1, i) + (alpha(k) * y(k - 1, k - i))
        end do
        y(k, k) = alpha(k)
    end do
    do i = 1, n
        outArray(i) = y(n, i)
    end do
    !$pragma endscop
end subroutine kernel_durbin
```

### C++ Unit Test

Now, let's create a C++ program to test the translated `kernel_durbin` function.

```cpp
#include <iostream>
#include <vector>

using DATA_TYPE = double;

void kernel_durbin(int n, std::vector<std::vector<DATA_TYPE>>& y, std::vector<std::vector<DATA_TYPE>>& sumArray, std::vector<DATA_TYPE>& alpha, std::vector<DATA_TYPE>& beta, const std::vector<DATA_TYPE>& r, std::vector<DATA_TYPE>& outArray) {
    beta[0] = 1;
    alpha[0] = r[0];

    for (int k = 1; k < n; ++k) {
        beta[k] = beta[k - 1] - (alpha[k - 1] * alpha[k - 1] * beta[k - 1]);
        sumArray[k][0] = r[k];

        for (int i = 0; i < k; ++i) {
            sumArray[k][i + 1] = sumArray[k][i] + (r[k - i - 1] * y[k - 1][i]);
        }

        alpha[k] = alpha[k] - (sumArray[k][k] * beta[k]);

        for (int i = 0; i < k; ++i) {
            y[k][i] = y[k - 1][i] + (alpha[k] * y[k - 1][k - i - 1]);
        }

        y[k][k] = alpha[k];
    }

    for (int i = 0; i < n; ++i) {
        outArray[i] = y[n - 1][i];
    }
}

int main() {
    int n = 5;
    std::vector<std::vector<DATA_TYPE>> y(n, std::vector<DATA_TYPE>(n));
    std::vector<std::vector<DATA_TYPE>> sumArray(n, std::vector<DATA_TYPE>(n));
    std::vector<DATA_TYPE> alpha(n
