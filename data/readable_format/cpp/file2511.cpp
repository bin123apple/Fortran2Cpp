#include <iostream>
#include <string>

// Simulating modC functionality
namespace modC {
    std::string exampleFunctionC() {
        return "Function from modC";
    }
}

// Simulating modD functionality
namespace modD {
    std::string exampleFunctionD() {
        return "Function from modD";
    }
}

// Basic testing function
void testFunction(const std::string& name, const std::string& expected, const std::string& actual) {
    std::cout << "Testing " << name << ": ";
    if (expected == actual) {
        std::cout << "PASS";
    } else {
        std::cout << "FAIL. Expected: " << expected << " Actual: " << actual;
    }
    std::cout << std::endl;
}

int main() {
    // Using the functions and printing results directly
    std::cout << modC::exampleFunctionC() << std::endl;
    std::cout << modD::exampleFunctionD() << std::endl;

    // Basic "tests"
    testFunction("modC::exampleFunctionC", "Function from modC", modC::exampleFunctionC());
    testFunction("modD::exampleFunctionD", "Function from modD", modD::exampleFunctionD());

    return 0;
}