Certainly! Here's the equivalent C++ code for the provided Fortran code:

```cpp
#include <iostream>
#include <cstdlib> // For exit()
#include <cmath> // For round()
#include <string>

// Function to find the closest integer to a given floating-point number
int closest_integer(const std::string& value) {
    double w;
    // Assuming the value is a floating-point number represented as a string
    std::stringstream(value) >> w;
    return std::round(w);
}

// Subroutine to assert conditions
void assert(bool condition, const std::string& message) {
    if (!condition) {
        std::cerr << message << std::endl;
        std::exit(1);
    }
}

int main() {
    // Main program body
    assert(closest_integer("10") == 10, "Assertion failed: closest_integer('10') == 10");
    assert(closest_integer("14.5") == 15, "Assertion failed: closest_integer('14.5') == 15");
    assert(closest_integer("-15.5") == -16, "Assertion failed: closest_integer('-15.5') == -16");
    assert(closest_integer("15.3") == 15, "Assertion failed: closest_integer('15.3') == 15");
    assert(closest_integer("0") == 0, "Assertion failed: closest_integer('0') == 0");

    return 0;
}
```

### Explanation:
1. **Function `closest_integer`:**
   - Takes a `std::string` as input.
   - Uses a `std::stringstream` to convert the string to a `double`.
   - Returns the closest integer to the given floating-point number using `std::round`.

2. **Subroutine `assert`:**
   - Takes a boolean condition and a message string.
   - Prints the message if the condition is false, then exits the program with an error code using `std::exit(1)`.

3. **Main function:**
   - Contains assertions similar to the Fortran version.
   - Calls the `assert` function with the expected conditions and messages.

This C++ code should behave similarly to the Fortran code, performing the same checks and exiting with an error if any assertion fails.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code.

### Fortran Unit Test Code

```fortran
program test_main
    implicit none

    ! Main program body
    call assert(closest_integer("10") == 10, "Assertion failed: closest_integer('10') == 10")
    call assert(closest_integer("14.5") == 15, "Assertion failed: closest_integer('14.5') == 15")
    call assert(closest_integer("-15.5") == -16, "Assertion failed: closest_integer('-15.5') == -16")
    call assert(closest_integer("15.3") == 15, "Assertion failed: closest_integer('15.3') == 15")
    call assert(closest_integer("0") == 0, "Assertion failed: closest_integer('0') == 0")

contains

    integer function closest_integer(value)
        character(len=*), intent(in) :: value
        real :: w
        read(value, *) w
        closest_integer = nint(w)
    end function closest_integer

    subroutine assert(condition, message)
        logical, intent(in) :: condition
        character(len=*), intent(in) :: message
        if (.not. condition) then
            write(*,*) message
            call exit(1)
        end if
    end subroutine assert

end program test_main
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <cstdlib> // For exit()
#include <cmath> // For round()
#include <string>
#include <sstream> // For string conversion

// Function to find the closest integer to a given floating-point number
int closest_integer(const std::string& value) {
    double w;
    // Assuming the value is a floating-point number represented as a string
    std::stringstream(value) >> w;
    return std::round(w);
}

// Subroutine to assert conditions
void assert(bool condition, const std::string& message) {
    if (!condition) {
        std::cerr << message << std::endl;
        std::exit(1);
    }
}

int main() {
    // Main program body
    assert(closest_integer("10") == 10, "Assertion failed: closest_integer('10') == 10");
    assert(closest_integer("14.5") == 15, "Assertion failed: closest_integer('14.5') == 15");
    assert(closest_integer("-15.5") == -16, "Assertion failed: closest_integer('-15.5') == -16");
    assert(closest_integer("15.3") == 15, "Assertion failed: closest_integer('15.3') == 15");
    assert(closest_integer("0") == 0, "Assertion failed: closest_integer('0') == 0");

    return 0;
}
```

### Explanation:

1. **Fortran Unit Test Code:**
   - The main program `test_main` contains assertions similar to the original Fortran code.
   - The `closest_integer` function and `assert` subroutine are defined within the same program.

2. **C++ Unit Test Code:**
   - The main function contains assertions similar to the translated C++ code.
   - The `closest_integer` function and `assert` function are defined in the same file.

### Running the Tests:

To run the Fortran unit test, you can use a Fortran compiler like `gfortran`:

```sh
gfortran -o test_fortran test_main.f90
./test_fortran
```

To run the C++ unit test, you can use a C++ compiler like `g++`:

```sh
g++ -o test_cpp test_main.cpp
./test_cpp
```

Both programs should pass the assertions without any errors if the translation is correct.
