#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <string>

// Function prototypes
float sumAbsDiff(const std::vector<float>& x, const std::vector<float>& y);
float sqrtSumSquares(const std::vector<float>& x);

// Test function prototype
void runTests();

int main() {
    // Running tests
    runTests();

    return 0;
}

float sumAbsDiff(const std::vector<float>& x, const std::vector<float>& y) {
    float sum = 0.0f;
    for (size_t i = 0; i < x.size(); ++i) {
        sum += std::abs(x[i] - y[i]);
    }
    return sum;
}

float sqrtSumSquares(const std::vector<float>& x) {
    float sum = 0.0f;
    for (const auto& val : x) {
        sum += val * val;
    }
    return std::sqrt(sum);
}

// Simple test framework functions
void testSumAbsDiff();
void testSqrtSumSquares();

void runTests() {
    testSumAbsDiff();
    testSqrtSumSquares();
}

void testSumAbsDiff() {
    std::vector<float> x = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    std::vector<float> y = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    float expected = 0.0f;
    float result = sumAbsDiff(x, y);
    if (std::abs(result - expected) < 0.001f) {
        std::cout << "testSumAbsDiff Passed" << std::endl;
    } else {
        std::cout << "testSumAbsDiff Failed" << std::endl;
    }
}

void testSqrtSumSquares() {
    std::vector<float> x = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    float expected = std::sqrt(55.0f);
    float result = sqrtSumSquares(x);
    if (std::abs(result - expected) < 0.001f) {
        std::cout << "testSqrtSumSquares Passed" << std::endl;
    } else {
        std::cout << "testSqrtSumSquares Failed" << std::endl;
    }
}