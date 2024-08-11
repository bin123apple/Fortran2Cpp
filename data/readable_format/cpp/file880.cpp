#include <gtest/gtest.h>
#include <cmath>

// Define the namespace and the precision directly in this file
namespace real_precision {
    using dp = double; // Use 'double' for double precision
}

// Test case to verify the precision
TEST(RealPrecisionTest, DoublePrecision) {
    real_precision::dp test_number = 1.0 / 3.0;
    // Using EXPECT_NEAR to check if the value of test_number is close enough to 0.333333333333333
    // considering a small delta for floating-point comparison.
    EXPECT_NEAR(test_number, 0.333333333333333, 1.0E-15);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}