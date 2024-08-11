#include <gtest/gtest.h>
#include <cmath>
#include <iostream>

// Define the SLAPY3 function directly in this file
double SLAPY3(double X, double Y, double Z) {
    const double ZERO = 0.0;
    double XABS, YABS, ZABS, W;

    XABS = std::abs(X);
    YABS = std::abs(Y);
    ZABS = std::abs(Z);
    W = std::max({XABS, YABS, ZABS});

    if (W == ZERO) {
        return XABS + YABS + ZABS;
    } else {
        return W * std::sqrt(std::pow(XABS / W, 2) + std::pow(YABS / W, 2) + std::pow(ZABS / W, 2));
    }
}

// Unit Tests
TEST(SLAPY3Test, PositiveNumbers) {
    EXPECT_NEAR(SLAPY3(3.0, 4.0, 5.0), std::sqrt(50), 1e-6);
}

TEST(SLAPY3Test, NegativeNumbers) {
    EXPECT_NEAR(SLAPY3(-3.0, -4.0, -5.0), std::sqrt(50), 1e-6);
}

TEST(SLAPY3Test, Zeros) {
    EXPECT_NEAR(SLAPY3(0.0, 0.0, 0.0), 0.0, 1e-6);
}

TEST(SLAPY3Test, MixedZero) {
    EXPECT_NEAR(SLAPY3(10.0, 0.0, 0.0), 10.0, 1e-6);
}

TEST(SLAPY3Test, MixedNumbers) {
    EXPECT_NEAR(SLAPY3(-5.0, 12.0, 0.0), std::sqrt(169), 1e-6);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}