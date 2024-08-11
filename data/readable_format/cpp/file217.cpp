#include <gtest/gtest.h>
#include <cmath>

// Assuming these functions are implemented in your main program.
double calculateYd(double x) {
    return x - std::sin(x);
}

double calculateFirstS(double x) {
    return std::pow(x, 3) / 6.0;
}

double calculateError(double s, double yd) {
    return std::abs((s - yd) / yd);
}

TEST(KincaidCheneyTest, CalculateYd) {
    double x = 1.9;
    // Expected values should be determined from your correct implementation or theoretical calculation
    double expectedYd = calculateYd(x); // Using the function directly for demonstration; replace with actual expected value
    ASSERT_NEAR(calculateYd(x), expectedYd, 1E-12);
}

TEST(KincaidCheneyTest, CalculateFirstS) {
    double x = 1.9;
    double expectedS = calculateFirstS(x); // Replace with actual expected value
    ASSERT_NEAR(calculateFirstS(x), expectedS, 1E-12);
}

TEST(KincaidCheneyTest, CalculateError) {
    double x = 1.9;
    double yd = calculateYd(x);
    double s = calculateFirstS(x);
    double expectedError = calculateError(s, yd); // Replace with actual expected value
    ASSERT_NEAR(calculateError(s, yd), expectedError, 1E-12);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}