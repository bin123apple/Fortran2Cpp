#include <iostream>
#include <vector>
#include <cmath>

const double tiny = 1.0e-20;

void ludcmp(std::vector<std::vector<double>>& a, int n, std::vector<int>& indx, double& d) {
    std::vector<double> vv(n);
    d = 1.0;

    for (int i = 0; i < n; i++) {
        double aamax = 0.0;
        for (int j = 0; j < n; j++) {
            if (fabs(a[i][j]) > aamax) aamax = fabs(a[i][j]);
        }
        if (aamax == 0.0) aamax = 1.0e-6;
        vv[i] = 1.0 / aamax;
    }

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < j; i++) {
            double sum = a[i][j];
            for (int k = 0; k < i; k++) {
                sum -= a[i][k] * a[k][j];
            }
            a[i][j] = sum;
        }

        double aamax = 0.0;
        int imax = 0;
        for (int i = j; i < n; i++) {
            double sum = a[i][j];
            for (int k = 0; k < j; k++) {
                sum -= a[i][k] * a[k][j];
            }
            a[i][j] = sum;

            double dum = vv[i] * fabs(sum);
            if (dum >= aamax) {
                imax = i;
                aamax = dum;
            }
        }

        if (j != imax) {
            for (int k = 0; k < n; k++) {
                double dum = a[imax][k];
                a[imax][k] = a[j][k];
                a[j][k] = dum;
            }
            d = -d;
            vv[imax] = vv[j];
        }

        indx[j] = imax;
        if (a[j][j] == 0.0) a[j][j] = tiny;
        if (j != n - 1) {
            double dum = 1.0 / a[j][j];
            for (int i = j + 1; i < n; i++) {
                a[i][j] *= dum;
            }
        }
    }
}

void printMatrix(const std::vector<std::vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n = 3;
    std::vector<std::vector<double>> a = {
        {1.0, 2.0, 3.0},
        {2.0, 3.0, 4.0},
        {3.0, 4.0, 5.0}
    };
    std::vector<int> indx(n);
    double d;

    ludcmp(a, n, indx, d);

    std::cout << "Decomposed matrix:" << std::endl;
    printMatrix(a);

    return 0;
}