#include <iostream>
#include <cmath> // For M_PI

// Assuming global_parameters.hpp contents
const double dp = 8.0;
const float sp = 4.0f;
const double pi = M_PI;

// Assuming source_class.hpp contents
class SourceClass {
public:
    float someValue = 10.0f;

    void displayValue() const {
        std::cout << "Displaying value from SourceClass: " << someValue << std::endl;
    }
};

// Assuming ftnunit.hpp contents and simple testing framework functionalities
class FtnUnit {
public:
    static void assertTrue(bool condition, const std::string& message) {
        if (!condition) {
            std::cerr << "Assertion failed: " << message << std::endl;
        } else {
            std::cout << "Test passed: " << message << std::endl;
        }
    }
};

// Main program
int main() {
    SourceClass source;
    source.displayValue();

    FtnUnit::assertTrue(true, "This is a dummy test.");

    std::cout << "Done with main program." << std::endl;
    return 0;
}