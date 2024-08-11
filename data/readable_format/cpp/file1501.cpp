// sphcover.cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <array>
#include <cstdlib>

using Point = std::array<double, 2>;

void sphcover(int n, std::vector<Point>& tp) {
    const double pi = 3.141592653589793;
    if (n <= 0) {
        std::cerr << "Error(sphcover): n <= 0 :" << n << std::endl;
        std::exit(EXIT_FAILURE);
    }

    double dz = 2.0 / n;
    double z = 1.0 - dz / 2.0;
    double dp = pi * (3.0 - std::sqrt(5.0));
    double p = 0.0;

    tp.resize(n);
    for (int k = 0; k < n; ++k) {
        tp[k][0] = std::acos(z);
        tp[k][1] = std::fmod(p, 2.0 * pi);
        z -= dz;
        p += dp;
    }
}

int main() {
    int n = 10;
    std::vector<Point> points;
    sphcover(n, points);

    for (int i = 0; i < n; ++i) {
        std::cout << "Point " << i + 1 << ": Theta = " << points[i][0]
                  << ", Phi = " << points[i][1] << std::endl;
    }

    return 0;
}