#include <vector>
#include <cstring> // for memset

void jac(int Neq, double t, std::vector<double>& Y, int mlow, int mup, std::vector<std::vector<double>>& pd, int nrowpd) {
    int ntmax = Neq / 2;
    int N0 = ntmax - 1;

    // Assuming gr is defined somewhere in the global scope or passed as a parameter
    extern double gr;

    // Initialize the pd matrix to zero
    for (int i = 0; i < nrowpd; ++i) {
        std::fill(pd[i].begin(), pd[i].end(), 0.0);
    }

    for (int nt = 1; nt <= ntmax; ++nt) {
        double xtmm = (nt - 1) * (nt - 1);
        pd[4][2 * (nt - 1) + 1] += 0.5 * gr * xtmm; // Adjusting indices for 0-based arrays
        pd[6][2 * (nt - 1)] -= 0.5 * gr * xtmm;
    }

    for (int nt = 1; nt <= ntmax; ++nt) {
        double xtmm = (N0 - nt + 1) * (N0 - nt + 1);
        pd[4][2 * (nt - 1) + 1] += 0.5 * gr * xtmm;
        pd[6][2 * (nt - 1)] -= 0.5 * gr * xtmm;
    }

    for (int nt = 1; nt <= ntmax; ++nt) {
        double xtmm = -(nt - 1) * (N0 - nt + 1) * 2;
        pd[4][2 * (nt - 1) + 1] += 0.5 * gr * xtmm;
        pd[6][2 * (nt - 1)] -= 0.5 * gr * xtmm;
    }
}

int main() {
    // Example usage:
    int Neq = 10; // Example value
    double t = 0.0; // Example value
    std::vector<double> Y(Neq, 0.0); // Example initialization
    int mlow = 0; // Example value
    int mup = 0; // Example value
    int nrowpd = 10; // Example value

    // Initialize pd matrix with nrowpd rows and Neq columns
    std::vector<std::vector<double>> pd(nrowpd, std::vector<double>(Neq, 0.0));

    // Define gr in the global scope
    double gr = 9.81; // Example value

    // Call the jac function
    jac(Neq, t, Y, mlow, mup, pd, nrowpd);

    // Output the pd matrix for verification
    for (const auto& row : pd) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}