#include <iostream>
#include <cmath>
#include <cassert>

void LBTORD(double& LRAD, double& BRAD, double& RA, double& DEC) {
    const double PI = 3.1415926535898;
    const double TWOPI = 2.0 * PI;
    const double CON27 = 27.40 * PI / 180.0;
    const double CON33 = 33.00 * PI / 180.0;
    const double CON192 = 192.25 * PI / 180.0;

    double X, Y, SINA;

    SINA = std::sin(BRAD) * std::sin(CON27) + std::cos(BRAD) * std::cos(CON27) * std::sin(LRAD - CON33);
    X = std::cos(BRAD) * std::cos(LRAD - CON33);
    Y = std::sin(BRAD) * std::cos(CON27) - std::cos(BRAD) * std::sin(CON27) * std::sin(LRAD - CON33);

    RA = std::atan2(X, Y) + CON192;
    DEC = std::asin(SINA);
    
    RA = std::fmod(RA + TWOPI, TWOPI);
}

// Simple assertion utility for floating-point comparison
void assertApprox(double actual, double expected, double epsilon = 1e-6) {
    assert(std::fabs(actual - expected) < epsilon);
}

int main() {
    double LRAD, BRAD, RA, DEC;

    // Test 1
    LRAD = 1.0;
    BRAD = 0.5;
    LBTORD(LRAD, BRAD, RA, DEC);
    std::cout << "Test 1: RA = " << RA << ", DEC = " << DEC << std::endl;
    // Note: Replace expected_RA and expected_DEC with the actual expected values
    // assertApprox(RA, expected_RA);
    // assertApprox(DEC, expected_DEC);

    // Test 2
    LRAD = 2.0;
    BRAD = 1.0;
    LBTORD(LRAD, BRAD, RA, DEC);
    std::cout << "Test 2: RA = " << RA << ", DEC = " << DEC << std::endl;
    // Note: Replace expected_RA and expected_DEC with the actual expected values
    // assertApprox(RA, expected_RA);
    // assertApprox(DEC, expected_DEC);

    // Add more tests as needed

    std::cout << "All tests passed!" << std::endl;

    return 0;
}