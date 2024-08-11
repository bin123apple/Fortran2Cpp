#include <iostream>
#include <vector>
#include <cassert>

// Definition of dsum function
double dsum(int n, const std::vector<double>& dx, int incx) {
    double dtemp = 0.0;
    double result = 0.0;
    int i, m, mp1, nincx;
    
    if (n <= 0 || incx <= 0) return 0.0;
    
    if (incx != 1) {
        nincx = n * incx;
        for (i = 0; i < nincx; i += incx) {
            dtemp += dx[i];
        }
        result = dtemp;
    } else {
        m = n % 6;
        for (i = 0; i < m; ++i) {
            dtemp += dx[i];
        }
        if (n < 6) {
            result = dtemp;
            return result;
        }
        mp1 = m;
        for (i = mp1; i < n; i += 6) {
            dtemp += dx[i] + dx[i + 1] + dx[i + 2] + dx[i + 3] + dx[i + 4] + dx[i + 5];
        }
        result = dtemp;
    }
    return result;
}

// Test runner function
void runTest(int testId, int n, std::vector<double> dx, int incx, double expected) {
    double result = dsum(n, dx, incx);
    std::cout << "Test " << testId << " (n=" << n << ", incx=" << incx << "): Result = " << result << ", Expected = " << expected << std::endl;
    assert(abs(result - expected) < 1e-6); // Using an epsilon value for floating-point comparison
}

int main() {
    // Test cases
    runTest(1, 10, {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0}, 1, 55.0);
    runTest(2, 6, {1.0, -1.0, 2.0, -2.0, 3.0, -3.0}, 2, 6.0);
    runTest(3, 3, {1.0, 100.0, -50.0}, 3, 1.0);

    std::cout << "All tests passed successfully." << std::endl;

    return 0;
}