#include <iostream>
#include <memory> // For std::unique_ptr

// Define a struct to represent the Fortran type 'x'
struct x {
    std::unique_ptr<int> i; // Using unique_ptr to represent a pointer to an integer
    
    x() : i(nullptr) {} // Constructor initializes i to nullptr, similar to '=> null()' in Fortran
};

int main() {
    x y; // Create an instance of 'x' named 'y'
    
    // Check if 'y.i' is associated (not null in C++ terms)
    bool associated = (y.i != nullptr);
    
    // Print the result
    std::cout << std::boolalpha << associated << std::endl;
    
    return 0;
}