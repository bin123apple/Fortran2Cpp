#include <iostream>
#include <limits>
#include <cmath>

// Define a namespace similar to the Fortran module
namespace kind_module {

    // Define types for single and double precision floating-point numbers
    using single = float;
    using double_ = double;

    // Constants for single and double precision types
    constexpr auto cSingle = std::numeric_limits<single>::digits10;
    constexpr auto cDouble = std::numeric_limits<double_>::digits10;
    constexpr auto cPrec = cDouble; // Choosing double precision as the default

}

// Simple function to demonstrate usage
void testKindModule() {
    std::cout << "Testing kind_module:" << std::endl;
    std::cout << "cSingle precision (expected ~6): " << kind_module::cSingle << std::endl;
    std::cout << "cDouble precision (expected ~15): " << kind_module::cDouble << std::endl;
    std::cout << "cPrec precision (expected to match cDouble): " << kind_module::cPrec << std::endl;

    // Demonstrate the precision using variables
    kind_module::single singleVar = 1.0f / 3.0f;
    kind_module::double_ doubleVar = 1.0 / 3.0;

    std::cout << "Single variable value: " << std::fixed << singleVar << std::endl;
    std::cout << "Double variable value: " << std::fixed << doubleVar << std::endl;

    // Basic "unit test" to verify precision
    if (std::abs(singleVar - doubleVar) < std::numeric_limits<kind_module::single>::epsilon()) {
        std::cout << "Test passed: single and double variables are close enough." << std::endl;
    } else {
        std::cout << "Test failed: single and double variables differ significantly." << std::endl;
    }
}

int main() {
    testKindModule();
    return 0;
}