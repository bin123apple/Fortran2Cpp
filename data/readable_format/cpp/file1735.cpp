#include <iostream>

// Assuming definitions similar to what was provided earlier
#define __SINGLE_PRECISION 1
#define __DOUBLE_PRECISION 2
#define __SFIELD           9
#define __VFIELD          10

class PpmModuleFmmInit {
public:
    static void ppm_fmm_init_s_sf() {
        std::cout << "Initializing single precision scalar field." << std::endl;
    }
    static void ppm_fmm_init_d_sf() {
        std::cout << "Initializing double precision scalar field." << std::endl;
    }
    static void ppm_fmm_init_s_vf() {
        std::cout << "Initializing single precision vector field." << std::endl;
    }
    static void ppm_fmm_init_d_vf() {
        std::cout << "Initializing double precision vector field." << std::endl;
    }
};

int main() {
    // Test calls to demonstrate functionality
    PpmModuleFmmInit::ppm_fmm_init_s_sf();
    PpmModuleFmmInit::ppm_fmm_init_d_sf();
    PpmModuleFmmInit::ppm_fmm_init_s_vf();
    PpmModuleFmmInit::ppm_fmm_init_d_vf();

    std::cout << "All initialization routines called successfully." << std::endl;

    return 0;
}