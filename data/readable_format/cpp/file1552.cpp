#include <iostream>
#include <vector>

void spline(const std::vector<double>& x, const std::vector<double>& y, int n, double yp1, double ypn, std::vector<double>& y2, std::vector<double>& u) {
    double p, qn, sig, un;
    
    if (yp1 > 0.99e30) {
        y2[0] = u[0] = 0.0;
    } else {
        y2[0] = -0.5;
        u[0] = (3.0 / (x[1] - x[0])) * ((y[1] - y[0]) / (x[1] - x[0]) - yp1);
    }
    
    for (int i = 1; i < n - 1; i++) {
        sig = (x[i] - x[i-1]) / (x[i+1] - x[i-1]);
        p = sig * y2[i-1] + 2.0;
        y2[i] = (sig - 1.0) / p;
        u[i] = (6.0 * ((y[i+1] - y[i]) / (x[i+1] - x[i]) - (y[i] - y[i-1]) / (x[i] - x[i-1])) / (x[i+1] - x[i-1]) - sig * u[i-1]) / p;
    }
    
    if (ypn > 0.99e30) {
        qn = un = 0.0;
    } else {
        qn = 0.5;
        un = (3.0 / (x[n-1] - x[n-2])) * (ypn - (y[n-1] - y[n-2]) / (x[n-1] - x[n-2]));
    }
    y2[n-1] = (un - qn * u[n-2]) / (qn * y2[n-2] + 1.0);
    
    for (int k = n - 2; k >= 0; k--) {
        y2[k] = y2[k] * y2[k+1] + u[k];
    }
}

void testSpline() {
    std::vector<double> x = {0.0, 1.0, 2.0, 3.0, 4.0};
    std::vector<double> y = {0.0, 0.8415, 0.9093, 0.1411, -0.7568};
    int n = x.size();
    double yp1 = 1.0, ypn = -1.0;
    std::vector<double> y2(n), u(n);

    spline(x, y, n, yp1, ypn, y2, u);

    std::cout << "y2 = ";
    for (double val : y2) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    testSpline();
    return 0;
}