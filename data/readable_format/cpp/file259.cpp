#include <iostream>
#include <cmath> // For std::fabs()

// Define the constants directly in the file
const int IFLAG_HALFSPACE_MOHO = 1;
const int IFLAG_MOHO_16km = 2;
const int IFLAG_ONE_LAYER_TOPOGRAPHY = 3;
const int IFLAG_BASEMENT_TOPO = 4;

void socal_model(int idoubling, double& rho, double& vp, double& vs) {
    if (idoubling == IFLAG_HALFSPACE_MOHO) {
        vp = 7.8;
        vs = 4.5;
        rho = 3.0;
    } else if (idoubling == IFLAG_MOHO_16km) {
        vp = 6.7;
        vs = 3.87;
        rho = 2.8;
    } else if (idoubling == IFLAG_ONE_LAYER_TOPOGRAPHY || idoubling == IFLAG_BASEMENT_TOPO) {
        vp = 5.5;
        vs = 3.18;
        rho = 2.4;
    } else {
        vp = 6.3;
        vs = 3.64;
        rho = 2.67;
    }

    // Convert from km/s to m/s and kg/cm^3 to kg/m^3
    vp = vp * 1000.0;
    vs = vs * 1000.0;
    rho = rho * 1000.0;
}

void test_socal_model(int idoubling, double expected_rho, double expected_vp, double expected_vs) {
    double rho, vp, vs;
    socal_model(idoubling, rho, vp, vs);
    std::cout << "Testing idoubling=" << idoubling << ": ";
    if (std::fabs(rho - expected_rho) < 1e-6 && std::fabs(vp - expected_vp) < 1e-6 && std::fabs(vs - expected_vs) < 1e-6) {
        std::cout << "PASS" << std::endl;
    } else {
        std::cout << "FAIL. Got rho=" << rho << ", vp=" << vp << ", vs=" << vs << std::endl;
    }
}

int main() {
    // Test cases
    test_socal_model(IFLAG_HALFSPACE_MOHO, 3000.0, 7800.0, 4500.0);
    test_socal_model(IFLAG_MOHO_16km, 2800.0, 6700.0, 3870.0);
    test_socal_model(IFLAG_ONE_LAYER_TOPOGRAPHY, 2400.0, 5500.0, 3180.0);
    test_socal_model(IFLAG_BASEMENT_TOPO, 2400.0, 5500.0, 3180.0);
    test_socal_model(-1, 2670.0, 6300.0, 3640.0); // Default case

    return 0;
}