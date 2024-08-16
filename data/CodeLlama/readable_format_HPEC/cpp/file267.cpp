#include <vector>

// Assuming DATA_TYPE is a placeholder for the actual data type, e.g., double.
// Adjust the type if necessary.
template<typename DATA_TYPE>
void init_array(int ni, int nj, int nk, int nl, int nm, 
                std::vector<std::vector<DATA_TYPE>>& a, 
                std::vector<std::vector<DATA_TYPE>>& b, 
                std::vector<std::vector<DATA_TYPE>>& c, 
                std::vector<std::vector<DATA_TYPE>>& d) {
    // Resize vectors to match dimensions
    a.resize(nk, std::vector<DATA_TYPE>(ni));
    b.resize(nj, std::vector<DATA_TYPE>(nk));
    c.resize(nm, std::vector<DATA_TYPE>(nj));
    d.resize(nl, std::vector<DATA_TYPE>(nm));

    // Initialize arrays
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nk; ++j) {
            a[j][i] = static_cast<DATA_TYPE>((i + 1) * (j + 1)) / ni;
        }
    }

    for (int i = 0; i < nk; ++i) {
        for (int j = 0; j < nj; ++j) {
            b[j][i] = static_cast<DATA_TYPE>((i + 1) * (j + 1)) / nj;
        }
    }

    for (int i = 0; i < nj; ++i) {
        for (int j = 0; j < nm; ++j) {
            c[j][i] = static_cast<DATA_TYPE>((i + 1) * (j + 2)) / nl;
        }
    }

    for (int i = 0; i < nm; ++i) {
        for (int j = 0; j < nl; ++j) {
            d[j][i] = static_cast<DATA_TYPE>((i + 1) * (j + 1)) / nk;
        }
    }
}
