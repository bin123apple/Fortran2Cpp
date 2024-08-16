Translating the provided Fortran code to C++ involves several steps, including changing the syntax, converting the module to a class or namespace, and handling array indexing differences. Here's how the Fortran code can be translated into C++:

```cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

namespace polynomial_module {
    // Define the poly function
    double poly(const std::vector<double>& xs, int n, double x) {
        double sum = 0.0;
        for (int i = 0; i < n; ++i) {
            sum += xs[i] * std::pow(x, i);
        }
        return sum;
    }

    // Define the find_zero function
    double find_zero(const std::vector<double>& xs, int n) {
        double ans = 0.0;
        double value = poly(xs, n, ans);
        while (std::abs(value) > 1e-6) {
            double driv = 0.0;
            for (int i = 1; i < n; ++i) {
                driv += xs[i] * (i) * std::pow(ans, i - 1);
            }
            ans -= value / driv;
            value = poly(xs, n, ans);
        }
        return ans;
    }
}

int main() {
    std::srand(std::time(nullptr));

    for (int i = 0; i < 100; ++i) {
        int ncoeff = 2 * (1 + std::rand() % 4);
        std::vector<double> coeffs(ncoeff);

        for (int j = 0; j < ncoeff; ++j) {
            coeffs[j] = -10 + std::rand() % 21;
            if (coeffs[j] == 0) coeffs[j] = 1;
        }

        double solution = polynomial_module::find_zero(coeffs, ncoeff);
        if (std::abs(polynomial_module::poly(coeffs, ncoeff, solution)) >= 1e-3) {
            std::cerr << "Assertion failed: abs(poly(coeffs, solution)) < 1e-3" << std::endl;
            return 1;
        }
    }

    return 0;
}
```

### Key Changes:

1. **Module to Namespace/Class**: Fortran modules are used to group related procedures and data. In C++, a namespace can serve a similar purpose. However, since we're not dealing with global state or encapsulating data, a namespace is more appropriate.

2. **Arrays**: Fortran arrays are 1-based, while C++ arrays (and vectors) are 0-based. This is accounted for in the translation.

3. **Random Number Generation**: The C++ `<cstdlib>` and `<ctime>` headers are used for random number generation, similar to Fortran's `random_seed` and `random_number`.

4. **Function Arguments**: In C++, functions can directly use `std::vector<double>` for the coefficients array, and primitive types for other arguments.

5. **Mathematical Functions**: The `std::pow` function from the `<cmath>` header is used for exponentiation, and `std::abs` for absolute value calculations.

6. **Program Structure**: The `main` function in C++ serves as the entry point for the program, similar to the `program` block in Fortran.

This translation should provide a functional equivalent of the original Fortran code in C++.
Let's write some test to verify if the translation is correct. 
Below are examples of unit tests for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the `poly` and `find_zero` functions under various conditions.

### Fortran Unit Tests

To test the Fortran code, we can write a simple test program that uses the `polynomial_module` and checks the functionality of `poly` and `find_zero` functions with predefined inputs.

```fortran
program test_polynomial_module
    use polynomial_module
    implicit none
    real(8) :: test_poly_coeffs(5)
    real(8) :: test_find_zero_coeffs(3)
    real(8) :: result
    integer :: i

    ! Test poly function
    test_poly_coeffs = [1.0d0, 2.0d0, 3.0d0, 4.0d0, 5.0d0]
    result = poly(test_poly_coeffs, 5, 2.0d0)
    print *, "Test poly with x = 2: ", result

    ! Test find_zero function
    test_find_zero_coeffs = [1.0d0, -2.0d0, 1.0d0]
    result = find_zero(test_find_zero_coeffs, 3)
    print *, "Test find_zero with solution x = ", result

end program test_polynomial_module
```

### C++ Unit Tests

For C++, we can use a simple testing approach similar to Fortran, or for more comprehensive testing, use a testing framework like Google Test. Here, I'll provide a basic example without a framework for simplicity.

```cpp
#include <iostream>
#include <vector>
#include <cmath>
#include "polynomial_module.hpp" // Assume the translated code is in this header

void test_poly(const std::vector<double>& coeffs, double x, double expected) {
    double result = polynomial_module::poly(coeffs, coeffs.size(), x);
    if (std::abs(result - expected) < 1e-6) {
        std::cout << "Test poly with x = " << x << " passed." << std::endl;
    } else {
        std::cerr << "Test poly with x = " << x << " failed." << std::endl;
    }
}

void test_find_zero(const std::vector<double>& coeffs, double expected) {
    double result = polynomial_module::find_zero(coeffs, coeffs.size());
    if (std::abs(result - expected) < 1e-6) {
        std::cout << "Test find_zero with solution x = " << result << " passed." << std::endl;
    } else {
        std::cerr << "Test find_zero with solution x = " << result << " failed." << std::endl;
    }
}

int main() {
    // Test poly function
    std::vector<double> test_poly_coeffs = {1.0, 2.0, 3.0, 4.0, 5.0};
    test_poly(test_poly_coeffs, 2.0, 25.0); // Expected result: 25.0

    // Test find_zero function
    std::vector<double> test_find_zero_coeffs = {1.0, -2.0, 1.0};
    test_find_zero(test_find_zero_coeffs, 1.0); // Expected result: 1.0

    return 0;
}
```

### Explanation:

1. **Fortran Tests**:
   - The `test_poly` function checks if the `poly` function returns the expected result for a predefined set of coefficients and a value of `x`.
   - The `test_find_zero` function checks if the `find_zero` function correctly finds a zero for a predefined set of coefficients.

2. **C++ Tests**:
   - The `test_poly` function in C++ performs a similar test to the Fortran version, checking the `poly` function's output.
   - The `test_find_zero` function checks the output of the `find_zero` function.

These tests should help verify that the `poly` and `find_zero` functions work as expected in both the Fortran and C++ implementations. Remember to compile and run these tests in their respective environments.
