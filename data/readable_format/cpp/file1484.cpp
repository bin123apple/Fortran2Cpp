#include <iostream>
#include <vector>
#include <cassert>

void dswap(int n, double* dx, int incx, double* dy, int incy) {
    if (n <= 0) return;
    int ix = (incx > 0) ? 0 : ((-n + 1) * incx);
    int iy = (incy > 0) ? 0 : ((-n + 1) * incy);
    for (int i = 0; i < n; ++i) {
        std::swap(dx[ix], dy[iy]);
        ix += incx;
        iy += incy;
    }
}

void testDswap() {
    // Test 1: Simple swap
    std::vector<double> dx1 = {1, 2, 3, 4, 5};
    std::vector<double> dy1 = {5, 4, 3, 2, 1};
    dswap(dx1.size(), dx1.data(), 1, dy1.data(), 1);
    assert(dx1 == std::vector<double>({5, 4, 3, 2, 1}));
    assert(dy1 == std::vector<double>({1, 2, 3, 4, 5}));

    // Test 2: Strided swap
    std::vector<double> dx2 = {1, 2, 3, 4, 5};
    std::vector<double> dy2 = {5, 4, 3, 2, 1};
    dswap(3, dx2.data(), 2, dy2.data(), 2);  // Adjusted to affect only 3 elements due to stride
    assert(dx2 == std::vector<double>({5, 2, 3, 4, 1}));
    assert(dy2 == std::vector<double>({1, 4, 3, 2, 5}));

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    testDswap();
    return 0;
}