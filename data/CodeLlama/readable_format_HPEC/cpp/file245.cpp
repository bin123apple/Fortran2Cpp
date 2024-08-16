#include <vector>
#include <cmath>

// Assuming DATA_TYPE is a placeholder for the actual data type.
// You can replace it with float, double, or any other appropriate type.
using DATA_TYPE = double;

void init_array(int n, std::vector<std::vector<DATA_TYPE>>& a, std::vector<DATA_TYPE>& x, std::vector<DATA_TYPE>& b, std::vector<DATA_TYPE>& y) {
    // Resize vectors to match the dimensions in Fortran code (n + 1, n + 1)
    a.resize(n + 1, std::vector<DATA_TYPE>(n + 1));
    x.resize(n + 1);
    b.resize(n + 1);
    y.resize(n + 1);

    for (int i = 0; i < n + 1; ++i) {
        x[i] = static_cast<DATA_TYPE>(i + 1); // Adjust for 0-based indexing
        y[i] = (i / static_cast<DATA_TYPE>(n) / 2.0) + 1.0;
        b[i] = (i / static_cast<DATA_TYPE>(n) / 2.0) + 42.0;
        for (int j = 0; j < n + 1; ++j) {
            a[j][i] = (static_cast<DATA_TYPE>(i + 1) * static_cast<DATA_TYPE>(j + 1)) / static_cast<DATA_TYPE>(n);
        }
    }
}
