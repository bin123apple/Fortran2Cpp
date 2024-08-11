#include <iostream>
#include <vector>

void tridiagonal(std::vector<std::vector<double>>& a, std::vector<double>& b, int n, int m, int lda) {
    double y;
    
    // Adjustments for base-1 array indexing in Fortran to base-0 in C++
    for (int k = 0; k < m; ++k) {
        a[k][2] = a[k][2] / a[k][1];
        b[k] = b[k] / a[k][1];
    }
    
    for (int k = m; k < n - m; ++k) {
        y = 1.0 / (a[k - m][2] * a[k][0] - a[k][1]);
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

void printVector(const std::vector<double>& v) {
    for (auto& val : v) {
        std::cout << val << std::endl;
    }
}

int main() {
    int n = 3, m = 1, lda = 3;
    std::vector<std::vector<double>> a(lda, std::vector<double>(3, 0.0));
    std::vector<double> b(n);

    // Initialize the same tridiagonal system as in the Fortran test
    a[0][0] = 0.0; a[0][1] = 2.0; a[0][2] = -1.0;
    a[1][0] = -1.0; a[1][1] = 2.0; a[1][2] = -1.0;
    a[2][0] = -1.0; a[2][1] = 2.0; a[2][2] = 0.0;
    
    b[0] = 1.0;
    b[1] = 2.0;
    b[2] = 3.0;

    tridiagonal(a, b, n, m, lda);

    std::cout << "Resulting b:" << std::endl;
    printVector(b);

    return 0;
}