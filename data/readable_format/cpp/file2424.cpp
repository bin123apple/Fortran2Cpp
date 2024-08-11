#include <iostream>

// Define a class 'T' similar to the derived type 't' in Fortran
class T {
public:
    // Constructor
    T() {
        // Initialization code (if any) goes here
    }
};

// Function that returns an instance of class 'T'
T foo() {
    return T();
}

int main() {
    // Create an instance of 'T' using the 'foo' function
    T obj = foo();
    
    // Use 'obj' as needed
    // For example, print a message (though the class itself doesn't have any data or methods to display)
    std::cout << "Instance of T created using foo()" << std::endl;

    return 0;
}