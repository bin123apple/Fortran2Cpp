Certainly! Below is the translated C++ code from the provided Fortran code:

```cpp
#include <iostream>
#include <cmath>
#include <cstdlib>

bool any_int(double a, double b, double c) {
    if (std::round(a) != a || std::round(b) != b || std::round(c) != c) {
        return false;
    }
    if (a + b == c || a + c == b || b + c == a) {
        return true;
    }
    return false;
}

int main() {
    bool result;

    result = any_int(2.0, 3.0, 1.0);
    if (!result) {
        std::cerr << "Assertion failed: any_int(2, 3, 1) == true" << std::endl;
        std::exit(1);
    }

    result = any_int(2.5, 2.0, 3.0);
    if (result) {
        std::cerr << "Assertion failed: any_int(2.5, 2, 3) == false" << std::endl;
        std::exit(1);
    }

    result = any_int(1.5, 5.0, 3.5);
    if (result) {
        std::cerr << "Assertion failed: any_int(1.5, 5, 3.5) == false" << std::endl;
        std::exit(1);
    }

    result = any_int(2.0, 6.0, 2.0);
    if (result) {
        std::cerr << "Assertion failed: any_int(2, 6, 2) == false" << std::endl;
        std::exit(1);
    }

    result = any_int(4.0, 2.0, 2.0);
    if (!result) {
        std::cerr << "Assertion failed: any_int(4, 2, 2) == true" << std::endl;
        std::exit(1);
    }

    result = any_int(2.2, 2.2, 2.2);
    if (result) {
        std::cerr << "Assertion failed: any_int(2.2, 2.2, 2.2) == false" << std::endl;
        std::exit(1);
    }

    result = any_int(-4.0, 6.0, 2.0);
    if (!result) {
        std::cerr << "Assertion failed: any_int(-4, 6, 2) == true" << std::endl;
        std::exit(1);
    }

    result = any_int(2.0, 1.0, 1.0);
    if (!result) {
        std::cerr << "Assertion failed: any_int(2, 1, 1) == true" << std::endl;
        std::exit(1);
    }

    result = any_int(3.0, 4.0, 7.0);
    if (!result) {
        std::cerr << "Assertion failed: any_int(3, 4, 7) == true" << std::endl;
        std::exit(1);
    }

    result = any_int(3.01, 4.0, 7.0);
    if (result) {
        std::cerr << "Assertion failed: any_int(3.01, 4, 7) == false" << std::endl;
        std::exit(1);
    }

    std::cout << "All tests passed." << std::endl;

    return 0;
}
```

This C++ code includes the same logic and tests as the original Fortran code. It defines a function `any_int` that takes three double-precision floating-point numbers as arguments and returns a boolean value indicating whether the function's conditions are met. The `main` function contains assertions similar to the Fortran program, checking the function's output against expected results and printing error messages if the assertions fail.
