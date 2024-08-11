#include <iostream>
#include <limits>
#include <cstdint>

namespace nrtype {
    // Integer types
    using I4B = int32_t; // 4 bytes integer, similar to SELECTED_INT_KIND(9)
    using I2B = int16_t; // 2 bytes integer, similar to SELECTED_INT_KIND(4)
    using I1B = int8_t;  // 1 byte integer, similar to SELECTED_INT_KIND(2)

    // Floating point types
    using SP = float; // Single precision
    using DP = double; // Double precision
    // For quadruple precision, C++ standard does not strictly define a type.
    // `long double` is the closest, but its precision is compiler-dependent.
    using QP = long double; 

    // Constants (using the precision of single and double)
    constexpr SP PI = 3.141592653589793238462643383279502884197f;
    constexpr SP PIO2 = 1.57079632679489661923132169163975144209858f;
    constexpr SP TWOPI = 6.283185307179586476925286766559005768394f;
    constexpr SP SQRT2 = 1.41421356237309504880168872420969807856967f;
    constexpr SP EULER = 0.5772156649015328606065120900824024310422f;

    constexpr DP PI_D = 3.141592653589793238462643383279502884197;
    constexpr DP PIO2_D = 1.57079632679489661923132169163975144209858;
    constexpr DP TWOPI_D = 6.283185307179586476925286766559005768394;
}

int main() {
    using namespace nrtype;
    std::cout << "Testing nrtype module..." << std::endl;
    std::cout << "Sizes (bytes) and ranges of integer types:" << std::endl;
    std::cout << "I4B: " << sizeof(I4B) << ", Range: " << std::numeric_limits<I4B>::max() << std::endl;
    std::cout << "I2B: " << sizeof(I2B) << ", Range: " << std::numeric_limits<I2B>::max() << std::endl;
    std::cout << "I1B: " << sizeof(I1B) << ", Range: " << std::numeric_limits<I1B>::max() << std::endl;

    std::cout << "Precision of floating point types (bytes):" << std::endl;
    std::cout << "SP: " << sizeof(SP) << std::endl;
    std::cout << "DP: " << sizeof(DP) << std::endl;
    std::cout << "QP: " << sizeof(QP) << std::endl;

    std::cout << "Mathematical constants (SP):" << std::endl;
    std::cout << "PI = " << PI << std::endl;
    std::cout << "PIO2 = " << PIO2 << std::endl;
    std::cout << "TWOPI = " << TWOPI << std::endl;
    std::cout << "SQRT2 = " << SQRT2 << std::endl;
    std::cout << "EULER = " << EULER << std::endl;

    std::cout << "Mathematical constants (DP):" << std::endl;
    std::cout << "PI_D = " << PI_D << std::endl;
    std::cout << "PIO2_D = " << PIO2_D << std::endl;
    std::cout << "TWOPI_D = " << TWOPI_D << std::endl;

    return 0;
}