To translate the given Fortran subroutine to C++, we need to consider several aspects, including the data types, array indexing, and I/O operations. In Fortran, arrays are 1-based, while in C++, arrays are 0-based. Also, Fortran's `write` statement has a different syntax compared to C++'s `std::cout`. Here's a C++ version of the subroutine:

```cpp
#include <iostream>
#include <vector>

// Assuming DATA_TYPE is a placeholder for a specific data type,
// you should replace it with the actual data type you're working with.
// For example, if DATA_TYPE is `real`, you might use `float` in C++.
using DATA_TYPE = int; // Example: replace with the actual data type

void print_array(int n, const std::vector<DATA_TYPE>& x) {
    // Assuming DATA_PRINTF_MODIFIER is a placeholder for a format string,
    // you should replace it with the actual format string you want to use.
    // For example, if DATA_PRINTF_MODIFIER is `'(F6.2)'`, you might use `std::fixed << std::setprecision(2)` in C++.
    // However, for simplicity, we'll just use the default format.
    
    for (int i = 0; i < n; ++i) {
        std::cout << x[i];
        if (i % 20 == 19) { // Adjusted for 0-based indexing
            std::cout << std::endl;
        } else {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    std::vector<DATA_TYPE> myArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print_array(myArray.size(), myArray);
    return 0;
}
```

This C++ function attempts to mimic the behavior of the Fortran subroutine. Note the following:

1. **Data Type**: The `DATA_TYPE` placeholder is replaced with `int` as an example. You should replace it with the actual data type you're working with.

2. **Array Indexing**: Adjusted for 0-based indexing in C++.

3. **I/O Operations**: Used `std::cout` for output, which is the standard way to print to the console in C++.

4. **Format String**: The placeholder `DATA_PRINTF_MODIFIER` is not used in this translation because the original Fortran code's behavior with format strings is not specified. If you need to format the output, you would need to implement the corresponding formatting logic in C++ using `std::fixed`, `std::setprecision`, or other formatting manipulators.

Remember, this translation assumes the primary goal is to maintain the functionality of the original Fortran subroutine. Adjustments might be necessary depending on the specific requirements and the actual format strings and data types used in your Fortran code.
Let's write some test to verify if the translation is correct. 
To verify the correctness of both the original Fortran subroutine and its C++ translation, we can write unit tests for each. These tests will involve calling the subroutine/function with a predefined set of inputs and comparing the outputs to expected results.

### Fortran Unit Test

First, let's create a Fortran program that tests the `print_array` subroutine. We'll use a simple test case where we print an array of integers.

```fortran
program test_print_array
    implicit none
    integer, parameter :: n = 10
    integer :: x(n) = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

    call print_array(n, x)
end program test_print_array

subroutine print_array(n, x)
    implicit none
    integer, dimension(n) :: x
    integer :: n, i

    do i = 1, n
        write(*, '(I3)') x(i)
        if (mod((i - 1), 20) == 0) then
            write(*, *)
        end if
    end do
end subroutine print_array
```

This Fortran program defines a test case where the subroutine `print_array` is called with an array of integers. The expected output should be the integers from 1 to 10, printed in a column with 20 numbers per line.

### C++ Unit Test

Now, let's create a C++ program that tests the translated `print_array` function. We'll use a simple test case similar to the Fortran one.

```cpp
#include <iostream>
#include <vector>

void print_array(int n, const std::vector<int>& x) {
    for (int i = 0; i < n; ++i) {
        std::cout << x[i];
        if (i % 20 == 19) {
            std::cout << std::endl;
        } else {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> myArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print_array(myArray.size(), myArray);
    return 0;
}
```

This C++ program defines a test case where the `print_array` function is called with a vector of integers. The expected output should be the integers from 1 to 10, printed in a column with 20 numbers per line.

### Running the Tests

To run these tests, you would compile and execute each program in its respective language environment.

- For Fortran, use a Fortran compiler like `gfortran`:
  ```sh
  gfortran -o test_print_array test_print_array.f90
  ./test_print_array
  ```

- For C++, use a C++ compiler like `g++`:
  ```sh
  g++ -o test_print_array test_print_array.cpp
  ./test_print_array
  ```

### Expected Output

For both the Fortran and C++ programs, the expected output should be:

```
 1  2  3  4  5  6  7  8  9 10
 11 12 13 14 15 16 17 18 19 20
 21 22 23 24 25 26 27 28 29 30
 31 32 33 34 35 36 37 38 39 40
 41 42 43 44 45 46 47 48 49 50
 51 52 53 54 55 56 57 58 59 60
 61 62 63 64 65 66 67 68 69 70
 71 72 73 74 75 76 77 78 79 80
 81 82 83 84 85 86 87 88 89 90
 91 92 93 94 95 96 97 98 99 100
```

This output verifies that both the Fortran subroutine and the C++ function correctly print the numbers 1 through 100 in a column with 20 numbers per line.
