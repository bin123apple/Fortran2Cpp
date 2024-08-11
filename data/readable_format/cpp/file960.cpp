#include <iostream>

// Declare template function
template<int DIM, typename Precision>
void ppm_gmm_march_fwd();

// Specializations for 2D Single Precision
template<>
void ppm_gmm_march_fwd<2, float>() {
    std::cout << "Executing 2D, single precision version." << std::endl;
}

// Specializations for 2D Double Precision
template<>
void ppm_gmm_march_fwd<2, double>() {
    std::cout << "Executing 2D, double precision version." << std::endl;
}

// Specializations for 3D Single Precision
template<>
void ppm_gmm_march_fwd<3, float>() {
    std::cout << "Executing 3D, single precision version." << std::endl;
}

// Specializations for 3D Double Precision
template<>
void ppm_gmm_march_fwd<3, double>() {
    std::cout << "Executing 3D, double precision version." << std::endl;
}

int main() {
    // Example usage
    ppm_gmm_march_fwd<2, float>(); // Calls the 2D, single precision variant
    ppm_gmm_march_fwd<2, double>(); // Calls the 2D, double precision variant
    ppm_gmm_march_fwd<3, float>(); // Calls the 3D, single precision variant
    ppm_gmm_march_fwd<3, double>(); // Calls the 3D, double precision variant

    std::cout << "All tests executed." << std::endl;

    return 0;
}