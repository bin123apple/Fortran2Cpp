#include <gtest/gtest.h>

// Your class definition goes here
class M {
public:
    int add(int a, int b) {
        return a + b;
    }
};

// Test case for the M class
TEST(MTest, HandlesZeroInput) {
    M m;
    EXPECT_EQ(0, m.add(0, 0));
}

TEST(MTest, CanAddPositiveNumbers) {
    M m;
    EXPECT_EQ(5, m.add(2, 3));
}

// The main function that initializes Google Test and runs the tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}