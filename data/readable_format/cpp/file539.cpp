#include <iostream>
#include <vector>
#include <cassert>

// Global variables setup (if these are used within SetBoundWake)
int nb = 2, nbe = 3, nt = 0; // Example values for demonstration
std::vector<double> xBE(10), yBE(10), zBE(10);
std::vector<std::vector<double>> x(10, std::vector<double>(10)),
                                 y(10, std::vector<double>(10)),
                                 z(10, std::vector<double>(10));

// Definition of SetBoundWake function
void SetBoundWake() {
    for (int i = 0; i < nb; ++i) {
        int nei = 1 + i * (nbe + 1) - 1; // Adjust for 0-based indexing, but start from 1 as in Fortran
        for (int j = 0; j <= nbe; ++j) { // Note: Inclusive range as in Fortran
            int nej = nei + j; // Already 0-based
            x[nt][nej] = xBE[nej]; // Adjusted for 0-based indexing
            y[nt][nej] = yBE[nej];
            z[nt][nej] = zBE[nej];
        }
    }
}

// Main function to test SetBoundWake
int main() {
    // Initialize xBE, yBE, zBE with sample data
    for (int i = 0; i < xBE.size(); ++i) {
        xBE[i] = (i + 1) * 1.0;
        yBE[i] = (i + 1) * 2.0;
        zBE[i] = (i + 1) * 3.0;
    }
    
    // Call the function
    SetBoundWake();
    
    // Verify the results and output for verification
    for (int i = 0; i < nb * (nbe + 1); ++i) {
        assert(x[nt][i] == xBE[i]);
        assert(y[nt][i] == yBE[i]);
        assert(z[nt][i] == zBE[i]);
        std::cout << "x[" << nt << "][" << i << "] = " << x[nt][i] << std::endl;
        std::cout << "y[" << nt << "][" << i << "] = " << y[nt][i] << std::endl;
        std::cout << "z[" << nt << "][" << i << "] = " << z[nt][i] << std::endl;
    }

    std::cout << "All tests passed!" << std::endl;
    return 0;
}