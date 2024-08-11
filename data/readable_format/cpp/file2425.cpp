#include <iostream>
#include <string>
#include <vector>

class ModA {
public:
    void subA() {
        std::cout << "subA is called" << std::endl;
    }
};

// A very basic "testing framework" for demonstration
class SimpleTest {
public:
    void runTest(void (*testFunc)(), const std::string& testName) {
        std::cout << "Running " << testName << "... ";
        testFunc();
        std::cout << "PASSED" << std::endl;
    }
};

// Test function
void testSubA() {
    ModA modAInstance;
    modAInstance.subA(); // We expect this to simply run without validation for demonstration
}

int main() {
    SimpleTest tester;
    tester.runTest(testSubA, "testSubA");
    return 0;
}