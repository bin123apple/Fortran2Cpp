Certainly! Below is the translated Fortran code to C++:

```cpp
#include <vector>

// Assuming DATA_TYPE is a floating-point type (e.g., float or double)
using DATA_TYPE = double;

void kernel_covariance(int m, int n, DATA_TYPE float_n, std::vector<std::vector<DATA_TYPE>>& dat, std::vector<std::vector<DATA_TYPE>>& symmat, std::vector<DATA_TYPE>& mean) {
    // Determine mean of column vectors of input data matrix
    for (int j = 0; j < m; ++j) {
        mean[j] = 0.0;
        for (int i = 0; i < n; ++i) {
            mean[j] += dat[j][i];
        }
        mean[j] /= float_n;
    }

    // Center the column vectors.
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dat[j][i] -= mean[j];
        }
    }

    // Calculate the m * m covariance matrix.
    for (int j1 = 0; j1 < m; ++j1) {
        for (int j2 = j1; j2 < m; ++j2) {
            symmat[j2][j1] = 0.0;
            for (int i = 0; i < n; ++i) {
                symmat[j2][j1] += dat[j1][i] * dat[j2][i];
            }
            symmat[j1][j2] = symmat[j2][j1];
        }
    }
}

int main() {
    // Example usage
    int m = 3; // Number of rows
    int n = 4; // Number of columns
    DATA_TYPE float_n = static_cast<DATA_TYPE>(n);

    // Initialize data matrix and mean vector
    std::vector<std::vector<DATA_TYPE>> dat = {
        {1.0, 2.0, 3.0, 4.0},
        {5.0, 6.0, 7.0, 8.0},
        {9.0, 10.0, 11.0, 12.0}
    };
    std::vector<std::vector<DATA_TYPE>> symmat(m, std::vector<DATA_TYPE>(m, 0.0));
    std::vector<DATA_TYPE> mean(m, 0.0);

    // Call the kernel_covariance function
    kernel_covariance(m, n, float_n, dat, symmat, mean);

    // Output results
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << symmat[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
```

### Explanation:
1. **Data Types and Variables**:
   - The `DATA_TYPE` is defined as `double`. You can change it to `float` if needed.
   - The input matrices and vectors are represented using `std::vector`.

2. **Mean Calculation**:
   - The mean of each column is calculated and stored in the `mean` vector.

3. **Centering the Data**:
   - Each element of the data matrix is subtracted by its corresponding mean.

4. **Covariance Matrix Calculation**:
   - The covariance matrix is calculated using the centered data.

5. **Main Function**:
   - An example `main` function is provided to demonstrate how to call the `kernel_covariance` function and print the results.

This C++ code should provide the same functionality as the original Fortran code.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code.

### Fortran Unit Test Code

```fortran
program test_kernel_covariance
    implicit none
    integer, parameter :: m = 3, n = 4
    real(kind=8), dimension(m, n) :: dat
    real(kind=8), dimension(m, m) :: symmat
    real(kind=8), dimension(m) :: mean
    real(kind=8) :: float_n
    integer :: i, j

    ! Initialize data
    float_n = real(n, kind=8)
    dat = reshape([1.0d0, 5.0d0, 9.0d0, &
                   2.0d0, 6.0d0, 10.0d0, &
                   3.0d0, 7.0d0, 11.0d0, &
                   4.0d0, 8.0d0, 12.0d0], shape(dat))

    ! Call the subroutine
    call kernel_covariance(m, n, float_n, dat, symmat, mean)

    ! Print the results
    print *, "Mean:"
    print *, mean
    print *, "Covariance Matrix:"
    do i = 1, m
        print *, symmat(i, :)
    end do
end program test_kernel_covariance

subroutine kernel_covariance(m, n, float_n, dat, symmat, mean)
    implicit none
    integer, intent(in) :: m, n
    real(kind=8), intent(in) :: float_n
    real(kind=8), dimension(m, n), intent(in) :: dat
    real(kind=8), dimension(m, m), intent(out) :: symmat
    real(kind=8), dimension(m), intent(out) :: mean
    integer :: i, j, j1, j2

    ! Determine mean of column vectors of input data matrix
    do j = 1, m
        mean(j) = 0.0D0
        do i = 1, n
            mean(j) = mean(j) + dat(j, i)
        end do
        mean(j) = mean(j) / float_n
    end do

    ! Center the column vectors.
    do i = 1, n
        do j = 1, m
            dat(j, i) = dat(j, i) - mean(j)
        end do
    end do

    ! Calculate the m * m covariance matrix.
    do j1 = 1, m
        do j2 = j1, m
            symmat(j2, j1) = 0.0D0
            do i = 1, n
                symmat(j2, j1) = symmat(j2, j1) + (dat(j1, i) * dat(j2, i))
            end do
            symmat(j1, j2) = symmat(j2, j1)
        end do
    end do
end subroutine kernel_covariance
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <vector>
#include <iomanip>

using DATA_TYPE = double;

void kernel_covariance(int m, int n, DATA_TYPE float_n, std::vector<std::vector<DATA_TYPE>>& dat, std::vector<std::vector<DATA_TYPE>>& symmat, std::vector<DATA_TYPE>& mean) {
    // Determine mean of column vectors of input data matrix
    for (int j = 0; j < m; ++j) {
        mean[j] = 0.0;
        for (int i = 0; i < n; ++i) {
            mean[j] += dat[j][i];
        }
        mean[j] /= float_n;
    }

    // Center the column vectors.
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dat[j][i] -= mean[j];
        }
    }

    // Calculate the m * m covariance matrix.
    for (int j1 = 0; j1 < m; ++j1) {
        for (int j2 = j1; j2 < m; ++j2) {
            symmat
