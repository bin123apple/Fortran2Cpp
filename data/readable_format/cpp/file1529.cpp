#include <gtest/gtest.h>
#include <cmath> // For log10

// The db function implementation directly included in this file
float db(float x) {
    float result = -99.0f;
    if (x > 1.259e-10f) {
        result = 10.0f * log10(x);
    }
    return result;
}

// Test cases for the db function
TEST(DbFunctionTest, HandlesZeroInput) {
    EXPECT_FLOAT_EQ(db(1.0e-11f), -99.0f);
}

TEST(DbFunctionTest, HandlesThresholdInput) {
    EXPECT_NEAR(db(1.259e-10f), -99.0f, 1e-5f);
}

TEST(DbFunctionTest, HandlesPositiveInput) {
    float xTest = 2.0e-10f;
    float expected = 10.0f * log10(xTest);
    EXPECT_NEAR(db(xTest), expected, 1e-5f);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}