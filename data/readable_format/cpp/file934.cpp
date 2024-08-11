#include <iostream>

// Define the constants
#define __SINGLE_PRECISION 1
#define __DOUBLE_PRECISION 2

// Namespace to encapsulate the module's functionality
namespace ppm_module_mg_finalize {

void ppm_mg_finalize(int kind) {
    switch (kind) {
    case __SINGLE_PRECISION:
        std::cout << "Single precision, 2D, scalar field." << std::endl;
        break;
    case __DOUBLE_PRECISION:
        std::cout << "Double precision, 2D, scalar field." << std::endl;
        break;
    default:
        std::cout << "Unsupported kind" << std::endl;
        break;
    }
}

}  // namespace ppm_module_mg_finalize

int main() {
    // Test single precision
    ppm_module_mg_finalize::ppm_mg_finalize(__SINGLE_PRECISION);
    // Test double precision
    ppm_module_mg_finalize::ppm_mg_finalize(__DOUBLE_PRECISION);

    return 0;
}