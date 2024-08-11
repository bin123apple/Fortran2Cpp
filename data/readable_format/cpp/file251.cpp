#include <iostream>
#include <cmath> // For std::abs

// Function declaration and definition
void init_conds(double x, double y, double z, double& rho, double& ux, double& uy, double& uz, double& p) {
    // Initialize vertical velocity to zero
    uz = 0.0;

    // Conditionally set pressure and density based on x and y coordinates
    if (x >= 0.25 && x <= 0.75 && y >= 0.25 && y <= 0.75) {
        p = 2.5;
        rho = 4.0;
    } else {
        p = 2.5;
        rho = 1.0;
    }

    // Initialize horizontal velocities
    ux = 0.5;
    uy = 0.5;
}

// Test function
void test_init_conds(double x, double y, double z, double expected_rho, double expected_ux, double expected_uy, double expected_uz, double expected_p) {
    double rho, ux, uy, uz, p;
    init_conds(x, y, z, rho, ux, uy, uz, p);

    if (std::abs(rho - expected_rho) < 1e-6 && std::abs(ux - expected_ux) < 1e-6 && std::abs(uy - expected_uy) < 1e-6 && std::abs(uz - expected_uz) < 1e-6 && std::abs(p - expected_p) < 1e-6) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
        std::cout << "Expected: rho=" << expected_rho << ", ux=" << expected_ux << ", uy=" << expected_uy << ", uz=" << expected_uz << ", p=" << expected_p << std::endl;
        std::cout << "Got: rho=" << rho << ", ux=" << ux << ", uy=" << uy << ", uz=" << uz << ", p=" << p << std::endl;
    }
}

// Main function
int main() {
    // Test case within specified range
    test_init_conds(0.5, 0.5, 0.0, 4.0, 0.5, 0.5, 0.0, 2.5);

    // Test case outside specified range
    test_init_conds(0.1, 0.1, 0.0, 1.0, 0.5, 0.5, 0.0, 2.5);

    return 0;
}