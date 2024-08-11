#include <iostream>

// Assuming double precision for the calculations
using real = double;

// Placeholder for the gsw_gibbs_ice function - replace with actual implementation
real gsw_gibbs_ice(int n1, int n2, real t, real p) {
    // Dummy implementation - replace with actual calculations
    return t * p * 0.01;
}

// Function to calculate the thermal expansion coefficient of ice
real gsw_alpha_wrt_t_ice(real t, real p) {
    return gsw_gibbs_ice(1, 1, t, p) / gsw_gibbs_ice(0, 1, t, p);
}

// Main function to test gsw_alpha_wrt_t_ice with different values of t and p
int main() {
    // Test case 1
    real t = 263.15;  // Kelvin
    real p = 10.0;    // Decibars
    std::cout << "Test case 1: T=" << t << " P=" << p << " Alpha=" << gsw_alpha_wrt_t_ice(t, p) << std::endl;

    // You can add more test cases here

    return 0;
}