#include <iostream>
#include <complex>
#include <vector>

// Define the zdscal function directly in the file
void zdscal(int n, double da, std::vector<std::complex<double>>& zx, int incx) {
    if (n <= 0 || incx <= 0) return;

    if (incx == 1) {
        for (int i = 0; i < n; ++i) {
            zx[i] *= std::complex<double>(da, 0.0);
        }
    } else {
        int nincx = n * incx;
        for (int i = 0; i < nincx; i += incx) {
            zx[i] *= std::complex<double>(da, 0.0);
        }
    }
}

void printVector(const std::vector<std::complex<double>>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << "zx[" << i << "] = " << v[i] << std::endl;
    }
}

int main() {
    int n = 5;
    double da = 2.0;
    int incx = 1;
    std::vector<std::complex<double>> zx(n);

    // Initialize zx with some values
    for (int i = 0; i < n; ++i) {
        zx[i] = std::complex<double>(i + 1, i + 1);
    }

    // Call zdscal
    zdscal(n, da, zx, incx);

    // Output the result
    std::cout << "Result:" << std::endl;
    printVector(zx);

    return 0;
}