#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

// Define the correct_flux function directly in this file
void correct_flux(int n, const std::vector<double>& velocity, const std::vector<double>& area, 
                  const std::vector<double>& flux_in, std::vector<double>& flux_out, double correction) {
    for (int i = 0; i < n; ++i) {
        if (velocity[i] > 0.0) {
            flux_out[i] = flux_in[i] * area[i] * correction;
        } else {
            flux_out[i] = flux_in[i];
        }
    }
}

// Define the unit test function
void test_correct_flux() {
    // Test 1: No correction needed
    {
        std::vector<double> velocity = {0.0, -1.0, 0.0};
        std::vector<double> area = {1.0, 1.0, 1.0};
        std::vector<double> flux_in = {100.0, 200.0, 300.0};
        std::vector<double> flux_out(3);
        double correction = 1.5;

        correct_flux(3, velocity, area, flux_in, flux_out, correction);

        assert(flux_out[0] == 100.0 && flux_out[1] == 200.0 && flux_out[2] == 300.0);
    }

    // Test 2: Correction applied to all elements
    {
        std::vector<double> velocity = {1.0, 2.0, 1.0};
        std::vector<double> area = {1.0, 1.0, 1.0};
        std::vector<double> flux_in = {100.0, 200.0, 300.0};
        std::vector<double> flux_out(3);
        double correction = 1.5;

        correct_flux(3, velocity, area, flux_in, flux_out, correction);

        assert(flux_out[0] == 150.0 && flux_out[1] == 300.0 && flux_out[2] == 450.0);
    }

    // Test 3: Mixed case
    {
        std::vector<double> velocity = {0.0, 2.0, -1.0};
        std::vector<double> area = {1.0, 1.0, 1.0};
        std::vector<double> flux_in = {100.0, 200.0, 300.0};
        std::vector<double> flux_out(3);
        double correction = 1.5;

        correct_flux(3, velocity, area, flux_in, flux_out, correction);

        assert(flux_out[0] == 100.0 && flux_out[1] == 300.0 && std::fabs(flux_out[2] - 300.0) < 1e-5);
    }

    std::cout << "All tests passed." << std::endl;
}

// The main function to run the tests
int main() {
    test_correct_flux();
    return 0;
}