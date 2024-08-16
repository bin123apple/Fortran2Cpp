#include <vector>
#include <cmath> // For std::pow

// Assuming DATA_TYPE is a placeholder for the actual data type, e.g., double or float.
// Adjust the type according to your needs.
using DATA_TYPE = double;

void init_array(int n, std::vector<std::vector<DATA_TYPE>>& a, std::vector<DATA_TYPE>& x, std::vector<DATA_TYPE>& c) {
    // Resize vectors to match the dimensions n x n for a and n for x and c
    a.resize(n, std::vector<DATA_TYPE>(n));
    x.resize(n);
    c.resize(n);

    for (int i = 0; i < n; ++i) {
        c[i] = static_cast<DATA_TYPE>(i) / static_cast<DATA_TYPE>(n);
        x[i] = static_cast<DATA_TYPE>(i) / static_cast<DATA_TYPE>(n);
        for (int j = 0; j < n; ++j) {
            a[j][i] = (static_cast<DATA_TYPE>(i) * static_cast<DATA_TYPE>(j)) / static_cast<DATA_TYPE>(n);
        }
    }
}

int main() {
    int n = 5; // Example size
    std::vector<std::vector<DATA_TYPE>> a;
    std::vector<DATA_TYPE> x, c;

    init_array(n, a, x, c);

    // Example usage: Print the first few elements
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << a[i][j] << " ";
        }
        std::cout << x[i] << " " << c[i] << std::endl;
    }

    return 0;
}
