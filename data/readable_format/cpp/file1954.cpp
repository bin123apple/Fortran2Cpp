#include <iostream>
#include <vector>
#include <cmath>

// Function declaration
void loop16_F77(int N, std::vector<double>& x, const std::vector<double>& a, const std::vector<double>& b, const std::vector<double>& c, std::vector<double>& y, double u);

int main() {
    int N = 5;
    std::vector<double> x(N), a(N), b(N), c(N), y(N);
    double u = 2.0;

    // Initialize vectors a, b, c
    for(int i = 0; i < N; ++i) {
        a[i] = 1.0 * (i + 1);
        b[i] = 2.0 * (i + 1);
        c[i] = 3.0 * (i + 1);
    }

    loop16_F77(N, x, a, b, c, y, u);

    // Check results and display output
    for(int i = 0; i < N; ++i) {
        std::cout << "y(" << i << ") = " << y[i] << std::endl;
    }

    return 0;
}

void loop16_F77(int N, std::vector<double>& x, const std::vector<double>& a, const std::vector<double>& b, const std::vector<double>& c, std::vector<double>& y, double u) {
    for(int i = 0; i < N; ++i) {
        x[i] = a[i] + b[i] + c[i];
        y[i] = x[i] + c[i] + u;
    }
}