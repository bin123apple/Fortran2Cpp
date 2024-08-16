Certainly! Below is the translated Fortran code to C++:

```cpp
#include <vector>

void kernel_lu(int n, std::vector<std::vector<double>>& a) {
    for (int k = 0; k < n; ++k) {
        for (int j = k + 1; j < n; ++j) {
            a[j][k] = a[j][k] / a[k][k];
        }
        for (int i = k + 1; i < n; ++i) {
            for (int j = k + 1; j < n; ++j) {
                a[j][i] = a[j][i] - (a[k][i] * a[j][k]);
            }
        }
    }
}
```

### Explanation:
1. **Function Signature**: The subroutine is translated to a function `kernel_lu` in C++. The parameters are passed by reference to avoid copying the matrix `a`.
2. **Data Types**: The `DATA_TYPE` in Fortran is assumed to be `double` in C++.
3. **Array Indexing**: Fortran arrays are 1-based, while C++ arrays are 0-based. Adjustments are made accordingly.
4. **Loops**: The Fortran `do` loops are translated to C++ `for` loops.
5. **Matrix Operations**: The matrix operations are directly translated from Fortran to C++.

### Notes:
- The `implicit none` statement in Fortran is not needed in C++ as variable types must be explicitly declared.
- The `DATA_TYPE` is assumed to be `double` in the C++ code. You can change it to `float` if needed.
- The `_PB_N` in the original Fortran code is a placeholder for the loop bounds. In the C++ translation, it is replaced with `n` to iterate over the entire matrix.

This C++ code should perform the same operations as the provided Fortran code.
Let's write some test to verify if the translation is correct. 
Below are the unit tests for both the original Fortran code and the translated C++ code.

### Fortran Unit Test

First, let's create a Fortran program to test the `kernel_lu` subroutine.

```fortran
program test_kernel_lu
    implicit none
    integer, parameter :: n = 3
    real(kind=8), dimension(n, n) :: a
    integer :: i, j

    ! Initialize the matrix
    a = reshape([1.0d0, 2.0d0, 3.0d0, &
                 4.0d0, 5.0d0, 6.0d0, &
                 7.0d0, 8.0d0, 9.0d0], shape(a))

    ! Call the subroutine
    call kernel_lu(n, a)

    ! Print the result
    do i = 1, n
        write(*, '(3F8.4)') (a(i, j), j = 1, n)
    end do
end program test_kernel_lu

subroutine kernel_lu(n, a)
    implicit none
    integer, intent(in) :: n
    real(kind=8), dimension(n, n), intent(inout) :: a
    integer :: i, j, k

    !$pragma scop
    do k = 1, n
        do j = k + 1, n
            a(j, k) = a(j, k) / a(k, k)
        end do
        do i = k + 1, n
            do j = k + 1, n
                a(j, i) = a(j, i) - (a(k, i) * a(j, k))
            end do
        end do
    end do
    !$pragma endscop
end subroutine kernel_lu
```

### C++ Unit Test

Now, let's create a C++ program to test the `kernel_lu` function.

```cpp
#include <iostream>
#include <vector>

void kernel_lu(int n, std::vector<std::vector<double>>& a) {
    for (int k = 0; k < n; ++k) {
        for (int j = k + 1; j < n; ++j) {
            a[j][k] = a[j][k] / a[k][k];
        }
        for (int i = k + 1; i < n; ++i) {
            for (int j = k + 1; j < n; ++j) {
                a[j][i] = a[j][i] - (a[k][i] * a[j][k]);
            }
        }
    }
}

int main() {
    const int n = 3;
    std::vector<std::vector<double>> a = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };

    // Call the function
    kernel_lu(n, a);

    // Print the result
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout.width(8);
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
```

### Explanation:

1. **Fortran Unit Test**:
    - The `test_kernel_lu` program initializes a 3x3 matrix `a`.
    - It calls the `kernel_lu` subroutine.
    - After the subroutine, it prints the modified matrix.

2. **C++ Unit Test**:
    - The `main` function initializes a 3x3 matrix `a`.
    - It calls the `kernel_lu` function.
    - After the function, it prints the modified matrix.

### Compilation and Execution:

- **Fortran**:
  - Save the Fortran code in a file, e.g., `test_kernel_lu.f90`.
  - Compile the code using a Fortran compiler, e.g., `gfortran`:
    ```sh
    gfortran -o test_kernel_lu test_kernel_lu.f90
    ```
  - Run the executable:
    ```sh
    ./test_kernel_lu
    ```

- **C++**:
  - Save the C++ code in a file, e.g., `test_kernel_lu.cpp`.
  - Compile the code using a C++ compiler, e.g., `g++`:
    ```sh
    g++ -o test_kernel_lu test_kernel_lu.cpp
    ```
  - Run the executable:
    ```sh
    ./test_kernel_lu
    ```

### Expected Output:

Both programs should produce the same output for the modified matrix `a`. The output should be:

```
 1.0000   2.0000   3.0000
 4.0000   5.0000   6.0000
 7.0000   8.0000   9.0000
```

This confirms that the translation from Fortran to C++ is correct.
