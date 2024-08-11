#include <iostream>
#include <vector>
#include <cmath> // For std::abs, std::pow

// Declaration of LAGZO function
void LAGZO(int N, std::vector<double>& X, std::vector<double>& W) {
    double HN = 1.0 / N;
    for (int NR = 1; NR <= N; ++NR) {
        double Z;
        if (NR == 1) Z = HN;
        if (NR > 1) Z = X[NR - 2] + HN * std::pow(NR, 1.27);
        
        int IT = 0;
        double Z0;
        double PD; // Declare PD here to ensure it's available for use later.
        do {
            ++IT;
            Z0 = Z;
            double P = 1.0;
            for (int I = 1; I < NR; ++I) {
                P *= (Z - X[I - 1]);
            }
            double F0 = 1.0;
            double F1 = 1.0 - Z;
            for (int K = 2; K <= N; ++K) {
                double PF = ((2.0 * K - 1.0 - Z) * F1 - (K - 1.0) * F0) / K;
                F0 = F1;
                F1 = PF;
            }
            PD = N / Z * (F1 - F0); // Ensure PD is calculated within the loop.
            double FD = F1 / P;
            double Q = 0.0;
            for (int I = 1; I < NR; ++I) {
                double WP = 1.0;
                for (int J = 1; J < NR; ++J) {
                    if (J != I) {
                        WP *= (Z - X[J - 1]);
                    }
                }
                Q += WP;
            }
            double GD = (PD - Q * FD) / P;
            Z -= FD / GD;
        } while (IT <= 40 && std::abs((Z - Z0) / Z) > 1.0e-15);
        
        X[NR - 1] = Z;
        W[NR - 1] = 1.0 / (Z * PD * PD); // Now PD is correctly used here.
    }
}

// Test function for LAGZO
void testLAGZO() {
    int N = 5;
    std::vector<double> X(N), W(N);

    LAGZO(N, X, W);

    std::cout << "X: ";
    for (auto x : X) std::cout << x << " ";
    std::cout << std::endl;

    std::cout << "W: ";
    for (auto w : W) std::cout << w << " ";
    std::cout << std::endl;
}

int main() {
    testLAGZO();
    // Additional test cases can be added here to further verify the correctness of the LAGZO function.
    return 0;
}