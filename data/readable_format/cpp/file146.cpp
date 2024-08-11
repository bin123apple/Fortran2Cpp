#include <iostream>

// Function to calculate the square of a number
float square(float x) {
    return x * x;
}

int main() {
    // Constants for mass, gravity, height, and velocity
    const float mass = 3.00;
    const float gravity = 9.81;
    const float height = 4.20;
    const float velocity = 4.00;

    // Calculating potential energy
    float potential_energy = mass * gravity * height;

    // Calculating kinetic energy
    float kinetic_energy = 0.5 * mass * square(velocity);

    // Calculating total energy
    float total_energy = potential_energy + kinetic_energy;

    // Printing the results
    std::cout << "Potential Energy: " << potential_energy << std::endl;
    std::cout << "Kinetic Energy: " << kinetic_energy << std::endl;
    std::cout << "Total Energy: " << total_energy << std::endl;

    return 0;
}