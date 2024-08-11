#include <iostream>
#include <cmath>
#include <string>

// Define precision as double for compatibility
using dp = double;

// Constants directly within the namespace
namespace constants {
    constexpr dp pi = 3.14159265358979323846;
    constexpr dp G_grav = 6.67430e-8; // Gravitational constant in cgs units
    constexpr dp Mpc = 3.085677581491367e24; // Megaparsec in cm
}

class cosmology_parameters {
public:
    static constexpr char cosmo_id[] = "WMAP5"; // Adjusted for potential linkage issue
    static constexpr dp h = 0.7;
    static constexpr dp Omega0 = 0.279;
    static constexpr dp Omega_B = 0.046;
    static constexpr dp cmbtemp = 2.726;
    static constexpr dp sigma8 = 0.817;
    static constexpr dp n_s = 0.96;
    static constexpr dp H0 = h * 100.0 * 1e5 / constants::Mpc; // Hubble constant
    static constexpr dp rho_crit_0 = 3.0 * H0 * H0 / (8.0 * constants::pi * constants::G_grav); // Critical density

    // Display function to show the constants
    static void display() {
        std::cout << "Cosmology ID: " << cosmo_id << std::endl
                  << "h: " << h << std::endl
                  << "Omega0: " << Omega0 << std::endl
                  << "Omega_B: " << Omega_B << std::endl
                  << "CMB Temperature: " << cmbtemp << " K" << std::endl
                  << "Sigma8: " << sigma8 << std::endl
                  << "Scalar Spectral Index (n_s): " << n_s << std::endl
                  << "Hubble Constant (H0): " << H0 << " (cm/s/Mpc)" << std::endl
                  << "Critical Density (rho_crit_0): " << rho_crit_0 << " (g/cm^3)" << std::endl;
    }
};

// Definition for static constexpr members that need to be addressed outside the class for certain compilers
constexpr char cosmology_parameters::cosmo_id[];

int main() {
    // Display all the cosmology parameters
    cosmology_parameters::display();

    return 0;
}