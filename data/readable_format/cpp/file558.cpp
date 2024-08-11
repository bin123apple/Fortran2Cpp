#include <iostream>
#include <vector>

// Function declaration
void loop4_Cpp(int niters, int N, std::vector<double>& x, const std::vector<double>& a, const std::vector<double>& b) {
    for(int iter = 0; iter < niters; ++iter) {
        for(int i = 0; i < N; ++i) {
            x[i] = a[i] + b[i];
        }
    }
}

// Test function
void testLoop4Cpp() {
    int N = 5;
    std::vector<double> x(N), a(N), b(N);

    // Initialize test data
    for(int i = 0; i < N; ++i) {
        a[i] = (i + 1) * 1.0; // Adjusted to match Fortran's 1-based indexing in initialization
        b[i] = (i + 1) * 2.0; // Adjusted to match Fortran's 1-based indexing in initialization
    }

    // Call the function
    loop4_Cpp(1, N, x, a, b);

    // Print results
    for(int i = 0; i < N; ++i) {
        std::cout << "x[" << i << "] = " << x[i] << std::endl;
    }
}

int main() {
    testLoop4Cpp();
    return 0;
}