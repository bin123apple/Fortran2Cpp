#include <gtest/gtest.h>
#include <cmath>
#include <complex>
#include <limits>

template<typename T>
bool nearlyEqual(T a, T b, T epsilon = 0.0001) {
    return std::abs(a - b) < epsilon;
}

TEST(PowerOperationsTest, ComplexNumbers) {
    std::complex<double> complexBase(2.0, -4.3);
    std::complex<double> result = std::pow(complexBase, 2);
    std::complex<double> expected(-14.49, -17.2); // Assuming this is the expected calculation result
    EXPECT_TRUE(nearlyEqual(result.real(), expected.real()) && nearlyEqual(result.imag(), expected.imag()));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}