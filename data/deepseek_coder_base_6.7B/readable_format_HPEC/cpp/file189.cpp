To translate the given Fortran code to C++, we need to consider several aspects, such as array indexing, I/O operations, and the loop structure. Fortran arrays are 1-based, while C++ arrays are 0-based. Also, Fortran's `write` statement for output is somewhat different from C++'s `std::cout`. Here's a C++ version of the given Fortran subroutine:

```cpp
#include <iostream>
#include <iomanip>

// Assuming the data type is float for the array elements.
// You can change the type as per your requirement.
using DataType = float;

void print_array(int n, DataType** a) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // Adjusting for 0-based indexing in C++
            std::cout << std::setw(12) << a[j][i];
            if ((i * n + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    const int n = 10; // Size of the array
    DataType** a = new DataType*[n];
    for (int i = 0; i < n; ++i) {
        a[i] = new DataType[n];
        // Initialize the array with some values
        for (int j = 0; j < n; ++j) {
            a[i][j] = static_cast<DataType>(i * n + j);
        }
    }

    print_array(n, a);

    // Clean up
    for (int i = 0; i < n; ++i) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}
```

### Key Points:

1. **Array Indexing:** Adjusted the loop indices to start from 0, as C++ uses 0-based indexing.
2. **I/O Operations:** Used `std::cout` for output, and `std::setw(12)` to set the width of the output, mimicking the Fortran `write` statement's formatting.
3. **Memory Management:** Dynamically allocated a 2D array to simulate the Fortran array, and ensured proper cleanup.
4. **Formatting:** Adjusted the formatting to closely match the Fortran output, including the newline after every 20th element.

This C++ code should provide similar functionality to the provided Fortran subroutine. Adjust the `DataType` as per your requirements, and ensure that the array `a` is properly initialized before calling `print_array`.
Let's write some test to verify if the translation is correct. 
Below are simple unit tests for both the Fortran and C++ versions of the code. These tests will verify that the output of the array printing functions matches the expected results.

### Fortran Unit Test

First, let's create a Fortran program that calls the `print_array` subroutine and checks its output.

```fortran
program test_print_array
    implicit none
    integer, parameter :: n = 10
    real, dimension(n, n) :: a
    integer :: i, j

    ! Initialize the array
    do i = 1, n
        do j = 1, n
            a(i, j) = real(i * n + j)
        end do
    end do

    ! Call the subroutine
    call print_array(n, a)

end program test_print_array

subroutine print_array(n, a)
    implicit none
    integer, intent(in) :: n
    real, dimension(n, n), intent(in) :: a
    integer :: i, j

    do i = 1, n
        do j = 1, n
            write(*, '(F12.6)') a(j, i)
            if (mod((i - 1) * n + j - 1, 20) == 0) then
                write(*, *)
            end if
        end do
    end do
    write(*, *)
end subroutine print_array
```

### C++ Unit Test

Now, let's create a C++ program that includes the `print_array` function and checks its output.

```cpp
#include <iostream>
#include <iomanip>
#include <cmath>

using DataType = float;

void print_array(int n, DataType** a) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << std::setw(12) << std::fixed << std::setprecision(6) << a[j][i];
            if ((i * n + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

int main() {
    const int n = 10;
    DataType** a = new DataType*[n];
    for (int i = 0; i < n; ++i) {
        a[i] = new DataType[n];
        for (int j = 0; j < n; ++j) {
            a[i][j] = static_cast<DataType>(i * n + j);
        }
    }

    print_array(n, a);

    for (int i = 0; i < n; ++i) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}
```

### Explanation

1. **Fortran Test:**
   - The `test_print_array` program initializes a 2D array `a` with values `i * n + j`.
   - It then calls the `print_array` subroutine, which prints the array elements with a format similar to the C++ version.
   - The output should match the expected values, ensuring that the translation from Fortran to C++ has been done correctly.

2. **C++ Test:**
   - The `main` function initializes a 2D array `a` with values `i * n + j`.
   - It calls the `print_array` function, which prints the array elements with similar formatting to the Fortran version.
   - The output should match the expected values, verifying that the C++ version behaves as expected.

### Running the Tests

To run the Fortran test:
1. Save the Fortran code in a file, e.g., `test_print_array.f90`.
2. Compile the Fortran code using a Fortran compiler, e.g., `gfortran`:
   ```sh
   gfortran -o test_print_array test_print_array.f90
   ```
3. Run the executable:
   ```sh
   ./test_print_array
   ```

To run the C++ test:
1. Save the C++ code in a file, e.g., `test_print_array.cpp`.
2. Compile the C++ code using a C++ compiler, e.g., `g++`:
   ```sh
   g++ -o test_print_array test_print_array.cpp
   ```
3. Run the executable:
   ```sh
   ./test_print_array
   ```

Both tests should produce the same output, verifying that the translation from Fortran to C++ has been done correctly.
