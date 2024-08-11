#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath> // Ensure cmath is included for fmod

void saxpy(int n, float sa, const std::vector<float>& sx, int incx, std::vector<float>& sy, int incy) {
    if (n <= 0) return;
    if (sa == 0.0f) return;

    if (incx == 1 && incy == 1) {
        // Use fmod without the std:: prefix
        int m = static_cast<int>(fmod(n, 4));
        if (m != 0) {
            for (int i = 0; i < m; ++i) {
                sy[i] = sy[i] + sa * sx[i];
            }
        }
        if (n < 4) return;
        int mp1 = m + 1;
        for (int i = mp1 - 1; i < n; i += 4) {
            sy[i] = sy[i] + sa * sx[i];
            sy[i + 1] = sy[i + 1] + sa * sx[i + 1];
            sy[i + 2] = sy[i + 2] + sa * sx[i + 2];
            sy[i + 3] = sy[i + 3] + sa * sx[i + 3];
        }
    } else {
        int ix = 0;
        int iy = 0;
        if (incx < 0) ix = (-n + 1) * incx;
        if (incy < 0) iy = (-n + 1) * incy;
        for (int i = 0; i < n; ++i) {
            sy[iy] = sy[iy] + sa * sx[ix];
            ix += incx;
            iy += incy;
        }
    }
}

int main() {
    std::vector<float> sx = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    std::vector<float> sy = {5.0f, 4.0f, 3.0f, 2.0f, 1.0f};

    // Call SAXPY with n=5, sa=2.0, incx=1, incy=1
    saxpy(5, 2.0f, sx, 1, sy, 1);

    // Print the result
    std::cout << "SY = ";
    for (float val : sy) {
        std::cout << std::fixed << std::setprecision(1) << val << " ";
    }
    std::cout << std::endl;

    return 0;
}