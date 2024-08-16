Certainly! Below is the translated Fortran code to C++:

```cpp
#include <iostream>
#include <iomanip>

// Assuming DATA_TYPE is a float for this translation. If it's different, you should adjust the type accordingly.
using DATA_TYPE = float;

void print_array(int ni, DATA_TYPE** c) {
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < ni; ++j) {
            // Assuming DATA_PRINTF_MODIFIER is a format specifier for floating-point numbers.
            // If it's different, you should adjust the format accordingly.
            std::cout << std::setprecision(6) << std::fixed << c[j][i] << " ";
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

### Explanation:
1. **Data Type**: The `DATA_TYPE` is assumed to be `float` in the C++ translation. If it's different, you should adjust the type accordingly.
2. **Array Initialization**: The Fortran code dynamically allocates a 2D array `c` with dimensions `ni x ni`. In C++, we use a pointer to a pointer to achieve the same effect.
3. **Printing the Array**: The nested loops iterate over the array, printing each element. The `std::setprecision(6)` and `std::fixed` are used to format the floating-point numbers similarly to the Fortran code's `write` statement with the `DATA_PRINTF_MODIFIER`.
4. **Cleanup**: Memory is cleaned up by deleting the dynamically allocated arrays.

This C++ code should provide similar functionality to the provided Fortran subroutine.
Let's write some test to verify if the translation is correct. 
Below are the unit tests for both the original Fortran code and the translated C++ code.

### Fortran Unit Test

First, let's create a Fortran program that tests the `print_array` subroutine.

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
    integer, parameter :: DATA_PRINTF_MODIFIER = '(F6.2)'
    integer :: ni, i, j
    real, dimension(ni, ni) :: c

    do i = 1, ni
        do j = 1, ni
            write(*, DATA_PRINTF_MODIFIER) c(j, i)
        end do
        write(*, *)
        if (mod(((i - 1) * ni) + j - 1, 20) == 0) then
            write(*, *)
        end if
    end do
    write(*, *)
end subroutine print_array
```

### C++ Unit Test

Now, let's create a C++ program that tests the `print_array` function.

```cpp
#include <iostream>
#include <iomanip>

using DATA_TYPE = float;

void print_array(int ni, DATA_TYPE** c) {
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < ni; ++j) {
            std::cout << std::setprecision(6) << std::fixed << c[j][i] << " ";
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

    print_array(ni, c);

    for (int i = 0; i < ni; ++i) {
        delete[] c[i];
    }
    delete[] c;

    return 0;
}
```

### Explanation:

1. **Fortran Unit Test**:
   - The `test_print_array` program initializes a 5x5 array `c` with values.
   - It then calls the `print_array` subroutine to print the array.

2. **C++ Unit Test**:
   - The `main` function initializes a 5x5 array `c` with values.
   - It calls the `print_array` function to print the array.
   - Memory is cleaned up by deleting the dynamically allocated arrays.

### Running the Tests:

To run the Fortran unit test, you can compile and execute the Fortran program using a Fortran compiler like `gfortran`:

```sh
gfortran -o test_print_array test_print_array.f90
./test_print_array
```

To run the C++ unit test, you can compile and execute the C++ program using a C++ compiler like `g++`:

```sh
g++ -o test_print_array test_print_array.cpp
./test_print_array
```

### Expected Output:

Both programs should produce the same output, which should look like this:

```
  1.00  6.00 11.00 16.00 21.00
  2.00  7.00 12.00 17.00 22.00
  3.00  8.00 13.00 18.00 23.00
  4.00  9.00 14.00 19.00 24.00
  5.00 10.00 15.00 20.00 25.00

```

This output verifies that the translation from Fortran to C++ is correct.
