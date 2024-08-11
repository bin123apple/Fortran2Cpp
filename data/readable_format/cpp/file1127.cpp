#include <iostream>
#include <type_traits>

// Assuming the function templates ppm_fmm_pretraverse need to be declared and defined
template<typename T>
void ppm_fmm_pretraverse() {
    if (std::is_same<T, float>::value) {
        std::cout << "Single precision calculation." << std::endl;
        // Single precision specific implementation here
    } else if (std::is_same<T, double>::value) {
        std::cout << "Double precision calculation." << std::endl;
        // Double precision specific implementation here
    } else {
        // This part will never be reached due to the explicit template instantiation below
        // but serves as a fallback for incorrect types
        static_assert(std::is_same<T, float>::value || std::is_same<T, double>::value, "Unsupported type");
    }
}

// Explicit template instantiation
template void ppm_fmm_pretraverse<float>();
template void ppm_fmm_pretraverse<double>();

// Simple test functions to demonstrate functionality
void testSinglePrecision() {
    // Call the single precision implementation
    ppm_fmm_pretraverse<float>();
    std::cout << "Single precision test passed." << std::endl;
}

void testDoublePrecision() {
    // Call the double precision implementation
    ppm_fmm_pretraverse<double>();
    std::cout << "Double precision test passed." << std::endl;
}

int main() {
    testSinglePrecision();
    testDoublePrecision();
    return 0;
}