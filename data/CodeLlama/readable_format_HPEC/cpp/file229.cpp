#include <vector>

void kernel_lu(int n, std::vector<std::vector<double>>& a) {
    // Loop variables
    int i, j, k;

    // Scoped block
    for (k = 0; k < n; ++k) {
        for (j = k + 1; j < n; ++j) {
            a[j][k] = a[j][k] / a[k][k];
        }
        for (i = k + 1; i < n; ++i) {
            for (j = k + 1; j < n; ++j) {
                a[j][i] = a[j][i] - (a[k][i] * a[j][k]);
            }
        }
    }
}

int main() {
    // Example usage
    int n = 4; // Matrix size
    std::vector<std::vector<double>> a = {
        {2.0, -1.0, 0.0, -1.0},
        {-1.0, 2.0, -1.0, 0.0},
        {0.0, -1.0, 2.0, -1.0},
        {-1.0, 0.0, -1.0, 2.0}
    };

    kernel_lu(n, a);

    // Print the result
    for (const auto& row : a) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
