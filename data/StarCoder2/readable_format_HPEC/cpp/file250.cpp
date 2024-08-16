#include <vector>

void init_array(int n, std::vector<std::vector<DATA_TYPE>>& a, std::vector<std::vector<DATA_TYPE>>& b) {
    // Resize the vectors to n x n
    a.resize(n, std::vector<DATA_TYPE>(n));
    b.resize(n, std::vector<DATA_TYPE>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[j][i] = (static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j + 1) + 2.0) / n;
            b[j][i] = (static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j + 2) + 3.0) / n;
        }
    }
}
