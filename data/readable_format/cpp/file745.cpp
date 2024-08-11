#include <gtest/gtest.h>

// Declare or define your functions
int square(int x) {
    return x * x;
}

// Now write your Google Test test cases
TEST(SquareTest, PositiveNos) { 
    ASSERT_EQ(9, square(3));
}

TEST(SquareTest, Zero) { 
    ASSERT_EQ(0, square(0));
}

// If you're not using gtest_main, you need to provide a main function
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}