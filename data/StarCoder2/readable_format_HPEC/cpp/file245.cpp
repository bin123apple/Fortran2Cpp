#include <vector>

// Assuming DATA_TYPE is double for this translation
using DATA_TYPE = double;

void init_array(int n, std::vector<std::vector<DATA_TYPE>>& a, std::vector<DATA_TYPE>& x, std::vector<DATA_TYPE>& c) {
    // Resize the vectors to n x n for 'a' and n for 'x', 'c'
    a.resize(n, std::vector<DATA_TYPE>(n));
    x.resize(n);
    c.resize(n);

    for (int i = 0; i < n; ++i) {
        c[i] = static_cast<DATA_TYPE>(i) / static_cast<DATA_TYPE>(n);
        x[i] = static_cast<DATA_TYPE>(i) / static_cast<DATA_TYPE>(n);
        for (int j = 0; j < n; ++j) {
            a[j][i] = (static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j)) / static_cast<DATA_TYPE>(n);
        }
    }
}
