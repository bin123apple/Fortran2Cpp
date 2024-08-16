#include <vector>

// Assuming DATA_TYPE is double for this translation
void init_array(int n, std::vector<double>& x1, std::vector<double>& x2, std::vector<double>& y1, std::vector<double>& y2, std::vector<std::vector<double>>& a) {
    // Resize vectors to n
    x1.resize(n);
    x2.resize(n);
    y1.resize(n);
    y2.resize(n);
    a.resize(n, std::vector<double>(n));

    for (int i = 0; i < n; ++i) {
        x1[i] = static_cast<double>(i) / static_cast<double>(n);
        x2[i] = (static_cast<double>(i) + 1.0) / static_cast<double>(n);
        y1[i] = (static_cast<double>(i) + 3.0) / static_cast<double>(n);
        y2[i] = (static_cast<double>(i) + 4.0) / static_cast<double>(n);
        for (int j = 0; j < n; ++j) {
            a[j][i] = (static_cast<double>(i) * static_cast<double>(j)) / static_cast<double>(n);
        }
    }
}
