#include <iostream>
#include <cassert>
#include <cmath>

// Define the translated function here
void floop16_F90(int N, float* y, float* x, const float* a, const float* b, const float* c, float u) {
    for (int i = 0; i < N; ++i) {
        x[i] = a[i] + b[i] + c[i];
        y[i] = x[i] + c[i] + u;
    }
}

// Unit test function
void testFloop16_F90() {
    const int N = 5;
    float y[N], x[N], a[N] = {1, 2, 3, 4, 5}, b[N] = {1, 2, 3, 4, 5}, c[N] = {1, 2, 3, 4, 5}, u = 2;
    float expectedX[N] = {3, 6, 9, 12, 15};
    float expectedY[N] = {6, 10, 14, 18, 22};

    floop16_F90(N, y, x, a, b, c, u);

    for (int i = 0; i < N; ++i) {
        assert(std::abs(x[i] - expectedX[i]) < 0.001);
        assert(std::abs(y[i] - expectedY[i]) < 0.001);
    }

    std::cout << "Test passed!" << std::endl;
}

int main() {
    testFloop16_F90();
    return 0;
}