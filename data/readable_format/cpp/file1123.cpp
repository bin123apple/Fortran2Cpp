// ddot.cpp
#include <iostream>
#include <vector>

double ddot(int n, const double* dx, int incx, const double* dy, int incy) {
    double dot_product = 0.0;
    int ix = 0;
    int iy = 0;
    for (int i = 0; i < n; i++) {
        dot_product += dx[ix] * dy[iy];
        ix += incx;
        iy += incy;
    }
    return dot_product;
}

int main() {
    // Test 1
    std::vector<double> dx = {1, 2, 3, 4, 5};
    std::vector<double> dy = {1, 2, 3, 4, 5};
    double result = ddot(5, dx.data(), 1, dy.data(), 1);
    std::cout << "C++ Test 1: " << result << " (Expected: 55)" << std::endl;

    return 0;
}