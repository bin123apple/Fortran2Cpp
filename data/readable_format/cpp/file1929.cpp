#include <iostream>
#include <cstdlib>

// Equivalent to the Fortran module `a`
namespace a {
    // Forward declarations for the functions to mimic the interface behavior with overloading
    double b(double i);
    double b(int j);

    // Implementing the function `d` and its entry point `c` as a class with overloaded call operators
    class dFunction {
    public:
        double operator()(double i) {
            return 1.0;
        }

        double operator()(int j) {
            return 2.0;
        }
    };

    // Implementing the function `e` and its entry point `f` as another class with overloaded call operators
    class eFunction {
    public:
        double operator()(double i) {
            return 3.0;
        }

        double operator()(int j) {
            return 4.0;
        }
    };

    // Instantiate the classes to use for the function calls
    dFunction d;
    eFunction e;

    // Mimicking the Fortran interface `b` by using function overloading
    double b(double i) {
        return d(i); // Calls the double version
    }

    double b(int j) {
        return d(j); // Calls the int version, mimicking the entry point behavior
    }

    // In Fortran, `e` and `f` would be accessed directly without going through an interface like `b`
    // So we don't define additional functions for them here; we'll use `e` object directly in the global scope
}

int main() {
    using namespace a; // Bring everything from namespace a into scope

    if (b(1.0) != 1.0) std::abort();
    if (b(1) != 2.0) std::abort();
    if (e(1.0) != 3.0) std::abort();
    if (e(1) != 4.0) std::abort();

    std::cout << "All checks passed." << std::endl;

    return 0;
}