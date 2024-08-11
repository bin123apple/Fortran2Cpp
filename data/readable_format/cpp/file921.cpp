#include <iostream>
#include <vector>

// The balbak function as previously described
void balbak(int NM, int N, int LOW, int IGH, std::vector<float>& SCALE, int M, std::vector<std::vector<float>>& Z) {
    int I, J, K, II;
    float S;

    if (M == 0) return;
    if (IGH == LOW) return;

    for (I = LOW; I <= IGH; ++I) {
        S = SCALE[I - 1]; // Adjusting index for 0-based indexing in C++
        for (J = 0; J < M; ++J) {
            Z[I - 1][J] *= S; // Adjusting indices for 0-based indexing in C++
        }
    }

    for (II = 1; II <= N; ++II) {
        I = II;
        if (I >= LOW && I <= IGH) continue;
        if (I < LOW) I = LOW - II;
        K = static_cast<int>(SCALE[I - 1]); // Assuming SCALE stores indices. Adjusting index for 0-based indexing in C++
        if (K == I) continue;
        for (J = 0; J < M; ++J) {
            S = Z[I - 1][J];
            Z[I - 1][J] = Z[K - 1][J]; // Adjusting indices for 0-based indexing in C++
            Z[K - 1][J] = S;
        }
    }
}

// Main function to test the balbak function
int main() {
    // Example test parameters
    int NM = 5, N = 3, LOW = 2, IGH = 4, M = 2;
    std::vector<float> SCALE = {1, 2, 3, 4, 5};
    std::vector<std::vector<float>> Z = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}};

    // Call the balbak function
    balbak(NM, N, LOW, IGH, SCALE, M, Z);

    // Print the modified Z matrix
    std::cout << "Modified Z:" << std::endl;
    for (int i = 0; i < NM; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cout << Z[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}