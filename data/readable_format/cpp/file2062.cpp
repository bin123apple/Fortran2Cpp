#include <iostream>
#include <vector>

// Define the DLAPMT function within the same file
void DLAPMT(bool FORWRD, int M, int N, std::vector<std::vector<double>>& X, std::vector<int>& K) {
    int I, IN, J, II;
    double TEMP;

    if (N <= 1) return;

    for (I = 1; I <= N; ++I) {
        K[I - 1] = -K[I - 1]; // Adjust index for 0-based
    }

    if (FORWRD) {
        for (I = 1; I <= N; ++I) {
            if (K[I - 1] > 0) continue;

            J = I;
            K[J - 1] = -K[J - 1]; // Adjust index for 0-based
            IN = K[J - 1]; // Adjust index for 0-based

            while (true) {
                if (K[IN - 1] > 0) break;

                for (II = 1; II <= M; ++II) {
                    TEMP = X[II - 1][J - 1]; // Adjust index for 0-based
                    X[II - 1][J - 1] = X[II - 1][IN - 1]; // Adjust index for 0-based
                    X[II - 1][IN - 1] = TEMP; // Adjust index for 0-based
                }

                K[IN - 1] = -K[IN - 1]; // Adjust index for 0-based
                J = IN;
                IN = K[IN - 1]; // Adjust index for 0-based
            }
        }
    } else {
        for (I = 1; I <= N; ++I) {
            if (K[I - 1] > 0) continue;

            K[I - 1] = -K[I - 1]; // Adjust index for 0-based
            J = K[I - 1]; // Adjust index for 0-based

            while (true) {
                if (J == I) break;

                for (II = 1; II <= M; ++II) {
                    TEMP = X[II - 1][I - 1]; // Adjust index for 0-based
                    X[II - 1][I - 1] = X[II - 1][J - 1]; // Adjust index for 0-based
                    X[II - 1][J - 1] = TEMP; // Adjust index for 0-based
                }

                K[J - 1] = -K[J - 1]; // Adjust index for 0-based
                J = K[J - 1]; // Adjust index for 0-based
            }
        }
    }
}

// Main function for testing
int main() {
    int M = 2, N = 3;
    std::vector<int> K = {3, 1, 2}; // Adjust for 1-based indexing
    std::vector<std::vector<double>> X = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}};
    bool FORWRD = true;

    DLAPMT(FORWRD, M, N, X, K);

    std::cout << "Result:" << std::endl;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << X[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}