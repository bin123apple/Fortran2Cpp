#include <iostream>
#include <cmath>

namespace rrsw_kg16 {
    const double constant1 = 1.0;

    void printConstant() {
        std::cout << "Constant1 is " << constant1 << std::endl;
    }

    double square(double x) {
        return std::pow(x, 2);
    }
}

// Test functions
void testSquare() {
    double value = 2.0;
    double result = rrsw_kg16::square(value);
    std::cout << "Square of " << value << " is " << result << std::endl;

    // Simple assertion
    if (result == 4.0) {
        std::cout << "Test passed for square function." << std::endl;
    } else {
        std::cout << "Test failed for square function." << std::endl;
    }
}

int main() {
    rrsw_kg16::printConstant();
    testSquare();

    return 0;
}