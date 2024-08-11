#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

void zbessela(int lmax, double x, std::vector<double>& a) {
    const int lst = 25;
    double xi, a0, a1, at, t1, t2, xmin;
    if (lmax < 0 || lmax > 50) {
        std::cout << "Error(zbessela): lmax out of range : " << lmax << std::endl;
        exit(1);
    }
    if (x < 0.0 || x > 1e8) {
        std::cout << "Error(zbessela): x out of range : " << x << std::endl;
        exit(1);
    }
    xi = 1.0 / x;
    xmin = 1e-7;
    if (lmax == 0) {
        xmin = 1e-6;
    } else if (lmax <= 2) {
        xmin = 1e-4;
    } else if (lmax <= 4) {
        xmin = 1e-2;
    } else {
        xmin = 1.0;
    }

    if (x < xmin) {
        a[0] = 1.0;
        t1 = 1.0;
        t2 = 1.0;
        for (int l = 1; l <= lmax; ++l) {
            t1 = t1 / static_cast<double>(2*l+1);
            t2 = -t2 * x;
            a[l] = t2 * t1;
        }
        return;
    }

    a[0] = xi * (sinh(x));
    if (lmax == 0) return;
    a[1] = xi * (a[0] - cosh(x));
    if (lmax == 1) return;
    a0 = a[0];
    a1 = a[1];
    for (int l = 2; l <= lmax; ++l) {
        at = static_cast<double>(2*l-1) * a1 * xi + a0;
        a0 = a1;
        a1 = at;
        a[l] = a1;
    }
}

int main() {
    const int lmax = 5;
    double x = 0.5;
    std::vector<double> a(lmax + 1);

    zbessela(lmax, x, a);

    for (int i = 0; i <= lmax; ++i) {
        std::cout << "a[" << i << "] = " << std::setprecision(17) << a[i] << std::endl;
    }

    return 0;
}