#include <iostream>
#include <cmath>
#include <iomanip>

// Declare and define the per_labsim2 function within the same file
void per_labsim2(int n, double** a, double* b, double* x, double eps, int itmax) {
    // Initialize x to 0
    for (int i = 0; i < n; ++i) {
        x[i] = 0.0;
        double ast = a[i][i];
        b[i] = b[i] / ast;
        
        for (int j = 0; j < n; ++j) {
            a[i][j] = a[i][j] / ast;
        }
    }

    for (int it = 1; it <= itmax; ++it) {
        int ifl = 1;

        for (int i = 0; i < n; ++i) {
            double xst = x[i];
            x[i] = b[i];

            for (int j = 0; j < n; ++j) {
                if (i != j) x[i] = x[i] - a[i][j] * x[j];
            }

            if (std::abs(xst - x[i]) > eps) ifl = 0;
        }

        if (ifl == 1) return;
    }

    std::cout << " No convergence after " << std::setw(4) << itmax << " iterations." << std::endl;
}

int main() {
    int n = 2;
    int itmax = 100;
    double eps = 1e-6;

    // Allocate and initialize matrix a and vectors b and x
    double* a[2];
    for (int i = 0; i < n; ++i) {
        a[i] = new double[n];
    }
    double b[2] = {3, 4}; // Example system: x + y = 3, 2x + y = 4
    double x[2] = {0, 0}; // Solution vector

    // Initialize matrix a for the example system
    a[0][0] = 1; a[0][1] = 1;
    a[1][0] = 2; a[1][1] = 1;

    per_labsim2(n, a, b, x, eps, itmax);

    std::cout << "Solution x: [" << x[0] << ", " << x[1] << "]" << std::endl;

    // Clean up dynamically allocated memory
    for (int i = 0; i < n; ++i) {
        delete[] a[i];
    }

    return 0;
}