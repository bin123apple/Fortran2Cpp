#include <vector>

// Assuming DATA_TYPE is double for this translation
void init_array(int m, int n, double& float_n, std::vector<std::vector<double>>& dat) {
    float_n = 1.2;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            dat[j][i] = (static_cast<double>(i) * static_cast<double>(j)) / static_cast<double>(m);
        }
    }
}

// Example usage
int main() {
    int m = 3; // Number of rows
    int n = 2; // Number of columns
    double float_n;
    std::vector<std::vector<double>> dat(n, std::vector<double>(m)); // 2D vector to represent the array

    init_array(m, n, float_n, dat);

    // Optional: Print the array to verify the results
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << dat[j][i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
