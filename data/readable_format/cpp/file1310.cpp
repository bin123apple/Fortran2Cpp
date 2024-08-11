#include <cstddef> // For size_t
#include <limits>  // For numeric_limits
#include <cstdint> // For fixed-width integer types
#include <cassert>
#include <iostream>

class TypeSizes {
public:
    // Assuming 8, 16, 32, 64 bit integers match the desired sizes.
    using OneByteInt = std::int8_t;
    using TwoByteInt = std::int16_t;
    using FourByteInt = std::int32_t;
    using EightByteInt = std::int64_t;

    // Using float for 4 bytes and double for 8 bytes real.
    using FourByteReal = float;
    using EightByteReal = double;

    static bool byteSizesOK() {
        // Check integer sizes
        bool intSizesOK = (sizeof(OneByteInt) * 8 == 8) &&
                          (sizeof(TwoByteInt) * 8 == 16) &&
                          (sizeof(FourByteInt) * 8 == 32) &&
                          (sizeof(EightByteInt) * 8 == 64);

        // Check real sizes
        bool realSizesOK = (sizeof(FourByteReal) * 8 == 32) &&
                           (sizeof(EightByteReal) * 8 == 64);

        // Check that FourByteReal and EightByteReal are different
        bool realTypesDifferent = !std::is_same<FourByteReal, EightByteReal>::value;

        return intSizesOK && realSizesOK && realTypesDifferent;
    }
};

void testByteSizesOK() {
    assert(TypeSizes::byteSizesOK() == true);
    std::cout << "Byte sizes and type requirements are OK." << std::endl;
}

int main() {
    testByteSizesOK();
    return 0;
}