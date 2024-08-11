#include <iostream>
#include <vector>
#include <cmath> // For fabs in case you need to compare floating-point numbers

// Function prototype
void s3(int n, std::vector<float>& z, const std::vector<float>& y);

// Function definition
void s3(int n, std::vector<float>& z, const std::vector<float>& y) {
    z.resize(n);
    for (int i = 0; i < n; ++i) {
        z[i] = y[i];
    }
}

// Simple test function
bool testS3() {
    int n = 5;
    std::vector<float> z;
    std::vector<float> y = {1, 2, 3, 4, 5}; // Example input
    s3(n, z, y);

    // Verify z matches y
    for (int i = 0; i < n; ++i) {
        if (z[i] != y[i]) {
            return false; // Test failed
        }
    }
    return true; // Test passed
}

// Main function to run tests
int main() {
    if (testS3()) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
    }
    return 0;
}