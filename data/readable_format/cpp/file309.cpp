#include <iostream>
#include <string>
#include <cassert>

// Function declaration
std::string fn(const std::string& x, const std::string& y) {
    return x + y; // Simply concatenates x and y without trimming.
}

int main() {
    // Test the fn function
    std::string x = "Hello";
    std::string y = "World";
    std::string result = fn(x, y);

    assert(result == "HelloWorld" && "fn function failed");
    std::cout << "Test Passed: fn function" << std::endl;

    return 0;
}