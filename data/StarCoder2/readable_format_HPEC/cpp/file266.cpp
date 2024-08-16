#include <vector>

void init_array(int n, std::vector<std::vector<double>>& a) {
    // Resize the vector to have n x n elements
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        a[i].resize(n);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[j][i] = static_cast<double>(i + 1) * static_cast<double>(j + 1) / static_cast<double>(n);
        }
    }
}
