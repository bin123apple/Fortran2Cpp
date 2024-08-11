#include <iostream>

// Assuming all functions work with integers for demonstration purposes
void great(int a, int b) {
    std::cout << "Great function called with: " << a << ", " << b << std::endl;
}

// Overload the great function to demonstrate handling different signatures
// You can define more overloads or entirely different functions as needed
void great(double a, double b) {
    std::cout << "Great function (double) called with: " << a << ", " << b << std::endl;
}

// Main function to test the great functions
int main() {
    great(5, 10); // Calls the first version
    great(3.14, 1.59); // Calls the overloaded version

    // Add calls to other functions or perform additional tests here
    return 0;
}