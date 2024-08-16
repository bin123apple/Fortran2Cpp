#include <vector>
#include <iostream>

// Assuming DATA_TYPE is a placeholder for the actual data type (e.g., float, double).
// Replace DATA_TYPE with the appropriate type, e.g., float, double.
using DATA_TYPE = double;

void kernel_3mm(int ni, int nj, int nk, int nl, int nm, 
                std::vector<std::vector<DATA_TYPE>>& e, 
                const std::vector<std::vector<DATA_TYPE>>& a, 
                const std::vector<std::vector<DATA_TYPE>>& b, 
                std::vector<std::vector<DATA_TYPE>>& f, 
                const std::vector<std::vector<DATA_TYPE>>& c, 
                const std::vector<std::vector<DATA_TYPE>>& d, 
                std::vector<std::vector<DATA_TYPE>>& g) {
    // Initialize e, f, and g to zero
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            e[j][i] = 0.0;
            f[j][i] = 0.0;
            g[j][i] = 0.0;
        }
    }

    // E := A*B
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            for (int k = 0; k < nk; ++k) {
                e[j][i] += a[k][i] * b[j][k];
            }
        }
    }

    // F := C*D
    for (int i = 0; i < nj; ++i) {
        for (int j = 0; j < nl; ++j) {
            for (int k = 0; k < nm; ++k) {
                f[j][i] += c[k][i] * d[j][k];
            }
        }
    }

    // G := E*F
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nl; ++j) {
            for (int k = 0; k < nj; ++k) {
                g[j][i] += e[k][i] * f[j][k];
            }
        }
    }
}

int main() {
    // Example usage
    int ni = 4, nj = 4, nk = 4, nl = 4, nm = 4;

    // Initialize matrices
    std::vector<std::vector<DATA_TYPE>> e(nj, std::vector<DATA_TYPE>(ni, 0.0));
    std::vector<std::vector<DATA_TYPE>> a(nk, std::vector<DATA_TYPE>(ni, 0.0));
    std::vector<std::vector<DATA_TYPE>> b(nj, std::vector<DATA_TYPE>(nk, 0.0));
    std::vector<std::vector<DATA_TYPE>> f(nl, std::vector<DATA_TYPE>(nj, 0.0));
    std::vector<std::vector<DATA_TYPE>> c(nm, std::vector<DATA_TYPE>(nj, 0.0));
    std::vector<std::vector<DATA_TYPE>> d(nl, std::vector<DATA_TYPE>(nm, 0.0));
    std::vector<std::vector<DATA_TYPE>> g(nl, std::vector<DATA_TYPE>(ni, 0.0));

    // Populate matrices with some values for demonstration
    // This part is left as an exercise since the original Fortran code does not initialize matrices

    // Call the kernel
    kernel_3mm(ni, nj, nk, nl, nm, e, a, b, f, c, d, g);

    // Print results (for demonstration)
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            std::cout << "e(" << j << "," << i << ") = " << e[j][i] << ", ";
            std::cout << "f(" << j << "," << i << ") = " << f[j][i] << ", ";
            std::cout << "g(" << j << "," << i << ") = " << g[j][i] << std::endl;
        }
    }

    return 0;
}
