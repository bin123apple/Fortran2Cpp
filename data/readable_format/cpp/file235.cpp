#include <iostream>
#include <cmath>
#include <algorithm>

// Assuming these are the functions from your translated program
void sub(const float* x, float* res, int size);
void doubleArray(float* x, int size);
float* get_var();
bool anyGreaterThanEpsilon(const float* arr, float value, float eps, int size);

float z[3] = {1.0, 1.0, 1.0}; // Global variable for demonstration

void sub(const float* x, float* res, int size) {
    std::copy(x, x+size, res);
}

void doubleArray(float* x, int size) {
    std::transform(x, x+size, x, [](float v) { return 2*v; });
}

float* get_var() {
    return z;
}

bool anyGreaterThanEpsilon(const float* arr, float value, float eps, int size) {
    for (int i = 0; i < size; ++i) {
        if (std::abs(arr[i] - value) > eps) {
            return true;
        }
    }
    return false;
}

// Simple test function for demonstration
void test_sub() {
    float testRes[3];
    const float inputArr[3] = {1.0, 1.0, 1.0};
    const float expectedRes[3] = {1.0, 1.0, 1.0};
    sub(inputArr, testRes, 3);
    bool passed = true;
    for (int i = 0; i < 3; ++i) {
        if (std::abs(testRes[i] - expectedRes[i]) >= std::numeric_limits<float>::epsilon()) {
            passed = false;
            break;
        }
    }
    std::cout << "test_sub: " << (passed ? "PASSED" : "FAILED") << std::endl;
}

// Add more test functions as needed

int main() {
    // Call your program's main functions here
    // ...

    // Call test functions at the end
    test_sub();
    // Add calls to other test functions as needed

    return 0;
}