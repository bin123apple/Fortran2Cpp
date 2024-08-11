#include <iostream>
#include <gtest/gtest.h>

// Example function to be tested
int add(int a, int b) {
    return a + b;
}

// Test case for the add function
TEST(AddFunctionTest, PositiveNumbers) {
    EXPECT_EQ(3, add(1, 2));
}

TEST(AddFunctionTest, NegativeNumbers) {
    EXPECT_EQ(-3, add(-1, -2));
}

// Main function
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}