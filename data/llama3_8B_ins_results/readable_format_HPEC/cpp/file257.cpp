#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void kernel_cholesky(int n, vector<vector<double>>& a, vector<double>& p) {
    for (int i = 1; i <= n; i++) {
        double x = a[i-1][i-1];
        for (int j = 1; j < i; j++) {
            x -= a[j-1][i-1] * a[j-1][i-1];
        }
        p[i-1] = 1.0 / sqrt(x);
        for (int j = i; j <= n; j++) {
            double x = a[j-1][i-1];
            for (int k = 1; k < i; k++) {
                x -= a[k-1][j-1] * a[k-1][i-1];
            }
            a[j-1][i-1] = x * p[i-1];
        }
    }
}
