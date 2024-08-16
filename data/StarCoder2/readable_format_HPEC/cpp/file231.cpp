#include <vector>
#include <cmath>

void init_array(int nx, int ny, std::vector<std::vector<double>>& a, std::vector<double>& r, std::vector<double>& p) {
    const double M_PI = 3.14159265358979323846;

    // Initialize p array
    for (int i = 0; i < ny; ++i) {
        p[i] = static_cast<double>(i) * M_PI;
    }

    // Initialize r array and a matrix
    for (int i = 0; i < nx; ++i) {
        r[i] = static_cast<double>(i) * M_PI;
        for (int j = 0; j < ny; ++j) {
            a[j][i] = (static_cast<double>(i) * static_cast<double>(j)) / nx;
        }
    }
}
