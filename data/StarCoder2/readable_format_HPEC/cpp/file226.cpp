#include <vector>

// Assuming DATA_TYPE is a placeholder for a specific type, e.g., double.
// You should replace DATA_TYPE with the actual type you are using.
void init_array(int n, std::vector<std::vector<DATA_TYPE>>& y, std::vector<std::vector<DATA_TYPE>>& sumArray, 
               std::vector<DATA_TYPE>& alpha, std::vector<DATA_TYPE>& beta, std::vector<DATA_TYPE>& r) {
    // Initialize vectors with the correct size
    y.resize(n, std::vector<DATA_TYPE>(n));
    sumArray.resize(n, std::vector<DATA_TYPE>(n));
    alpha.resize(n);
    beta.resize(n);
    r.resize(n);

    for (int i = 0; i < n; ++i) {
        alpha[i] = i + 1; // Adjusting for 0-based indexing
        beta[i] = (i + 1) / static_cast<DATA_TYPE>(n) / 2.0;
        r[i] = (i + 1) / static_cast<DATA_TYPE>(n) / 4.0;
        for (int j = 0; j < n; ++j) {
            y[j][i] = static_cast<DATA_TYPE>((i + 1) * (j + 1)) / static_cast<DATA_TYPE>(n);
            sumArray[j][i] = static_cast<DATA_TYPE>((i + 1) * (j + 1)) / static_cast<DATA_TYPE>(n);
        }
    }
}
