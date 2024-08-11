#include <iostream>
#include <vector>
#include <complex>
#include <cassert>

float scasum(int n, const std::vector<std::complex<float>>& cx, int incx) {
    float stemp = 0.0f;

    if (n <= 0 || incx <= 0) {
        return 0.0f;
    }

    if (incx == 1) {
        for (int i = 0; i < n; ++i) {
            stemp += std::abs(cx[i].real()) + std::abs(cx[i].imag());
        }
    } else {
        for (int i = 0; i < n * incx; i += incx) {
            stemp += std::abs(cx[i].real()) + std::abs(cx[i].imag());
        }
    }

    return stemp;
}

int main() {
    std::vector<std::complex<float>> cx = {
        {1.0f, 2.0f},
        {3.0f, -4.0f},
        {-5.0f, 6.0f},
        {-7.0f, -8.0f},
        {9.0f, 10.0f}
    };

    int n = 5;
    int incx = 1;

    // Test with incx = 1
    float result = scasum(n, cx, incx);
    std::cout << "Result for scasum with incx=1: " << result << std::endl;
    assert(result == 55.0f);

    // Test with incx = 2
    result = scasum(3, cx, incx = 2);
    std::cout << "Result for scasum with incx=2: " << result << std::endl;
    assert(result == 33.0f);

    std::cout << "All tests passed." << std::endl;
    return 0;
}