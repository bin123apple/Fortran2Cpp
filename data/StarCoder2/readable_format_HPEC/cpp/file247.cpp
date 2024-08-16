#include <vector>

// Assuming DATA_TYPE is a double for this translation
using DATA_TYPE = double;

void init_array(int nr, int nq, int np, std::vector<std::vector<std::vector<DATA_TYPE>>>& a, std::vector<std::vector<DATA_TYPE>>& cFour) {
    // Resize the arrays to match the dimensions
    a.resize(np, std::vector<std::vector<DATA_TYPE>>(nq, std::vector<DATA_TYPE>(nr)));
    cFour.resize(np, std::vector<DATA_TYPE>(np));

    for (int i = 0; i < nr; ++i) {
        for (int j = 0; j < nq; ++j) {
            for (int k = 0; k < np; ++k) {
                a[k][j][i] = ((static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j)) + static_cast<DATA_TYPE>(k)) / static_cast<DATA_TYPE>(np);
            }
        }
    }

    for (int i = 0; i < np; ++i) {
        for (int j = 0; j < np; ++j) {
            cFour[j][i] = (static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j)) / static_cast<DATA_TYPE>(np);
        }
    }
}
