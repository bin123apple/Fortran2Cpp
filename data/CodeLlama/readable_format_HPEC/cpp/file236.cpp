#include <vector>

// Assuming DATA_TYPE is a placeholder for the actual data type, e.g., double.
// Adjust the data type if necessary.
using DATA_TYPE = double;

void init_array(int ni, int nj, DATA_TYPE& alpha, DATA_TYPE& beta, std::vector<std::vector<DATA_TYPE>>& c, std::vector<std::vector<DATA_TYPE>>& a, std::vector<std::vector<DATA_TYPE>>& b) {
    // Initialize alpha and beta
    alpha = 32412.0;
    beta = 2123.0;

    // Resize the matrices to match the dimensions
    a.resize(nj, std::vector<DATA_TYPE>(ni));
    b.resize(nj, std::vector<DATA_TYPE>(ni));
    c.resize(ni, std::vector<DATA_TYPE>(ni));

    // Fill the matrices
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            a[j][i] = static_cast<DATA_TYPE>((i * j) / static_cast<DATA_TYPE>(ni));
            b[j][i] = static_cast<DATA_TYPE>((i * j) / static_cast<DATA_TYPE>(ni));
        }
    }

    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < ni; ++j) {
            c[j][i] = static_cast<DATA_TYPE>((i * j) / static_cast<DATA_TYPE>(ni));
        }
    }
}
