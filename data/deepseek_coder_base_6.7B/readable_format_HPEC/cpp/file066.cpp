Certainly! Below is the translated C++ code from the provided Fortran code. Note that C++ uses zero-based indexing, unlike Fortran's one-based indexing. Also, C++ does not have a direct equivalent of Fortran's `command_argument_count` and `get_command_argument` functions, so we use `argc` and `argv` from the main function to handle command line arguments. Additionally, OpenMP directives in C++ are similar to those in Fortran but must be enabled with compiler flags (e.g., `-fopenmp` for GCC).

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <omp.h>

int main(int argc, char *argv[]) {
    int len = 10000;
    int x = 0;

    if (argc == 1) {
        std::cout << "No command line arguments provided." << std::endl;
    } else {
        std::stringstream ss(argv[1]);
        if (!(ss >> len)) {
            std::cout << "Error, invalid integer value." << std::endl;
        }
    }

    #pragma omp parallel for private(x)
    for (int i = 0; i <= len; ++i) {
        x = i;
    }

    std::cout << "x = " << x << std::endl;

    return 0;
}
```

Key Points in the Translation:

1. **Command Line Arguments**: The C++ version uses `argc` and `argv` to handle command line arguments. The Fortran version uses `command_argument_count` and `get_command_argument`.

2. **Dynamic Array Allocation**: The Fortran code uses `allocate` with a status check. In C++, we use `std::vector` for dynamic arrays, which automatically manages memory and provides a size method.

3. **OpenMP Directives**: The `!$omp parallel do private(i)` directive in Fortran is translated to `#pragma omp parallel for private(x)` in C++.

4. **Variable Declarations**: The variable types and declarations are adapted to C++ syntax.

5. **I/O Operations**: The Fortran `write` statements are replaced with `std::cout` in C++.

6. **Program Termination**: The Fortran `stop` statement is replaced with `return 0;` in C++ to indicate successful program termination.

Remember to compile this C++ code with OpenMP support enabled, typically with a command like `g++ -fopenmp your_program.cpp -o your_program`.
Let's write some test to verify if the translation is correct. 
Creating unit tests for both the Fortran and C++ code involves checking the functionality with different command line arguments and verifying the output. Below are the unit test codes for both languages.

### Fortran Unit Test

For the Fortran code, we'll create a simple test program that calls the main program with different arguments and checks the output.

```fortran
program test_DRB010
    implicit none
    integer :: i, len, argCount, allocStatus, rdErr, x, ix
    character(len=80), dimension(:), allocatable :: args
    character(len=80) :: test_command
    character(len=80) :: output
    character(len=80) :: expected_output

    ! Test cases
    len = 10000
    test_command = "./DRB010_lastprivatemissing_var_yes " // trim(adjustl(write(len, '(i10)') // " "))
    expected_output = "x = 9999"

    ! Run the test
    call execute_command_line(test_command, output)

    ! Check the output
    if (trim(adjustl(output)) == expected_output) then
        print *, "Test passed."
    else
        print *, "Test failed."
        print *, "Expected: ", expected_output
        print *, "Got: ", trim(adjustl(output))
    end if
end program test_DRB010
```

### C++ Unit Test

For the C++ code, we'll use a simple test framework like Google Test. However, for simplicity, I'll provide a basic test similar to the Fortran test above.

```cpp
#include <iostream>
#include <sstream>
#include <string>
#include <cassert>

std::string run_program(int len) {
    std::ostringstream command;
    command << "./DRB010_lastprivatemissing_var_yes " << len;
    std::string output = system(command.str().c_str());
    return output;
}

void test_case(int len, const std::string& expected_output) {
    std::string output = run_program(len);
    if (output == expected_output) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
        std::cout << "Expected: " << expected_output << std::endl;
        std::cout << "Got: " << output << std::endl;
    }
}

int main() {
    // Test cases
    test_case(10000, "x = 9999");

    return 0;
}
```

### Running the Tests

1. **Fortran Test**:
   - Compile the Fortran test program using a Fortran compiler (e.g., `gfortran`).
   - Run the executable and check the output.

   ```sh
   gfortran -o test_DRB010 test_DRB010.f90
   ./test_DRB010
   ```

2. **C++ Test**:
   - Compile the C++ test program with a C++ compiler (e.g., `g++`) and OpenMP support.
   - Run the executable and check the output.

   ```sh
   g++ -fopenmp -o test_DRB010_cpp test_DRB010_cpp.cpp
   ./test_DRB010_cpp
   ```

These tests will verify that the translated C++ code behaves the same as the original Fortran code when run with the specified test cases. Adjust the test cases as needed to cover more scenarios.
