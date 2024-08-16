#include <vector>

// Assuming DATA_TYPE is a placeholder for the actual data type (e.g., float, double).
// Adjust the type if necessary.
using DATA_TYPE = double;

void init_array(int m, int n, DATA_TYPE& float_n, std::vector<std::vector<DATA_TYPE>>& dat) {
    float_n = 1.2;
    dat.resize(n, std::vector<DATA_TYPE>(m)); // Resize the 2D vector to have dimensions n x m.

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            dat[j][i] = static_cast<DATA_TYPE>((i * j) / static_cast<DATA_TYPE>(m));
        }
    }
}

int main() {
    int m = 5; // Example value for m
    int n = 10; // Example value for n
    DATA_TYPE float_n;
    std::vector<std::vector<DATA_TYPE>> dat;

    init_array(m, n, float_n, dat);

    // Optional: Print the array to verify the initialization
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << dat[j][i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
