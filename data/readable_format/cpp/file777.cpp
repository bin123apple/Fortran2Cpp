#include <iostream>
#include <vector>
#include <algorithm>
#include <gtest/gtest.h>

// Assuming we are working with the previously discussed main logic that involves random numbers
// For simplicity, let's simulate a simple function instead
int getMaxValue(const std::vector<int>& vec) {
    return *std::max_element(vec.begin(), vec.end());
}

// Main program logic for demonstration (normally would be more complex)
void runMainProgram() {
    std::vector<int> data = {1, 2, 3, 4, 5};
    int maxValue = getMaxValue(data);
    std::cout << "Maximum Value: " << maxValue << std::endl;
}

// Test case for the getMaxValue function
TEST(MaxValueTest, HandlesPositiveNumbers) {
    std::vector<int> testVec = {1, 2, 3, 4, 5};
    ASSERT_EQ(getMaxValue(testVec), 5);
}

TEST(MaxValueTest, HandlesNegativeNumbers) {
    std::vector<int> testVec = {-5, -4, -3, -2, -1};
    ASSERT_EQ(getMaxValue(testVec), -1);
}

// The main function that will first run the program logic, then run all the tests
int main(int argc, char **argv) {
    // Optionally run the main program logic
    runMainProgram();

    // Initialize Google Test (this processes any command-line arguments provided to the test program)
    ::testing::InitGoogleTest(&argc, argv);
    
    // Run all tests and return the result
    return RUN_ALL_TESTS();
}