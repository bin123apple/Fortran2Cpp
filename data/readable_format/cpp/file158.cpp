#include <gtest/gtest.h>
#include <cmath>

// Define the function directly in this file to avoid linker issues
double specific__tan_r8(double parm) {
    return std::tan(parm);
}

// Test cases
TEST(SpecificTanR8Test, HandlesPositiveInput) {
    EXPECT_NEAR(specific__tan_r8(M_PI / 4), 1.0, 1e-7); // pi/4 should be close to 1
}

TEST(SpecificTanR8Test, HandlesZeroInput) {
    EXPECT_NEAR(specific__tan_r8(0.0), 0.0, 1e-7); // tan(0) should be 0
}

// main() function for the test runner
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}