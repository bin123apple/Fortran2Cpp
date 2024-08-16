#include <cmath>
#include <vector>

// Assuming DATA_TYPE is double for this translation
using DATA_TYPE = double;

void kernel_cholesky(int n, std::vector<DATA_TYPE>& p, std::vector<std::vector<DATA_TYPE>>& a) {
    DATA_TYPE x;

    // OpenMP pragma directive for parallel region
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < n; ++i) {
        x = a[i][i];
        for (int j = 0; j < i; ++j) {
            x -= a[j][i] * a[j][i];
        }
        p[i] = 1.0 / std::sqrt(x);
        for (int j = i + 1; j < n; ++j) {
            x = a[j][i];
            for (int k = 0; k < i; ++k) {
                x -= (a[k][j] * a[k][i]);
            }
            a[i][j] = x * p[i];
        }
    }
}

int main() {
    // Example usage
    int n = 4; // Size of the matrix
    std::vector<DATA_TYPE> p(n);
    std::vector<std::vector<DATA_TYPE>> a(n, std::vector<DATA_TYPE>(n));

    // Initialize matrix 'a' and vector 'p' with some values
    //...

    kernel_cholesky(n, p, a);

    // Output the results
    //...

    return 0;
}
