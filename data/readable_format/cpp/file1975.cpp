#include <iostream>
#include <cmath> // For std::abs()

// Assuming the definition of the constants you need
constexpr double SEC_PER_DAY = 86400.0;

// The GetDelta function, as previously defined
double GetDelta(double timestep) {
    return timestep / SEC_PER_DAY;
}

// Main function to test the GetDelta function
int main() {
    double timestep = 43200.0; // Example: half of a day in seconds
    double expectedDelta = 0.5;
    double computedDelta = GetDelta(timestep);

    std::cout << "Expected Delta: " << expectedDelta << std::endl;
    std::cout << "Computed Delta: " << computedDelta << std::endl;

    // Test the result with a small margin for potential floating-point arithmetic errors
    if (std::abs(computedDelta - expectedDelta) < 1e-7) {
        std::cout << "Test Passed." << std::endl;
    } else {
        std::cout << "Test Failed." << std::endl;
    }

    return 0;
}