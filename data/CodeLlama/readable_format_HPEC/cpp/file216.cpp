#include <cmath>
#include <vector>

// Assuming DATA_TYPE is a placeholder for the actual data type, e.g., double or float.
// Adjust the type according to your needs.
using DATA_TYPE = double;

void kernel_gramschmidt(int ni, int nj, std::vector<std::vector<DATA_TYPE>>& a, std::vector<std::vector<DATA_TYPE>>& r, std::vector<std::vector<DATA_TYPE>>& q) {
    DATA_TYPE nrm;

    // Initialize r to zeroes
    for (int k = 0; k < nj; ++k) {
        for (int j = 0; j < nj; ++j) {
            r[k][j] = 0.0;
        }
    }

    // Calculate the norm and store it in r
    for (int k = 0; k < nj; ++k) {
        nrm = 0.0;
        for (int i = 0; i < ni; ++i) {
            nrm += a[k][i] * a[k][i];
        }
        r[k][k] = std::sqrt(nrm);
    }

    // Calculate q = a / r
    for (int k = 0; k < nj; ++k) {
        for (int i = 0; i < ni; ++i) {
            q[k][i] = a[k][i] / r[k][k];
        }
    }

    // Update r and a based on q
    for (int j = 0; j < nj; ++j) {
        for (int k = 0; k < nj; ++k) {
            if (j != k) {
                r[j][k] = 0.0;
                for (int i = 0; i < ni; ++i) {
                    r[j][k] += q[k][i] * a[j][i];
                }
                for (int i = 0; i < ni; ++i) {
                    a[j][i] -= q[k][i] * r[j][k];
                }
            }
        }
    }
}

int main() {
    // Example usage
    int ni = 3; // Example value, adjust as needed
    int nj = 3; // Example value, adjust as needed

    std::vector<std::vector<DATA_TYPE>> a(nj, std::vector<DATA_TYPE>(ni, 0.0)); // Example initialization, adjust as needed
    std::vector<std::vector<DATA_TYPE>> r(nj, std::vector<DATA_TYPE>(nj, 0.0));
    std::vector<std::vector<DATA_TYPE>> q(nj, std::vector<DATA_TYPE>(ni, 0.0));

    // Call the function
    kernel_gramschmidt(ni, nj, a, r, q);

    // Output results for verification
    for (int i = 0; i < nj; ++i) {
        for (int j = 0; j < ni; ++j) {
            std::cout << "q[" << i << "][" << j << "] = " << q[i][j] << std::endl;
        }
    }

    return 0;
}
