#include <iostream>

// Define constants for precision and dimension
#define __SINGLE_PRECISION         1
#define __DOUBLE_PRECISION         2
#define __2D                       3
#define __3D                       4

namespace ppm_module_gmm_cpt {

template<int DIM, int KIND>
class ppm_gmm_cpt {
public:
    static void process() {
        std::cout << "Generic GMM Component Processing" << std::endl;
    }
};

// Specializations for 2D Single Precision
template<>
class ppm_gmm_cpt<__2D, __SINGLE_PRECISION> {
public:
    static void process() {
        std::cout << "2D Single Precision GMM Component" << std::endl;
        // Implementation here...
    }
};

// Specializations for 2D Double Precision
template<>
class ppm_gmm_cpt<__2D, __DOUBLE_PRECISION> {
public:
    static void process() {
        std::cout << "2D Double Precision GMM Component" << std::endl;
        // Implementation here...
    }
};

// Specializations for 3D Single Precision
template<>
class ppm_gmm_cpt<__3D, __SINGLE_PRECISION> {
public:
    static void process() {
        std::cout << "3D Single Precision GMM Component" << std::endl;
        // Implementation here...
    }
};

// Specializations for 3D Double Precision
template<>
class ppm_gmm_cpt<__3D, __DOUBLE_PRECISION> {
public:
    static void process() {
        std::cout << "3D Double Precision GMM Component" << std::endl;
        // Implementation here...
    }
};

} // namespace ppm_module_gmm_cpt

// Main function to demonstrate calling the GMM component processing functions
int main() {
    ppm_module_gmm_cpt::ppm_gmm_cpt<__2D, __SINGLE_PRECISION>::process();
    ppm_module_gmm_cpt::ppm_gmm_cpt<__2D, __DOUBLE_PRECISION>::process();
    ppm_module_gmm_cpt::ppm_gmm_cpt<__3D, __SINGLE_PRECISION>::process();
    ppm_module_gmm_cpt::ppm_gmm_cpt<__3D, __DOUBLE_PRECISION>::process();

    return 0;
}