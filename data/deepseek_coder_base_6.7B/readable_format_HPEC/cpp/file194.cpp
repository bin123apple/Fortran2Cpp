To translate the given Fortran code to C++, we need to consider several aspects, including the syntax differences between Fortran and C++, the way arrays are handled, and the I/O operations. The Fortran code defines a subroutine that prints a symmetric matrix, with a specific format for each element. Here's how you can translate it to C++:

```cpp
#include <iostream>
#include <iomanip>

// Assuming DATA_TYPE is a type like int, float, double, etc.
// and DATA_PRINTF_MODIFIER is a format string for output, e.g., "%d"
template<typename T>
void print_array(int m, T** symmat) {
    // Set precision for floating point types
    if constexpr (std::is_floating_point<T>::value) {
        std::cout << std::fixed << std::setprecision(2);
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            // Adjusting for 0-based indexing in C++
            std::cout << symmat[j][i] << " ";
            if (((i * m) + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    const int m = 5;
    // Assuming DATA_TYPE is int for this example
    int** symmat = new int*[m];
    for (int i = 0; i < m; ++i) {
        symmat[i] = new int[m];
        for (int j = 0; j < m; ++j) {
            // Fill the matrix with some values for demonstration
            symmat[i][j] = i * m + j;
        }
    }

    print_array(m, symmat);

    // Clean up
    for (int i = 0; i < m; ++i) {
        delete[] symmat[i];
    }
    delete[] symmat;

    return 0;
}
```

### Key Points:

1. **Array Handling**: In C++, arrays are typically 0-based, unlike Fortran's 1-based arrays. This difference is accounted for in the loop indices.

2. **Dynamic Memory Allocation**: The example uses dynamic memory allocation for the symmetric matrix. This is necessary because the size of the matrix is not known at compile time.

3. **I/O Operations**: The `std::cout` is used for output, and `std::setprecision` is used to set the precision for floating-point types, mimicking the Fortran behavior.

4. **Template Function**: The `print_array` function is templated to accept any data type, assuming `DATA_TYPE` is replaced with the appropriate C++ type.

5. **Cleanup**: Memory is cleaned up to avoid memory leaks.

This translation assumes that `DATA_TYPE` is a fundamental type (int, float, double, etc.) and `DATA_PRINTF_MODIFIER` is a format string for output operations, which might be "%d" for integers or "%f" for floating-point numbers. Adjust the template type and format string as necessary for your specific use case.
Let's write some test to verify if the translation is correct. 
Below are examples of how you could write unit tests for both the Fortran and C++ versions of the code to verify their correctness. These tests will focus on checking the functionality of the `print_array` subroutine/function for a given input matrix.

### Fortran Unit Test

For the Fortran code, we'll write a simple program that calls the `print_array` subroutine with a predefined matrix and checks the output manually since automatic testing of console output in Fortran is not straightforward without additional tools.

```fortran
program test_print_array
    implicit none
    integer, parameter :: m = 5
    integer :: symmat(m, m)
    integer :: i, j

    ! Initialize the matrix
    do i = 1, m
        do j = 1, m
            symmat(j, i) = i * m + j
        end do
    end do

    ! Call the subroutine
    call print_array(m, symmat)

end program test_print_array
```

To test, you would compile and run this program, then manually verify that the output matches the expected matrix format.

### C++ Unit Test

For the C++ code, we can use a testing framework like Google Test for more automated testing. Below is an example of how you might write a test case for the `print_array` function. This assumes you have Google Test set up in your environment.

```cpp
#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include <iomanip>

// Assuming print_array is defined in print_array.h
#include "print_array.h"

TEST(PrintArrayTest, CorrectOutput) {
    const int m = 5;
    int** symmat = new int*[m];
    for (int i = 0; i < m; ++i) {
        symmat[i] = new int[m];
        for (int j = 0; j < m; ++j) {
            symmat[i][j] = i * m + j;
        }
    }

    // Redirect std::cout to a stringstream
    std::stringstream buffer;
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    // Call the function
    print_array(m, symmat);

    // Restore original buffer before assertions (to see test results)
    std::cout.rdbuf(prevcoutbuf);

    // Define the expected output
    std::string expected = "";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            expected += std::to_string(symmat[j][i]) + " ";
            if (((i * m) + j) % 20 == 0) {
                expected += "
";
            }
        }
    }
    expected += "
";

    // Compare the output
    EXPECT_EQ(buffer.str(), expected);

    // Clean up
    for (int i = 0; i < m; ++i) {
        delete[] symmat[i];
    }
    delete[] symmat;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

This test case redirects `std::cout` to a `stringstream` to capture the output of the `print_array` function, then compares it to the expected output string.

### Running the Tests

- **Fortran**: Compile and run the Fortran test program as you would with any Fortran code, using a Fortran compiler like `gfortran`.
  
  ```sh
  gfortran -o test_print_array test_print_array.f90
  ./test_print_array
  ```

- **C++ with Google Test**: Ensure Google Test is installed and properly set up in your project. Compile the C++ test with Google Test linked, and run the resulting executable.

  ```sh
  g++ -o test_print_array_cpp test_print_array_cpp.cpp -lgtest -lgtest_main -pthread
  ./test_print_array_cpp
  ```

These tests will help ensure that the `print_array` subroutine/function works as expected for a predefined matrix. Adjust the matrix initialization and expected output as necessary to fit your specific requirements.
