#include <iostream>
#include <climits>
#include <cfloat>
#include <cstdint>

// Defining the parameters namespace directly in this file
namespace parameters {
    using iprec1 = std::int16_t;
    using iprec4 = std::int32_t;
    using iprec8 = std::int64_t;
    using rprec4 = float;
    using rprec8 = double;
    using rprec16 = long double;
}

// Function to perform manual tests
void test_parameters() {
    std::cout << "Testing integer kinds..." << std::endl;
    std::cout << ((sizeof(parameters::iprec1) * CHAR_BIT >= 16) ? "iprec1 pass" : "iprec1 fail") << std::endl;
    std::cout << ((sizeof(parameters::iprec4) * CHAR_BIT >= 32) ? "iprec4 pass" : "iprec4 fail") << std::endl;
    std::cout << ((sizeof(parameters::iprec8) * CHAR_BIT >= 64) ? "iprec8 pass" : "iprec8 fail") << std::endl;

    std::cout << "Testing real kinds..." << std::endl;
    std::cout << ((FLT_DIG <= sizeof(parameters::rprec4) * CHAR_BIT) ? "rprec4 pass" : "rprec4 fail") << std::endl;
    std::cout << ((DBL_DIG <= sizeof(parameters::rprec8) * CHAR_BIT) ? "rprec8 pass" : "rprec8 fail") << std::endl;
    // Note: Testing for long double precision is not straightforward due to its compiler-dependent nature
    std::cout << ((LDBL_DIG <= sizeof(parameters::rprec16) * CHAR_BIT) ? "rprec16 pass" : "rprec16 fail") << std::endl;
}

int main() {
    test_parameters();
    return 0;
}