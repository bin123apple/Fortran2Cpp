#include <vector>
#include <cmath> // For std::pow

// Assuming DATA_TYPE is a placeholder for the actual data type (e.g., double, float).
// We'll use double for this example.
using DATA_TYPE = double;

void init_array(int n, DATA_TYPE& alpha, std::vector<std::vector<DATA_TYPE>>& a, std::vector<std::vector<DATA_TYPE>>& b) {
    // Initialize alpha
    alpha = 32412.0;

    // Resize vectors to n x n
    a.resize(n, std::vector<DATA_TYPE>(n));
    b.resize(n, std::vector<DATA_TYPE>(n));

    // Fill arrays a and b
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[j][i] = static_cast<DATA_TYPE>((i * j) / static_cast<DATA_TYPE>(n));
            b[j][i] = static_cast<DATA_TYPE>((i * j) / static_cast<DATA_TYPE>(n));
        }
    }
}

int main() {
    int n = 5; // Example size
    DATA_TYPE alpha;
    std::vector<std::vector<DATA_TYPE>> a, b;

    init_array(n, alpha, a, b);

    // Example usage: Printing the first few elements of a and b
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << "a[" << i << "][" << j << "] = " << a[i][j] << ", ";
            std::cout << "b[" << i << "][" << j << "] = " << b[i][j] << std::endl;
        }
    }

    return 0;
}
