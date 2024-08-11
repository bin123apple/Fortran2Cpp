#include <iostream>
#include <iomanip>

// Function prototype is optional since the function is defined before main in this case.
// void SLAG2D(int M, int N, float* SA, int LDSA, double* A, int LDA, int& INFO);

void SLAG2D(int M, int N, float* SA, int LDSA, double* A, int LDA, int& INFO) {
    INFO = 0;
    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < M; ++i) {
            // Compute the index in column-major order as used in Fortran
            int indexSA = i + j*LDSA;
            int indexA = i + j*LDA;
            // Convert and assign the value
            A[indexA] = static_cast<double>(SA[indexSA]);
        }
    }
}

int main() {
    const int M = 2, N = 3;
    float SA[M*N] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f};
    double A[M*N];
    int INFO;

    SLAG2D(M, N, SA, M, A, M, INFO);

    std::cout << "Converted matrix A:" << std::endl;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << std::fixed << std::setprecision(2) << A[i + j*M] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}