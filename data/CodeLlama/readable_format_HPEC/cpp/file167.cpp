#include <cmath>
#include <vector>

// Assuming the data structures and variables are defined and initialized as follows:
// double rnorm;
// extern std::vector<double> q, z, r, p;
// extern std::vector<int> rowstr, colidx;
// extern double a[];
// extern double x[];
// int naa, lastrow, lastcol, cgitmax, kz;

void conj_grad(double& rnorm) {
    int cgit, cgitmax = 25;
    double d, sum, rho, rho0, alpha, beta, suml;

    rho = 0.0;
    sum = 0.0;

    // Initialization of vectors q, z, r, p
    for (int j = 0; j < naa + 1; ++j) {
        q[j] = 0.0;
        z[j] = 0.0;
        r[j] = x[j];
        p[j] = r[j];
    }

    // Calculate rho
    for (int j = 0; j < lastcol - firstcol + 1; ++j) {
        rho += r[j] * r[j];
    }

    for (cgit = 1; cgit <= cgitmax; ++cgit) {
        rho0 = rho;
        d = 0.0;
        rho = 0.0;

        for (int j = 0; j < lastrow - firstrow + 1; ++j) {
            suml = 0.0;
            for (int k = rowstr[j] - 1; k < rowstr[j + 1] - 1; ++k) { // Adjusted for 0-based indexing
                suml += a[k] * p[colidx[k] - 1]; // Adjusted for 0-based indexing
            }
            q[j] = suml;
        }

        for (int j = 0; j < lastcol - firstcol + 1; ++j) {
            d += p[j] * q[j];
        }

        alpha = rho0 / d;

        for (int j = 0; j < lastcol - firstcol + 1; ++j) {
            z[j] += alpha * p[j];
            r[j] -= alpha * q[j];
            rho += r[j] * r[j];
        }

        beta = rho / rho0;

        for (int j = 0; j < lastcol - firstcol + 1; ++j) {
            p[j] = r[j] + beta * p[j];
        }
    }

    for (int j = 0; j < lastrow - firstrow + 1; ++j) {
        suml = 0.0;
        for (int k = rowstr[j] - 1; k < rowstr[j + 1] - 1; ++k) { // Adjusted for 0-based indexing
            suml += a[k] * z[colidx[k] - 1]; // Adjusted for 0-based indexing
        }
        r[j] = suml;
    }

    for (int j = 0; j < lastcol - firstcol + 1; ++j) {
        suml = x[j] - r[j];
        sum += suml * suml;
    }

    rnorm = std::sqrt(sum);
}
