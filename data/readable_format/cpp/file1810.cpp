#include <iostream>
#include <vector>

// Declaration and definition of the DSMTV function
void DSMTV(int N, const std::vector<double>& X, std::vector<double>& Y, int NELT, const std::vector<int>& IA, const std::vector<int>& JA, const std::vector<double>& A, int ISYM) {
    // Initialize Y to zero
    for (int i = 0; i < N; ++i) {
        Y[i] = 0.0;
    }

    // Main matrix-vector multiplication
    for (int iRow = 0; iRow < N; ++iRow) {
        int iBgn = JA[iRow] - 1; // Adjusting for 0-based indexing
        int iEnd = JA[iRow + 1] - 1 - 1; // Adjusting for both 0-based indexing and end condition

        for (int i = iBgn; i <= iEnd; ++i) {
            Y[iRow] += A[i] * X[IA[i] - 1]; // Adjusting for 0-based indexing
        }
    }

    // If the matrix is symmetric, perform the additional operations
    if (ISYM == 1) {
        for (int iCol = 0; iCol < N; ++iCol) {
            int jBgn = JA[iCol] - 1 + 1; // Adjusting for 0-based indexing, but skipping the diagonal element
            int jEnd = JA[iCol + 1] - 1 - 1; // Adjusting for both 0-based indexing and end condition

            if (jBgn > jEnd) continue; // Equivalent to the GOTO statement in Fortran

            for (int j = jBgn; j <= jEnd; ++j) {
                Y[IA[j] - 1] += A[j] * X[iCol]; // Adjusting for 0-based indexing
            }
        }
    }
}

int main() {
    // Define a 3x3 sparse matrix and a vector
    int N = 3, NELT = 5;
    std::vector<double> A = {2.0, 3.0, 4.0, 5.0, 6.0};
    std::vector<int> IA = {1, 3, 2, 1, 3};
    std::vector<int> JA = {1, 3, 4, 6};
    std::vector<double> X = {1.0, 2.0, 3.0};
    std::vector<double> Y(N, 0.0); // Initialize Y with zeros
    int ISYM = 0; // Non-symmetric matrix

    DSMTV(N, X, Y, NELT, IA, JA, A, ISYM);

    std::cout << "Resulting vector Y:" << std::endl;
    for (int i = 0; i < N; ++i) {
        std::cout << Y[i] << std::endl;
    }

    return 0;
}