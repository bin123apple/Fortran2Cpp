#include <iostream>
#include <string>

// Function to run a test comparison and print the result
void runTest(bool condition, const std::string& testName) {
    if (condition) {
        std::cout << testName << ": Test passed." << std::endl;
    } else {
        std::cout << testName << ": Test failed." << std::endl;
    }
}

int main() {
    // Running tests for each comparison
    runTest(1.0 > 0.1, "1.0 > 0.1");
    runTest(1 < 2, "1 < 2");
    runTest(1 >= 1.0, "1 >= 1.0");
    runTest(1 <= 1.0, "1 <= 1.0");
    runTest(1 != 2, "1 != 2");
    runTest(1 == 1.0, "1 == 1.0");

    return 0;
}