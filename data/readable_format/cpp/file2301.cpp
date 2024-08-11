#include <cmath>
#include <vector>
#include <cstdlib>

void SLARRA(int N, std::vector<double>& D, std::vector<double>& E, std::vector<double>& E2, double SPLTOL, double TNRM, 
            int& NSPLIT, std::vector<int>& ISPLIT, int& INFO) {
    const double ZERO = 0.0;
    NSPLIT = 1;
    INFO = 0;

    if (SPLTOL < 0) {
        double TMP1 = std::abs(SPLTOL) * TNRM;
        for (int I = 0; I < N - 1; ++I) {
            double EABS = std::abs(E[I]);
            if (EABS <= TMP1) {
                E[I] = ZERO;
                E2[I] = ZERO;
                ISPLIT[NSPLIT - 1] = I + 1; // Fortran to C++ index adjustment
                NSPLIT++;
            }
        }
    } else {
        for (int I = 0; I < N - 1; ++I) {
            double EABS = std::abs(E[I]);
            if (EABS <= SPLTOL * std::sqrt(std::abs(D[I])) * std::sqrt(std::abs(D[I + 1]))) {
                E[I] = ZERO;
                E2[I] = ZERO;
                ISPLIT[NSPLIT - 1] = I + 1; // Fortran to C++ index adjustment
                NSPLIT++;
            }
        }
    }
    ISPLIT[NSPLIT - 1] = N; // Fortran to C++ index adjustment
}

int main() {
    // Example usage
    int N = 5;
    std::vector<double> D = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<double> E = {0.1, 0.2, 0.3, 0.4};
    std::vector<double> E2 = {0.01, 0.04, 0.09, 0.16};
    double SPLTOL = 0.2;
    double TNRM = 1.0;
    int NSPLIT;
    std::vector<int> ISPLIT(N);
    int INFO;

    SLARRA(N, D, E, E2, SPLTOL, TNRM, NSPLIT, ISPLIT, INFO);

    // Output results
    for (int i = 0; i < NSPLIT; ++i) {
        std::cout << "ISPLIT[" << i << "] = " << ISPLIT[i] << std::endl;
    }

    return 0;
}