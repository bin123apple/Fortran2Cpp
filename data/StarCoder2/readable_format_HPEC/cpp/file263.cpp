#include <vector>

// Assuming DATA_TYPE is a double for this example
using DATA_TYPE = double;

void init_array(int ni, int nj, int nk, int nl, int nm, 
                std::vector<std::vector<DATA_TYPE>>& a, 
                std::vector<std::vector<DATA_TYPE>>& b, 
                std::vector<std::vector<DATA_TYPE>>& c, 
                std::vector<std::vector<DATA_TYPE>>& d) {
    
    // Initialize arrays a, b, c, d
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nk; ++j) {
            a[j][i] = static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j) / ni;
        }
    }

    for (int i = 0; i < nk; ++i) {
        for (int j = 0; j < nj; ++j) {
            b[j][i] = static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j) / nj;
        }
    }

    for (int i = 0; i < nj; ++i) {
        for (int j = 0; j < nm; ++j) {
            c[j][i] = static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j + 2) / nl;
        }
    }

    for (int i = 0; i < nm; ++i) {
        for (int j = 0; j < nl; ++j) {
            d[j][i] = static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j + 1) / nk;
        }
    }
}

int main() {
    // Example usage
    int ni = 10, nj = 10, nk = 10, nl = 10, nm = 10;
    std::vector<std::vector<DATA_TYPE>> a(nk, std::vector<DATA_TYPE>(ni)),
                                    b(nj, std::vector<DATA_TYPE>(nk)),
                                    c(nm, std::vector<DATA_TYPE>(nj)),
                                    d(nl, std::vector<DATA_TYPE>(nm));

    init_array(ni, nj, nk, nl, nm, a, b, c, d);

    // Optional: Print the arrays to verify the results
    for (const auto& row : a) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
