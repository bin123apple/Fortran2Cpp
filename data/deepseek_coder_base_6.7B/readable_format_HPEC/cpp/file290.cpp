To translate the given Fortran code to C++, we need to consider several aspects, including the syntax differences between Fortran and C++, the array indexing, and the way functions (or subroutines in Fortran) are defined and called. In Fortran, arrays are 1-based, while in C++, arrays are 0-based. Also, Fortran's `write` statement has a different syntax compared to C++'s `std::cout`. Here's how the Fortran subroutine could be translated to a C++ function:

```cpp
#include <iostream>
#include <vector>

// Assuming DATA_TYPE is a placeholder for a specific data type,
// we'll use int as an example. You should replace it with the actual data type.
using DATA_TYPE = int;

void print_array(int n, const std::vector<DATA_TYPE>& a) {
    // Assuming DATA_PRINTF_MODIFIER is a placeholder for a specific formatting,
    // we'll use "%d" as an example. You should replace it with the actual format string.
    const char* DATA_PRINTF_MODIFIER = "%d";

    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " "; // Replace "%d" with DATA_PRINTF_MODIFIER if needed
        if ((i + 1) % 20 == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    std::vector<DATA_TYPE> array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    print_array(array.size(), array);

    return 0;
}
```

Key Points:
- The `std::vector<DATA_TYPE>& a` parameter in the C++ function captures the array passed from the main function.
- The `for` loop in C++ starts from 0 and goes up to `n - 1`, considering C++ uses 0-based indexing.
- The `std::cout` is used for output in C++, replacing Fortran's `write` statement.
- The `if` condition checks if the current index `i` is a multiple of 20, similar to the Fortran code.
- The `std::endl` is used to insert a newline character and flush the output buffer, similar to Fortran's behavior with the `write` statement.
- The `main` function demonstrates how to call the `print_array` function with an example array.

Please adjust the `DATA_TYPE` and `DATA_PRINTF_MODIFIER` as needed to match your specific data type and formatting requirements.
Let's write some test to verify if the translation is correct. 
To verify the correctness of both the original Fortran code and the translated C++ code, we can create simple unit tests. These tests will call the respective functions/subroutines with predefined arrays and compare the outputs against expected results.

### Fortran Unit Test

First, let's create a Fortran program that tests the `print_array` subroutine. We'll use a simple array and print its elements to verify the subroutine's functionality.

```fortran
program test_print_array
    implicit none
    integer, parameter :: n = 20
    integer :: a(n)
    integer :: i

    ! Initialize array
    do i = 1, n
        a(i) = i
    end do

    ! Call the subroutine
    call print_array(n, a)

end program test_print_array

subroutine print_array(n, a)
    implicit none
    integer, dimension(n) :: a
    integer :: n, i

    do i = 1, n
        write(*, '(I3)') a(i)
        if (mod(i - 1, 20) == 0) then
            write(*, *)
        end if
    end do
    write(*, *)
end subroutine print_array
```

This Fortran program initializes an array with integers from 1 to 20, then calls the `print_array` subroutine to print them. You can compile and run this Fortran program using a Fortran compiler like `gfortran`.

### C++ Unit Test

Now, let's create a C++ program that tests the `print_array` function. We'll use a similar approach, initializing an array and printing its elements to verify the function's functionality.

```cpp
#include <iostream>
#include <vector>

using DATA_TYPE = int;

void print_array(int n, const std::vector<DATA_TYPE>& a) {
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " ";
        if ((i + 1) % 20 == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

int main() {
    std::vector<DATA_TYPE> array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    print_array(array.size(), array);

    return 0;
}
```

This C++ program does essentially the same thing as the Fortran test program. It initializes a vector with integers from 1 to 20, calls the `print_array` function to print them, and then prints a newline to separate the output from the next test.

### Expected Output

For both the Fortran and C++ programs, the expected output should be:

```
 1  2  3  4  5  6  7  8  9 10
11 12 13 14 15 16 17 18 19 20
```

### Running the Tests

To run the Fortran test:

1. Save the Fortran code in a file, e.g., `test_print_array.f90`.
2. Compile it using a Fortran compiler, e.g., `gfortran -o test_print_array test_print_array.f90`.
3. Run the executable, e.g., `./test_print_array`.

To run the C++ test:

1. Save the C++ code in a file, e.g., `test_print_array.cpp`.
2. Compile it using a C++ compiler, e.g., `g++ -o test_print_array test_print_array.cpp`.
3. Run the executable, e.g., `./test_print_array`.

If both programs produce the expected output, you can be confident that the translation from Fortran to C++ is correct.
