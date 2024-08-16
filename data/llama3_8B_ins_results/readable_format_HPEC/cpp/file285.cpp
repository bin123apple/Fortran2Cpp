#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void norm2u3(vector<vector<vector<double>>> r, int n1, int n2, int n3, double& rnm2, double& rnmu, int nx, int ny, int nz) {
    double s = 0.0;
    rnmu = 0.0;

    if (timeron) {
        // Start timer
    }

    double dn = 1.0 * nx * ny * nz;

    for (int i3 = 2; i3 < n3 - 1; i3++) {
        for (int i2 = 2; i2 < n2 - 1; i2++) {
            for (int i1 = 2; i1 < n1 - 1; i1++) {
                s += r[i1][i2][i3] * r[i1][i2][i3];
                double a = abs(r[i1][i2][i3]);
                rnmu = max(rnmu, a);
            }
        }
    }

    rnm2 = sqrt(s / dn);

    if (timeron) {
        // Stop timer
    }
}

int main() {
    // Initialize variables
    int n1 = 10;
    int n2 = 10;
    int n3 = 10;
    int nx = 10;
    int ny = 10;
    int nz = 10;
    vector<vector<vector<double>>> r(n1, vector<vector<double>>(n2, vector<double>(n3)));
    double rnm2 = 0.0;
    double rnmu = 0.0;

    // Call the subroutine
    norm2u3(r, n1, n2, n3, rnm2, rnmu, nx, ny, nz);

    // Print the results
    cout << "rnm2: " << rnm2 << endl;
    cout << "rnmu: " << rnmu << endl;

    return 0;
}
