#include <vector>

void init_array(int ni, int nj, std::vector<std::vector<double>>& a, std::vector<std::vector<double>>& r, std::vector<std::vector<double>>& q) {
    // Assuming a, r, and q are already sized appropriately outside this function

    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            a[j][i] = (static_cast<double>(i) * static_cast<double>(j)) / static_cast<double>(ni);
            q[j][i] = (static_cast<double>(i) * static_cast<double>(j + 1)) / static_cast<double>(nj);
        }
    }

    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            r[j][i] = (static_cast<double>(i) * static_cast<double>(j + 1)) / static_cast<double>(nj);
        }
    }
}
