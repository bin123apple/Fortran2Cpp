#include <iostream>
#include <vector>
#include <stdexcept>

void splintd(const std::vector<float>& xa, const std::vector<float>& ya, const std::vector<float>& y2a, int n, float x, float& y) {
    static int klo = 1, khi = 1;
    int k;
    float a, b, h;

    if (khi <= n) {
        if (xa[khi] > x && xa[klo] < x && khi - klo == 1) {
            goto step2;
        }
    }

    klo = 1;
    khi = n;
step1:
    if (khi - klo > 1) {
        k = (khi + klo) / 2;
        if (xa[k] > x) {
            khi = k;
        } else {
            klo = k;
        }
        goto step1;
    }

step2:
    h = xa[khi] - xa[klo];
    if (h <= 0) {
        throw std::runtime_error("bad xa input in splint");
    }

    a = (xa[khi] - x) / h;
    b = (x - xa[klo]) / h;
    y = a * ya[klo] + b * ya[khi] + ((a * a * a - a) * y2a[klo] + (b * b * b - b) * y2a[khi]) * (h * h) / 6.0f;
}

int main() {
    // Example usage
    std::vector<float> xa = {0.0f, 1.0f, 2.0f, 3.0f};
    std::vector<float> ya = {0.0f, 1.0f, 4.0f, 9.0f};
    std::vector<float> y2a = {0.0f, 0.5f, 1.0f, 1.5f};
    int n = xa.size();
    float x = 1.5f;
    float y;

    try {
        splintd(xa, ya, y2a, n, x, y);
        std::cout << "Interpolated value at x = " << x << " is y = " << y << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}