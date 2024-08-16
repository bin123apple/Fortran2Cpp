To translate the given Fortran code to C++, we need to understand the structure and functionality of the original code and then replicate that behavior using C++ syntax and constructs. The Fortran code defines a subroutine named `print_array` that takes an integer `n` and an array `w` of size `n` as input, and then prints each element of the array followed by a newline, with a maximum of 20 elements per line.

Here's how you can translate the given Fortran code to C++:

```cpp
#include <iostream>
#include <vector>

// Assuming DATA_TYPE is a placeholder for the actual data type,
// we'll use `double` as an example. You should replace `double` with the actual data type.
using DataType = double;

void print_array(int n, const std::vector<DataType>& w) {
    for (int i = 0; i < n; ++i) {
        // Assuming DATA_PRINTF_MODIFIER is a format string for printing the data,
        // we'll use a simple formatting approach. You should replace "%.2f" with the actual format string.
        std::cout << w[i] << " ";
        
        // Print a newline after every 20 elements or at the end of the array
        if ((i + 1) % 20 == 0 || i == n - 1) {
            std::cout << std::endl;
        }
    }
}

int main() {
    // Example usage
    std::vector<DataType> array = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10};
    int n = array.size();
    
    print_array(n, array);
    
    return 0;
}
```

Key Points in the Translation:

1. **Data Type**: The Fortran code uses a placeholder `DATA_TYPE`. In the C++ translation, I've used `double` as an example. You should replace `double` with the actual data type you're working with.

2. **Array Representation**: Fortran arrays are 1-based, while C++ arrays (and vectors) are 0-based. This difference is accounted for in the loop by starting the loop from `0` and using `i + 1` when checking for the newline condition.

3. **Printing**: The Fortran `write` statement is replaced with `std::cout` in C++. The formatting of the output is handled differently, as C++ does not support format specifiers in the same way Fortran does (`DATA_PRINTF_MODIFIER`). I've used a simple space `" "` to separate the elements, which you can adjust based on your actual requirements.

4. **Newline Logic**: The Fortran code checks if the loop index `i` is a multiple of 20 and inserts a newline if true. The C++ translation replicates this logic with `(i + 1) % 20 == 0`.

5. **Main Function**: The `main` function demonstrates how to use the `print_array` function with an example array.

This translation assumes that the data type `DataType` and the format string `"%.2f"` are placeholders and should be replaced with the actual data type and formatting requirements of your application.
Let's write some test to verify if the translation is correct. 
Below are examples of how you could write unit tests for both the original Fortran code and the translated C++ code. These tests will verify the functionality of the `print_array` subroutine/function by comparing their outputs against expected results.

### Fortran Unit Test

For the Fortran code, we'll write a simple program that calls the `print_array` subroutine with a predefined array and captures its output to a file. Then, we'll compare this output against an expected result.

```fortran
program test_print_array
    implicit none
    integer, parameter :: n = 10
    real, dimension(n) :: w = [1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10]
    character(len=100) :: output_file
    character(len=100) :: expected_file
    character(len=100) :: command

    output_file = 'output.txt'
    expected_file = 'expected.txt'

    ! Call the subroutine and redirect output to output_file
    call print_array(n, w)

    ! Compare output_file with expected_file
    command = 'diff ' // trim(output_file) // ' ' // trim(expected_file)
    call system(command)
end program test_print_array
```

### C++ Unit Test

For the C++ code, we'll use a similar approach, redirecting the output to a file and comparing it with an expected result.

```cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

// Assuming the print_array function is defined as shown in the previous C++ translation
void print_array(int n, const std::vector<DataType>& w);

int main() {
    std::vector<DataType> array = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10};
    int n = array.size();

    // Redirect cout to a file
    std::ofstream out("output.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); // Save old buf
    std::cout.rdbuf(out.rdbuf()); // Redirect cout to output.txt

    // Call the function
    print_array(n, array);

    // Reset cout to standard output
    std::cout.rdbuf(coutbuf); // Reset to standard output
    out.close();

    // Compare output.txt with expected.txt
    std::string command = "diff output.txt expected.txt";
    system(command.c_str());

    return 0;
}
```

### Expected Output File (`expected.txt`)

This file should contain the expected output of the `print_array` function when given the same input as the test. You can create this file by manually typing in the expected output or by running the `print_array` function with the same input on a trusted system and copying the output.

### Running the Tests

1. **Fortran**: Compile the Fortran test program with a Fortran compiler (e.g., `gfortran`) and run the resulting executable. Ensure that the `print_array` subroutine and the test program are in the same file or appropriately linked.

2. **C++**: Compile the C++ test program with a C++ compiler (e.g., `g++`) and run the resulting executable. Make the `print_array` function is correctly defined and included in the test file.

These tests will compare the output of the `print_array` function against an expected result, allowing you to verify the correctness of the translation.
