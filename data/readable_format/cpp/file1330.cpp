// laplace_corrected.cpp
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int N1 = 64, N2 = 64;
const double PI = 3.141592653589793238463;

double laplace() {
    int niter = 100;
    vector<vector<double>> u(N1, vector<double>(N2, 0.0));
    vector<vector<double>> uu(N1, vector<double>(N2, 0.0));
    double value = 0.0;

    // Boundary conditions
    for(int j = 1; j < N2 - 1; ++j) {
        for(int i = 1; i < N1 - 1; ++i) {
            u[i][j] = sin(static_cast<double>(i) / N1 * PI) + cos(static_cast<double>(j) / N2 * PI);
        }
    }

    // Main iteration
    for(int k = 0; k < niter; ++k) {
        uu = u;
        for(int j = 1; j < N2 - 1; ++j) {
            for(int i = 1; i < N1 - 1; ++i) {
                u[i][j] = (uu[i-1][j] + uu[i+1][j] + uu[i][j-1] + uu[i][j+1]) / 4.0;
            }
        }
    }

    // Compute the verification value
    for(int j = 1; j < N2 - 1; ++j) {
        for(int i = 1; i < N1 - 1; ++i) {
            value += fabs(uu[i][j] - u[i][j]);
        }
    }

    return value;
}

int main() {
    double value = laplace();
    cout << "Verification = " << value << endl;
    return 0;
}