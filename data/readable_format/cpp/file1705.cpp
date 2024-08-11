#include <iostream>
#include <vector>
#include <complex>
#include <cmath>

// Define the scnrm2 function within the same file
float scnrm2(int n, const std::complex<float>* x, int incx) {
    float one = 1.0f, zero = 0.0f;
    if (n < 1 || incx < 1) {
        return zero;
    }

    float norm = zero, scale = zero, ssq = one, temp;
    
    for (int ix = 0; ix < n * incx; ix += incx) {
        // Handle real part
        if (std::real(x[ix]) != zero) {
            temp = std::abs(std::real(x[ix]));
            if (scale < temp) {
                ssq = one + ssq * (scale / temp) * (scale / temp);
                scale = temp;
            } else {
                ssq += (temp / scale) * (temp / scale);
            }
        }
        // Handle imaginary part
        if (std::imag(x[ix]) != zero) {
            temp = std::abs(std::imag(x[ix]));
            if (scale < temp) {
                ssq = one + ssq * (scale / temp) * (scale / temp);
                scale = temp;
            } else {
                ssq += (temp / scale) * (temp / scale);
            }
        }
    }
    
    norm = scale * std::sqrt(ssq);
    return norm;
}

// Test function for scnrm2
void testScnrm2() {
    // Test 1
    int N = 3, INCX = 1;
    std::vector<std::complex<float>> x1 = {{1, 1}, {2, 2}, {3, 3}};
    float result1 = scnrm2(N, x1.data(), INCX);
    std::cout << "Test 1 Result: " << result1 << std::endl;

    // Test 2
    N = 4; INCX = 2;
    std::vector<std::complex<float>> x2 = {{0.5, -0.5}, {1, -1}, {1.5, -1.5}, {2, -2}};
    float result2 = scnrm2(N, x2.data(), INCX);
    std::cout << "Test 2 Result: " << result2 << std::endl;
}

int main() {
    testScnrm2();
    return 0;
}