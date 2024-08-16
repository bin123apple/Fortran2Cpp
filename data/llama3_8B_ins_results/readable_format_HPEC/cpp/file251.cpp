#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void kernel_correlation(int m, int n, double float_n, vector<vector<double>>& dat, vector<vector<double>>& symmat, vector<double>& mean, vector<double>& stddev) {
    double EPS = 0.1;

    // Determine mean of column vectors of input data matrix
    for (int j = 0; j < m; j++) {
        mean[j] = 0.0;
        for (int i = 0; i < n; i++) {
            mean[j] += dat[j][i];
        }
        mean[j] /= float_n;
    }

    // Determine standard deviations of column vectors of data matrix
    for (int j = 0; j < m; j++) {
        stddev[j] = 0.0;
        for (int i = 0; i < n; i++) {
            stddev[j] += (dat[j][i] - mean[j]) * (dat[j][i] - mean[j]);
        }
        stddev[j] /= float_n;
        stddev[j] = sqrt(stddev[j]);
        if (stddev[j] <= EPS) {
            stddev[j] = 1.0;
        }
    }

    // Center and reduce the column vectors
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dat[j][i] -= mean[j];
            dat[j][i] /= (sqrt(float_n) * stddev[j]);
        }
    }

    // Calculate the m * m correlation matrix
    for (int j1 = 0; j1 < m - 1; j1++) {
        symmat[j1][j1] = 1.0;
        for (int j2 = j1 + 1; j2 < m; j2++) {
            symmat[j2][j1] = 0.0;
        }
        for (int i = 0; i < n; i++) {
            symmat[j2][j1] += dat[j1][i] * dat[j2][i];
        }
        symmat[j1][j2] = symmat[j2][j1];
    }
    symmat[m - 1][m - 1] = 1.0;
}
