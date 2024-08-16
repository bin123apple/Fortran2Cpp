#include <vector>
#include <cmath> // For std::pow

// Assuming DATA_TYPE is double for this translation
using DATA_TYPE = double;

void init_array(int n, std::vector<std::vector<DATA_TYPE>>& a, std::vector<DATA_TYPE>& b, std::vector<DATA_TYPE>& x, std::vector<DATA_TYPE>& y) {
    // Resize vectors to n + 1 to accommodate 0-based indexing
    a.resize(n + 1, std::vector<DATA_TYPE>(n + 1));
    x.resize(n + 1);
    b.resize(n + 1);
    y.resize(n + 1);

    for (int i = 0; i <= n; ++i) {
        x[i] = static_cast<DATA_TYPE>(i + 1); // Adjusting for 0-based indexing
        y[i] = (static_cast<DATA_TYPE>(i + 1) / n / 2.0) + 1.0;
        b[i] = (static_cast<DATA_TYPE>(i + 1) / n / 2.0) + 42.0;
        for (int j = 0; j <= n; ++j) {
            a[j][i] = (static_cast<DATA_TYPE>(i + 1) * static_cast<DATA_TYPE>(j + 1)) / static_cast<DATA_TYPE>(n);
        }
    }
}
