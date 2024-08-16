To translate the given Fortran code to C++, we need to consider several aspects, including the syntax differences between Fortran and C++, the array indexing, and the way functions (or subroutines in Fortran) are defined and called. Here's a C++ version of the Fortran subroutine:

```cpp
#include <iostream>
#include <iomanip>

// Assuming DATA_TYPE is a type, for example, double, float, or int.
// You need to define it according to your specific needs.
using DATA_TYPE = double;

void print_array(int ni, DATA_TYPE** c) {
    // Assuming c is a 2D array dynamically allocated with size ni x ni.
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < ni; ++j) {
            // Assuming DATA_PRINTF_MODIFIER is a format specifier for the output.
            // You need to define it according to your specific needs.
            std::cout << std::setw(12) << c[j][i] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    const int ni = 5;
    DATA_TYPE** c = new DATA_TYPE*[ni];
    for (int i = 0; i < ni; ++i) {
        c[i] = new DATA_TYPE[ni];
        for (int j = 0; j < ni; ++j) {
            // Initialize the array with some values
            c[i][j] = static_cast<DATA_TYPE>(i * ni + j);
        }
    }

    print_array(ni, c);

    // Clean up
    for (int i = 0; i < ni; ++i) {
        delete[] c[i];
    }
    delete[] c;

    return 0;
}
```

### Key Points:

1. **Array Representation**: In C++, arrays are typically zero-indexed, unlike Fortran which is one-indexed. This difference is accounted for in the loops.

2. **Dynamic Allocation**: The example uses dynamic allocation for the 2D array `c`. This is necessary because the size of the array is not known at compile time.

3. **Formatting**: The `std::setw(12)` is used to format the output similar to the Fortran code's `write(0, DATA_PRINTF_MODIFIER)`. Adjust the width as needed.

4. **Printing**: The nested loops print the array elements, similar to the Fortran code.

5. **Cleanup**: Memory is cleaned up to avoid memory leaks.

6. **Function Signature**: The function `print_array` takes a pointer to a pointer (`DATA_TYPE** c`) to represent the 2D array.

This translation assumes that `DATA_TYPE` and `DATA_PRINTF_MODIFIER` are defined according to your specific needs. Adjust the types and formatting as necessary.
Let's write some test to verify if the translation is correct. 
Below are examples of unit tests for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the array printing functionality.

### Fortran Unit Test

For the Fortran code, we'll create a simple program that calls the `print_array` subroutine and checks its output.

```fortran
program test_print_array
    implicit none
    integer, parameter :: ni = 5
    real, dimension(ni, ni) :: c
    integer :: i, j

    ! Initialize the array
    do i = 1, ni
        do j = 1, ni
            c(j, i) = real(i * ni + j)
        end do
    end do

    ! Call the subroutine
    call print_array(ni, c)

end program test_print_array

subroutine print_array(ni, c)
    implicit none
    integer, parameter :: DATA_PRINTF_MODIFIER = 'F12.6'
    real, dimension(ni, ni) :: c
    integer :: ni, i, j

    do i = 1, ni
        do j = 1, ni
            write(*, DATA_PRINTF_MODIFIER) c(j, i)
        end do
        write(*, *)
    end do
    write(*, *)
end subroutine print_array
```

### C++ Unit Test

For the C++ code, we'll use a simple main function to call the `print_array` function and verify its output.

```cpp
#include <iostream>
#include <iomanip>
#include <cassert>

using DATA_TYPE = double;

void print_array(int ni, DATA_TYPE** c) {
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < ni; ++j) {
            std::cout << std::setw(12) << c[j][i] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    const int ni = 5;
    DATA_TYPE** c = new DATA_TYPE*[ni];
    for (int i = 0; i < ni; ++i) {
        c[i] = new DATA_TYPE[ni];
        for (int j = 0; j < ni; ++j) {
            c[i][j] = static_cast<DATA_TYPE>(i * ni + j);
        }
    }

    // Call the function
    print_array(ni, c);

    // Clean up
    for (int i = 0; i < ni; ++i) {
        delete[] c[i];
    }
    delete[] c;

    return 0;
}
```

### Explanation

1. **Fortran Test**:
   - The `test_print_array` program initializes a 2D array `c`.
   - It calls the `print_array` subroutine with `ni` and `c`.
   - The subroutine prints the array elements, which is then manually verified.

2. **C++ Test**:
   - The `main` function initializes a 2D array `c`.
   - It calls the `print_array` function with `ni` and `c`.
   - The function prints the array elements, which is then manually verified.

### Running the Tests

- **Fortran**: Compile and run the Fortran test program using a Fortran compiler, e.g., `gfortran`.
  ```sh
  gfortran -o test_fortran test_print_array.f90
  ./test_fortran
  ```

- **C++**: Compile and run the C++ test program using a C++ compiler, e.g., `g++`.
  ```sh
  g++ -o test_cpp test_print_array.cpp
  ./test_cpp
  ```

These tests will print the array to the console. Manually verify that the output matches the expected values. If the outputs are identical, the translation is likely correct.
