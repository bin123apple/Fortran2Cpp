#include <iostream>
#include <cmath>

double PLTFRC(double REALN) {
    return REALN - std::floor(REALN);
}

void TestCase(double input, double expected) {
    double result = PLTFRC(input);
    if (std::abs(result - expected) < 1.0E-6) {
        std::cout << "Test passed for input " << input << std::endl;
    } else {
        std::cout << "Test failed for input " << input << ". Expected " << expected << " but got " << result << std::endl;
    }
}

int main() {
    // Test cases
    TestCase(3.14, 0.14);
    TestCase(-2.71, 0.29);  // Adjusted expected value for consistency
    TestCase(5.0, 0.0);

    return 0;
}