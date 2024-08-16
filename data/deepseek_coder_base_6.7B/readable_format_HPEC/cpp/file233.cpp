To translate the given Fortran subroutine to C++, we need to consider several aspects, including the data types, array indexing, and I/O operations. Fortran arrays are 1-based, while C++ arrays are 0-based. Also, Fortran's `write` statement for arrays is somewhat different from C++'s stream output. Here's a C++ version of the subroutine:

```cpp
#include <iostream>
#include <iomanip> // For std::setw

// Assuming DATA_TYPE is a placeholder for a specific data type,
// we'll use int as an example. You should replace it with the actual type.
using DATA_TYPE = int;

void print_array(int n, DATA_TYPE* outArray) {
    for (int i = 0; i < n; ++i) {
        // Assuming DATA_PRINTF_MODIFIER is a format string for printing,
        // we'll use a simple output without formatting for simplicity.
        std::cout << outArray[i];

        // Check if we need to print a newline after every 20 elements
        if ((i + 1) % 20 == 0) {
            std::cout << std::endl;
        } else {
            std::cout << " "; // Space instead of newline for every other element
        }
    }
}

int main() {
    // Example usage
    const int n = 100; // Size of the array
    DATA_TYPE outArray[n];

    // Initialize the array with some values for demonstration
    for (int i = 0; i < n; ++i) {
        outArray[i] = i + 1; // Fill the array with values 1 to n
    }

    print_array(n, outArray);

    return 0;
}
```

This C++ code defines a function `print_array` that takes the size of the array and a pointer to the array as arguments. It then iterates through the array, printing each element, and inserts a newline after every 20 elements to mimic the Fortran behavior. Note that in C++, arrays are 0-based, so the loop runs from 0 to `n-1`.

Remember to replace `DATA_TYPE` and `DATA_PRINTF_MODIFIER` with the actual data type and format string you're using in your Fortran code, respectively. Also, if you're working with complex data types or need more sophisticated formatting, you might need to use `std::cout` with formatting flags (`std::setw`, `std::setprecision`, etc.) to match the Fortran output format exactly.
Let's write some test to verify if the translation is correct. 
To verify the correctness of both the original Fortran code and the translated C++ code, we can write unit tests for each. These tests will check if the output of the `print_array` function matches the expected results for a predefined input array.

### Fortran Unit Test

For the Fortran code, we'll write a simple program that calls the `print_array` subroutine and checks its output. Since Fortran doesn't have a built-in unit testing framework like some other languages, we'll manually check the output.

```fortran
program test_print_array
    implicit none
    integer, parameter :: n = 100
    integer :: outArray(n)
    integer :: i

    ! Initialize the array
    do i = 1, n
        outArray(i) = i
    end do

    ! Call the subroutine
    call print_array(n, outArray)

end program test_print_array

subroutine print_array(n, outArray)
    implicit none
    integer, dimension(n) :: outArray
    integer :: n
    integer :: i
    do i = 1, n
        write(*, '(I3)') outArray(i)
        if (mod(i - 1, 20) == 0) then
            write(*, *)
        end if
    end do
end subroutine
```

This program initializes an array with values from 1 to 100, calls the `print_array` subroutine, and prints the output. You should manually verify that the output matches the expected format (values 1 to 100, with 20 values per line).

### C++ Unit Test

For the C++ code, we can use a simple testing approach similar to the Fortran example, or we can use a unit testing framework like Google Test for more comprehensive testing. Here, I'll provide a basic example without a framework for simplicity.

```cpp
#include <iostream>
#include <sstream> // For std::stringstream
#include <string>

// Assuming DATA_TYPE is int for this example
using DATA_TYPE = int;

void print_array(int n, DATA_TYPE* outArray, std::ostringstream& oss);

int main() {
    const int n = 100;
    DATA_TYPE outArray[n];
    std::ostringstream oss;

    // Initialize the array
    for (int i = 0; i < n; ++i) {
        outArray[i] = i + 1; // Fill the array with values 1 to n
    }

    // Call the function and capture the output
    print_array(n, outArray, oss);

    // Convert the captured output to a string for comparison
    std::string output = oss.str();
    std::string expectedOutput = ""; // Expected output string

    // Check if the output matches the expected output
    if (output == expectedOutput) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
        std::cout << "Expected:" << std::endl << expectedOutput << std::endl;
        std::cout << "Got:" << std::endl << output << std::endl;
    }

    return 0;
}

void print_array(int n, DATA_TYPE* outArray, std::ostringstream& oss) {
    for (int i = 0; i < n; ++i) {
        oss << outArray[i];
        if ((i + 1) % 20 == 0) {
            oss << std::endl;
        } else {
            oss << " ";
        }
    }
}
```

This C++ code captures the output of the `print_array` function into a `std::ostringstream` object, which is then compared to an expected output string. You should replace `expectedOutput` with the actual expected output string based on the Fortran program's output.

### Note:

- For both tests, you should manually verify the output against the expected results.
- For more comprehensive testing, especially in C++, consider using a unit testing framework like Google Test, which provides a rich set of assertions and testing utilities.
