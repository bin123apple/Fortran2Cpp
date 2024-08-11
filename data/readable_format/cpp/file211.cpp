#include <iostream>
#include <vector>
#include <cmath> // For fabs

// Function to multiply elements of A and B, add ONE to each, and store in C
void mamult(const std::vector<double>& A, const std::vector<double>& B, std::vector<double>& C, int N, double ONE) {
    for (int i = 0; i < N; ++i) {
        C[i] = A[i] * B[i] + ONE;
    }
}

// Simple test function to check correctness
void test_mamult() {
    std::vector<double> A = {1.0, 2.0, 3.0};
    std::vector<double> B = {4.0, 5.0, 6.0};
    std::vector<double> expected = {5.0, 11.0, 19.0};
    std::vector<double> C(3);
    mamult(A, B, C, 3, 1.0);

    bool test_passed = true;
    for (size_t i = 0; i < C.size(); ++i) {
        if (std::fabs(C[i] - expected[i]) > 1e-6) { // Simple floating point comparison
            std::cout << "Test failed at index " << i << ": Expected " << expected[i] << ", got " << C[i] << std::endl;
            test_passed = false;
        }
    }

    if (test_passed) {
        std::cout << "All tests passed." << std::endl;
    } else {
        std::cout << "Some tests failed." << std::endl;
    }
}

int main() {
    test_mamult();
    return 0;
}