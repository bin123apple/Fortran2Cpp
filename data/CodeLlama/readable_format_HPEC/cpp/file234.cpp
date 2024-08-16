#include <vector>

void kernel_mvt(int n, std::vector<double>& x1, std::vector<double>& y1, std::vector<double>& x2, std::vector<double>& y2, std::vector<std::vector<double>>& a) {
    // Loop to update x1
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            x1[i] = x1[i] + (a[j][i] * y1[j]);
        }
    }

    // Loop to update x2
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            x2[i] = x2[i] + (a[i][j] * y2[j]);
        }
    }
}

int main() {
    int n = 10; // Example size
    std::vector<double> x1(n), y1(n), x2(n), y2(n);
    std::vector<std::vector<double>> a(n, std::vector<double>(n));

    // Initialize vectors
    // For example purposes, fill them with some values
    for (int i = 0; i < n; ++i) {
        x1[i] = 1.0;
        y1[i] = 2.0;
        x2[i] = 3.0;
        y2[i] = 4.0;
        for (int j = 0; j < n; ++j) {
            a[i][j] = static_cast<double>(i * j); // Example values
        }
    }

    // Call the function
    kernel_mvt(n, x1, y1, x2, y2, a);

    // Print results (for verification)
    for (int i = 0; i < n; ++i) {
        std::cout << "x1[" << i << "] = " << x1[i] << ", x2[" << i << "] = " << x2[i] << std::endl;
    }

    return 0;
}
