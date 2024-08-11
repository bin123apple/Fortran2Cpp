#include <iostream>
#include <vector>

// Function declaration is optional here since the definition is in the same file
void NMRV(int N, double H, const std::vector<double>& Q, const std::vector<double>& S, std::vector<double>& U) {
    double G = H * H / 12.0;
    
    for (int i = 1; i < N-1; ++i) {  // Adjusted for 0-based indexing
        double C0 = 1.0 + G * ((Q[i-1] - Q[i+1]) / 2.0 + Q[i]);
        double C1 = 2.0 - G * (Q[i+1] + Q[i-1] + 8.0 * Q[i]);
        double C2 = 1.0 + G * ((Q[i+1] - Q[i-1]) / 2.0 + Q[i]);
        double D = G * (S[i+1] + S[i-1] + 10.0 * S[i]);
        double UTMP = C1 * U[i] - C0 * U[i-1] + D;
        U[i+1] = UTMP / C2;  // Adjusted for 0-based indexing
    }
}

int main() {
    int N = 5;
    double H = 0.1;
    std::vector<double> Q = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<double> S = {2.0, 3.0, 4.0, 5.0, 6.0};
    std::vector<double> U(N, 0.0); // Initialize U with zeros

    NMRV(N, H, Q, S, U);

    // Output for verification
    std::cout << "Output U:" << std::endl;
    for (double u : U) {
        std::cout << u << std::endl;
    }

    return 0;
}