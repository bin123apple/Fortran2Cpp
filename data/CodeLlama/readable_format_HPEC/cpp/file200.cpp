#include <vector>
#include <cmath>

// Assuming DATA_TYPE is a placeholder for the actual data type you want to use.
// For simplicity, let's use double for this example.
using DATA_TYPE = double;

void init_array(int n, DATA_TYPE& alpha, DATA_TYPE& beta, std::vector<std::vector<DATA_TYPE>>& a, std::vector<std::vector<DATA_TYPE>>& b, std::vector<DATA_TYPE>& x) {
    // Initialize alpha and beta
    alpha = 43532.0;
    beta = 12313.0;

    // Resize vectors to match dimensions n x n
    a.resize(n, std::vector<DATA_TYPE>(n));
    b.resize(n, std::vector<DATA_TYPE>(n));
    x.resize(n);

    // Fill vectors with values
    for (int i = 0; i < n; ++i) {
        x[i] = static_cast<DATA_TYPE>(i) / static_cast<DATA_TYPE>(n);
        for (int j = 0; j < n; ++j) {
            a[j][i] = (static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j)) / static_cast<DATA_TYPE>(n);
            b[j][i] = (static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j)) / static_cast<DATA_TYPE>(n);
        }
    }
}

int main() {
    int n = 5; // Example size
    DATA_TYPE alpha, beta;
    std::vector<std::vector<DATA_TYPE>> a, b;
    std::vector<DATA_TYPE> x;

    init_array(n, alpha, beta, a, b, x);

    // Example usage: print some values to verify
    for (int i = 0; i < 5; ++i) {
        std::cout << "x[" << i << "] = " << x[i] << std::endl;
        std::cout << "a[" << i << "][0] = " << a[i][0] << std::endl;
        std::cout << "b[" << i << "][0] = " << b[i][0] << std::endl;
    }

    return 0;
}
