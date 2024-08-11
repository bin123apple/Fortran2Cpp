#include <iostream>
#include <cstdint>
#include <climits>
#include <limits> // Include for std::numeric_limits

class TypeSizes {
public:
    // Use standard C++ fixed-width integer types
    static constexpr int OneByteInt = 8;
    static constexpr int TwoByteInt = 16;
    static constexpr int FourByteInt = 32;
    static constexpr int EightByteInt = 64;

    // Use std::numeric_limits to get the radix (base of the floating-point representation)
    static constexpr int FourByteReal = std::numeric_limits<float>::radix;
    static constexpr int EightByteReal = std::numeric_limits<double>::radix;

    static bool byteSizesOK() {
        int8_t One;
        int16_t Two;
        int32_t Four;

        // Check the sizes in bytes * CHAR_BIT for bits equivalence
        // and verify floating-point types are IEEE 754 (binary) floating-point representation
        if (sizeof(One) * CHAR_BIT == 8 &&
            sizeof(Two) * CHAR_BIT == 16 &&
            sizeof(Four) * CHAR_BIT == 32 &&
            std::numeric_limits<float>::is_iec559 && // IEEE 754 floating-point format check for float
            std::numeric_limits<double>::is_iec559 && // IEEE 754 floating-point format check for double
            FourByteReal == EightByteReal) {
            return true;
        } else {
            return false;
        }
    }
};

// Simple test function to verify the byteSizesOK method
void testByteSizesOK() {
    std::cout << "Testing byteSizesOK function... ";
    if (TypeSizes::byteSizesOK()) {
        std::cout << "Passed!" << std::endl;
    } else {
        std::cout << "Failed!" << std::endl;
    }
}

int main() {
    testByteSizesOK();
    return 0;
}