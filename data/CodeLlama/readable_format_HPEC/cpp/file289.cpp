#include <cmath>
#include <algorithm>
#include <vector>

void norm2u3(const std::vector<std::vector<std::vector<double>>>& r, 
              int n1, int n2, int n3, 
              double& rnm2, double& rnmu, 
              int nx, int ny, int nz, 
              bool timeron) {
    double s = 0.0;
    double a = 0.0;
    double dn = 1.0 * nx * ny * nz;

    if (timeron) {
        // Start timer
    }

    for (int i3 = 1; i3 < n3 - 1; ++i3) {
        for (int i2 = 1; i2 < n2 - 1; ++i2) {
            for (int i1 = 1; i1 < n1 - 1; ++i1) {
                s += r[i1][i2][i3] * r[i1][i2][i3];
                a = std::max(a, std::abs(r[i1][i2][i3]));
            }
        }
    }

    rnm2 = std::sqrt(s / dn);
    rnmu = a;

    if (timeron) {
        // Stop timer
    }
}

int main() {
    // Example usage
    int n1 = 10, n2 = 10, n3 = 10;
    int nx = 10, ny = 10, nz = 10;
    bool timeron = true;
    double rnm2, rnmu;

    std::vector<std::vector<std::vector<double>>> r(n1, std::vector<std::vector<double>>(n2, std::vector<double>(n3, 0.0)));

    // Initialize r with some values
    // ...

    norm2u3(r, n1, n2, n3, rnm2, rnmu, nx, ny, nz, timeron);

    return 0;
}
