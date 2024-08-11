#include <iostream>
#include <vector>
#include <cmath>

void gauleg(double x1, double x2, std::vector<double>& x, std::vector<double>& w, int n) {
    const double EPS = 3.0e-14;
    int m = (n + 1) / 2;
    double xm = 0.5 * (x2 + x1);
    double xl = 0.5 * (x2 - x1);
    
    for (int i = 0; i < m; i++) { // Corrected the loop to be zero-based
        double z = cos(M_PI * (i + 0.75) / (n + 0.5));
        double pp; // Declare pp at an appropriate scope
        while (true) {
            double p1 = 1.0;
            double p2 = 0.0;
            for (int j = 1; j <= n; j++) {
                double p3 = p2;
                p2 = p1;
                p1 = ((2.0 * j - 1.0) * z * p2 - (j - 1.0) * p3) / j;
            }
            pp = n * (z * p1 - p2) / (z * z - 1.0);
            double z1 = z;
            z = z1 - p1 / pp;
            if (fabs(z - z1) <= EPS) {
                break;
            }
        }
        x[i] = xm - xl * z;
        x[n-i-1] = xm + xl * z;
        w[i] = 2.0 * xl / ((1.0 - z * z) * pp * pp);
        w[n-i-1] = w[i];
    }
}

void testGauleg() {
    int N = 5;
    double X1 = 0.0, X2 = 1.0;
    std::vector<double> X(N), W(N);
    
    gauleg(X1, X2, X, W, N);
    
    std::cout << "X: ";
    for (const auto& xi : X) std::cout << xi << " ";
    std::cout << std::endl;
    
    std::cout << "W: ";
    for (const auto& wi : W) std::cout << wi << " ";
    std::cout << std::endl;
}

int main() {
    testGauleg();
    return 0;
}