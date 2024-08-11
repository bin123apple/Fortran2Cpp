#include <gtest/gtest.h>

// Function definition directly included in this C++ file.
bool SB02MV(double REIG, double IEIG) {
    // IEIG is unused in this function.
    return REIG < 0.0;
}

// Test cases.
TEST(SB02MVTest, HandlesPositiveREIG) {
    double reig_positive = 1.0;
    double ieig = 0.0;  // Not used in SB02MV
    EXPECT_FALSE(SB02MV(reig_positive, ieig));
}

TEST(SB02MVTest, HandlesNegativeREIG) {
    double reig_negative = -1.0;
    double ieig = 0.0;  // Not used in SB02MV
    EXPECT_TRUE(SB02MV(reig_negative, ieig));
}

// Main function to run the tests.
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}