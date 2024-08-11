#include <gtest/gtest.h>
#include <cmath>
#include <chrono>

// Function implementations
float ABSF(float x) {
    return std::abs(x);
}

float SIGNF(float x, float y) {
    return (y >= 0) ? std::abs(x) : -std::abs(x);
}

float INTF(float x) {
    return std::trunc(x);
}

float SQRTF(float x) {
    return std::sqrt(x);
}

float SINF(float x) {
    return std::sin(x);
}

float COSF(float x) {
    return std::cos(x);
}

float ARCOSF(float x) {
    return std::acos(x);
}

float ARSINF(float x) {
    return std::asin(x);
}

float ATN1F(float x, float y) {
    return std::atan2(x, y);
}

float CLOCKF(float xx) {
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    // Assuming you want to convert milliseconds to minutes and then normalize based on a 60.0 scale
    return (millis / 1000.0) / 60.0;
}

// Unit tests
TEST(FunctionTests, ABSF) {
    EXPECT_FLOAT_EQ(ABSF(-5.0), 5.0);
}

TEST(FunctionTests, SIGNF) {
    EXPECT_FLOAT_EQ(SIGNF(-5.0, 3.0), 5.0);
    EXPECT_FLOAT_EQ(SIGNF(-5.0, -3.0), -5.0);
}

TEST(FunctionTests, INTF) {
    EXPECT_FLOAT_EQ(INTF(5.8), 5.0);
}

TEST(FunctionTests, SQRTF) {
    EXPECT_FLOAT_EQ(SQRTF(16.0), 4.0);
}

TEST(FunctionTests, Trigonometry) {
    float x = 0.5;
    EXPECT_NEAR(SINF(x), std::sin(x), 1e-5);
    EXPECT_NEAR(COSF(x), std::cos(x), 1e-5);
    EXPECT_NEAR(ARCOSF(x), std::acos(x), 1e-5);
    EXPECT_NEAR(ARSINF(x), std::asin(x), 1e-5);
}

TEST(FunctionTests, ATN1F) {
    EXPECT_NEAR(ATN1F(1.0, 1.0), std::atan2(1.0, 1.0), 1e-5);
}

// Main function
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}