#include <gtest/gtest.h>

// Example function to test
int add(int a, int b) {
    return a + b;
}

// Test case for the add function
TEST(AddTest, HandlesPositiveInput) {
    EXPECT_EQ(3, add(1, 2));
}

// You can define more tests and functions here

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}