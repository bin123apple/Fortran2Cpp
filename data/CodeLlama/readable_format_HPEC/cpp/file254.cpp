#include <vector>

// Assuming DATA_TYPE is a placeholder for the actual data type, e.g., double.
// Adjust the type if necessary.
void init_array(int n, std::vector<std::vector<double>>& a, std::vector<std::vector<double>>& b) {
    // Resize the vectors to have dimensions n x n
    a.resize(n, std::vector<double>(n));
    b.resize(n, std::vector<double>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[j][i] = (static_cast<double>(i) * static_cast<double>(j + 1) + 2.0) / n;
            b[j][i] = (static_cast<double>(i) * static_cast<double>(j + 2) + 3.0) / n;
        }
    }
}

int main() {
    int n = 5; // Example size
    std::vector<std::vector<double>> a, b;

    init_array(n, a, b);

    // Optional: Print the arrays to verify the results
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << b[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
