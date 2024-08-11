#include <iostream>
#include <cassert>
#include <cmath> // For std::abs

// Function definition directly in this file
double damaxf(int n, const double* dx, int incx) {
    if (n < 1 || incx <= 0) return 0.0;

    double damaxf = 0.0;
    int ix;

    if (incx != 1) {
        ix = 0; // Adjusted for 0-based indexing in C++
        damaxf = std::abs(dx[ix]);
        ix += incx;
        for (int i = 1; i < n; i++) {
            if (std::abs(dx[ix]) > damaxf) {
                damaxf = std::abs(dx[ix]);
            }
            ix += incx;
        }
    } else { // Handling unit stride
        damaxf = std::abs(dx[0]);
        for (int i = 1; i < n; i++) {
            if (std::abs(dx[i]) > damaxf) {
                damaxf = std::abs(dx[i]);
            }
        }
    }
    return damaxf;
}

void runTests() {
    {
        // Test 1
        const double dx[] = {1.0, -2.0, 3.0, -4.0, 5.0};
        int n = 5, incx = 1;
        assert(damaxf(n, dx, incx) == 5.0);
        std::cout << "Test 1 passed." << std::endl;
    }

    {
        // Test 2
        const double dx[] = {1.0, 3.0, -7.0, 2.0, 9.0};
        int n = 3, incx = 2;
        assert(damaxf(n, dx, incx) == 9.0);
        std::cout << "Test 2 passed." << std::endl;
    }

    {
        // Test 3
        const double dx[] = {1.0, -2.0, 3.0, -4.0, 5.0}; // Will not be accessed, but provided for completeness
        int n = 0, incx = 1;
        assert(damaxf(n, dx, incx) == 0.0);
        std::cout << "Test 3 passed." << std::endl;
    }

    std::cout << "All tests passed." << std::endl;
}

int main() {
    runTests();
    return 0;
}