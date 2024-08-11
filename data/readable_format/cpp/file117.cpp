#include <iostream>
#include <string>
#include <cctype> // for std::tolower and std::toupper

// StringManipulation class definition
class StringManipulation {
public:
    void convertCase(std::string &str, int direction) {
        for (char &ch : str) {
            if (direction == 0) {
                if (std::isupper(ch)) {
                    ch = std::tolower(ch);
                }
            } else if (direction == 1) {
                if (std::islower(ch)) {
                    ch = std::toupper(ch);
                }
            }
        }
    }
};

// Simplified test function
void testConvertCase() {
    StringManipulation manipulator;
    std::string testString;
    
    // Test 1: Convert to lowercase
    testString = "Hello, World!";
    manipulator.convertCase(testString, 0);
    if (testString == "hello, world!") {
        std::cout << "Test 1 Passed: Convert to lowercase" << std::endl;
    } else {
        std::cout << "Test 1 Failed: Convert to lowercase" << std::endl;
    }
    
    // Test 2: Convert to uppercase
    testString = "hello, world!";
    manipulator.convertCase(testString, 1);
    if (testString == "HELLO, WORLD!") {
        std::cout << "Test 2 Passed: Convert to uppercase" << std::endl;
    } else {
        std::cout << "Test 2 Failed: Convert to uppercase" << std::endl;
    }
}

// Main function
int main() {
    testConvertCase();
    return 0;
}