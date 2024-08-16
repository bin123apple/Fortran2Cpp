#include <vector>

// Assuming DATA_TYPE is a typedef for some floating-point type, e.g., float or double
using DATA_TYPE = double;

void kernel_mvt(int n, std::vector<DATA_TYPE>& x1, std::vector<DATA_TYPE>& x2, 
               const std::vector<DATA_TYPE>& y1, const std::vector<DATA_TYPE>& y2, 
               const std::vector<std::vector<DATA_TYPE>>& a) {
    // Assuming _PB_N is a preprocessor definition for some integer value
    // If _PB_N is not used in the original Fortran code, you can remove this line
    // and directly use 'n' in the loop conditions.
    
    // OpenACC directives are not directly translatable to C++, so we'll omit them.
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            x1[i] = x1[i] + (a[j][i] * y1[j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            x2[i] = x2[i] + (a[i][j] * y2[j]);
        }
    }
}
