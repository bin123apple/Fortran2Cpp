#include <iostream>
#include <vector>

// Function Prototype for SVBKSB
void SVBKSB(const std::vector<std::vector<double>>& U, const std::vector<double>& W, 
            const std::vector<std::vector<double>>& V, int M, int N, 
            const std::vector<double>& B, std::vector<double>& X);

// Function Prototype for the Test Function
void testSVBKSB();

// Main Function
int main() {
    testSVBKSB();
    return 0;
}

// SVBKSB Function Definition
void SVBKSB(const std::vector<std::vector<double>>& U, const std::vector<double>& W, 
            const std::vector<std::vector<double>>& V, int M, int N, 
            const std::vector<double>& B, std::vector<double>& X) {
    std::vector<double> TMP(N);

    for (int j = 0; j < N; ++j) {
        double S = 0.0;
        if (W[j] != 0.0) {
            for (int i = 0; i < M; ++i) {
                S += U[i][j] * B[i];
            }
            S /= W[j];
        }
        TMP[j] = S;
    }

    for (int j = 0; j < N; ++j) {
        double S = 0.0;
        for (int jj = 0; jj < N; ++jj) {
            S += V[j][jj] * TMP[jj];
        }
        X[j] = S;
    }
}

// Test Function Definition
void testSVBKSB() {
    std::vector<std::vector<double>> U = {
        {1.0, 0.0, 0.0},
        {0.0, 1.0, 0.0},
        {0.0, 0.0, 1.0}
    };
    std::vector<double> W = {1.0, 2.0, 3.0};
    std::vector<std::vector<double>> V = {
        {1.0, 0.0, 0.0},
        {0.0, 1.0, 0.0},
        {0.0, 0.0, 1.0}
    };
    std::vector<double> B = {1.0, 2.0, 3.0};
    std::vector<double> X(3); // Initialize X with size 3.
  
    SVBKSB(U, W, V, 3, 3, B, X);
  
    std::cout << "X:" << std::endl;
    for (auto x : X) {
        std::cout << x << std::endl;
    }
}