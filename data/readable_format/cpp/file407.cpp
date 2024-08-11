#include <iostream>
#include <functional>
#include <cstdlib>
#include <string>
#include <stdexcept>

// Function to be tested
int doubleFn(int x) {
    return x * 2;
}

// Utility function that uses the passed function
std::string f1(std::function<int(int)> fn, int i) {
    std::string str(fn(i), ' ');
    return str;
}

// Test function that throws if condition is false
void assertTest(bool condition, const std::string& message) {
    if (!condition) {
        throw std::runtime_error("Test failed: " + message);
    }
}

// Testing framework
void runTests() {
    // Test doubleFn
    assertTest(doubleFn(10) == 20, "doubleFn(10) should return 20");

    // Test f1 indirectly through its use of doubleFn
    auto resultStr = f1(doubleFn, 100);
    assertTest(resultStr.length() == 200, "f1(doubleFn, 100) should return a string of length 200");
    
    std::cout << "All tests passed." << std::endl;
}

int main() {
    try {
        runTests();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}