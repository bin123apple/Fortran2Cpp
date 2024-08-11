#include <iostream>
#include <string>
#include <vector>
#include <utility>

// Function to format the greeting
std::string FormatGreeting(const std::string& part1, const std::string& part2) {
    return part1 + " " + part2;
}

// A simple test function
void TestFormatGreeting() {
    // Test data containing pairs of input strings and the expected result
    std::vector<std::pair<std::pair<std::string, std::string>, std::string>> testData = {
        {{"Hello,", "World!"}, "Hello, World!"},
        {{"Good morning,", "Alice"}, "Good morning, Alice"}
    };

    bool passed = true;
    for (const auto& test : testData) {
        std::string result = FormatGreeting(test.first.first, test.first.second);
        if (result != test.second) {
            std::cerr << "Test failed: Expected \"" << test.second << "\", got \"" << result << "\"" << std::endl;
            passed = false;
        }
    }

    if (passed) {
        std::cout << "All tests passed." << std::endl;
    } else {
        std::cerr << "Some tests failed." << std::endl;
    }
}

int main() {
    // Run the tests
    TestFormatGreeting();
    return 0;
}