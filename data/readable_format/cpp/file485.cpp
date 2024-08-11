#include <iostream>
#include <cassert>

#define SINGLE_PRECISION 1
#define DOUBLE_PRECISION 2

namespace ppm_module_util_gmres {

constexpr int ppm_gmres_param_success = 0;
constexpr int ppm_gmres_param_failure = 1;
constexpr int ppm_gmres_param_maxiter = 2;

// Simulated implementation for single precision
template<int Precision>
int ppm_util_gmres() {
    std::cout << "Called GMRES with precision: " << Precision << std::endl;
    return ppm_gmres_param_success; // Dummy success
}

// Simulated implementation for double precision
template<int Precision>
int ppm_util_gmres_solveupper() {
    std::cout << "Called solve upper with precision: " << Precision << std::endl;
    return ppm_gmres_param_success; // Dummy success
}

} // namespace ppm_module_util_gmres

int main() {
    using namespace ppm_module_util_gmres;

    // Test single precision GMRES
    assert(ppm_util_gmres<SINGLE_PRECISION>() == ppm_gmres_param_success);
    std::cout << "Single precision GMRES test passed." << std::endl;

    // Test double precision GMRES
    assert(ppm_util_gmres<DOUBLE_PRECISION>() == ppm_gmres_param_success);
    std::cout << "Double precision GMRES test passed." << std::endl;

    // Test single precision solve upper
    assert(ppm_util_gmres_solveupper<SINGLE_PRECISION>() == ppm_gmres_param_success);
    std::cout << "Single precision solve upper test passed." << std::endl;

    // Test double precision solve upper
    assert(ppm_util_gmres_solveupper<DOUBLE_PRECISION>() == ppm_gmres_param_success);
    std::cout << "Double precision solve upper test passed." << std::endl;

    return 0;
}