#include <vector>
#include <cmath>

// Assuming DATA_TYPE is double for this translation
using DATA_TYPE = double;

void init_array(int n, DATA_TYPE& alpha, DATA_TYPE& beta, std::vector<std::vector<DATA_TYPE>>& a, std::vector<std::vector<DATA_TYPE>>& b, std::vector<DATA_TYPE>& x) {
    alpha = 43532.0;
    beta = 12313.0;

    // Resize vectors to match dimensions n x n for a and b, and n for x
    a.resize(n, std::vector<DATA_TYPE>(n));
    b.resize(n, std::vector<DATA_TYPE>(n));
    x.resize(n);

    for (int i = 0; i < n; ++i) {
        x[i] = static_cast<DATA_TYPE>(i) / static_cast<DATA_TYPE>(n);
        for (int j = 0; j < n; ++j) {
            a[j][i] = (static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j)) / static_cast<DATA_TYPE>(n);
            b[j][i] = (static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j)) / static_cast<DATA_TYPE>(n);
        }
    }
}
