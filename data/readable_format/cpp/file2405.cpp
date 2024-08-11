// dcovarxy.cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

void dcovarxy(const std::vector<std::vector<double>>& x, 
              const std::vector<std::vector<double>>& y, 
              double xmsg, double ymsg, 
              std::vector<std::vector<double>>& cxy, 
              int n, int m, int lag, int ncrit, int iopt) {
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            double nxy = 0.0;
            double sumx = 0.0, sumy = 0.0, sumxy = 0.0, sumxx = 0.0, sumyy = 0.0;

            for (int k = lag; k < n; k++) {
                if (x[k][i] != xmsg && y[k - lag][j] != ymsg) {
                    ++nxy;
                    sumx += x[k][i];
                    sumy += y[k - lag][j];
                    sumxy += x[k][i] * y[k - lag][j];
                    sumxx += x[k][i] * x[k][i];
                    sumyy += y[k - lag][j] * y[k - lag][j];
                }
            }

            if (nxy >= ncrit) {
                cxy[i][j] = (sumxy - (sumx * sumy) / nxy) / (nxy - 1.0);

                if (iopt == 1) {
                    double xvar = (sumxx - (sumx * sumx) / nxy) / (nxy - 1.0);
                    double yvar = (sumyy - (sumy * sumy) / nxy) / (nxy - 1.0);
                    cxy[i][j] = cxy[i][j] / (sqrt(xvar) * sqrt(yvar));
                }
            } else {
                cxy[i][j] = xmsg;
            }
        }
    }
}

int main() {
    const int n = 5;
    const int m = 2;
    const int lag = 1;
    const int ncrit = 1;
    const int iopt = 0;
    const double xmsg = -999.0;
    const double ymsg = -999.0;

    std::vector<std::vector<double>> x = {{1.0, 2.0, 3.0, 4.0, 5.0},
                                          {2.0, 3.0, 4.0, 5.0, 6.0}};
    std::vector<std::vector<double>> y = {{5.0, 4.0, 3.0, 2.0, 1.0},
                                          {6.0, 5.0, 4.0, 3.0, 2.0}};
    std::vector<std::vector<double>> cxy(m, std::vector<double>(m, 0.0));

    // Transpose x and y to match Fortran's column-major order in memory layout
    std::vector<std::vector<double>> xt(n, std::vector<double>(m)), yt(n, std::vector<double>(m));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            xt[j][i] = x[i][j];
            yt[j][i] = y[i][j];
        }
    }

    dcovarxy(xt, yt, xmsg, ymsg, cxy, n, m, lag, ncrit, iopt);

    std::cout << "C++ cxy:" << std::endl;
    std::cout << std::fixed << std::setprecision(15);
    for (const auto& row : cxy) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}