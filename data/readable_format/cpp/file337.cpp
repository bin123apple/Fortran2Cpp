#include <iostream>
#include <cmath>

// Function definitions
void loop3_F90(int N, double* x, double* y, double a) {
    for (int i = 0; i < N; ++i) {
        y[i] = y[i] + a * x[i];
    }
}

void loop3_F90Overhead(int N, double* x, double* y, double a) {
    // Intentionally left empty
}

// Test functions
void testLoop3_F90() {
    int N = 5;
    double a = 2.5;
    double x[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double y[] = {1.0, 1.0, 1.0, 1.0, 1.0};
    double expectedY[] = {3.5, 6.0, 8.5, 11.0, 13.5};

    loop3_F90(N, x, y, a);

    bool correct = true;
    for (int i = 0; i < N; ++i) {
        if (std::abs(y[i] - expectedY[i]) > 1e-6) {
            correct = false;
            break;
        }
    }

    std::cout << "Test loop3_F90: " << (correct ? "PASSED" : "FAILED") << std::endl;
}

void testLoop3_F90Overhead() {
    int N = 5;
    double a = 2.5;
    double x[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double y[] = {1.0, 1.0, 1.0, 1.0, 1.0}; // Expected to remain unchanged

    loop3_F90Overhead(N, x, y, a);

    bool correct = true;
    for (int i = 0; i < N; ++i) {
        if (y[i] != 1.0) {
            correct = false;
            break;
        }
    }

    std::cout << "Test loop3_F90Overhead: " << (correct ? "PASSED" : "FAILED") << std::endl;
}

// Main function
int main() {
    // Running the unit tests
    testLoop3_F90();
    testLoop3_F90Overhead();

    return 0;
}