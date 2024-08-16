#include <vector>

// Assuming DATA_TYPE is float for this example
using DATA_TYPE = float;

void kernel_3mm(int ni, int nj, int nk, int nl, int nm, 
               std::vector<std::vector<DATA_TYPE>>& a, 
               std::vector<std::vector<DATA_TYPE>>& b, 
               std::vector<std::vector<DATA_TYPE>>& c, 
               std::vector<std::vector<DATA_TYPE>>& d, 
               std::vector<std::vector<DATA_TYPE>>& e, 
               std::vector<std::vector<DATA_TYPE>>& f, 
               std::vector<std::vector<DATA_TYPE>>& g) {
    
    // E := A*B
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            e[j][i] = 0.0f;
            for (int k = 0; k < nk; ++k) {
                e[j][i] += a[k][i] * b[j][k];
            }
        }
    }

    // F := C*D
    for (int i = 0; i < nj; ++i) {
        for (int j = 0; j < nl; ++j) {
            f[j][i] = 0.0f;
            for (int k = 0; k < nm; ++k) {
                f[j][i] += c[k][i] * d[j][k];
            }
        }
    }

    // G := E*F
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nl; ++j) {
            g[j][i] = 0.0f;
            for (int k = 0; k < nj; ++k) {
                g[j][i] += e[k][i] * f[j][k];
            }
        }
    }
}
