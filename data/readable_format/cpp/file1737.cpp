#include <iostream>
#include <gtest/gtest.h>

// Function to be tested
float square(float x) {
    return x * x;
}

// Test case for the square function
TEST(SquareFunction, PositiveNumber) {
    EXPECT_FLOAT_EQ(4.0, square(2.0));
}

TEST(SquareFunction, NegativeNumber) {
    EXPECT_FLOAT_EQ(9.0, square(-3.0));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}