#include <iostream>

class XYZ {
public:
    int x;
    XYZ() : x(123) {} // Constructor initializes x to 123
};

int main() {
    XYZ a, b; // Create two instances of XYZ

    // Check if the instances have the x value correctly set to 123
    if (a.x != 123) {
        std::cerr << "Error: a.x is not 123" << std::endl;
        return 1; // Return 1 if a.x is not 123
    }
    if (b.x != 123) {
        std::cerr << "Error: b.x is not 123" << std::endl;
        return 2; // Return 2 if b.x is not 123
    }

    // If both checks pass, print a success message and exit with code 0
    std::cout << "C++ code checks passed." << std::endl;
    return 0;
}