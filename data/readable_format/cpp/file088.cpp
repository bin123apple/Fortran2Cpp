#include <iostream>
#include <cmath>
#include <cassert>

// Define the area function
void area(double r, double& a) {
    a = M_PI * std::pow(r, 2);
}

int main() {
    double radius;
    double calculatedArea;

    // Test 1: Radius = 0.0
    radius = 0.0;
    area(radius, calculatedArea);
    assert(calculatedArea == 0.0);

    // Test 2: Radius = 1.0 (Area should be Pi)
    radius = 1.0;
    area(radius, calculatedArea);
    assert(calculatedArea == M_PI);

    // Test 3: Radius = 10.0
    radius = 10.0;
    area(radius, calculatedArea);
    assert(calculatedArea == M_PI * 100.0);

    // Test 4: Small radius
    radius = 0.001;
    area(radius, calculatedArea);
    assert(calculatedArea == M_PI * std::pow(0.001, 2));

    std::cout << "All tests passed!" << std::endl;

    return 0;
}