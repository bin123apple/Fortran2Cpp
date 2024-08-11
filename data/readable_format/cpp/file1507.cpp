// combined_test_openpde_kinds.cpp
#include <iostream>
#include <limits>
#include <cstdint> // For fixed-width integer types
#include <gtest/gtest.h>

// Define the types directly in this file, instead of using a separate header.
namespace openpde_kinds {

    using R8P = double; // double typically offers 15 decimal digits precision.
    using R4P = float;  // float typically offers 6 decimal digits precision.
    using R_P = R8P;    // Default real precision to double

    // Mapping Fortran integer kinds to C++ integer types.
    using I8P = int64_t; // long long is at least 64 bits, often enough for 18 decimal digits.
    using I4P = int32_t; // int is typically 32 bits, enough for 9 decimal digits.
    using I2P = int16_t; // short is typically 16 bits, enough for at least 4 decimal digits.
    using I1P = int8_t;  // Assuming 8 bits for 2 decimal digits. Rarely used for counting.
    using I_P = I4P;     // Default integer precision to 32 bits.

} // namespace openpde_kinds

// Unit tests
TEST(OpenPDEKindsTest, RealPrecision) {
    openpde_kinds::R4P r4 = 12345.6789f;
    openpde_kinds::R8P r8 = 123456789012345.6789;

    EXPECT_FLOAT_EQ(r4, 12345.6789f);
    EXPECT_DOUBLE_EQ(r8, 123456789012345.6789);
}

TEST(OpenPDEKindsTest, IntegerRange) {
    openpde_kinds::I1P i1 = std::numeric_limits<openpde_kinds::I1P>::max();
    openpde_kinds::I2P i2 = std::numeric_limits<openpde_kinds::I2P>::max();
    openpde_kinds::I4P i4 = std::numeric_limits<openpde_kinds::I4P>::max();
    openpde_kinds::I8P i8 = std::numeric_limits<openpde_kinds::I8P>::max();

    EXPECT_EQ(i1, 127);
    EXPECT_EQ(i2, 32767);
    EXPECT_EQ(i4, 2147483647);
    EXPECT_EQ(i8, 9223372036854775807LL);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}