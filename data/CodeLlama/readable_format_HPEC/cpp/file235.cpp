#include <cmath>
#include <vector>

// Assuming DATA_TYPE is double for this translation
using DATA_TYPE = double;

void init_array(int nx, int ny, std::vector<std::vector<DATA_TYPE>>& a, std::vector<DATA_TYPE>& r, std::vector<DATA_TYPE>& p) {
    const DATA_TYPE M_PI = 3.14159265358979323846;

    // Resize vectors to match dimensions
    a.resize(ny, std::vector<DATA_TYPE>(nx));
    r.resize(nx);
    p.resize(ny);

    // Initialize p
    for (int i = 0; i < ny; ++i) {
        p[i] = static_cast<DATA_TYPE>(i) * M_PI;
    }

    // Initialize r and a
    for (int i = 0; i < nx; ++i) {
        r[i] = static_cast<DATA_TYPE>(i) * M_PI;
        for (int j = 0; j < ny; ++j) {
            a[j][i] = (static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j)) / nx;
        }
    }
}
