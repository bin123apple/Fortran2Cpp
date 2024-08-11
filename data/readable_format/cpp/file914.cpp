#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

void sedivm(int n, float* dx, int incx, float* dy, int incy) {
    if (n <= 0) return;

    int ix = (incx > 0) ? 0 : (-n + 1) * incx;
    int iy = (incy > 0) ? 0 : (-n + 1) * incy;

    for (int i = 0; i < n; ++i) {
        dy[iy] /= dx[ix];
        ix += incx;
        iy += incy;
    }
}

void runTests() {
    // Test 1
    std::vector<float> dx = {1, 2, 3, 4, 5};
    std::vector<float> dy = {10, 20, 30, 40, 50};
    sedivm(5, dx.data(), 1, dy.data(), 1);
    std::cout << "Test 1: ";
    for (auto& val : dy) std::cout << val << " ";
    std::cout << std::endl;

    // Test 2
    dx = {1, 2, 3, 4, 5};
    dy = {5, 10, 15, 20, 25};
    sedivm(3, dx.data(), 2, dy.data(), 2);
    std::cout << "Test 2: ";
    for (auto& val : dy) std::cout << val << " ";
    std::cout << std::endl;

    // Test 3
    dx = {5, 4, 3, 2, 1};
    dy = {50, 40, 30, 20, 10};
    sedivm(5, dx.data(), -1, dy.data(), -1);
    std::cout << "Test 3: ";
    for (auto& val : dy) std::cout << val << " ";
    std::cout << std::endl;
}

int main() {
    runTests();
    return 0;
}