#include <vector>

void init_array(int tmax, int nx, int ny, std::vector<double>& fict, std::vector<std::vector<double>>& ex, std::vector<std::vector<double>>& ey, std::vector<std::vector<double>>& hz) {
    // Initialize fict array
    for (int i = 0; i < tmax; ++i) {
        fict[i] = static_cast<double>(i);
    }

    // Initialize ex, ey, hz arrays
    for (int i = 0; i < nx; ++i) {
        for (int j = 0; j < ny; ++j) {
            ex[j][i] = (static_cast<double>((i) * (j + 1))) / static_cast<double>(nx);
            ey[j][i] = (static_cast<double>((i) * (j + 2))) / static_cast<double>(ny);
            hz[j][i] = (static_cast<double>((i) * (j + 3))) / static_cast<double>(nx);
        }
    }
}
