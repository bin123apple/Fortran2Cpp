#include <iostream>
#include <vector>

void floop18_F90(int N, std::vector<float>& x, const std::vector<float>& a, const std::vector<float>& b, float u, float v) {
    for (int i = 0; i < N; ++i) {
        x[i] = (u + a[i]) * (v + b[i]);
    }
}

void floop18_F90Overhead(int N, std::vector<float>& x, const std::vector<float>& a, const std::vector<float>& b, float u, float v) {
    // No operation
}

int main() {
    int N = 10; // Example size
    std::vector<float> x(N), a(N), b(N);
    float u = 1.0f, v = 2.0f;

    // Initialize a and b for demonstration
    for (int i = 0; i < N; ++i) {
        a[i] = i;      // Matches Fortran's adjusted initialization
        b[i] = i + 1;  // Matches Fortran
    }

    // Call the function
    floop18_F90(N, x, a, b, u, v);

    // Output the results
    std::cout << "Results from C++:" << std::endl;
    for (int i = 0; i < N; ++i) {
        std::cout << "x[" << i << "] = " << x[i] << std::endl;
    }

    return 0;
}