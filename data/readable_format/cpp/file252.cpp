#include <iostream>
#include <cmath> // for std::isnan()

// Defining the DARNAN function directly in this file
void DARNAN(double NUM, int& INFO) {
    INFO = 0;
    
    if (std::isnan(NUM)) {
        INFO = 1;
    }
}

int main() {
    double test_val;
    int info;

    // Test with a NaN value
    test_val = NAN; // Using NAN macro for portability
    DARNAN(test_val, info);
    std::cout << "Testing with NaN. Expected INFO=1, got INFO=" << info << std::endl;

    // Test with a non-NaN value
    test_val = 1.0;
    DARNAN(test_val, info);
    std::cout << "Testing with 1.0. Expected INFO=0, got INFO=" << info << std::endl;

    return 0;
}