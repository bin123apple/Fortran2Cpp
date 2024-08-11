#include <iostream>
#include <complex>
#include <vector>
#include <random>
#include <algorithm>

const int n = 10;

using ComplexMatrix = std::vector<std::vector<std::complex<float>>>;

void generateRandomMatrix(ComplexMatrix &matrix) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(0.0, 1.0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            float re = dis(gen);
            float im = dis(gen);
            matrix[i][j] = std::complex<float>(re, im);
        }
    }
}

bool matricesAreEqual(const ComplexMatrix &a, const ComplexMatrix &b) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] != b[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ComplexMatrix a(n, std::vector<std::complex<float>>(n));
    ComplexMatrix b(n, std::vector<std::complex<float>>(n));
    ComplexMatrix c(n, std::vector<std::complex<float>>(n));

    generateRandomMatrix(c);

    a = c;
    b = c;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            b[i][j].real(a[i][j].real() - 0.5);
            b[i][j].imag(a[i][j].imag() - 0.5);
            a[i][j].real(a[i][j].real() - 0.5);
            a[i][j].imag(a[i][j].imag() - 0.5);
        }
    }

    if (!matricesAreEqual(a, b)) {
        std::cerr << "Stop 1" << std::endl;
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            b[i][j].imag(a[i][j].real());
            a[i][j].imag(a[i][j].real());
        }
    }

    if (!matricesAreEqual(a, b)) {
        std::cerr << "Stop 2" << std::endl;
        return 2;
    }

    a = c;
    b = c;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            b[i][j].real(a[i - 1][j].real());
            a[i][j].real(a[i - 1][j].real());
        }
    }

    if (!matricesAreEqual(a, b)) {
        std::cerr << "Stop 3" << std::endl;
        return 3;
    }

    a = c;
    b = c;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n; ++j) {
            b[i][j].imag(a[i + 1][j].imag());
            a[i][j].imag(a[i + 1][j].imag());
        }
    }

    if (!matricesAreEqual(a, b)) {
        std::cerr << "Stop 4" << std::endl;
        return 4;
    }

    return 0;
}