#include <iostream>
#include <array>

// Function to increment elements of the array A and store results in C
void incrementArray(const std::array<int, 12>& A, std::array<int, 12>& C) {
    for (int i = 0; i < 12; ++i) {
        C[i] = A[i] + 1;
    }
}

// Simple test function to verify the correctness of incrementArray
void testIncrementArray() {
    std::array<int, 12> A, C, expected;
    bool testPassed = true;

    // Initialize A with values 1 to 12 and expected with values 2 to 13
    for (int i = 0; i < 12; ++i) {
        A[i] = i + 1;
        expected[i] = i + 2;
    }

    // Call the function to test
    incrementArray(A, C);

    // Check if the result matches the expected output
    for (int i = 0; i < 12; ++i) {
        if (C[i] != expected[i]) {
            std::cerr << "Test failed at element " << i << ": expected " << expected[i] << ", got " << C[i] << std::endl;
            testPassed = false;
            break;
        }
    }

    if (testPassed) {
        std::cout << "Test passed." << std::endl;
    }
}

int main() {
    // You can call your test functions here
    testIncrementArray();

    return 0;
}