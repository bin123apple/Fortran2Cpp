#include <vector>
#include <cmath>

// Assuming DATA_TYPE is a placeholder for the actual data type (e.g., float, double).
// Replace DATA_TYPE with the appropriate data type (e.g., float, double).
using DATA_TYPE = double;

void init_array(int nr, int nq, int np, std::vector<std::vector<std::vector<DATA_TYPE>>> &a, std::vector<std::vector<DATA_TYPE>> &cFour) {
    // Resize the arrays to match the dimensions specified by nr, nq, np.
    a.resize(np, std::vector<std::vector<DATA_TYPE>>(nq, std::vector<DATA_TYPE>(nr)));
    cFour.resize(np, std::vector<DATA_TYPE>(np));

    // Initialize the array a as specified in the Fortran code.
    for (int i = 0; i < nr; ++i) {
        for (int j = 0; j < nq; ++j) {
            for (int k = 0; k < np; ++k) {
                a[k][j][i] = ((static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j)) + static_cast<DATA_TYPE>(k)) / static_cast<DATA_TYPE>(np);
            }
        }
    }

    // Initialize the array cFour as specified in the Fortran code.
    for (int i = 0; i < np; ++i) {
        for (int j = 0; j < np; ++j) {
            cFour[i][j] = (static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j)) / static_cast<DATA_TYPE>(np);
        }
    }
}

int main() {
    // Example usage
    int nr = 3, nq = 3, np = 3;
    std::vector<std::vector<std::vector<double>>> a;
    std::vector<std::vector<double>> cFour;

    init_array(nr, nq, np, a, cFour);

    // Optionally, print the arrays to verify the initialization
    for (int i = 0; i < np; ++i) {
        for (int j = 0; j < np; ++j) {
            std::cout << "cFour[" << i << "][" << j << "] = " << cFour[i][j] << std::endl;
        }
    }

    return 0;
}
