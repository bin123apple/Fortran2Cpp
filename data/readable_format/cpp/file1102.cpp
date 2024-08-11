// rsc_combined.cpp
#include <iostream>
#include <cstdint>
#include <cmath>

// Function declaration
double rsc(int32_t K, int32_t NA, double EA, int32_t NB, double EB, int32_t NC, double EC, int32_t ND, double ED) {
    return (EA + EB + EC + ED) / 4.0 * (K + NA + NB + NC + ND);
}

// Simple test function to verify the behavior of rsc
void testRscFunction() {
    // Example input
    int32_t K = 1, NA = 2, NB = 3, NC = 4, ND = 5;
    double EA = 3.0, EB = 4.0, EC = 5.0, ED = 6.0;
    
    // Expected output
    double expected = ((EA + EB + EC + ED) / 4.0) * (K + NA + NB + NC + ND);
    
    // Actual output
    double result = rsc(K, NA, EA, NB, EB, NC, EC, ND, ED);
    
    // Check if the actual output matches the expected output within a small tolerance
    if (std::abs(result - expected) < 1e-6) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed: Expected " << expected << ", got " << result << std::endl;
    }
}

// Main function
int main() {
    // Run the test
    testRscFunction();
    return 0;
}