#include <vector>

// Assuming DATA_TYPE is double for this translation
void init_array(int m, int n, double& float_n, std::vector<std::vector<double>>& dat) {
    float_n = 1.2;
    dat.resize(n, std::vector<double>(m)); // Resize the 2D vector to m x n

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            dat[j][i] = static_cast<double>((i * j) / m);
        }
    }
}
