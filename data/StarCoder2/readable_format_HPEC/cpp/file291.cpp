#include <vector>

// Assuming DATA_TYPE is double for this translation
using DATA_TYPE = double;

void kernel_seidel(int tsteps, int n, std::vector<std::vector<DATA_TYPE>>& a) {
    // Assuming _PB_TSTEPS and _PB_N are macros or constants defined elsewhere
    // #define _PB_TSTEPS tsteps
    // #define _PB_N n

    // OpenACC directives are translated to OpenACC pragmas in C++
    #pragma acc scop
    for (int t = 1; t <= _PB_TSTEPS; ++t) {
        for (int i = 1; i < _PB_N - 1; ++i) { // Adjusted for 0-based indexing
            for (int j = 1; j < _PB_N - 1; ++j) { // Adjusted for 0-based indexing
                a[j][i] = (a[j - 1][i - 1] + a[j][i - 1] + a[j + 1][i - 1] +
                          a[j - 1][i] + a[j][i] + a[j + 1][i] +
                          a[j - 1][i + 1] + a[j][i + 1] +
                          a[j + 1][i + 1]) / 9.0;
            }
        }
    }
    #pragma acc endscop
}
