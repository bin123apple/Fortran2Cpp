#include <cstdint>
#include <iostream>
#include <gtest/gtest.h>

// Define the Precision namespace directly in this file
namespace Precision {
    using int1 = int8_t;  // At least 1 byte
    using int2 = int16_t; // At least 2 bytes
    using int4 = int32_t; // At least 4 bytes
    using int8 = int64_t; // At least 8 bytes
    
    using real4 = float;       // Typically represents a 4-byte (32-bit) float
    using real8 = double;      // Typically represents an 8-byte (64-bit) double
    using real16 = long double; // The size of long double can vary, but often represents at least 10 bytes (80-bit), though it can be 16 bytes (128-bit) on some systems
    
    using ik = int4; // Integer kind selected
    using rk = real8; // Real kind selected
}

// Unit Tests
TEST(PrecisionTest, IntegerSizes) {
    EXPECT_EQ(sizeof(Precision::int1), 1);
    EXPECT_EQ(sizeof(Precision::int2), 2);
    EXPECT_EQ(sizeof(Precision::int4), 4);
    EXPECT_EQ(sizeof(Precision::int8), 8);
}

TEST(PrecisionTest, RealSizes) {
    EXPECT_EQ(sizeof(Precision::real4), 4);
    EXPECT_EQ(sizeof(Precision::real8), 8);
    // The size of real16 can vary; adjust the expectation based on your system's `long double` size
    EXPECT_TRUE(sizeof(Precision::real16) == 16 || sizeof(Precision::real16) == 8 || sizeof(Precision::real16) == 10);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}