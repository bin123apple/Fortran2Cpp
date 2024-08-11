#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

void ksd(double& df, const std::vector<double>& g, const std::vector<double>& dgdx, int ng, double rho) {
    double toler = -40.0;
    double sum1 = 0.0;
    double sum2 = 0.0;
    double gmax = g[0];  // Adjusted for 0-based indexing

    if (ng < 2) {
        df = dgdx[0];
        return;
    }

    // Finding the maximum g value
    for (int i = 1; i < ng; ++i) { // Adjusted loop for 0-based indexing
        if (g[i] > gmax) gmax = g[i];
    }

    // Calculating sums
    for (int i = 0; i < ng; ++i) { // Adjusted loop for 0-based indexing
        double val = rho * (g[i] - gmax);
        if (val >= toler) {
            sum1 += exp(val) * dgdx[i];
            sum2 += exp(val);
        }
    }

    // Calculating df
    df = (ng > 1) ? sum1 / sum2 : dgdx[0];
}