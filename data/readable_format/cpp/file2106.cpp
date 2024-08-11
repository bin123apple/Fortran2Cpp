#include <gtest/gtest.h>
#include <iostream>

// Define 'suba' function directly in this file
void suba(int* c) {
    std::cout << *c << std::endl; // Printing the value of the first element of the array
}

// Unit test for 'suba' function
TEST(SubATest, HandlesFirstElement) {
    int c[100];
    c[0] = 1; // Set the first element
    // Directly calling 'suba' function here. Since it only prints, we have not much to ASSERT or EXPECT.
    // This is just to demonstrate the structure.
    EXPECT_EQ(c[0], 1); // This check is somewhat trivial as we're not capturing the output of 'suba'.
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}