#include <vector>

// Assuming DATA_TYPE is double for this translation
using DATA_TYPE = double;

void init_array(int n, std::vector<std::vector<DATA_TYPE>>& x, std::vector<std::vector<DATA_TYPE>>& a, std::vector<std::vector<DATA_TYPE>>& b) {
    // Resize the vectors to n x n
    x.resize(n, std::vector<DATA_TYPE>(n));
    a.resize(n, std::vector<DATA_TYPE>(n));
    b.resize(n, std::vector<DATA_TYPE>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            x[j][i] = (static_cast<DATA_TYPE>((i) * (j + 1)) + 1.0) / static_cast<DATA_TYPE>(n);
            a[j][i] = (static_cast<DATA_TYPE>((i) * (j + 2)) + 2.0) / static_cast<DATA_TYPE>(n);
            b[j][i] = (static_cast<DATA_TYPE>((i) * (j + 3)) + 3.0) / static_cast<DATA_TYPE>(n);
        }
    }
}
