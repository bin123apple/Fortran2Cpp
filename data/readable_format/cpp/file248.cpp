#include <iostream>
#include <cmath> // For std::isnan

// Function Declaration
void IARNAN(double NUM, int& INFO) {
    INFO = 0;
    if (std::isnan(NUM)) {
        INFO = 1;
    }
}

// Simple Test Function
void testIARNAN(double num, int expected, const std::string& testName) {
    int info = 0;
    IARNAN(num, info);
    if (info == expected) {
        std::cout << testName << " passed." << std::endl;
    } else {
        std::cout << testName << " failed. Expected INFO=" << expected << ", Got INFO=" << info << "." << std::endl;
    }
}

int main() {
    // Test with a normal number
    testIARNAN(1.0, 0, "Test with normal number");

    // Test with NaN
    double nanValue = std::nan("1");
    testIARNAN(nanValue, 1, "Test with NaN");

    return 0;
}