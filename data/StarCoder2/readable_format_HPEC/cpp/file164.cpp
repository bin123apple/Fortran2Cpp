#include <cmath>
#include <vector>

// Assuming the existence of a namespace or class to encapsulate the data and functions
// For simplicity, we'll assume global variables for the arrays and other parameters

extern std::vector<double> q, z, r, p;
extern std::vector<int> rowstr, colidx;
extern std::vector<double> a;
extern int naa, lastrow, firstrow, lastcol, firstcol;

void conj_grad(double& rnorm) {
    int j, cgit, cgitmax = 25;
    double d, sum, rho, rho0, alpha, beta, suml;

    rho = 0.0;
    sum = 0.0;

    // Initialize q, z, r, p
    for (j = 0; j < naa + 1; ++j) {
        q[j] = 0.0;
        z[j] = 0.0;
        r[j] = x[j]; // Assuming x is a global or externally defined vector
        p[j] = r[j];
    }

    // Compute rho
    for (j = 0; j < lastcol - firstcol + 1; ++j) {
        rho += r[j] * r[j];
    }

    for (cgit = 1; cgit <= cgitmax; ++cgit) {
        rho0 = rho;
        d = 0.0;
        rho = 0.0;

        // Compute q
        for (j = 0; j < lastrow - firstrow + 1; ++j) {
            suml = 0.0;
            for (int k = rowstr[j] - 1; k < rowstr[j + 1] - 1; ++k) { // Adjusting for 0-based indexing
                suml += a[k] * p[colidx[k] - 1]; // Adjusting for 0-based indexing
            }
            q[j] = suml;
        }

        // Compute d
        for (j = 0; j < lastcol - firstcol + 1; ++j) {
            d += p[j] * q[j];
        }

        alpha = rho0 / d;

        // Update z and r
        for (j = 0; j < lastcol - firstcol + 1; ++j) {
            z[j] += alpha * p[j];
            r[j] -= alpha * q[j];

            rho += r[j] * r[j];
        }

        beta = rho / rho0;

        for (j = 0; j < lastcol - firstcol + 1; ++j) {
            p[j] = r[j] + beta * p[j];
        }
    }

    // Compute r
    for (j = 0; j < lastrow - firstrow + 1; ++j) {
        suml = 0.0;
        for (int k = rowstr[j] - 1; k < rowstr[j + 1] - 1; ++k) { // Adjusting for 0-based indexing
            suml += a[k] * z[colidx[k] - 1]; // Adjusting for 0-based indexing
        }
        r[j] = suml;
    }

    // Compute rnorm
    for (j = 0; j < lastcol - firstcol + 1; ++j) {
        suml = x[j] - r[j];
        sum += suml * suml;
    }

    rnorm = std::sqrt(sum);
}
