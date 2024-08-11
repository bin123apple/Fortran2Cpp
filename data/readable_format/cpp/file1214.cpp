#include <iostream>
#include <vector>
#include <cmath>

void sgtsl(int n, std::vector<double>& c, std::vector<double>& d, std::vector<double>& e, std::vector<double>& b, int& info) {
    info = 0;
    int nm1 = n - 1;
    if (nm1 < 1) return;

    for (int k = 0; k < nm1; ++k) {
        int kp1 = k + 1;
        double t;
        if (std::abs(c[k]) >= std::abs(e[k])) {
            t = e[k] / c[k];
            e[k] = c[k];
            c[k] = d[k] - t * e[k];
            d[k] = b[k] - t * d[k];
            b[k] = -t * b[k];
        } else {
            t = c[k] / e[k];
            c[k] = e[k];
            e[k] = d[k] - t * c[k];
            d[k] = b[k] - t * d[k];
            b[k] = -t * b[k];
        }
    }

    b[0] = d[0] / c[0];
    for (int k = 1; k < n; ++k) {
        b[k] = (d[k] - e[k-1] * b[k-1]) / c[k];
    }

    for (int k = n-2; k >= 0; --k) {
        b[k] = b[k] - b[k+1] * e[k] / c[k+1];
    }
}

void printVector(const std::vector<double>& v) {
    for (double val : v) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    int n = 4;
    std::vector<double> c = {1.0, 2.0, 3.0, 4.0};
    std::vector<double> d = {1.0, 2.0, 3.0, 4.0};
    std::vector<double> e = {0.0, 1.0, 1.0, 1.0};
    std::vector<double> b = {5.0, 5.0, 5.0, 5.0};
    int info = 0;

    sgtsl(n, c, d, e, b, info);

    std::cout << "Info: " << info << std::endl;
    std::cout << "Solution vector b: ";
    printVector(b);

    return 0;
}