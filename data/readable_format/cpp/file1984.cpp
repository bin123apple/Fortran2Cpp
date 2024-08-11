#include <vector>

void initializeMatrixToZero(std::vector<std::vector<double>>& c, int n) {
    // Assuming 'c' has been sized appropriately outside this function
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            c[i][j] = 0.0;
        }
    }
}