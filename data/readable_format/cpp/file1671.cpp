#include <iostream>
#include <cmath>
#include <gtest/gtest.h>

namespace plt_coord_stack {
    // Example global variable
    double globalVariable = 0.0;

    // Initialize function
    void initialize() {
        // Initialize your global variables here
        globalVariable = 42.0;
    }

    // A hypothetical calculation using the global variable
    double perform_some_calculation() {
        // Placeholder for actual calculation using globals
        return globalVariable;
    }
}

TEST(CalculationTest, TestSimpleCalculation) {
    plt_coord_stack::initialize();

    double result = plt_coord_stack::perform_some_calculation();
    double expected_result = 42.0;

    EXPECT_NEAR(result, expected_result, 1.0e-6);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}