#include <vector>

// Assuming DATA_TYPE is a placeholder for a specific type, e.g., double.
// You should replace it with the actual type you're using.
using DATA_TYPE = double;

void init_array(DATA_TYPE& alpha, DATA_TYPE& beta, 
               std::vector<std::vector<DATA_TYPE>>& a, 
               std::vector<std::vector<DATA_TYPE>>& b, 
               std::vector<std::vector<DATA_TYPE>>& c, 
               std::vector<std::vector<DATA_TYPE>>& d, 
               int ni, int nj, int nk, int nl) {
    
    alpha = 32412.0;
    beta = 2123.0;

    // Initialize arrays a, b, c, d
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nk; ++j) {
            a[j][i] = static_cast<DATA_TYPE>((i) * (j)) / ni;
        }
    }

    for (int i = 0; i < nk; ++i) {
        for (int j = 0; j < nj; ++j) {
            b[j][i] = static_cast<DATA_TYPE>((i) * (j+1)) / nj;
        }
    }

    for (int i = 0; i < nl; ++i) {
        for (int j = 0; j < nj; ++j) {
            c[j][i] = static_cast<DATA_TYPE>(i) * (j+2) / nl;
        }
    }

    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nl; ++j) {
            d[j][i] = static_cast<DATA_TYPE>(i) * (j+1) / nk;
        }
    }
}
