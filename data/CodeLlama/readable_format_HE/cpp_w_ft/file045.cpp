Certainly! Below is the equivalent C++ code for the provided Fortran code:

```cpp
#include <iostream>
#include <cstdlib> // For exit()
#include <ctime> // For srand() and rand()

// Function declaration
int add(int x, int y);

int main() {
    // Assertions
    if (add(0, 1) != 1) {
        std::cerr << "Assertion failed: add(0, 1) == 1" << std::endl;
        exit(1);
    }

    if (add(1, 0) != 1) {
        std::cerr << "Assertion failed: add(1, 0) == 1" << std::endl;
        exit(1);
    }

    if (add(2, 3) != 5) {
        std::cerr << "Assertion failed: add(2, 3) == 5" << std::endl;
        exit(1);
    }

    if (add(5, 7) != 12) {
        std::cerr << "Assertion failed: add(5, 7) == 12" << std::endl;
        exit(1);
    }

    if (add(7, 5) != 12) {
        std::cerr << "Assertion failed: add(7, 5) == 12" << std::endl;
        exit(1);
    }

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    // Loop with random number generation and assertions
    for (int i = 1; i <= 100; ++i) {
        int x = rand() % 1000;
        int y = rand() % 1000;
        if (add(x, y) != x + y) {
            std::cerr << "Assertion failed: add(" << x << ", " << y << ") == " << (x + y) << std::endl;
            exit(1);
        }
    }

    return 0;
}

// Function definition
int add(int x, int y) {
    return x + y;
}
```

### Explanation:
1. **Header Files**:
   - `#include <iostream>` for input and output operations.
   - `#include <cstdlib>` for the `exit()` function.
   - `#include <ctime>` for random number generation.

2. **Function Declaration**:
   - The `add` function is declared before `main` to ensure it is recognized when called.

3. **Assertions**:
   - The assertions are directly translated from Fortran to C++ with the same logic.

4. **Random Number Generation**:
   - The `srand` function is used to seed the random number generator.
   - The `rand()` function is used to generate random numbers.

5. **Loop with Assertions**:
   - The loop generates random numbers and checks the result of `add` against the expected value.

6. **Error Handling**:
   - If an assertion fails, an error message is printed to `std::cerr` and the program exits with a status code of `1`.

This C++ code should behave similarly to the provided Fortran code.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code.

### Fortran Unit Test Code

To create a unit test for the Fortran code, you can use a simple Fortran program that calls the `add` function with various inputs and checks the results.

```fortran
program test_add
    implicit none
    integer :: errors
    errors = 0

    ! Test cases
    if (add(0, 1) /= 1) then
        write(*,*) "Test failed: add(0, 1) == 1"
        errors = errors + 1
    end if

    if (add(1, 0) /= 1) then
        write(*,*) "Test failed: add(1, 0) == 1"
        errors = errors + 1
    end if

    if (add(2, 3) /= 5) then
        write(*,*) "Test failed: add(2, 3) == 5"
        errors = errors + 1
    end if

    if (add(5, 7) /= 12) then
        write(*,*) "Test failed: add(5, 7) == 12"
        errors = errors + 1
    end if

    if (add(7, 5) /= 12) then
        write(*,*) "Test failed: add(7, 5) == 12"
        errors = errors + 1
    end if

    ! Final report
    if (errors == 0) then
        write(*,*) "All tests passed successfully."
    else
        write(*,*) errors, " tests failed."
    end if

contains

    integer function add(x, y)
        integer, intent(in) :: x, y
        add = x + y
    end function add

end program test_add
```

### C++ Unit Test Code

To create a unit test for the C++ code, you can use a simple C++ program that calls the `add` function with various inputs and checks the results.

```cpp
#include <iostream>
#include <cassert> // For assert()

// Function declaration
int add(int x, int y);

int main() {
    // Test cases
    assert(add(0, 1) == 1);
    assert(add(1, 0) == 1);
    assert(add(2, 3) == 5);
    assert(add(5, 7) == 12);
    assert(add(7, 5) == 12);

    std::cout << "All tests passed successfully." << std::endl;

    return 0;
}

// Function definition
int add(int x, int y) {
    return x + y;
}
```

### Explanation:

1. **Fortran Unit Test Code**:
   - The `test_add` program contains a series of assertions to test the `add` function.
   - If any test fails, it prints an error message and increments the `errors` variable.
   - At the end, it reports the number of failed tests.

2. **C++ Unit Test Code**:
   - The `main` function contains a series of `assert` statements to test the `add` function.
   - If any test fails, the program will terminate and indicate the failed assertion.
   - If all tests pass, it prints a success message.

These unit tests will help ensure that the `add` function behaves correctly in both the Fortran and C++ implementations.
