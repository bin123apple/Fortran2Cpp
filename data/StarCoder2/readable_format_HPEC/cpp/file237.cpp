#include <vector>

void init_array(int n, std::vector<std::vector<DATA_TYPE>>& path) {
    // Resize the path vector to have n rows and columns
    path.resize(n, std::vector<DATA_TYPE>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            path[j][i] = static_cast<DATA_TYPE>((i + 1) * (j + 1)) / static_cast<DATA_TYPE>(n);
        }
    }
}
