#include <vector>
#include <iostream>

int main() {
    const int N = 4000;
    // Using vector of vectors to create a 2D array
    std::vector<std::vector<double>> A(N, std::vector<double>(N));
    std::vector<std::vector<double>> B(N, std::vector<double>(N));

    // Initializing A and B with 1.0
    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < N; ++i) {
            A[i][j] = 1.0;
            B[i][j] = 1.0;
        }
    }

    // Adding B transpose to A
    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < N; ++i) {
            A[i][j] += B[j][i];
        }
    }

    // In C++, a program returns 0 to indicate successful completion
    return 0;
}