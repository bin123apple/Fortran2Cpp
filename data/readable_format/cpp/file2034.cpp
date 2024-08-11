#include <iostream>
#include <string>
#include <sstream>

// A simple assertion function to mimic basic unit test behavior
void assertEqual(int actual, int expected, const std::string& testName) {
    if (actual == expected) {
        std::cout << testName << " Passed." << std::endl;
    } else {
        std::cout << testName << " Failed. Expected " << expected << " but got " << actual << std::endl;
    }
}

void assertEqual(const std::string& actual, const std::string& expected, const std::string& testName) {
    if (actual == expected) {
        std::cout << testName << " Passed." << std::endl;
    } else {
        std::cout << testName << " Failed. Expected " << expected << " but got " << actual << std::endl;
    }
}

void assertApprox(float actual, float expected, float epsilon, const std::string& testName) {
    if (abs(actual - expected) < epsilon) {
        std::cout << testName << " Passed." << std::endl;
    } else {
        std::cout << testName << " Failed. Expected approximately " << expected << " but got " << actual << std::endl;
    }
}

// Example functions to test
int add(int a, int b) {
    return a + b;
}

float multiply(float a, float b) {
    return a * b;
}

int stringToInt(const std::string& str) {
    int num;
    std::stringstream(str) >> num;
    return num;
}

std::string intToString(int num) {
    return std::to_string(num);
}

// Main function to run tests
int main() {
    // Arithmetic tests
    assertEqual(add(10, 5), 15, "Test Add");
    assertApprox(multiply(20.5f, 2.0f), 41.0f, 0.01f, "Test Multiply");

    // Conversion tests
    assertEqual(stringToInt("123"), 123, "Test String to Int");
    assertEqual(intToString(123), "123", "Test Int to String");

    return 0;
}