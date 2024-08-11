#include <iostream>
#include <cmath> // For fabs function

// Function prototype
void addv(int n, double* a, double* b, double* c);

// Function implementation
void addv(int n, double* a, double* b, double* c) {
    for(int i = 0; i < n; i++) {
        c[i] = a[i] + b[i];
    }
}

// Test function
bool testAddv(int n, double* a, double* b, double* expected) {
    double* c = new double[n];
    addv(n, a, b, c);
    for(int i = 0; i < n; ++i) {
        if(std::fabs(c[i] - expected[i]) > 1e-6) {
            delete[] c;
            return false;
        }
    }
    delete[] c;
    return true;
}

int main() {
    // Test case 1: Small array
    {
        double A[] = {1.0};
        double B[] = {-1.0};
        double expected[] = {0.0};
        std::cout << "Test 1 (Single element): " << (testAddv(1, A, B, expected) ? "PASS" : "FAIL") << std::endl;
    }

    // Test case 2: Larger array with positive, negative, and zero values
    {
        double A[] = {1.0, -2.0, 3.0, 0.0, -5.0};
        double B[] = {5.0, 4.0, -3.0, 0.0, 2.0};
        double expected[] = {6.0, 2.0, 0.0, 0.0, -3.0};
        std::cout << "Test 2 (Mixed values): " << (testAddv(5, A, B, expected) ? "PASS" : "FAIL") << std::endl;
    }

    // Additional tests can be added following the pattern above

    return 0;
}