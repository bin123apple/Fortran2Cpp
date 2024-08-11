// square.cpp
#include <gtest/gtest.h>
#include <iostream>

// Function to be tested
float square(float x) {
    return x * x;
}

// Test case for the square function
TEST(SquareTest, PositiveInput) {
    EXPECT_FLOAT_EQ(16.0, square(4.0));
}

TEST(SquareTest, NegativeInput) {
    EXPECT_FLOAT_EQ(9.0, square(-3.0));
}

int main(int argc, char **argv) {
    // Initialize Google Test
    ::testing::InitGoogleTest(&argc, argv);
    // Run all tests
    return RUN_ALL_TESTS();
}