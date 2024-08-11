#include <gtest/gtest.h>

// Function to be tested
double square(double input) {
    return input * input;
}

// Test case for the function
TEST(SquareFunctionTest, PositiveInput) {
    EXPECT_DOUBLE_EQ(square(5.0), 25.0);
}

TEST(SquareFunctionTest, NegativeInput) {
    EXPECT_DOUBLE_EQ(square(-4.0), 16.0);
}

TEST(SquareFunctionTest, ZeroInput) {
    EXPECT_DOUBLE_EQ(square(0.0), 0.0);
}

// Main function
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}