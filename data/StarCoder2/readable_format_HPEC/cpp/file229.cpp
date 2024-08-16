#include <vector>

// Assuming DATA_TYPE is double for this translation
using DATA_TYPE = double;

void init_array(int n, DATA_TYPE& alpha, std::vector<std::vector<DATA_TYPE>>& a, std::vector<std::vector<DATA_TYPE>>& b) {
    alpha = 32412.0;
    
    // Adjusting for 0-based indexing in C++
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[j][i] = (static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j)) / static_cast<DATA_TYPE>(n);
            b[j][i] = ((static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j))) / static_cast<DATA_TYPE>(n);
        }
    }
}

int main() {
    int n = 4; // Example size
    DATA_TYPE alpha;
    std::vector<std::vector<DATA_TYPE>> a(n, std::vector<DATA_TYPE>(n));
    std::vector<std::vector<DATA_TYPE>> b(n, std::vector<DATA_TYPE>(n));

    init_array(n, alpha, a, b);

    // Optional: Print the arrays to verify the results
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << "a[" << j << "][" << i << "] = " << a[j][i] << ", b[" << j << "][" << i << "] = " << b[j][i] << std::endl;
        }
    }

    return 0;
}
