#include <iostream>
#include <cmath> // For std::fabs

// Assuming the correct signature and implementation of floop19_F77 from the translation
void floop19_F77(int N, float* y, float* x, float* a, float* b, float u, float v) {
    for(int i = 0; i < N; ++i) {
        x[i] = u * a[i];
        y[i] = v * b[i];
    }
}

// Unit test function
void testFloop19_F77() {
    const int N = 5;
    float y[N], x[N], a[N] = {1.0, 2.0, 3.0, 4.0, 5.0}, b[N] = {5.0, 4.0, 3.0, 2.0, 1.0};
    float u = 2.0, v = 3.0;
    float expectedX[N] = {2.0, 4.0, 6.0, 8.0, 10.0};
    float expectedY[N] = {15.0, 12.0, 9.0, 6.0, 3.0};
    
    floop19_F77(N, y, x, a, b, u, v);

    bool passed = true;
    for(int i = 0; i < N; ++i) {
        if(std::fabs(x[i] - expectedX[i]) > 0.001 || std::fabs(y[i] - expectedY[i]) > 0.001) {
            std::cerr << "Test failed for index " << i << " x[i]: " << x[i] << ", expectedX[i]: " << expectedX[i]
                      << ", y[i]: " << y[i] << ", expectedY[i]: " << expectedY[i] << std::endl;
            passed = false;
        }
    }
    
    if(passed) {
        std::cout << "All tests passed!" << std::endl;
    }
}

// Main function to run the test
int main() {
    testFloop19_F77();
    return 0;
}