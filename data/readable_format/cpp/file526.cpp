#include <gtest/gtest.h>

// Example function to test
int add(int a, int b) {
    return a + b;
}

// Test case
TEST(AddTest, PositiveNumbers) {
    ASSERT_EQ(2, add(1, 1));
}

// Main function
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}