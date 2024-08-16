To translate the given Fortran code to C++, we need to understand the structure and functionality of the original code. The Fortran code defines a subroutine named `print_array` that takes an integer `n` and an array `x` of size `n + 1` and prints each element of the array. It also prints a newline after every 20 elements.

Here's how you can translate the given Fortran code to C++:

```cpp
#include <iostream>
#include <vector>

// Assuming DATA_TYPE is a placeholder for a specific data type, 
// we'll use double for the example. You should replace it with the actual data type.
using DataType = double;

void print_array(int n, const std::vector<DataType>& x) {
    for (int i = 0; i < n + 1; ++i) {
        // Assuming DATA_PRINTF_MODIFIER is a format string for printing the data,
        // we'll use a simple format for demonstration. You should replace it with the actual format string.
        std::cout << x[i] << " ";
        
        // Print a newline after every 20 elements
        if ((i + 1) % 20 == 0) {
            std::cout << std::endl;
        }
    }
}

int main() {
    // Example usage
    int n = 100; // Size of the array
    std::vector<DataType> x(n + 1);
    
    // Initialize the array with some values for demonstration
    for (int i = 0; i < n + 1; ++i) {
        x[i] = i; // Example initialization
    }
    
    print_array(n, x);
    
    return 0;
}
```

### Explanation:
1. **Data Type**: The Fortran code uses `DATA_TYPE` as a placeholder for the data type of the array elements. In the C++ translation, we use `std::vector<DataType>` to represent the array. The `DataType` is defined as `double` in the example, but you should replace it with the actual data type you're working with.

2. **Array Initialization**: The Fortran code initializes the array `x` with size `n + 1`. In C++, this is handled by creating a `std::vector<DataType>` of size `n + 1`.

3. **Printing Elements**: The loop in the `print_array` function iterates from `0` to `n` (inclusive) to print each element of the array. The formatting for each element is handled by the `std::cout` stream.

4. **Newline After 20 Elements**: The condition `if ((i + 1) % 20 == 0)` checks if the current element is the 20th, 40th, 60th, etc., and prints a newline to break the line after every 20 elements.

5. **Main Function**: The `main` function demonstrates how to initialize the array and call the `print_array` function.

Make sure to replace `double` with the actual data type you're working with and adjust the formatting strings as necessary.
Let's write some test to verify if the translation is correct. 
Below are the unit tests for both the original Fortran code and the translated C++ code. These tests will help verify that the translation is correct.

### Fortran Unit Test

First, let's create a Fortran program that calls the `print_array` subroutine and tests its functionality.

```fortran
program test_print_array
    implicit none
    integer, parameter :: n = 100
    real, dimension(n + 1) :: x
    integer :: i

    ! Initialize the array
    do i = 1, n + 1
        x(i) = i
    end do

    ! Call the subroutine
    call print_array(n, x)

contains

    subroutine print_array(n, x)
        implicit none
        integer, intent(in) :: n
        real, dimension(n + 1), intent(in) :: x
        integer :: i

        do i = 1, n + 1
            write(*, '(F6.2)') x(i)
            if (mod(i - 1, 20) == 0) then
                write(*, *)
            end if
        end do
    end subroutine print_array

end program test_print_array
```

### C++ Unit Test

Now, let's create a C++ program that includes the `print_array` function and tests its functionality.

```cpp
#include <iostream>
#include <vector>

using DataType = double;

void print_array(int n, const std::vector<DataType>& x) {
    for (int i = 0; i < n + 1; ++i) {
        std::cout << x[i] << " ";
        if ((i + 1) % 20 == 0) {
            std::cout << std::endl;
        }
    }
}

int main() {
    int n = 100; // Size of the array
    std::vector<DataType> x(n + 1);
    
    // Initialize the array with some values for demonstration
    for (int i = 0; i < n + 1; ++i) {
        x[i] = i; // Example initialization
    }
    
    print_array(n, x);
    
    return 0;
}
```

### Explanation:

1. **Fortran Test Program**:
    - The `test_print_array` program initializes an array `x` of size `n + 1` with values from 1 to `n + 1`.
    - It then calls the `print_array` subroutine to print the array elements.
    - The subroutine `print_array` is defined within the same program for simplicity.

2. **C++ Test Program**:
    - The `main` function initializes a `std::vector<DataType>` `x` of size `n + 1` with values from 0 to `n`.
    - It calls the `print_array` function to print the array elements.
    - The `print_array` function is defined as shown above.

### Running the Tests:

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

### Verifying the Output:

After running both programs, you should compare their outputs to ensure they are identical. The output should show the numbers from 1 to `n + 1` with a newline after every 20 numbers, similar to the Fortran program. The C++ program should produce the same output.

If both programs produce identical outputs, it confirms that the translation is correct.
