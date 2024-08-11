// mySign.cpp
#include <cmath> // For std::abs

// Corrected mySign function
float mySign(float parm1, float parm2) {
    return (parm2 >= 0) ? std::abs(parm1) : -std::abs(parm1);
}

// mySignTest.cpp
#include <gtest/gtest.h>

// Declare the mySign function
float mySign(float parm1, float parm2);

// Unit tests for the mySign function
TEST(MySignTest, CorrectBehavior) {
    EXPECT_FLOAT_EQ(mySign(5.0f, -2.0f), -5.0f);
    EXPECT_FLOAT_EQ(mySign(-3.0f, 3.0f), 3.0f);
    EXPECT_FLOAT_EQ(mySign(-4.0f, -1.0f), -4.0f);
    EXPECT_FLOAT_EQ(mySign(2.0f, 0.0f), 2.0f);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}