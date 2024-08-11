#include <iostream>
#include <vector>

// Declaration of the MB03BA function
void MB03BA(int K, int H, std::vector<int>& S, int& SMULT, std::vector<int>& AMAP, std::vector<int>& QMAP) {
    int TEMP;

    if (S[H-1] == -1) {
        SMULT = -1;
        for (int I = 1; I <= H; ++I) {
            AMAP[I-1] = H - I + 1;
        }
        for (int I = H+1; I <= K; ++I) {
            AMAP[I-1] = H + 1 - I + K;
        }
        TEMP = (H % K) + 1;
        for (int I = TEMP; I >= 1; --I) {
            QMAP[TEMP - I] = I;
        }
        for (int I = K; I > TEMP; --I) {
            QMAP[TEMP + K - I] = I;
        }
    } else {
        SMULT = 1;
        for (int I = H; I <= K; ++I) {
            AMAP[I - H] = I;
            QMAP[I - H] = I;
        }
        for (int I = 1; I < H; ++I) {
            AMAP[K - H + I] = I;
            QMAP[K - H + I] = I;
        }
    }
}

// Helper function to print vectors
void printVector(const std::vector<int>& vec) {
    for (auto v : vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

// Main function containing the unit test
int main() {
    const int K = 5;
    const int H = 3;
    std::vector<int> S = {1, 1, -1, 1, 1}; // Sample S vector
    int SMULT; // Scalar multiplier
    std::vector<int> AMAP(K), QMAP(K); // AMAP and QMAP vectors

    // Call the MB03BA function
    MB03BA(K, H, S, SMULT, AMAP, QMAP);

    // Print the results to verify correctness
    std::cout << "SMULT: " << SMULT << std::endl;
    std::cout << "AMAP: ";
    printVector(AMAP);
    std::cout << "QMAP: ";
    printVector(QMAP);

    return 0;
}