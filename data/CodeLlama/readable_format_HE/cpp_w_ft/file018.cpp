Certainly! Below is the equivalent C++ code for the provided Fortran code. This C++ code includes the necessary headers and uses standard I/O streams for output.

```cpp
#include <iostream>
#include <string>
#include <cstdlib> // For exit()

// Function to get the length of a string
int strlen(const std::string& str) {
    return str.length();
}

void run_assertions() {
    // Assertions
    if (strlen("") != 0) {
        std::cerr << "Assertion failed: strlen("") == 0" << std::endl;
        std::exit(1);
    }

    if (strlen("x") != 1) {
        std::cerr << "Assertion failed: strlen("x") == 1" << std::endl;
        std::exit(1);
    }

    if (strlen("asdasnakj") != 9) {
        std::cerr << "Assertion failed: strlen("asdasnakj") == 9" << std::endl;
        std::exit(1);
    }

    std::cout << "All assertions passed." << std::endl;
}

int main() {
    // Main program logic
    run_assertions();
    return 0;
}
```

### Explanation:
1. **Headers and Namespaces:**
   - `#include <iostream>` for input/output operations.
   - `#include <string>` for using the `std::string` class.
   - `#include <cstdlib>` for using the `std::exit()` function.

2. **Function `strlen`:**
   - This function takes a `const std::string&` as its parameter and returns the length of the string using the `length()` member function of `std::string`.

3. **Subroutine `run_assertions`:**
   - This function contains the assertions. If any assertion fails, it prints an error message to `std::cerr` and exits the program using `std::exit(1)`.

4. **Main Function:**
   - The `main` function calls `run_assertions` to run the assertions.

This C++ code should behave similarly to the provided Fortran code, executing the assertions and printing the results to the console.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the `strlen` function and the `run_assertions` subroutine/function.

### Fortran Unit Test Code

To test the Fortran code, you can create a separate Fortran program that calls the `run_assertions` subroutine and checks the output. Here is an example:

```fortran
program test_main
    implicit none

    ! Main program logic
    call run_assertions()

contains

    ! Function to get the length of a string
    integer function strlen(str)
        character(len=*), intent(in) :: str
        strlen = len_trim(str)
    end function strlen

    subroutine run_assertions()
        ! Assertions
        if (strlen('') /= 0) then
            write(*,*) 'Assertion failed: strlen("") == 0'
            call exit(1)
        end if

        if (strlen('x') /= 1) then
            write(*,*) 'Assertion failed: strlen("x") == 1'
            call exit(1)
        end if

        if (strlen('asdasnakj') /= 9) then
            write(*,*) 'Assertion failed: strlen("asdasnakj") == 9'
            call exit(1)
        end if

        write(*,*) 'All assertions passed.'
    end subroutine run_assertions

end program test_main
```

### C++ Unit Test Code

For the C++ code, you can use a simple main function to call the `run_assertions` function and check the output. Here is an example:

```cpp
#include <iostream>
#include <string>
#include <cstdlib> // For exit()

// Function to get the length of a string
int strlen(const std::string& str) {
    return str.length();
}

void run_assertions() {
    // Assertions
    if (strlen("") != 0) {
        std::cerr << "Assertion failed: strlen("") == 0" << std::endl;
        std::exit(1);
    }

    if (strlen("x") != 1) {
        std::cerr << "Assertion failed: strlen("x") == 1" << std::endl;
        std::exit(1);
    }

    if (strlen("asdasnakj") != 9) {
        std::cerr << "Assertion failed: strlen("asdasnakj") == 9" << std::endl;
        std::exit(1);
    }

    std::cout << "All assertions passed." << std::endl;
}

int main() {
    // Main program logic
    run_assertions();
    return 0;
}
```

### Explanation:

1. **Fortran Unit Test:**
   - The `test_main` program calls the `run_assertions` subroutine.
   - The `run_assertions` subroutine contains the assertions. If any assertion fails, it prints an error message and exits the program with a non-zero status.
   - If all assertions pass, it prints "All assertions passed."

2. **C++ Unit Test:**
   - The `main` function calls the `run_assertions` function.
   - The `run_assertions` function contains the assertions. If any assertion fails, it prints an error message to `std::cerr` and exits the program using `std::exit(1)`.
   - If all assertions pass, it prints "All assertions passed."

### Running the Tests:

To run the Fortran unit test, you can compile and execute the Fortran code using a Fortran compiler like `gfortran`:

```sh
gfortran -o test_fortran test_main.f90
./test_fortran
```

To run the C++ unit test, you can compile and execute the C++ code using a C++ compiler like `g++`:

```sh
g++ -o test_cpp test_main.cpp
./test_cpp
```

These tests will verify that the `strlen` function and the `run_assertions` subroutine/function work correctly in both Fortran and C++.
