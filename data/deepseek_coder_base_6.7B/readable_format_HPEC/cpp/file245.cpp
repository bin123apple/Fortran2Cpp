Certainly! Below is the translated Fortran code to C++:

```cpp
#include <vector>
#include <iostream>

// Assuming DATA_TYPE is a floating-point type (e.g., float, double, etc.)
using DATA_TYPE = double;

void init_array(int n, std::vector<std::vector<DATA_TYPE>>& a, std::vector<DATA_TYPE>& x, std::vector<DATA_TYPE>& c) {
    // Resize the vectors to nxn and n elements respectively
    a.resize(n, std::vector<DATA_TYPE>(n));
    x.resize(n);
    c.resize(n);

    for (int i = 0; i < n; ++i) {
        c[i] = static_cast<DATA_TYPE>(i) / static_cast<DATA_TYPE>(n);
        x[i] = static_cast<DATA_TYPE>(i) / static_cast<DATA_TYPE>(n);
        for (int j = 0; j < n; ++j) {
            a[j][i] = static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j) / static_cast<DATA_TYPE>(n);
        }
    }
}

int main() {
    int n = 5; // Example size
    std::vector<std::vector<DATA_TYPE>> a;
    std::vector<DATA_TYPE> x, c;

    init_array(n, a, x, c);

    // Optional: Print the arrays for verification
    for (int i = 0; i < n; ++i) {
        std::cout << "c[" << i << "] = " << c[i] << ", x[" << i << "] = " << x[i] << std::endl;
        for (int j = 0; j < n; ++j) {
            std::cout << "a[" << j << "][" << i << "] = " << a[j][i] << std::endl;
        }
    }

    return 0;
}
```

### Explanation:
1. **Data Types**: The `DATA_TYPE` is defined as `double` in the C++ code. You can change it to `float` if needed.
2. **Vectors**: The arrays `a`, `x`, and `c` are represented using `std::vector`.
3. **Initialization**: The nested loops in Fortran are translated to nested loops in C++.
4. **Static Casting**: Used to convert integers to `DATA_TYPE`.
5. **Resizing**: The vectors are resized before being used to ensure they have the correct dimensions.

This C++ code should provide equivalent functionality to the provided Fortran subroutine.
Let's write some test to verify if the translation is correct. 
Below are the unit tests for both the original Fortran code and the translated C++ code.

### Fortran Unit Test

First, let's create a Fortran program to test the `init_array` subroutine:

```fortran
program test_init_array
    implicit none
    integer, parameter :: n = 5
    real, dimension(n, n) :: a
    real, dimension(n) :: c, x
    integer :: i, j

    call init_array(n, a, x, c)

    ! Print the arrays for verification
    do i = 1, n
        print *, 'c(', i, ') = ', c(i), ', x(', i, ') = ', x(i)
        do j = 1, n
            print *, 'a(', j, ',', i, ') = ', a(j, i)
        end do
    end do
end program test_init_array

subroutine init_array(n, a, x, c)
    implicit none
    integer, intent(in) :: n
    real, dimension(n, n), intent(out) :: a
    real, dimension(n), intent(out) :: c, x
    integer :: i, j

    do i = 1, n
        c(i) = real(i - 1) / real(n)
        x(i) = real(i - 1) / real(n)
        do j = 1, n
            a(j, i) = (real(i - 1) * real(j - 1)) / real(n)
        end do
    end do
end subroutine init_array
```

### C++ Unit Test

Now, let's create a C++ program to test the `init_array` function:

```cpp
#include <vector>
#include <iostream>
#include <cmath> // For fabs

using DATA_TYPE = double;

void init_array(int n, std::vector<std::vector<DATA_TYPE>>& a, std::vector<DATA_TYPE>& x, std::vector<DATA_TYPE>& c) {
    a.resize(n, std::vector<DATA_TYPE>(n));
    x.resize(n);
    c.resize(n);

    for (int i = 0; i < n; ++i) {
        c[i] = static_cast<DATA_TYPE>(i) / static_cast<DATA_TYPE>(n);
        x[i] = static_cast<DATA_TYPE>(i) / static_cast<DATA_TYPE>(n);
        for (int j = 0; j < n; ++j) {
            a[j][i] = static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j) / static_cast<DATA_TYPE>(n);
        }
    }
}

int main() {
    int n = 5; // Example size
    std::vector<std::vector<DATA_TYPE>> a;
    std::vector<DATA_TYPE> x, c;

    init_array(n, a, x, c);

    // Print the arrays for verification
    for (int i = 0; i < n; ++i) {
        std::cout << "c[" << i << "] = " << c[i] << ", x[" << i << "] = " << x[i] << std::endl;
        for (int j = 0; j < n; ++j) {
            std::cout << "a[" << j << "][" << i << "] = " << a[j][i] << std::endl;
        }
    }

    return 0;
}
```

### Explanation:

1. **Fortran Test**:
   - The `test_init_array` program calls the `init_array` subroutine.
   - It prints the arrays `a`, `x`, and `c` to verify the correct initialization.

2. **C++ Test**:
   - The `main` function calls the `init_array` function.
   - It prints the arrays `a`, `x`, and `c` to verify the correct initialization.

### Running the Tests:

To run the Fortran test:
1. Save the Fortran code in a file, e.g., `test_init_array.f90`.
2. Compile the Fortran code using a Fortran compiler, e.g., `gfortran`:
   ```sh
   gfortran -o test_init_array test_init_array.f90
   ```
3. Run the executable:
   ```sh
   ./test_init_array
   ```

To run the C++ test:
1. Save the C++ code in a file, e.g., `test_init_array.cpp`.
2. Compile the C++ code using a C++ compiler, e.g., `g++`:
   ```sh
   g++ -o test_init_array test_init_array.cpp
   ```
3. Run the executable:
   ```sh
   ./test_init_array
   ```

Both tests should output the initialized arrays for `a`, `x`, and `c`, allowing you to verify the correctness of the translation.
