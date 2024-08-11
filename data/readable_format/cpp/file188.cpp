#include <iostream>
#include <vector>
#include <cmath> // For fabs

// Function prototype for sla_SVDSOL
void sla_SVDSOL(int M, int N, int MP, int NP, const std::vector<double>& B, 
                const std::vector<std::vector<double>>& U, const std::vector<double>& W, 
                const std::vector<std::vector<double>>& V, std::vector<double>& WORK, 
                std::vector<double>& X);

void testSimpleCase() {
    std::vector<double> B = {1.0, 2.0};
    std::vector<std::vector<double>> U = {{1.0, 0.0}, {0.0, 1.0}};
    std::vector<double> W = {1.0, 2.0};
    std::vector<std::vector<double>> V = {{1.0, 0.0}, {0.0, 1.0}};
    std::vector<double> WORK(2);
    std::vector<double> X(2);

    sla_SVDSOL(2, 2, 2, 2, B, U, W, V, WORK, X);

    std::cout << "X:" << std::endl;
    for (auto val : X) std::cout << val << std::endl;
}

int main() {
    testSimpleCase();
    return 0;
}

// Definition of sla_SVDSOL
void sla_SVDSOL(int M, int N, int MP, int NP, const std::vector<double>& B, 
                const std::vector<std::vector<double>>& U, const std::vector<double>& W, 
                const std::vector<std::vector<double>>& V, std::vector<double>& WORK, 
                std::vector<double>& X) {

    int J, I, JJ;
    double S;

    // Adjusting all array accesses for 0-based indexing

    for (J = 0; J < N; ++J) {
        S = 0.0;
        if (W[J] != 0.0) {
            for (I = 0; I < M; ++I) {
                S += U[I][J] * B[I];
            }
            S /= W[J];
        }
        WORK[J] = S;
    }

    for (J = 0; J < N; ++J) {
        S = 0.0;
        for (JJ = 0; JJ < N; ++JJ) {
            S += V[J][JJ] * WORK[JJ];
        }
        X[J] = S;
    }
}