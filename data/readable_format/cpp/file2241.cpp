#include <iostream>
#include <vector>

double ddot(int n, const std::vector<double>& dx, int incx, const std::vector<double>& dy, int incy) {
    double dtemp = 0.0;

    if (n <= 0) return 0.0;

    if (incx == 1 && incy == 1) {
        int m = n % 5;
        if (m != 0) {
            for (int i = 0; i < m; ++i) {
                dtemp += dx[i] * dy[i];
            }
            if (n < 5) {
                return dtemp;
            }
        }
        for (int i = m; i < n; i += 5) {
            dtemp += dx[i] * dy[i] + dx[i+1] * dy[i+1] + dx[i+2] * dy[i+2] + dx[i+3] * dy[i+3] + dx[i+4] * dy[i+4];
        }
    } else {
        int ix = (incx < 0) ? (-n + 1) * incx + 1 : 0;
        int iy = (incy < 0) ? (-n + 1) * incy + 1 : 0;
        for (int i = 0; i < n; ++i) {
            dtemp += dx[ix] * dy[iy];
            ix += incx;
            iy += incy;
        }
    }

    return dtemp;
}

int main() {
    // Example usage
    std::vector<double> dx = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<double> dy = {5.0, 4.0, 3.0, 2.0, 1.0};
    int n = 5;
    int incx = 1;
    int incy = 1;

    double result = ddot(n, dx, incx, dy, incy);
    std::cout << "DDOT result: " << result << std::endl;

    return 0;
}