#include <iostream>
#include <vector>

// Definition of dscal function
void dscal(int n, double da, double* dx, int incx) {
    int i, m, mp1, nincx;

    if (n <= 0 || incx <= 0) return;

    if (incx == 1) {
        // Optimized loop for unit increment
        m = n % 5;
        for (i = 0; i < m; i++) {
            dx[i] = da * dx[i];
        }
        if (n < 5) return;
        for (i = m; i < n; i += 5) {
            dx[i] = da * dx[i];
            dx[i + 1] = da * dx[i + 1];
            dx[i + 2] = da * dx[i + 2];
            dx[i + 3] = da * dx[i + 3];
            dx[i + 4] = da * dx[i + 4];
        }
    } else {
        // General loop for arbitrary increment
        nincx = n * incx;
        for (i = 0; i < nincx; i += incx) {
            dx[i] = da * dx[i];
        }
    }
}

// Helper function to print vectors
void printVector(const std::vector<double>& v) {
    for (auto& e : v) std::cout << e << " ";
    std::cout << std::endl;
}

int main() {
    // Test 1: Basic functionality
    std::vector<double> dx1 = {1.0, 2.0, 3.0, 4.0, 5.0};
    dscal(dx1.size(), 2.0, dx1.data(), 1);
    std::cout << "Test 1: dx = ";
    printVector(dx1);
    
    // Test 2: Non-unit increment
    std::vector<double> dx2 = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    dscal(dx2.size(), 3.0, dx2.data(), 2);
    std::cout << "Test 2: dx = ";
    printVector(dx2);
    
    // Test 3: Edge case with n <= 0
    std::vector<double> dx3 = {1.0, 2.0, 3.0};
    dscal(0, 2.0, dx3.data(), 1);
    std::cout << "Test 3: Should not modify dx, dx = ";
    printVector(dx3);
    
    return 0;
}