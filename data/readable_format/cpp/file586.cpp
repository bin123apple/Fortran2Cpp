#include <iostream>
#include <string>

// Function to classify numbers
std::string classifyNumber(int number) {
    if (number > 0) {
        return "Positive";
    } else if (number < 0) {
        return "Negative";
    } else {
        return "Zero";
    }
}

// A simple assert function for testing
void assertEqual(const std::string& result, const std::string& expected, const std::string& testName) {
    if (result == expected) {
        std::cout << testName << " Passed" << std::endl;
    } else {
        std::cout << testName << " Failed: Expected " << expected << ", got " << result << std::endl;
    }
}

// Main function to run tests
int main() {
    // Test cases
    assertEqual(classifyNumber(5), "Positive", "Test Positive Number");
    assertEqual(classifyNumber(-3), "Negative", "Test Negative Number");
    assertEqual(classifyNumber(0), "Zero", "Test Zero");

    return 0;
}