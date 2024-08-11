// main.cpp
#include <iostream>
#include <vector>
#include <numeric> // For std::accumulate

// Function to initialize the array
void initializeArray(std::vector<double>& array) {
    for (size_t i = 0; i < array.size(); ++i) {
        array[i] = static_cast<double>(i + 1);
    }
}

// Function to test the result
void testResult(double result, double expected) {
    const double epsilon = 1.0e-6;
    if (std::abs(result - expected) > epsilon) {
        std::cerr << "Test failed: Expected: " << expected << " Got: " << result << std::endl;
    } else {
        std::cout << "Test passed." << std::endl;
    }
}

int main() {
    const int N = 200001;
    std::vector<double> array(N);
    double expected, result;

    // Initialize array
    initializeArray(array);

    // Compute the sum
    result = std::accumulate(array.begin(), array.end(), 0.0);

    // Expected result
    expected = static_cast<double>(N) * (N + 1) / 2.0;

    // Test the result
    testResult(result, expected);

    return 0;
}