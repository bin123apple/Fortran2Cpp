#include <vector>

// Assuming DATA_TYPE is double for this example
void init_array(int n, std::vector<double>& a, std::vector<double>& b) {
    for (int i = 0; i < n; ++i) {
        a[i] = (static_cast<double>(i) + 2.0) / n;
        b[i] = (static_cast<double>(i) + 3.0) / n;
    }
}
