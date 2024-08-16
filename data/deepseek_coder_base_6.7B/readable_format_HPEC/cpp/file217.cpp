To translate the given Fortran code to C++, we need to understand the functionality of the original code and then implement it using C++ syntax and constructs. The Fortran code defines a subroutine named `print_array` that takes an array (of unspecified type) as an argument and prints its elements. The `implicit none` statement in Fortran specifies that all variables must be explicitly declared. The `DATA_TYPE` and `DATA_PRINTF_MODIFIER` placeholders in the Fortran code suggest that the array elements might be of a specific type, which we'll need to replace with a suitable C++ type.

In C++, we can use templates for a similar functionality, allowing us to write a function that can work with any data type. We'll use `std::cout` for output, and we'll assume that the elements of the array can be printed using the stream's insertion operator (`<<`).

Here's how the translation might look in C++:

```cpp
#include <iostream>

// Assuming DATA_TYPE is a placeholder for a specific type,
// we'll use a template to make the function work with any type.
template<typename T>
void print_array(T* output, int size) {
    // Print each element of the array, followed by a space
    for (int i = 0; i < size; ++i) {
        std::cout << output[i] << " ";
    }
    // Print a newline to separate the output from the next call
    std::cout << std::endl;
}

int main() {
    // Example usage
    int intArray[] = {1, 2, 3, 4, 5};
    float floatArray[] = {1.1f, 2.2f, 3.3f};

    print_array(intArray, 5);
    print_array(floatArray, 3);

    return 0;
}
```

This C++ code defines a template function `print_array` that can be used to print elements of an array of any type (as long as the type has an insertion operator defined for `std::cout`). The `main` function demonstrates how to call `print_array` with both an array of integers and an array of floating-point numbers.

Note: The original Fortran code uses `write(0, DATA_PRINTF_MODIFIER) output` and `write(0, *)` to print the array elements. In the C++ translation, we use `std::cout` for output, which is a common way to perform console output in C++. The `<<` operator is used to insert data into the output stream, which is similar to the `write` statement in Fortran.
Let's write some test to verify if the translation is correct. 
Creating unit tests for both the Fortran and C++ code involves writing some additional code that will call the `print_array` subroutine/function with different types of arrays and verify the output. For simplicity, we'll focus on testing with integer and floating-point arrays, as these are the types used in the provided examples.

### Fortran Unit Test

For the Fortran code, we'll write a simple program that calls the `print_array` subroutine with different types of arrays. Fortran doesn't have a built-in unit testing framework, so we'll manually check the output.

```fortran
program test_print_array
    implicit none
    integer :: intArray(5) = [1, 2, 3, 4, 5]
    real :: floatArray(3) = [1.1, 2.2, 3.3]

    call print_array(intArray)
    call print_array(floatArray)
end program test_print_array
```

To compile and run this Fortran test, you would use a Fortran compiler like `gfortran`. The output should manually verified to ensure it matches the expected integer and floating-point values.

### C++ Unit Test

For C++, we can use a simple testing approach similar to the Fortran example. C++ also doesn't have a built-in unit testing framework, but for more complex scenarios, you might consider using frameworks like Google Test. Here, we'll keep it simple and manual.

```cpp
#include <iostream>
#include <sstream> // For std::stringstream
#include <string> // For std::string

// Include or copy the print_array function here

void test_print_array() {
    std::stringstream buffer;
    // Save cout's buffer here
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    // Test with an integer array
    int intArray[] = {1, 2, 3, 4, 5};
    print_array(intArray, 5);
    std::string output = buffer.str();
    buffer.str(""); // Clear buffer
    buffer.clear(); // Clear error state

    // Test with a float array
    float floatArray[] = {1.1f, 2.2f, 3.3f};
    print_array(floatArray, 3);
    output += buffer.str();

    // Restore cout's original buffer
    std::cout.rdbuf(prevcoutbuf);

    // Verify the output
    std::string expectedOutput = "1 2 3 4 5 
1.1 2.2 3.3 
";
    if (output == expectedOutput) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
        std::cout << "Expected:" << std::endl << expectedOutput << std::endl;
        std::cout << "Got:" << std::endl << output << std::endl;
    }
}

int main() {
    test_print_array();
    return 0;
}
```

This C++ code captures the output of `std::cout` while running `print_array` with both an integer and a float array, then compares it to the expected output. If the output matches, it prints "Test passed."; otherwise, it prints "Test failed." along with the expected and actual outputs.

To compile and run the C++ test, you would use a C++ compiler like `g++`.

These simple tests will help verify that the functionality of both the original Fortran code and the translated C++ code works as expected for the given test cases. For more comprehensive testing, especially for complex software, consider using dedicated unit testing frameworks and more detailed test cases.
