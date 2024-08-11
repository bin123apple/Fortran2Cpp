#include <cassert>
#include <complex>
#include <iostream>
#include <vector>

void cla_wwaddw(int n, std::vector<std::complex<double>>& x, std::vector<std::complex<double>>& y, const std::vector<std::complex<double>>& w) {
    for (int i = 0; i < n; ++i) {
        auto s = x[i] + w[i];
        y[i] = ((x[i] - s) + w[i]) + y[i];
        x[i] = s;
    }
}

int main() {
    std::vector<std::complex<double>> x = {{1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}};
    std::vector<std::complex<double>> y = {{7.0, 8.0}, {9.0, 10.0}, {11.0, 12.0}};
    const std::vector<std::complex<double>> w = {{0.5, 1.5}, {2.5, 3.5}, {4.5, 5.5}};
    int n = 3;

    cla_wwaddw(n, x, y, w);

    // Output results for verification
    std::cout << "X:" << std::endl;
    for (const auto& val : x) {
        std::cout << val.real() << ", " << val.imag() << std::endl;
    }

    std::cout << "Y:" << std::endl;
    for (const auto& val : y) {
        std::cout << val.real() << ", " << val.imag() << std::endl;
    }

    return 0;
}