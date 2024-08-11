#include <gtest/gtest.h>
#include <cmath> // For std::abs

// Assuming the class and methods are to be defined in this file:
template<typename T>
class PpmTreeBoxCost {
public:
    // Example function that calculates some cost based on the precision type T
    // This is a placeholder, replace with actual functionality
    T boxCost(T input) {
        return input * 2; // Placeholder operation, modify as needed
    }
};

// Unit tests using Google Test

// Test case for single precision
TEST(PpmTreeBoxCostTest, SinglePrecision) {
    PpmTreeBoxCost<float> boxCostCalculator;
    float result = boxCostCalculator.boxCost(1.0f);
    EXPECT_NEAR(result, 2.0f, 1.0E-6f);
}

// Test case for double precision
TEST(PpmTreeBoxCostTest, DoublePrecision) {
    PpmTreeBoxCost<double> boxCostCalculator;
    double result = boxCostCalculator.boxCost(1.0);
    EXPECT_NEAR(result, 2.0, 1.0E-15);
}

int main(int argc, char **argv) {
    // Initializes Google Test
    ::testing::InitGoogleTest(&argc, argv);
    // Runs all tests
    return RUN_ALL_TESTS();
}