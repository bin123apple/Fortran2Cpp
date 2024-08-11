#include <iostream>

// Using namespace to simulate Fortran module
namespace bad {
    
    // C++ class to represent Fortran type with default initialization
    class DefaultInitialization {
    public:
        int x = 42; // Default initialization
    };

    // Instance of class to simulate the type declaration in Fortran
    DefaultInitialization t;
}

int main() {
    // Example usage
    std::cout << "The value of x is: " << bad::t.x << std::endl;
    return 0;
}