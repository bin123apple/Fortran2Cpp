#include <vector>

void sescalm(int n, const std::vector<float>& dx, int incx, std::vector<float>& dy, int incy) {
    if (n <= 0) return;

    int ix = 0, iy = 0;

    if (incx == 1 && incy == 1) {
        for (int i = 0; i < n; ++i) {
            dy[i] *= dx[i];
        }
    } else {
        if (incx < 0) ix = (-n + 1) * incx;
        if (incy < 0) iy = (-n + 1) * incy;

        for (int i = 0; i < n; ++i) {
            dy[iy] *= dx[ix];
            ix += incx;
            iy += incy;
        }
    }
}

// Example usage
int main() {
    int n = 5;
    std::vector<float> dx = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<float> dy = {1.0, 1.0, 1.0, 1.0, 1.0};
    int incx = 1;
    int incy = 1;

    sescalm(n, dx, incx, dy, incy);

    for (auto val : dy) {
        std::cout << val << " ";
    }

    return 0;
}