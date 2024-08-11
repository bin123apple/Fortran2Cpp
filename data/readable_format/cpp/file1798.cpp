#include <iostream>
#include <complex>
#include <vector>
#include <cmath>
#include <cassert>

void zlassq(int n, const std::vector<std::complex<double>>& x, int incx, double& scale, double& sumsq) {
    double temp1;
    
    if (n > 0) {
        for (int ix = 0; ix < n; ix += incx) {
            // Process the real part
            temp1 = std::abs(std::real(x[ix]));
            if (temp1 != 0) {
                if (scale < temp1) {
                    sumsq = 1 + sumsq * (scale / temp1) * (scale / temp1);
                    scale = temp1;
                } else {
                    sumsq += (temp1 / scale) * (temp1 / scale);
                }
            }
            // Process the imaginary part
            temp1 = std::abs(std::imag(x[ix]));
            if (temp1 != 0) {
                if (scale < temp1) {
                    sumsq = 1 + sumsq * (scale / temp1) * (scale / temp1);
                    scale = temp1;
                } else {
                    sumsq += (temp1 / scale) * (temp1 / scale);
                }
            }
        }
    }
}

int main() {
    std::vector<std::complex<double>> x = {{3.0, 4.0}, {5.0, 12.0}};
    int n = x.size();
    int incx = 1;
    double scale = 0.0;
    double sumsq = 0.0;

    zlassq(n, x, incx, scale, sumsq);

    std::cout << "Scale: " << scale << ", Sumsq: " << sumsq << std::endl;

    // Assertions to ensure correctness
    assert(std::abs(scale - 12.0) < 1e-6);
    assert(std::abs(sumsq - 1.3472222222222223) < 1e-6);

    std::cout << "Passed all assertions." << std::endl;

    return 0;
}