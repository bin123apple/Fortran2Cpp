#include <vector>
#include <iostream>
#include <cassert>
#include <cmath> // For std::fabs

// Function prototype is not necessary since the definition is before main in this case.

// Definition of dscal function
void dscal(int n, double da, std::vector<double>& dx, int incx) {
    if (n <= 0 || incx <= 0) return;

    if (incx == 1) {
        int m = n % 5;
        for (int i = 0; i < m; ++i) {
            dx[i] *= da;
        }
        if (n < 5) return;

        for (int i = m; i < n; i += 5) {
            dx[i] *= da;
            dx[i + 1] *= da;
            dx[i + 2] *= da;
            dx[i + 3] *= da;
            dx[i + 4] *= da;
        }
    } else {
        int nincx = n * incx;
        for (int i = 0; i < nincx; i += incx) {
            dx[i] *= da;
        }
    }
}

// Test function for dscal
void testDscal() {
    int n = 5;
    double da = 2.0;
    std::vector<double> dx = {1.0, 2.0, 3.0, 4.0, 5.0};
    int incx = 1;

    dscal(n, da, dx, incx);

    // Check results with assertions to make sure each element was scaled correctly
    for (int i = 0; i < n; ++i) {
        assert(std::fabs(dx[i] - da * (i + 1)) < 1e-9);
    }

    std::cout << "All tests passed." << std::endl;
}

// Main function to run the test
int main() {
    testDscal();
    return 0;
}