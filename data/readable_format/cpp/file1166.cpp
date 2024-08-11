#include <iostream>
#include <vector>
#include <cmath>

// Define the LEGZO function directly in this file
void LEGZO(int N, std::vector<double>& X, std::vector<double>& W) {
    double Z, Z0, P, F0, F1, PF, PD, FD, Q, WP, GD;
    int N0 = (N + 1) / 2;
    
    for (int NR = 1; NR <= N0; ++NR) {
        Z = cos(3.14159265358979323846 * (NR - 0.25) / N);
        do {
            Z0 = Z;
            P = 1.0;
            for (int I = 1; I < NR; ++I) {
                P = P * (Z - X[I - 1]); // Adjusted for 0-based indexing
            }
            F0 = 1.0;
            if (NR == N0 && N != 2 * (N / 2)) Z = 0.0;
            F1 = Z;
            for (int K = 2; K <= N; ++K) {
                PF = (2.0 - 1.0 / K) * Z * F1 - (1.0 - 1.0 / K) * F0;
                PD = K * (F1 - Z * PF) / (1.0 - Z * Z);
                F0 = F1;
                F1 = PF;
            }
            if (Z == 0.0) break;
            FD = PF / P;
            Q = 0.0;
            for (int I = 1; I <= NR; ++I) {
                WP = 1.0;
                for (int J = 1; J <= NR; ++J) {
                    if (J != I) WP = WP * (Z - X[J - 1]); // Adjusted for 0-based indexing
                }
                Q += WP;
            }
            GD = (PD - Q * FD) / P;
            Z = Z - FD / GD;
        } while (std::abs(Z - Z0) > std::abs(Z) * 1.0e-15);
        
        X[NR - 1] = Z; // Adjusted for 0-based indexing
        X[N - NR] = -Z;
        W[NR - 1] = 2.0 / ((1.0 - Z * Z) * PD * PD); // Adjusted for 0-based indexing
        W[N - NR] = W[NR - 1];
    }
}

int main() {
    int N = 5; // Example size
    std::vector<double> X(N), W(N);
    
    // Call the LEGZO function
    LEGZO(N, X, W);
    
    // Output the results for verification
    std::cout << "X values:" << std::endl;
    for (double x : X) {
        std::cout << x << std::endl;
    }
    
    std::cout << "W values:" << std::endl;
    for (double w : W) {
        std::cout << w << std::endl;
    }
    
    // Example very simple "test" without using a testing framework
    // Here you can add conditions to check if X and W match expected values
    // And output success or failure messages

    return 0;
}