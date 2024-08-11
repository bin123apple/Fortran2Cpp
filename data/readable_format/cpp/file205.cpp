#include <iostream>
#include <cassert>
#include <complex>
#include <cstdint>

// Define the nrtype namespace directly in this file
namespace nrtype {

using i1  = int8_t;
using i2  = int16_t;
using i4  = int32_t;
using i8  = int64_t;
// Note: Standard C++ does not support int128_t as a built-in type. 
// This example will omit the equivalent of Fortran's i16 for simplicity.

using sp  = float;
using dp  = double;
using spc = std::complex<float>;
using dpc = std::complex<double>;

// Logical types in Fortran are essentially boolean in C++.
using lgt = bool;
using lgf = bool;

// Constants with double precision
constexpr dp pi    = 3.141592653589793238462643383279502884197;
constexpr dp pi2   = 1.57079632679489661923132169163975144209858;
constexpr dp tau   = 6.283185307179586476925286766559005768394;
constexpr dp sqrt2 = 1.41421356237309504880168872420969807856967;
constexpr dp euler = 2.71828182845904523536028747135266249775725;

} // namespace nrtype

int main() {
    // Simple tests to verify the precision and types
    static_assert(sizeof(nrtype::i1) == 1, "Size of i1 is not 1 byte");
    static_assert(sizeof(nrtype::i2) == 2, "Size of i2 is not 2 bytes");
    static_assert(sizeof(nrtype::i4) == 4, "Size of i4 is not 4 bytes");
    static_assert(sizeof(nrtype::i8) == 8, "Size of i8 is not 8 bytes");

    // Constants precision test
    assert(nrtype::pi == 3.141592653589793238462643383279502884197);
    assert(nrtype::pi2 == 1.57079632679489661923132169163975144209858);
    assert(nrtype::tau == 6.283185307179586476925286766559005768394);
    assert(nrtype::sqrt2 == 1.41421356237309504880168872420969807856967);
    assert(nrtype::euler == 2.71828182845904523536028747135266249775725);

    std::cout << "All tests passed." << std::endl;

    return 0;
}