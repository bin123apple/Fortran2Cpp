#include <iostream>
#include <cmath> // For fabs function

// Function to calculate potential energy
float calculate_potential_energy(float mass, float gravity, float height) {
    return mass * gravity * height;
}

// Basic function to test the calculate_potential_energy function
void test_potential_energy(float mass, float gravity, float height, float expected) {
    float result = calculate_potential_energy(mass, gravity, height);
    if (fabs(result - expected) < 0.001) {
        std::cout << "Test passed: " << result << " is close to expected " << expected << std::endl;
    } else {
        std::cout << "Test failed: " << result << " is not close to expected " << expected << std::endl;
    }
}

int main() {
    // Constants
    const float mass = 3.00f;
    const float gravity = 0.81f;
    const float height = 4.20f;
    
    // Calculate potential energy
    float potential_energy = calculate_potential_energy(mass, gravity, height);
    std::cout << "Potential energy: " << potential_energy << std::endl;
    
    // Run a basic test
    test_potential_energy(mass, gravity, height, mass * gravity * height);

    return 0;
}