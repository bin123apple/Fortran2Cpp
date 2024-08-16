#include <vector>
#include <cmath>

// Assuming DATA_TYPE is a placeholder for the actual data type, e.g., float or double.
// Adjust the type accordingly.
using DATA_TYPE = double;

void init_array(int ni, int nj, int nk, DATA_TYPE& alpha, DATA_TYPE& beta, std::vector<std::vector<DATA_TYPE>>& c, std::vector<std::vector<DATA_TYPE>>& a, std::vector<std::vector<DATA_TYPE>>& b) {
    // Initialize alpha and beta
    alpha = 32412;
    beta = 2123;

    // Resize vectors to the correct dimensions
    c.resize(nj, std::vector<DATA_TYPE>(ni));
    a.resize(nk, std::vector<DATA_TYPE>(ni));
    b.resize(nj, std::vector<DATA_TYPE>(nk));

    // Fill arrays
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            c[j][i] = (static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j)) / static_cast<DATA_TYPE>(ni);
        }
    }

    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nk; ++j) {
            a[j][i] = (static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j)) / static_cast<DATA_TYPE>(ni);
        }
    }

    for (int i = 0; i < nk; ++i) {
        for (int j = 0; j < nj; ++j) {
            b[j][i] = (static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j)) / static_cast<DATA_TYPE>(ni);
        }
    }
}
