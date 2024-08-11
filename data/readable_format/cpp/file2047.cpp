#include <iostream>
#include <cmath>
#include <algorithm>

// Define the dlapy3 function directly in this file
double dlapy3(double x, double y, double z) {
    double zero = 0.0;
    double w, xAbs, yAbs, zAbs;

    xAbs = std::abs(x);
    yAbs = std::abs(y);
    zAbs = std::abs(z);
    w = std::max({xAbs, yAbs, zAbs}); // Use initializer list for max

    if (w == zero) {
        return xAbs + yAbs + zAbs;
    } else {
        return w * std::sqrt(std::pow(xAbs / w, 2) + std::pow(yAbs / w, 2) + std::pow(zAbs / w, 2));
    }
}

// Main function to test dlapy3
int main() {
    // Test 1
    double result = dlapy3(3.0, 4.0, 0.0);
    std::cout << "Test 1 (3,4,0): Should be close to 5.0 - Result: " << result << std::endl;
    
    // Test 2
    result = dlapy3(0.0, 0.0, 0.0);
    std::cout << "Test 2 (0,0,0): Should be 0.0 - Result: " << result << std::endl;
    
    // Test 3
    result = dlapy3(1.0, 1.0, 1.0);
    std::cout << "Test 3 (1,1,1): Should be close to 1.732 - Result: " << result << std::endl;
    
    // Add more tests as needed

    return 0;
}