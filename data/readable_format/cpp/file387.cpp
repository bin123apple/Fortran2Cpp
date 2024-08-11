#include <iostream>
#include <cmath>

// Define the kind of real number directly in this file, removing the need for a separate header.
using wp = double; // Assuming double meets the precision and range requirements.

int main() {
    bool precisionTestPassed = false;
    bool rangeTestPassed = false;

    // Test for precision
    wp precisionTest = 1.0;
    precisionTest /= 3.0;
    precisionTest *= 3.0;
    if (std::abs(precisionTest - 1.0) <= 1.0E-12) {
        precisionTestPassed = true;
        std::cout << "Precision test passed." << std::endl;
    } else {
        std::cout << "Precision test failed." << std::endl;
    }

    // Test for range
    wp rangeTestMin = std::pow(10.0, -307);
    wp rangeTestMax = std::pow(10.0, 307);
    if (rangeTestMin > 0.0 && rangeTestMax > 0.0) {
        rangeTestPassed = true;
        std::cout << "Range test passed." << std::endl;
    } else {
        std::cout << "Range test failed." << std::endl;
    }

    return !(precisionTestPassed && rangeTestPassed); // Return 0 if both tests passed, indicating success.
}