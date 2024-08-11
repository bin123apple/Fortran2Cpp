// tridiagonal.cpp
#include <vector>
#include <iostream>

void tridiagonal(std::vector<std::vector<double>>& a, std::vector<double>& b, int n, int m) {
    for (int k = 0; k < m; ++k) {
        a[k][2] = a[k][2] / a[k][1];
        b[k] = b[k] / a[k][1];
    }
    for (int k = m; k < n - m; ++k) {
        double y = 1.0 / (a[k - m][2] * a[k][0] - a[k][1]);
        a[k][2] = -a[k][2] * y;
        b[k] = (b[k - m] * a[k][0] - b[k]) * y;
    }
    for (int k = n - m; k < n; ++k) {
        a[k][1] = a[k - m][2] * a[k][0] - a[k][1];
        b[k] = (b[k - m] * a[k][0] - b[k]) / a[k][1];
    }
    for (int k = n - m - 1; k >= 0; --k) {
        b[k] = b[k] - a[k][2] * b[k + m];
    }
}

int main() {
    int n = 5, m = 1;
    std::vector<std::vector<double>> a(n, std::vector<double>(3));
    std::vector<double> b(n);

    // Initialize the vectors 'a' and 'b'
    for (int i = 0; i < n; ++i) {
        a[i][0] = 1.0; // a1
        a[i][1] = 2.0; // a2
        a[i][2] = 3.0; // a3
        b[i] = 4.0;
    }

    tridiagonal(a, b, n, m);

    // Print the result
    std::cout << "Resulting b:" << std::endl;
    for (const auto& value : b) {
        std::cout << value << std::endl;
    }

    return 0;
}