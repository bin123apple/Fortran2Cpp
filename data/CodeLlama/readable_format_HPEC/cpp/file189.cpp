#include <vector>
#include <cmath> // For std::pow

// Assuming DATA_TYPE is double for this translation
void init_array(int n, std::vector<std::vector<double>>& x, std::vector<std::vector<double>>& a, std::vector<std::vector<double>>& b) {
    // Resize the vectors to have dimensions n x n
    x.resize(n, std::vector<double>(n));
    a.resize(n, std::vector<double>(n));
    b.resize(n, std::vector<double>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            x[j][i] = (std::pow(i + 1, 2) + 1.0) / n;
            a[j][i] = (std::pow(i + 1, 2) + 2.0) / n;
            b[j][i] = (std::pow(i + 1, 2) + 3.0) / n;
        }
    }
}

int main() {
    int n = 4; // Example size
    std::vector<std::vector<double>> x, a, b;

    init_array(n, x, a, b);

    // Optionally print the arrays to verify
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << x[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
