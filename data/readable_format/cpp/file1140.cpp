#include <iostream>
#include <cmath> // For std::abs
#include <vector>
#include <string>

// Linear interpolation function
double linearInterpolation(double x1, double y1, double x2, double y2, double xi) {
    return y1 + (xi - x1) * (y2 - y1) / (x2 - x1);
}

// A simple test function for linear interpolation
void testLinearInterpolation(double x1, double y1, double x2, double y2, double xi, double expectedYi, const std::string& testName) {
    double yi = linearInterpolation(x1, y1, x2, y2, xi);
    if (std::abs(yi - expectedYi) < 1e-6) {
        std::cout << "PASS: " << testName << std::endl;
    } else {
        std::cout << "FAIL: " << testName << " - Expected " << expectedYi << ", got " << yi << std::endl;
    }
}

int main() {
    // Test cases for linear interpolation
    testLinearInterpolation(0.0, 0.0, 10.0, 10.0, 5.0, 5.0, "Test 1: Simple linear interpolation");
    testLinearInterpolation(1.0, 2.0, 3.0, 4.0, 2.0, 3.0, "Test 2: Off-origin linear interpolation");

    return 0;
}