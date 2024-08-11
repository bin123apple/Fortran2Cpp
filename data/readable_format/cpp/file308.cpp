#include <gtest/gtest.h>
#include <cmath>
#include <algorithm>

// SLAPY3 function implementation
float SLAPY3(float X, float Y, float Z) {
    const float ZERO = 0.0f;
    float W, XABS, YABS, ZABS;

    XABS = std::abs(X);
    YABS = std::abs(Y);
    ZABS = std::abs(Z);
    W = std::max({XABS, YABS, ZABS}); // Using initializer list to compare three values

    if (W == ZERO) {
        return XABS + YABS + ZABS;
    } else {
        return W * std::sqrt((XABS / W) * (XABS / W) + (YABS / W) * (YABS / W) +
                             (ZABS / W) * (ZABS / W));
    }
}

// Unit tests for the SLAPY3 function
TEST(SLAPY3Test, AllZeros) {
    EXPECT_FLOAT_EQ(SLAPY3(0.0f, 0.0f, 0.0f), 0.0f);
}

TEST(SLAPY3Test, PositiveNumbers) {
    EXPECT_NEAR(SLAPY3(3.0f, 4.0f, 5.0f), std::sqrt(50.0f), 1e-5);
}

TEST(SLAPY3Test, NegativeNumbers) {
    EXPECT_NEAR(SLAPY3(-3.0f, -4.0f, -5.0f), std::sqrt(50.0f), 1e-5);
}

TEST(SLAPY3Test, MixedSigns) {
    EXPECT_NEAR(SLAPY3(-3.0f, 4.0f, -5.0f), std::sqrt(50.0f), 1e-5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}