#include <vector>

// Assuming DATA_TYPE is double for this translation
using DATA_TYPE = double;

void kernel_gemver(int n, DATA_TYPE alpha, DATA_TYPE beta,
                  std::vector<std::vector<DATA_TYPE>>& a,
                  const std::vector<DATA_TYPE>& u1,
                  const std::vector<DATA_TYPE>& v1,
                  const std::vector<DATA_TYPE>& u2,
                  const std::vector<DATA_TYPE>& v2,
                  std::vector<DATA_TYPE>& w,
                  std::vector<DATA_TYPE>& x,
                  const std::vector<DATA_TYPE>& y,
                  const std::vector<DATA_TYPE>& z) {
    // OpenACC directives are not directly translatable to C++,
    // so we'll omit them for this translation.

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[j][i] = a[j][i] + (u1[i] * v1[j]) + (u2[i] * v2[j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            x[i] = x[i] + (beta * a[i][j] * y[j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        x[i] = x[i] + z[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            w[i] = w[i] + (alpha * a[j][i] * x[j]);
        }
    }
}
