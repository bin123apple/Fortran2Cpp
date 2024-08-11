#include <cmath>
#include <iostream>
#include <gtest/gtest.h>

template <typename T>
T sign(T a, T b) {
    if (b > 0 || (b == 0 && std::signbit(b) == false)) {
        return std::abs(a);
    } else {
        return -std::abs(a);
    }
}

// Tests
TEST(SignFunction, HandlesIntegers) {
    EXPECT_EQ(sign(2, 3), 2);
    EXPECT_EQ(sign(4, -5), -4);
    EXPECT_EQ(sign(-6, 7), 6);
    EXPECT_EQ(sign(-8, -9), -8);
}

TEST(SignFunction, HandlesFloats) {
    EXPECT_FLOAT_EQ(sign(1.0f, 2.0f), 1.0f);
    EXPECT_FLOAT_EQ(sign(1.0f, -2.0f), -1.0f);
    EXPECT_FLOAT_EQ(sign(1.0f, 0.0f), 1.0f);
    EXPECT_FLOAT_EQ(sign(1.0f, -0.0f), -1.0f); // This now correctly handles -0.0
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}