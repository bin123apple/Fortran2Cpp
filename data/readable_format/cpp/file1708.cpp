#include <iostream>
#include <cstdlib> // For abort()
#include <vector>

// Simulating the Fortran module with a namespace
namespace nonF03ComBlock {

// Global variables simulating the common block
double r;
double s;

// Function prototype
void hello(std::vector<int>& myArray);

// Definition of the hello function
void hello(std::vector<int>& myArray) {
    r = 1.0;
    s = 2.0;
}

} // End of namespace nonF03ComBlock

int main() {
    // Using the namespace
    using namespace nonF03ComBlock;

    // Simulating the Fortran array with a std::vector
    std::vector<int> myArray(10); // Note: C++ uses 0-based indexing

    // Call the function
    hello(myArray);

    // Check the values of r and s, and call abort if they are not as expected
    if(r != 1.0) {
        std::abort();
    }
    if(s != 2.0) {
        std::abort();
    }

    return 0;
}