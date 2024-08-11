#include <iostream>
#include <vector>
using namespace std;

// Function prototype
double dsdot(int n, float sx[], int incx, float sy[], int incy);

void testDSDOT() {
    // Test 1: Basic functionality
    vector<float> sx = {1.0f, 2.0f, 3.0f, 4.0f};
    vector<float> sy = {1.0f, 1.0f, 1.0f, 1.0f};
    int n = 4;
    int incx = 1, incy = 1;
    cout << "Test 1 Result: " << dsdot(n, sx.data(), incx, sy.data(), incy) << endl;  // Expected: 10.0

    // Test 2: Positive increments
    sx = {1.0f, -1.0f, 2.0f, -2.0f};
    sy = {1.0f, 2.0f, 3.0f, 4.0f};
    incx = 2;
    incy = 2;
    cout << "Test 2 Result: " << dsdot(n, sx.data(), incx, sy.data(), incy) << endl;  // Expected: 7.0

    // Test 3: Zero and negative increments
    sx = {2.0f, 0.0f, -2.0f, 0.0f};
    sy = {0.0f, 3.0f, 0.0f, -3.0f};
    incx = -1;
    incy = -1;
    cout << "Test 3 Result: " << dsdot(2, sx.data(), incx, sy.data(), incy) << endl;  // Expected: 6.0
}

// Function definition
double dsdot(int n, float sx[], int incx, float sy[], int incy) {
    double dsdot = 0.0;
    if (n <= 0) return dsdot;

    if (incx == incy && incx > 0) {
        int ns = n * incx;
        for (int i = 0; i < ns; i += incx) {
            dsdot += static_cast<double>(sx[i]) * static_cast<double>(sy[i]);
        }
    } else {
        int kx = 0;
        int ky = 0;
        if (incx < 0) kx = (1 - n) * incx;
        if (incy < 0) ky = (1 - n) * incy;
        for (int i = 0; i < n; ++i) {
            dsdot += static_cast<double>(sx[kx]) * static_cast<double>(sy[ky]);
            kx += incx;
            ky += incy;
        }
    }

    return dsdot;
}

int main() {
    testDSDOT();
    return 0;
}