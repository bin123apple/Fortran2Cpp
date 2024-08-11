#include <iostream>

// ConverterCommonModule class definition
class ConverterCommonModule {
private:
    bool SupportPreproc = false;

public:
    // Constructor
    ConverterCommonModule() {}

    // Public getter for SupportPreproc
    bool getSupportPreproc() const {
        return SupportPreproc;
    }

    // Public setter for SupportPreproc
    void setSupportPreproc(bool value) {
        SupportPreproc = value;
    }
};

// Simple test function
void runTests() {
    ConverterCommonModule module;
    bool testPassed = true;

    // Test 1: Check initial value
    if (module.getSupportPreproc() != false) {
        std::cout << "Test 1 Failed: SupportPreproc is not initially false." << std::endl;
        testPassed = false;
    } else {
        std::cout << "Test 1 Passed." << std::endl;
    }

    // Test 2: Check if value can be set to true
    module.setSupportPreproc(true);
    if (module.getSupportPreproc() != true) {
        std::cout << "Test 2 Failed: SupportPreproc was not set to true." << std::endl;
        testPassed = false;
    } else {
        std::cout << "Test 2 Passed." << std::endl;
    }

    if (testPassed) {
        std::cout << "All tests passed." << std::endl;
    } else {
        std::cout << "Some tests failed." << std::endl;
    }
}

// Main function
int main() {
    runTests();

    return 0;
}