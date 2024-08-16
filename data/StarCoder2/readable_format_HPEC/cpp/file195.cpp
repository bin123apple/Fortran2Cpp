#include <vector>

// Assuming DATA_TYPE corresponds to double in the Fortran code
using DATA_TYPE = double;

void kernel_doitgen(int nr, int nq, int np,
                    std::vector<std::vector<std::vector<DATA_TYPE>>>& a,
                    const std::vector<std::vector<DATA_TYPE>>& cFour,
                    std::vector<std::vector<std::vector<DATA_TYPE>>>& sumA) {
    
    // Adjusting array dimensions to 0-based indexing
    int _PB_NR = nr - 1;
    int _PB_NQ = nq - 1;
    int _PB_NP = np - 1;

    // OpenACC directives in C++
    #pragma scop
    for (int r = 0; r <= _PB_NR; ++r) {
        for (int q = 0; q <= _PB_NQ; ++q) {
            for (int p = 0; p <= _PB_NP; ++p) {
                sumA[p][q][r] = 0.0;
                for (int s = 0; s <= _PB_NP; ++s) {
                    sumA[p][q][r] += a[s][q][r] * cFour[p][s];
                }
            }
            for (int p = 0; p <= _PB_NP; ++p) {
                a[p][q][r] = sumA[p][q][r];
            }
        }
    }
    #pragma endscop
}
