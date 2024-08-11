#include <iostream>
#include <vector>
#include <cmath>

// Define the tridag function directly in this file
void tridag(const std::vector<double>& a, const std::vector<double>& b, const std::vector<double>& c, 
            const std::vector<double>& r, std::vector<double>& u, int n) {
    std::vector<double> gam(n, 0.0); // Temporary vector, initialized to zero
    double bet;

    if (b[0] == 0.0) {
        std::cerr << "tridag: rewrite equations" << std::endl;
        exit(1);
    }

    bet = b[0];
    u[0] = r[0] / bet;

    for (int j = 1; j < n; j++) {
        gam[j] = c[j - 1] / bet;
        bet = b[j] - a[j] * gam[j];
        if (bet == 0.0) {
            std::cerr << "tridag failed" << std::endl;
            exit(1);
        }
        u[j] = (r[j] - a[j] * u[j - 1]) / bet;
    }

    for (int j = n - 2; j >= 0; j--) {
        u[j] -= gam[j + 1] * u[j + 1];
    }
}

int main() {
    // Example usage of the tridag function
    int n = 4; // Size of the system
    std::vector<double> a = {0, -1, -1, -1}; // Sub-diagonal elements
    std::vector<double> b = {4, 4, 4, 4}; // Diagonal elements
    std::vector<double> c = {-1, -1, -1, 0}; // Super-diagonal elements
    std::vector<double> r = {5, 5, 10, 3}; // Right-hand side
    std::vector<double> u(n); // Solution vector will be stored here

    tridag(a, b, c, r, u, n);

    std::cout << "Results:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "u[" << i << "] = " << u[i] << std::endl;
    }

    return 0;
}