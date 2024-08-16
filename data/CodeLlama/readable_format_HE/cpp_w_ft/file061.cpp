Certainly! Below is the translated C++ code from the provided Fortran code:

```cpp
#include <iostream>
#include <cmath>
#include <cstdlib>

// Function prototype
double triangle_area(double a, double b, double c);
void check_assertion(bool condition, const std::string& message);

int main() {
    // Main program body
    check_assertion(std::abs(triangle_area(3.0, 4.0, 5.0) - 6.0) < 0.01, "Assertion failed: triangle_area(3, 4, 5)");
    check_assertion(std::abs(triangle_area(1.0, 2.0, 10.0) + 1.0) < 0.01, "Assertion failed: triangle_area(1, 2, 10)");
    check_assertion(std::abs(triangle_area(4.0, 8.0, 5.0) - 8.18) < 0.01, "Assertion failed: triangle_area(4, 8, 5)");
    check_assertion(std::abs(triangle_area(2.0, 2.0, 2.0) - 1.73) < 0.01, "Assertion failed: triangle_area(2, 2, 2)");
    check_assertion(std::abs(triangle_area(1.0, 2.0, 3.0) + 1.0) < 0.01, "Assertion failed: triangle_area(1, 2, 3)");
    check_assertion(std::abs(triangle_area(10.0, 5.0, 7.0) - 16.25) < 0.01, "Assertion failed: triangle_area(10, 5, 7)");
    check_assertion(std::abs(triangle_area(2.0, 6.0, 3.0) + 1.0) < 0.01, "Assertion failed: triangle_area(2, 6, 3)");
    check_assertion(std::abs(triangle_area(1.0, 1.0, 1.0) - 0.43) < 0.01, "Assertion failed: triangle_area(1, 1, 1)");
    check_assertion(std::abs(triangle_area(2.0, 2.0, 10.0) + 1.0) < 0.01, "Assertion failed: triangle_area(2, 2, 10)");

    return 0;
}

double triangle_area(double a, double b, double c) {
    double h, area;
    if (a + b <= c || a + c <= b || b + c <= a) {
        area = -1.0;
    } else {
        h = (a + b + c) / 2.0;
        area = std::sqrt(h * (h - a) * (h - b) * (h - c));
    }
    return area;
}

void check_assertion(bool condition, const std::string& message) {
    if (!condition) {
        std::cout << message << std::endl;
        std::exit(1);
    }
}
```

This C++ code includes the necessary headers for input/output operations, mathematical functions, and program termination. The `triangle_area` function calculates the area of a triangle given its three sides, and the `check_assertion` function checks if the condition is met, printing a message and terminating the program if the condition is not met.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the `triangle_area` function and the `check_assertion` subroutine/function.

### Fortran Unit Test Code

```fortran
program test_main
    implicit none
    real :: a, b, c, area

    ! Test cases for triangle_area function
    a = 3.0
    b = 4.0
    c = 5.0
    area = triangle_area(a, b, c)
    call check_assertion(abs(area - 6.0) < 0.01, "Test failed: triangle_area(3, 4, 5)")

    a = 1.0
    b = 2.0
    c = 10.0
    area = triangle_area(a, b, c)
    call check_assertion(abs(area + 1.0) < 0.01, "Test failed: triangle_area(1, 2, 10)")

    a = 4.0
    b = 8.0
    c = 5.0
    area = triangle_area(a, b, c)
    call check_assertion(abs(area - 8.18) < 0.01, "Test failed: triangle_area(4, 8, 5)")

    a = 2.0
    b = 2.0
    c = 2.0
    area = triangle_area(a, b, c)
    call check_assertion(abs(area - 1.73) < 0.01, "Test failed: triangle_area(2, 2, 2)")

    a = 1.0
    b = 2.0
    c = 3.0
    area = triangle_area(a, b, c)
    call check_assertion(abs(area + 1.0) < 0.01, "Test failed: triangle_area(1, 2, 3)")

    a = 10.0
    b = 5.0
    c = 7.0
    area = triangle_area(a, b, c)
    call check_assertion(abs(area - 16.25) < 0.01, "Test failed: triangle_area(10, 5, 7)")

    a = 2.0
    b = 6.0
    c = 3.0
    area = triangle_area(a, b, c)
    call check_assertion(abs(area + 1.0) < 0.01, "Test failed: triangle_area(2, 6, 3)")

    a = 1.0
    b = 1.0
    c = 1.0
    area = triangle_area(a, b, c)
    call check_assertion(abs(area - 0.43) < 0.01, "Test failed: triangle_area(1, 1, 1)")

    a = 2.0
    b = 2.0
    c = 10.0
    area = triangle_area(a, b, c)
    call check_assertion(abs(area + 1.0) < 0.01, "Test failed: triangle_area(2, 2, 10)")

contains

    function triangle_area(a, b, c) result(area)
        real :: a, b, c, area, h
        if (a + b <= c .or. a + c <= b .or. b + c <= a) then
            area = -1.0
        else
            h = (a + b + c) / 2.0
            area = sqrt(h * (h - a) * (h - b) * (h - c))
        end if
    end function triangle_area

    subroutine check_assertion(condition, message)
        logical :: condition
        character(len=*) :: message
        if (.not. condition) then
            write(*,*) message
            call exit(1)
        end if
    end subroutine check_assertion

end program test_main
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>

double triangle_area(double a, double b, double c);
void check_assertion(bool condition, const std::string& message);

int main() {
    // Test cases for triangle_area function
    check_assertion(std::abs(triangle_area(3.0, 4.0, 5.0) - 6
