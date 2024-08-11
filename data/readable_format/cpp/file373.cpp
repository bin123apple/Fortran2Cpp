#include <iostream>
#include <cmath>
#include <cstdlib>

// Rename gamma to gamma_const to avoid name clash with the gamma function in math.h
const double gamma_const = 1.4;

// speed_of_sound function prototype
double speed_of_sound(double p, double rho);

// Test function prototype
void test_speed_of_sound(double p, double rho, double expected);

// Definition of speed_of_sound function
double speed_of_sound(double p, double rho) {
    return std::sqrt(gamma_const * p / rho);
}

// Definition of the test function
void test_speed_of_sound(double p, double rho, double expected) {
    const double tolerance = 1e-5;
    double result = speed_of_sound(p, rho);
    if (std::fabs(result - expected) > tolerance) {
        std::cerr << "Test failed for p=" << p << " and rho=" << rho << " | Expected: " << expected << ", Got: " << result << std::endl;
        std::exit(EXIT_FAILURE);
    } else {
        std::cout << "Test passed for p=" << p << " and rho=" << rho << std::endl;
    }
}

int main() {
    // Example test case
    double p = 101325; // Pressure in Pascals
    double rho = 1.225; // Density in kg/m^3 (approximately air density at sea level)
    double expected_speed = std::sqrt(gamma_const * p / rho); // Manually calculate expected speed for testing

    test_speed_of_sound(p, rho, expected_speed);

    return 0;
}