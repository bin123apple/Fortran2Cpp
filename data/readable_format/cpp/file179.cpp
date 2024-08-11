#include <gtest/gtest.h>
#include <cmath>
#include <algorithm>

// Define the DLAPY3 function in the same file
double DLAPY3(double X, double Y, double Z) {
    const double ZERO = 0.0;
    double W, XABS, YABS, ZABS;

    XABS = std::abs(X);
    YABS = std::abs(Y);
    ZABS = std::abs(Z);
    W = std::max({XABS, YABS, ZABS});

    if (W == ZERO) {
        return XABS + YABS + ZABS;
    } else {
        return W * std::sqrt((XABS / W) * (XABS / W) + (YABS / W) * (YABS / W) + (ZABS / W) * (ZABS / W));
    }
}

// Unit tests
TEST(DLAPY3Test, HandlesPositiveNumbers) {
    EXPECT_NEAR(DLAPY3(1.0, 2.0, 2.0), std::sqrt(9.0), 1e-9);
}

TEST(DLAPY3Test, HandlesZeroes) {
    EXPECT_NEAR(DLAPY3(0.0, 3.0, 4.0), 5.0, 1e-9);
    EXPECT_NEAR(DLAPY3(0.0, 0.0, 0.0), 0.0, 1e-9);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}