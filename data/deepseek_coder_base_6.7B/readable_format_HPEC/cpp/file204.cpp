Certainly! Below is the translated Fortran code to C++:

```cpp
#include <vector>

// Assuming DATA_TYPE is a floating-point type (e.g., double)
using DATA_TYPE = double;

void init_array(int n, std::vector<DATA_TYPE>& p, std::vector<std::vector<DATA_TYPE>>& a) {
    // Resize the vectors to match the dimensions
    p.resize(n);
    a.resize(n, std::vector<DATA_TYPE>(n));

    // Initialize the arrays
    for (int i = 0; i < n; ++i) {
        p[i] = 1.0 / n;
        for (int j = 0; j < n; ++j) {
            a[j][i] = 1.0 / n;
        }
    }
}

int main() {
    int n = 5; // Example size
    std::vector<DATA_TYPE> p;
    std::vector<std::vector<DATA_TYPE>> a;

    init_array(n, p, a);

    // Optional: Print the arrays to verify
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < n; ++i) {
        std::cout << p[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

### Explanation:
1. **Data Types**: The `DATA_TYPE` is defined as `double` in C++. This matches the Fortran code's `DATA_TYPE`.
2. **Vectors**: The `p` array is a `std::vector<DATA_TYPE>`, and `a` is a `std::vector<std::vector<DATA_TYPE>>` to represent the 2D array.
3. **Initialization**: The `init_array` function initializes the `p` and `a` arrays based on the given logic.
4. **Main Function**: Demonstrates how to call `init_array` and print the arrays (optional).

This C++ code should provide similar functionality to the provided Fortran subroutine.
Let's write some test to verify if the translation is correct. 
Below are the unit tests for both the original Fortran code and the translated C++ code.

### Fortran Unit Test

First, let's create a Fortran program to test the `init_array` subroutine.

```fortran
program test_init_array
    implicit none
    integer, parameter :: n = 5
    real(8), dimension(n) :: p
    real(8), dimension(n, n) :: a
    integer :: i, j

    call init_array(n, p, a)

    ! Print the arrays
    do i = 1, n
        print *, 'p(', i, ') = ', p(i)
    end do

    do i = 1, n
        do j = 1, n
            print *, 'a(', j, ',', i, ') = ', a(j, i)
        end do
    end do
end program test_init_array

subroutine init_array(n, p, a)
    implicit none
    integer, intent(in) :: n
    real(8), dimension(n), intent(out) :: p
    real(8), dimension(n, n), intent(out) :: a
    integer :: i, j

    do i = 1, n
        p(i) = 1.0d0 / n
        do j = 1, n
            a(j, i) = 1.0d0 / n
        end do
    end do
end subroutine init_array
```

### C++ Unit Test

Now, let's create a C++ program to test the `init_array` function.

```cpp
#include <iostream>
#include <vector>
#include <cmath> // For fabs

using DATA_TYPE = double;

void init_array(int n, std::vector<DATA_TYPE>& p, std::vector<std::vector<DATA_TYPE>>& a) {
    p.resize(n);
    a.resize(n, std::vector<DATA_TYPE>(n));

    for (int i = 0; i < n; ++i) {
        p[i] = 1.0 / n;
        for (int j = 0; j < n; ++j) {
            a[j][i] = 1.0 / n;
        }
    }
}

int main() {
    int n = 5;
    std::vector<DATA_TYPE> p;
    std::vector<std::vector<DATA_TYPE>> a;

    init_array(n, p, a);

    // Print the arrays
    for (int i = 0; i < n; ++i) {
        std::cout << "p(" << i << ") = " << p[i] << std::endl;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << "a(" << j << "," << i << ") = " << a[j][i] << std::endl;
        }
    }

    return 0;
}
```

### Explanation:
1. **Fortran Test**:
   - The `test_init_array` program calls the `init_array` subroutine.
   - It prints the values of `p` and `a` to verify the initialization.

2. **C++ Test**:
   - The `main` function calls the `init_array` function.
   - It prints the values of `p` and `a` to verify the initialization.

### Running the Tests:
1. **Fortran**:
   - Save the Fortran code in a file, e.g., `test_init_array.f90`.
   - Compile and run the Fortran code using a Fortran compiler, e.g., `gfortran`:
     ```sh
     gfortran test_init_array.f90 -o test_init_array
     ./test_init_array
     ```

2. **C++**:
   - Save the C++ code in a file, e.g., `test_init_array.cpp`.
   - Compile and run the C++ code using a C++ compiler, e.g., `g++`:
     ```sh
     g++ test_init_array.cpp -o test_init_array
     ./test_init_array
     ```

Both programs should output the initialized values of `p` and `a`, allowing you to verify that the translation is correct.
