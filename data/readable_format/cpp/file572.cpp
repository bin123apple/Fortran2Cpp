#include <iostream>
#include <cmath> // For std::abs

// Define the BrickTee class
class BrickTee {
private:
    double c, a, rho_te, sa, TE_0;
    double TE;

public:
    // Constructor
    BrickTee() {}

    // Member functions
    void init_brick_tee(double h_capacity, double expansion_coeff,
                        double density0, double ocsa, double Initial_TE,
                        double& thermal) {
        c = h_capacity;
        a = expansion_coeff;
        rho_te = density0;
        sa = ocsa;
        TE_0 = Initial_TE;

        thermal = TE_0;
        TE = thermal;
    }

    void brick_tee_step_forward(double deltaH, double thermal_previous,
                                 double& thermal_current) {
        thermal_current = thermal_previous + deltaH * a / (c * rho_te * rho_te * sa);
        TE = thermal_current;
    }

    void brick_tee_step_backward(double deltaH, double thermal_current,
                                 double& thermal_previous) {
        thermal_previous = thermal_current - deltaH * a / (c * rho_te * rho_te * sa);
    }
};

int main() {
    BrickTee brickTee;
    double thermal;
    double deltaH = 10.0;
    double thermal_previous = 100.0;
    double thermal_current;
    double expected_thermal_current;
    double expected_thermal_previous;
    
    // Initialize the BrickTee
    brickTee.init_brick_tee(1.0, 0.5, 2.0, 4.0, 100.0, thermal);
    
    // Test brick_tee_step_forward
    brickTee.brick_tee_step_forward(deltaH, thermal_previous, thermal_current);
    expected_thermal_current = thermal_previous + deltaH * 0.5 / (1.0 * 2.0 * 2.0 * 4.0);
    if (std::abs(thermal_current - expected_thermal_current) < 1e-6) {
        std::cout << "brick_tee_step_forward test passed." << std::endl;
    } else {
        std::cout << "brick_tee_step_forward test failed." << std::endl;
    }
    
    // Test brick_tee_step_backward
    brickTee.brick_tee_step_backward(deltaH, thermal_current, thermal_previous);
    expected_thermal_previous = thermal_current - deltaH * 0.5 / (1.0 * 2.0 * 2.0 * 4.0);
    if (std::abs(thermal_previous - expected_thermal_previous) < 1e-6) {
        std::cout << "brick_tee_step_backward test passed." << std::endl;
    } else {
        std::cout << "brick_tee_step_backward test failed." << std::endl;
    }

    return 0;
}