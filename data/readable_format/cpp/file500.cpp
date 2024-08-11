#include <iostream>
#include <complex>
#include <vector>

// Declaration of MA01BZ function
void MA01BZ(double BASE, int K, const int* S, std::complex<double>* A, int INCA,
            std::complex<double>& ALPHA, std::complex<double>& BETA, int& SCAL);

// Main function to test MA01BZ
int main() {
    int K = 2;
    int INCA = 1;
    double BASE = 2.0;
    std::vector<std::complex<double>> A = {{1.0, 2.0}, {3.0, 4.0}};
    std::vector<int> S = {1, 0};
    std::complex<double> ALPHA, BETA;
    int SCAL;

    // Calling the MA01BZ function
    MA01BZ(BASE, K, S.data(), A.data(), INCA, ALPHA, BETA, SCAL);

    // Output results
    std::cout << "ALPHA: " << ALPHA << std::endl;
    std::cout << "BETA: " << BETA << std::endl;
    std::cout << "SCAL: " << SCAL << std::endl;

    return 0;
}

// Implementation of MA01BZ function
void MA01BZ(double BASE, int K, const int* S, std::complex<double>* A, int INCA,
            std::complex<double>& ALPHA, std::complex<double>& BETA, int& SCAL) {
    const double ONE = 1.0;
    const double ZERO = 0.0;
    const std::complex<double> CONE(ONE, ZERO);
    const std::complex<double> CZERO(ZERO, ZERO);

    std::complex<double> CBASE(BASE, ZERO);
    ALPHA = CONE;
    BETA = CONE;
    SCAL = 0;
    int INDA = 0; // Adjusted to start from 0 for C++ array indexing

    for (int I = 0; I < K; ++I) {
        if (S[I] == 1) {
            ALPHA *= A[INDA];
        } else {
            if (A[INDA] == CZERO) {
                BETA = CZERO;
            } else {
                ALPHA /= A[INDA];
            }
        }
        if (std::abs(ALPHA) == ZERO) {
            ALPHA = CZERO;
            SCAL = 0;
            if (std::abs(BETA) == ZERO) {
                return;
            }
        } else {
            while (std::abs(ALPHA) < ONE) {
                ALPHA *= CBASE;
                SCAL -= 1;
            }
            while (std::abs(ALPHA) >= BASE) {
                ALPHA /= CBASE;
                SCAL += 1;
            }
        }
        INDA += INCA;
    }
}