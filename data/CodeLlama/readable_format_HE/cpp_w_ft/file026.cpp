Certainly! Below is the translated C++ code from the provided Fortran code. This C++ code includes the `is_prime` function and a series of assertions to test the function, similar to the Fortran version.

```cpp
#include <iostream>
#include <cmath>

// Function to check if a number is prime
bool is_prime(int n) {
    if (n < 2) return false;

    for (int i = 2; i <= static_cast<int>(std::sqrt(n)); ++i) {
        if (n % i == 0) return false;
    }

    return true;
}

int main() {
    // Assertions to test the is_prime function
    if (!is_prime(6)) {
        std::cerr << "Assertion failed: is_prime(6) == false" << std::endl;
        return 1;
    }

    if (!is_prime(101)) {
        std::cerr << "Assertion failed: is_prime(101) == true" << std::endl;
        return 1;
    }

    if (!is_prime(11)) {
        std::cerr << "Assertion failed: is_prime(11) == true" << std::endl;
        return 1;
    }

    if (!is_prime(13441)) {
        std::cerr << "Assertion failed: is_prime(13441) == true" << std::endl;
        return 1;
    }

    if (!is_prime(61)) {
        std::cerr << "Assertion failed: is_prime(61) == true" << std::endl;
        return 1;
    }

    if (!is_prime(4)) {
        std::cerr << "Assertion failed: is_prime(4) == false" << std::endl;
        return 1;
    }

    if (!is_prime(1)) {
        std::cerr << "Assertion failed: is_prime(1) == false" << std::endl;
        return 1;
    }

    if (!is_prime(5)) {
        std::cerr << "Assertion failed: is_prime(5) == true" << std::endl;
        return 1;
    }

    if (!is_prime(11)) {
        std::cerr << "Assertion failed: is_prime(11) == true" << std::endl;
        return 1;
    }

    if (!is_prime(17)) {
        std::cerr << "Assertion failed: is_prime(17) == true" << std::endl;
        return 1;
    }

    if (is_prime(5 * 17)) {
        std::cerr << "Assertion failed: is_prime(5 * 17) == false" << std::endl;
        return 1;
    }

    if (is_prime(11 * 7)) {
        std::cerr << "Assertion failed: is_prime(11 * 7) == false" << std::endl;
        return 1;
    }

    if (is_prime(13441 * 19)) {
        std::cerr << "Assertion failed: is_prime(13441 * 19) == false" << std::endl;
        return 1;
    }

    std::cout << "All assertions passed." << std::endl;

    return 0;
}
```

This C++ code includes the necessary headers and uses the `std::sqrt` function to calculate the square root of a number, similar to the Fortran `sqrt` function. The `is_prime` function is implemented to check if a number is prime, and the main function contains assertions to test this function with various inputs. If any assertion fails, the program will print an error message and return a non-zero exit code, indicating a failed test.
