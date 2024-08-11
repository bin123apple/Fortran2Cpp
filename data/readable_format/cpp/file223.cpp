#include <gtest/gtest.h>

// Example function to be tested
int add(int a, int b) {
    return a + b;
}

// Define a test case
TEST(AdditionTest, HandlesPositiveNumbers) {
    EXPECT_EQ(3, add(1, 2));
}

TEST(AdditionTest, HandlesNegativeNumbers) {
    EXPECT_EQ(-1, add(-1, 0));
}

// Main function to run all tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}