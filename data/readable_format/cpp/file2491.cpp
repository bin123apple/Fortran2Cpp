#include <iostream>

bool XDLAISNAN(double DIN1, double DIN2) {
    return DIN1 != DIN2;
}

int main() {
    double a, b;

    // Test case 1: a and b are equal
    a = 1.0;
    b = 1.0;
    std::cout << "Test case 1: " << std::boolalpha << XDLAISNAN(a, b) << std::endl;  // Expected output: false

    // Test case 2: a and b are different
    a = 1.0;
    b = 2.0;
    std::cout << "Test case 2: " << std::boolalpha << XDLAISNAN(a, b) << std::endl;  // Expected output: true
}