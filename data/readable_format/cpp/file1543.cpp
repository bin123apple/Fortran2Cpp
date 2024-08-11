#include <iostream>
#include <complex>
#include <vector>

// Declaration and definition of the caxpy function
void caxpy(int n, std::complex<float> ca, std::complex<float>* cx, int incx, std::complex<float>* cy, int incy) {
    if (n <= 0) return;
    if (std::abs(ca.real()) + std::abs(ca.imag()) == 0.0f) return;

    if (incx == 1 && incy == 1) {
        // Process without increments
        for (int i = 0; i < n; ++i) {
            cy[i] = cy[i] + ca * cx[i];
        }
    } else {
        // Process with increments
        int ix = 0;
        int iy = 0;
        if (incx < 0) ix = (-n + 1) * incx;
        if (incy < 0) iy = (-n + 1) * incy;
        for (int i = 0; i < n; ++i) {
            cy[iy] = cy[iy] + ca * cx[ix];
            ix += incx;
            iy += incy;
        }
    }
}

// Test scenarios for the caxpy function
void test_scenario(int n, std::complex<float> ca, int incx, int incy) {
    std::vector<std::complex<float>> cx(n, {0, 0}), cy(n, {0, 0});

    // Initialize vectors
    for (int i = 0; i < n; ++i) {
        cx[i] = std::complex<float>(i+1, -(i+1));
        cy[i] = std::complex<float>(n-i-1, -(n-i-1));
    }

    // Call caxpy
    caxpy(n, ca, cx.data(), incx, cy.data(), incy);

    // Output the result for verification
    std::cout << "Result for n=" << n << ", ca=" << ca << ", incx=" << incx << ", incy=" << incy << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << "cy[" << i << "] = " << cy[i] << std::endl;
    }
}

int main() {
    // Test 1: n is zero
    test_scenario(0, {1.0, 2.0}, 1, 1);

    // Test 2: ca is zero
    test_scenario(5, {0.0, 0.0}, 1, 1);

    // Test 3: incx and incy are both 1
    test_scenario(5, {1.0, 2.0}, 1, 1);

    // Test 4: incx and incy are not 1
    test_scenario(5, {1.0, 2.0}, 2, 3);

    return 0;
}