#include <iostream>
#include <vector>

// Function declarations
void initializeAndModifyArrays(std::vector<float> &a, std::vector<float> &b);
void testArrayValues(const std::vector<float> &a, const std::vector<float> &b, float expectedA, float expectedB, const std::string &testName);

int main() {
    const int n = 32;
    std::vector<float> a(n), b(n);

    // Initialize and modify arrays as per the original program logic
    initializeAndModifyArrays(a, b);

    // Run tests
    testArrayValues(a, b, 6.0f, 3.0f, "Final State Test");

    return 0;
}

void initializeAndModifyArrays(std::vector<float> &a, std::vector<float> &b) {
    const int n = a.size();

    // Initialize arrays
    for (int i = 0; i < n; ++i) {
        a[i] = 1.0f;
        b[i] = 0.0f;
    }

    // First modification
    for (int i = 0; i < n; ++i) {
        b[i] = 2.0f;
        a[i] = a[i] + b[i];
    }

    // Test after first modification
    testArrayValues(a, b, 3.0f, 2.0f, "First Modification Test");

    // Second modification
    for (int i = 0; i < n; ++i) {
        b[i] = 3.0f;
        a[i] = a[i] + b[i];
    }
}

void testArrayValues(const std::vector<float> &a, const std::vector<float> &b, float expectedA, float expectedB, const std::string &testName) {
    bool testPassed = true;
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != expectedA || b[i] != expectedB) {
            testPassed = false;
            break;
        }
    }

    if (testPassed) {
        std::cout << testName << ": Passed" << std::endl;
    } else {
        std::cout << testName << ": Failed" << std::endl;
    }
}