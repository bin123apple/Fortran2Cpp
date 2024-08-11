#include <cmath>
#include <complex>
#include <iostream>

float scnrm2(int n, const std::complex<float>* x, int incx) {
    const float one = 1.0f;
    const float zero = 0.0f;
    float norm, scale, ssq, temp;
    
    if (n < 1 || incx < 1) {
        norm = zero;
    } else {
        scale = zero;
        ssq = one;
        for (int ix = 0; ix < n * incx; ix += incx) {
            if (std::real(x[ix]) != zero) {
                temp = std::abs(std::real(x[ix]));
                if (scale < temp) {
                    ssq = one + ssq * (scale / temp) * (scale / temp);
                    scale = temp;
                } else {
                    ssq += (temp / scale) * (temp / scale);
                }
            }
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
    }
    return norm;
}

int main() {
    const int n = 3; // Size of the array
    const int incx = 1; // Increment
    std::complex<float> x[] = { {1.0f, 2.0f}, {-2.0f, 1.0f}, {0.5f, -0.5f} };
    
    // Expected norm value
    const float expected_norm = 3.201562f;
    float norm = scnrm2(n, x, incx);
    
    std::cout << "Norm: " << norm << std::endl;
    
    // Compare the result with expected value with a tolerance for floating point comparison
    if (std::abs(norm - expected_norm) < 0.0001f) {
        std::cout << "Test passed!" << std::endl;
    } else {
        std::cout << "Test failed!" << std::endl;
    }

    return 0;
}