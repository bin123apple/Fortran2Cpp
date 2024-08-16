#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void kernel_gramschmidt(int ni, int nj, vector<vector<double>>& a, vector<vector<double>>& r, vector<vector<double>>& q) {
    for (int k = 0; k < nj; k++) {
        double nrm = 0.0;
        for (int i = 0; i < ni; i++) {
            nrm += a[k][i] * a[k][i];
        }
        r[k][k] = sqrt(nrm);
        for (int i = 0; i < ni; i++) {
            q[k][i] = a[k][i] / r[k][k];
        }
        for (int j = k + 1; j < nj; j++) {
            r[j][k] = 0.0;
            for (int i = 0; i < ni; i++) {
                r[j][k] += q[k][i] * a[j][i];
            }
            for (int i = 0; i < ni; i++) {
                a[j][i] -= q[k][i] * r[j][k];
            }
        }
    }
}
