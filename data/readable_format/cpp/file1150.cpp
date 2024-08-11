#include <iostream>
#include <string>
#include <cassert>

// Function declaration and definition
std::string f(const std::string& x) {
    // Assuming the function just returns the input string
    return x;
}

// Basic test function for f
void testF() {
    std::string input = "Hello";
    std::string expected = "Hello";
    std::string result = f(input);
    assert(result == expected); // Using assert for a simple check
    std::cout << "Test passed: f(\"" << input << "\") == \"" << result << "\"" << std::endl;
}

int main() {
    // Call the test function
    testF();

    return 0;
}