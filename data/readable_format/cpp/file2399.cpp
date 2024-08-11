#include <gtest/gtest.h>
#include <iostream>

// Function definition directly included in the file
void enq_v1_iae_code(int n, int &iae, int s) {
    if (s != 0) return;
    iae = n;
}

// Test case 1
TEST(EnqV1IaeCodeTest, Test1) {
    int n = 5;
    int iae = 0;
    int s = 0;

    enq_v1_iae_code(n, iae, s);

    ASSERT_EQ(iae, 5); // Expect iae to be set to n
}

// Test case 2
TEST(EnqV1IaeCodeTest, Test2) {
    int n = 10;
    int iae = 0;
    int s = 1;

    enq_v1_iae_code(n, iae, s);

    ASSERT_EQ(iae, 0); // Expect iae to remain unchanged because s != 0
}

// Main function to run the tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}