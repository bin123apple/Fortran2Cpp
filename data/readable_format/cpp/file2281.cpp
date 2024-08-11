#include <vector>

void ERD__NORMALIZE_CARTESIAN(int M, int NXYZ, int L, const std::vector<double>& NORM, std::vector<std::vector<double>>& BATCH) {
    int N = 0;
    double SCALAR, XNORM;

    for (int X = L; X >= 0; --X) {
        XNORM = NORM[X];
        int YBEG = L - X;
        for (int Y = YBEG; Y >= 0; --Y) {
            int Z = YBEG - Y;
            SCALAR = XNORM * NORM[Y] * NORM[Z];

            N += 1;

            for (int I = 0; I < M; ++I) {
                BATCH[I][N-1] = SCALAR * BATCH[I][N-1];
            }
        }
    }
}

int main() {
    // Example usage
    int M = 3, NXYZ = 10, L = 2;
    std::vector<double> NORM = {1.0, 2.0, 3.0}; // example values
    std::vector<std::vector<double>> BATCH(M, std::vector<double>(NXYZ, 1.0)); // example values

    ERD__NORMALIZE_CARTESIAN(M, NXYZ, L, NORM, BATCH);

    return 0;
}