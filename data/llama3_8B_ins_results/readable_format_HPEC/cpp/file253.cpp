#include <iostream>
#include <vector>

using namespace std;

void kernel_gesummv(int n, double alpha, double beta, vector<vector<double>>& a, vector<double>& x, vector<double>& y, vector<double>& tmp) {
    for (int i = 0; i < n; i++) {
        tmp[i] = 0.0;
        y[i] = 0.0;
    }

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            tmp[i] += a[j][i] * x[j];
            y[i] += b[j][i] * x[j];
        }
    }

    for (int i = 0; i < n; i++) {
        y[i] = alpha * tmp[i] + beta * y[i];
    }
}

int main() {
    int n = 10; // adjust this value as needed
    double alpha = 1.0;
    double beta = 2.0;

    vector<vector<double>> a(n, vector<double>(n));
    vector<double> x(n);
    vector<double> y(n);
    vector<double> tmp(n);

    // initialize a, x, y, and tmp arrays (not shown)

    kernel_gesummv(n, alpha, beta, a, x, y, tmp);

    // print or use the results as needed

    return 0;
}
