#include <iostream>

void floop17_F77(int N, float* x, float* a, float* b, float* c, float* d) {
    for (int i = 0; i < N; i++) {
        x[i] = (a[i] + b[i]) * (c[i] + d[i]);
    }
}

int main() {
    // Example usage
    const int N = 5;
    float x[N] = {0};
    float a[N] = {1, 2, 3, 4, 5};
    float b[N] = {2, 3, 4, 5, 6};
    float c[N] = {3, 4, 5, 6, 7};
    float d[N] = {4, 5, 6, 7, 8};

    floop17_F77(N, x, a, b, c, d);

    // Output the result
    for (int i = 0; i < N; i++) {
        std::cout << "x[" << i << "] = " << x[i] << std::endl;
    }

    return 0;
}