#include <vector>

// Assuming DATA_TYPE is a placeholder for the actual data type, e.g., double or float.
// Adjust the type according to your needs.
using DATA_TYPE = double;

void kernel_doitgen(int nr, int nq, int np, std::vector<std::vector<std::vector<DATA_TYPE>>> &a,
                   std::vector<std::vector<std::vector<DATA_TYPE>>> &sumA,
                   std::vector<std::vector<DATA_TYPE>> &cFour) {
    // Adjusting for 0-based indexing in C++
    for (int r = 0; r < nr; ++r) {
        for (int q = 0; q < nq; ++q) {
            for (int p = 0; p < np; ++p) {
                sumA[p][q][r] = 0.0;
            }
        }
    }

    for (int r = 0; r < nr; ++r) {
        for (int q = 0; q < nq; ++q) {
            for (int p = 0; p < np; ++p) {
                for (int s = 0; s < np; ++s) {
                    sumA[p][q][r] += a[s][q][r] * cFour[p][s];
                }
            }
        }
    }

    for (int r = 0; r < nr; ++r) {
        for (int q = 0; q < nq; ++q) {
            for (int p = 0; p < np; ++p) {
                a[p][q][r] = sumA[p][q][r];
            }
        }
    }
}

int main() {
    // Example usage
    int nr = 10; // Example value for nr
    int nq = 10; // Example value for nq
    int np = 10; // Example value for np

    // Initialize a, sumA, and cFour with appropriate sizes and values
    std::vector<std::vector<std::vector<DATA_TYPE>>> a(np, std::vector<std::vector<DATA_TYPE>>(nq, std::vector<DATA_TYPE>(nr)));
    std::vector<std::vector<std::vector<DATA_TYPE>>> sumA(np, std::vector<std::vector<DATA_TYPE>>(nq, std::vector<DATA_TYPE>(nr, 0.0)));
    std::vector<std::vector<DATA_TYPE>> cFour(np, std::vector<DATA_TYPE>(np));

    // Populate a, sumA, and cFour with your data
    // ...

    kernel_doitgen(nr, nq, np, a, sumA, cFour);

    // Output results
    // ...

    return 0;
}
