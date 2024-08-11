#include <iostream>
#include <string>
#include <stdexcept>

std::string repeat(const std::string& str, int n) {
    std::string result;
    for(int i = 0; i < n; ++i) {
        result += str;
    }
    return result;
}

void testRepeatFunction() {
    std::string s1 = "42";
    if (repeat(s1, 1) != s1) throw std::logic_error("Test failed for repeat(s1, 1)");
    if (repeat(s1, 2) != (s1 + s1)) throw std::logic_error("Test failed for repeat(s1, 2)");
    // Additional tests can be added here as needed
    std::cout << "All repeat function tests passed successfully.";
}

int main() {
    try {
        testRepeatFunction();
    } catch (const std::exception& e) {
        std::cerr << "A test failed: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}