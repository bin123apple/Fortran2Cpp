#include <iostream>
#include <cmath>
#include <cstring> // For std::memset

// Assuming the size of DTK is known and fixed at 40
double DTK[40];
double TPREV, TBLOCK;

void IBLOCK() {
    DTK[0] = 1.0;
    for (int K = 1; K < 40; ++K) {
        DTK[K] = 0.5 * DTK[K - 1];
    }

    TPREV = 0.0;
    TBLOCK = 0.0;
}

// Simple assertion function to check values
void assert_close(double actual, double expected, const std::string& message) {
    if (std::abs(actual - expected) > 1e-9) { // Using an epsilon to compare floating-point numbers
        std::cerr << "Assertion failed: " << message << ". Expected " << expected << ", got " << actual << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

// Function to run tests on IBLOCK
void run_tests() {
    std::memset(DTK, 0, sizeof(DTK)); // Resetting DTK values to ensure clean test environment
    IBLOCK(); // Call the function to test

    // Test DTK values
    for (int i = 0; i < 40; ++i) {
        double expected = std::pow(0.5, i);
        assert_close(DTK[i], expected, "DTK[" + std::to_string(i) + "]");
    }

    // Test TPREV and TBLOCK values
    assert_close(TPREV, 0.0, "TPREV");
    assert_close(TBLOCK, 0.0, "TBLOCK");

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    run_tests(); // Run the tests
    return 0;
}