#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

void dswap(int N, double* dx, int strideX, double* dy, int strideY) {
    if (N <= 0) {
        return;
    }

    if (strideX == 1 && strideY == 1) {
        for (int i = 0; i < N; i++) {
            std::swap(dx[i], dy[i]);
        }
    } else {
        int ix = (strideX < 0) ? (N - 1) * strideX : 0;
        int iy = (strideY < 0) ? (N - 1) * strideY : 0;

        for (int i = 0; i < N; ++i) {
            std::swap(dx[ix], dy[iy]);
            ix += strideX;
            iy += strideY;
        }
    }
}

int main() {
    // Example unit test for dswap function
    std::vector<double> dx = {1, 2, 3};
    std::vector<double> dy = {4, 5, 6};
    dswap(3, dx.data(), 1, dy.data(), 1);
    assert(dx == std::vector<double>({4, 5, 6}) && dy == std::vector<double>({1, 2, 3}));
    
    // Add more tests here as needed

    std::cout << "C++ code: All tests passed." << std::endl;
    return 0;
}