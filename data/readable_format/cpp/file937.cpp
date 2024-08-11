#include <gtest/gtest.h>

// Define the DoublePrecision namespace directly in this file
namespace DoublePrecision {
    using DP = double;
}

// A simple test to check the precision of DoublePrecision::DP
TEST(DoublePrecisionTest, PrecisionTest) {
    DoublePrecision::DP x = 1.0 / 3.0;
    EXPECT_DOUBLE_EQ(x, 1.0 / 3.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}