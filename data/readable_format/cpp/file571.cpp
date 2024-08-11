#include <iostream>
#include <string>

void testStringLength(const std::string& testString, size_t expectedLength) {
    size_t actualLength = testString.length();
    if (actualLength == expectedLength) {
        std::cout << "C++ Test PASSED." << std::endl;
    } else {
        std::cout << "C++ Test FAILED." << std::endl;
    }
}

int main() {
    std::string testString = "Hello";
    size_t expectedLength = 5;

    testStringLength(testString, expectedLength);
    return 0;
}