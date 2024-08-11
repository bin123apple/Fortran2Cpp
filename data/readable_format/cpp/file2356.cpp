#include <iostream>
#include <cstdint> // for fixed width integer types

// Define the namespace DataPrecisionGlobals within the same file
namespace DataPrecisionGlobals {

    // Define integer types of specific bit-widths
    using int32 = int32_t;
    using int64 = int64_t;

    // Define floating point types
    using real32 = float;
    using real64 = double;
    using default_prec = real64;

    // Define constants
    constexpr real64 constant_zero = 0.0;
    constexpr real64 constant_one = 1.0;
    constexpr real64 constant_minusone = -1.0;
    constexpr real64 constant_twenty = 20.0;
    constexpr real64 constant_pointfive = 0.5;
    constexpr real64 EXP_LowerLimit = -20.0;
    constexpr real64 EXP_UpperLimit = 40.0;

} // namespace DataPrecisionGlobals

// Test or main program section
int main() {
    using namespace DataPrecisionGlobals;

    std::cout << "Testing constants from DataPrecisionGlobals..." << std::endl;
    std::cout << "constant_zero: " << constant_zero << std::endl;
    std::cout << "constant_one: " << constant_one << std::endl;
    std::cout << "constant_minusone: " << constant_minusone << std::endl;
    std::cout << "constant_twenty: " << constant_twenty << std::endl;
    std::cout << "constant_pointfive: " << constant_pointfive << std::endl;
    std::cout << "EXP_LowerLimit: " << EXP_LowerLimit << std::endl;
    std::cout << "EXP_UpperLimit: " << EXP_UpperLimit << std::endl;

    // More tests or program logic can be added here.

    return 0;
}