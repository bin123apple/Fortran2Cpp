#include <iostream>
#include <cmath>
#include <cassert>

// CORERD function definition
double CORERD(int KW, double MC, double M0, double MFLASH) {
    const double MCH = 1.44;
    double result;

    if (KW == 14) {
        result = 4.24e-06 * MC;
    } else if (KW == 13) {
        result = 1.4e-05;
    } else if (KW <= 1 || KW == 7) {
        result = 0.0;
    } else if (KW == 4 || KW == 5 || (KW <= 3 && M0 > MFLASH)) {
        result = 0.2239 * std::pow(MC, 0.62);
    } else {
        double temp = std::max(1.48204e-06, std::pow(MCH / MC, 2.0 / 3.0) - std::pow(MC / MCH, 2.0 / 3.0));
        result = 0.0115 * std::sqrt(temp);
        if (KW <= 9) result = 5.0 * result;
    }

    return result;
}

// Main function with test cases
int main() {
    double result;
    double epsilon = 1e-8; // Tolerance for floating-point comparison

    // Test Case 1
    result = CORERD(14, 1.0, 0.0, 0.0);
    std::cout << "Test Case 1 (KW=14): " << result << std::endl;
    assert(std::abs(result - 4.24e-06) < epsilon);

    // Test Case 2
    result = CORERD(13, 1.0, 0.0, 0.0);
    std::cout << "Test Case 2 (KW=13): " << result << std::endl;
    assert(std::abs(result - 1.4e-05) < epsilon);

    // Additional test cases can be added here following the same pattern

    std::cout << "All tests passed successfully." << std::endl;

    return 0;
}