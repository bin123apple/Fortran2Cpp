#include <iostream>
#include <vector>
#include <omp.h>

// Function to perform the sum calculation
bool verifySum() {
    const int t = 100 * 101 / 2; // Theoretical sum of numbers from 1 to 100
    std::vector<int> s(16, 0); // Initialize vector of size 16 with 0s

    // Parallel loop
    #pragma omp parallel for
    for (int j = 0; j < 16; ++j) {
        for (int i = 1; i <= 100; ++i) {
            s[j] += i;
        }
    }

    // Check if any element of s is not equal to t
    for (int j = 0; j < 16; ++j) {
        if (s[j] != t) {
            return false;
        }
    }
    return true;
}

// Main function containing the test
int main() {
    // Run the test
    bool testResult = verifySum();

    // Check the test result and print the corresponding message
    if (testResult) {
        std::cout << "Test passed: All elements match the expected sum." << std::endl;
    } else {
        std::cout << "Test failed: At least one element does not match the expected sum." << std::endl;
        return 1; // Return error code 1 if the test fails
    }

    return 0; // Return 0 to indicate success
}