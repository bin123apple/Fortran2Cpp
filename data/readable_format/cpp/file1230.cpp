#include <iostream>
#include <string>
#include <cctype> // For std::toupper and std::tolower

// Function definition
void xxcase(const std::string& input, std::string& output, const std::string& type) {
    output = input; // Copy input to output

    if (type == "UC" || type == "uc") {
        for (char &c : output) c = std::toupper(c);
    } else if (type == "LC" || type == "lc") {
        for (char &c : output) c = std::tolower(c);
    }
}

// Basic testing function
void test(const std::string& testName, const std::string& input, const std::string& expected, const std::string& type) {
    std::string output;
    xxcase(input, output, type);
    if (output == expected) {
        std::cout << testName << ": Passed" << std::endl;
    } else {
        std::cout << testName << ": Failed" << std::endl;
        std::cout << "Expected: " << expected << ", Got: " << output << std::endl;
    }
}

int main() {
    // Run tests
    test("Test 1 - Convert to uppercase", "hello, world!", "HELLO, WORLD!", "UC");
    test("Test 2 - Convert to lowercase", "HELLO, WORLD!", "hello, world!", "LC");
    test("Test 3 - Mixed case to uppercase", "Hello, World!", "HELLO, WORLD!", "UC");
    test("Test 4 - Mixed case to lowercase", "Hello, World!", "hello, world!", "LC");

    return 0;
}