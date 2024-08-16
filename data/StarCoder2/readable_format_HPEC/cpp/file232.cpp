#include <vector>
#include <iostream>

// Assuming DATA_TYPE is double for this translation
using DATA_TYPE = double;

void init_array(int ni, int nj, DATA_TYPE& alpha, DATA_TYPE& beta, std::vector<std::vector<DATA_TYPE>>& c, std::vector<std::vector<DATA_TYPE>>& a, std::vector<std::vector<DATA_TYPE>>& b) {
    alpha = 32412.0;
    beta = 2123.0;

    // Initialize a and b
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            a[j][i] = static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j) / static_cast<DATA_TYPE>(ni);
            b[j][i] = static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j) / static_cast<DATA_TYPE>(ni);
        }
    }

    // Initialize c
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < ni; ++j) {
            c[j][i] = static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j) / static_cast<DATA_TYPE>(ni);
        }
    }
}

int main() {
    int ni = 4; // Example dimensions
    int nj = 3;

    // Initialize 2D arrays with dimensions ni x nj
    std::vector<std::vector<DATA_TYPE>> a(nj, std::vector<DATA_TYPE>(ni));
    std::vector<std::vector<DATA_TYPE>> b(nj, std::vector<DATA_TYPE>(ni));
    std::vector<std::vector<DATA_TYPE>> c(ni, std::vector<DATA_TYPE>(ni));

    DATA_TYPE alpha, beta;

    init_array(ni, nj, alpha, beta, c, a, b);

    // Example: Print the first element of array a to verify the initialization
    std::cout << "First element of a: " << a[0][0] << std::endl;

    return 0;
}
