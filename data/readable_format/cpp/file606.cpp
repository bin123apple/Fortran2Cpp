#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <iomanip>

void fgauss(double x, const std::vector<double>& a, double& y, std::vector<double>& dyda) {
    y = 0.0;
    int na = a.size();
    dyda.resize(na); // Ensure dyda has the same size as a
    for (int i = 0; i < na - 1; i += 3) {
        double arg = (x - a[i + 1]) / a[i + 2];
        double ex = exp(-arg * arg);
        double fac = a[i] * ex * 2.0 * arg;
        y += a[i] * ex;
        dyda[i] = ex;
        dyda[i + 1] = fac / a[i + 2];
        dyda[i + 2] = fac * arg / a[i + 2];
    }
}

int main() {
    std::vector<double> a = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    double x = 2.5;
    double y;
    std::vector<double> dyda;

    fgauss(x, a, y, dyda);

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Y: " << y << std::endl;
    std::cout << "DYDA:" << std::endl;
    for (size_t i = 0; i < dyda.size(); ++i) {
        std::cout << "dyda[" << i << "]: " << dyda[i] << std::endl;
    }

    // Example of a very basic check
    assert(std::abs(y - 1.35335) < 0.00001); // This threshold is arbitrary and might need adjustment based on expected precision

    return 0;
}