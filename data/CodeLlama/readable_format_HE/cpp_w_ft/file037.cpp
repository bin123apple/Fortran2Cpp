Certainly! Below is the translated C++ code from the provided Fortran code:

```cpp
#include <iostream>
#include <cmath>
#include <cstdlib>

// Function prototype
double triangle_area(double a, double h);

int main() {
    double result;

    // Test cases
    result = triangle_area(5.0, 3.0);
    if (std::abs(result - 7.5) > 1e-4) {
        std::cerr << "Assertion failed: triangle_area(5, 3) should be 7.5" << std::endl;
        std::exit(1);
    }

    result = triangle_area(2.0, 2.0);
    if (std::abs(result - 2.0) > 1e-4) {
        std::cerr << "Assertion failed: triangle_area(2, 2) should be 2.0" << std::endl;
        std::exit(1);
    }

    result = triangle_area(10.0, 8.0);
    if (std::abs(result - 40.0) > 1e-4) {
        std::cerr << "Assertion failed: triangle_area(10, 8) should be 40.0" << std::endl;
        std::exit(1);
    }

    std::cout << "All tests passed successfully." << std::endl;

    return 0;
}

// Function definition
double triangle_area(double a, double h) {
    return (a * h) * 0.5;
}
```

This C++ code includes the main function and the `triangle_area` function, which calculates the area of a triangle given the base and height. The main function contains several test cases to verify the correctness of the `triangle_area` function. If any test case fails, it prints an error message and exits with a non-zero status. If all tests pass, it prints a success message.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the `triangle_area` function in both languages.

### Fortran Unit Test Code

Save the following Fortran code in a file named `test_triangle_area.f90`:

```fortran
program test_triangle_area
    implicit none
    real :: result

    ! Test cases
    result = triangle_area(5.0, 3.0)
    if (abs(result - 7.5) > 1e-4) then
        write(*,*) "Test failed: triangle_area(5, 3) should be 7.5"
        call exit(1)
    end if

    result = triangle_area(2.0, 2.0)
    if (abs(result - 2.0) > 1e-4) then
        write(*,*) "Test failed: triangle_area(2, 2) should be 2.0"
        call exit(1)
    end if

    result = triangle_area(10.0, 8.0)
    if (abs(result - 40.0) > 1e-4) then
        write(*,*) "Test failed: triangle_area(10, 8) should be 40.0"
        call exit(1)
    end if

    write(*,*) "All tests passed successfully."

contains

    function triangle_area(a, h) result(area)
        real, intent(in) :: a, h
        real :: area
        area = (a * h) * 0.5
    end function triangle_area

end program test_triangle_area
```

To compile and run the Fortran code, use the following commands:

```sh
gfortran -o test_triangle_area test_triangle_area.f90
./test_triangle_area
```

### C++ Unit Test Code

Save the following C++ code in a file named `test_triangle_area.cpp`:

```cpp
#include <iostream>
#include <cmath>
#include <cstdlib>

// Function prototype
double triangle_area(double a, double h);

int main() {
    double result;

    // Test cases
    result = triangle_area(5.0, 3.0);
    if (std::abs(result - 7.5) > 1e-4) {
        std::cerr << "Test failed: triangle_area(5, 3) should be 7.5" << std::endl;
        std::exit(1);
    }

    result = triangle_area(2.0, 2.0);
    if (std::abs(result - 2.0) > 1e-4) {
        std::cerr << "Test failed: triangle_area(2, 2) should be 2.0" << std::endl;
        std::exit(1);
    }

    result = triangle_area(10.0, 8.0);
    if (std::abs(result - 40.0) > 1e-4) {
        std::cerr << "Test failed: triangle_area(10, 8) should be 40.0" << std::endl;
        std::exit(1);
    }

    std::cout << "All tests passed successfully." << std::endl;

    return 0;
}

// Function definition
double triangle_area(double a, double h) {
    return (a * h) * 0.5;
}
```

To compile and run the C++ code, use the following commands:

```sh
g++ -o test_triangle_area test_triangle_area.cpp
./test_triangle_area
```

These unit tests will verify that the `triangle_area` function works correctly in both Fortran and C++ by comparing the computed results with the expected values. If all tests pass, it indicates that the function behaves as expected in both languages.
