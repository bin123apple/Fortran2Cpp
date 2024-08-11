#include <iostream>
#include <vector>
#include <algorithm> // For std::min

// Definition of the DGENND function within the same file
bool DGENND(int M, int N, const std::vector<std::vector<double>>& A) {
    const double ZERO = 0.0;
    int K = std::min(M, N);

    for (int I = 0; I < K; ++I) {
        if (A[I][I] < ZERO) {
            return false;
        }
    }
    return true;
}

int main() {
    // Test 1: Matrix with positive diagonal
    std::vector<std::vector<double>> A1 = {
        {1.0, 2.0},
        {3.0, 4.0}
    };
    bool result = DGENND(2, 2, A1);
    std::cout << "Test 1 (Expected: 1): " << result << std::endl;

    // Test 2: Matrix with a negative diagonal element
    std::vector<std::vector<double>> A2 = {
        {1.0, 2.0},
        {3.0, -4.0}
    };
    result = DGENND(2, 2, A2);
    std::cout << "Test 2 (Expected: 0): " << result << std::endl;

    return 0;
}