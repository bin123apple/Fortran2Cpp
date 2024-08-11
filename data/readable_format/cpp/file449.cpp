#include <iostream>

// Define precision macros similarly to the original approach
#define SINGLE_PRECISION 1
#define DOUBLE_PRECISION 2

// Forward declarations of template functions
template<int precision>
void ppm_topo_box2subs(float a, float b);

template<int precision>
void ppm_topo_box2subs(double a, double b);

// Template specialization for single precision
template<>
void ppm_topo_box2subs<SINGLE_PRECISION>(float a, float b) {
    std::cout << "Single precision calculation: " << a * b << std::endl;
}

// Template specialization for double precision
template<>
void ppm_topo_box2subs<DOUBLE_PRECISION>(double a, double b) {
    std::cout << "Double precision calculation: " << a * b << std::endl;
}

int main() {
    // Example usage
    ppm_topo_box2subs<SINGLE_PRECISION>(2.0f, 3.0f);
    ppm_topo_box2subs<DOUBLE_PRECISION>(2.0, 3.0);

    return 0;
}