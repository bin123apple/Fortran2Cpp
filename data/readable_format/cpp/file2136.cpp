#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

void REDUC(int NM, int N, std::vector<std::vector<float>>& A, std::vector<std::vector<float>>& B, std::vector<float>& DL, int& IERR) {
    IERR = 0;
    int NN = std::abs(N);

    if (N < 0) return; // Replace goto with return; adjust logic as needed.

    for (int I = 1; I <= N; ++I) {
        int I1 = I - 1;
        float Y = 0.0; // Declare Y here to avoid crossing initialization.
        for (int J = I; J <= N; ++J) {
            float X = B[I-1][J-1];
            if (I != 1) {
                for (int K = 1; K <= I1; ++K) {
                    X -= B[I-1][K-1] * B[J-1][K-1];
                }
            }
            if (J == I) {
                if (X <= 0.0) {
                    IERR = 7 * N + 1;
                    return; // Replace goto with return.
                }
                Y = std::sqrt(X);
                DL[I-1] = Y;
            } else {
                B[J-1][I-1] = X / Y;
            }
        }
    }

    for (int I = 1; I <= NN; ++I) {
        int I1 = I - 1;
        float Y = DL[I-1];
        for (int J = I; J <= NN; ++J) {
            float X = A[I-1][J-1];
            if (I != 1) {
                for (int K = 1; K <= I1; ++K) {
                    X -= B[I-1][K-1] * A[J-1][K-1];
                }
            }
            A[J-1][I-1] = X / Y;
        }
    }

    for (int J = 1; J <= NN; ++J) {
        int J1 = J - 1;
        for (int I = J; I <= NN; ++I) {
            float X = A[I-1][J-1];
            int I1 = (I == J) ? I : I - 1; // Adjust I1 initialization.
            if (I != J) {
                for (int K = J; K <= I1; ++K) {
                    X -= A[K-1][J-1] * B[I-1][K-1];
                }
            }
            if (J != 1) {
                for (int K = 1; K <= J1; ++K) {
                    X -= A[J-1][K-1] * B[I-1][K-1];
                }
            }
            A[I-1][J-1] = X / DL[I-1];
        }
    }
}

int main() {
    const int NM = 4;
    const int N = 3;
    int IERR;

    std::vector<std::vector<float>> A = {
        {1.0, 0.5, 0.2, 0.0},
        {0.5, 1.0, 0.3, 0.0},
        {0.2, 0.3, 1.0, 0.0},
        {0.0, 0.0, 0.0, 0.0}
    };

    std::vector<std::vector<float>> B = {
        {1.0, 0.5, 0.2, 0.0},
        {0.5, 1.0, 0.3, 0.0},
        {0.2, 0.3, 1.0, 0.0},
        {0.0, 0.0, 0.0, 0.0}
    };

    std::vector<float> DL(NM, 0.0);

    REDUC(NM, N, A, B, DL, IERR);

    std::cout << "IERR = " << IERR << std::endl;

    std::cout << "A = " << std::endl;
    for (const auto& row : A) {
        for (const auto& elem : row) {
            std::cout << std::setw(10) << elem << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "B = " << std::endl;
    for (const auto& row : B) {
        for (const auto& elem : row) {
            std::cout << std::setw(10) << elem << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "DL = ";
    for (const auto& elem : DL) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}