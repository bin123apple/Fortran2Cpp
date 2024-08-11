#include <iostream>
#include <vector>
#include <cmath> // For std::abs

// Function declaration and definition in the same file
void loop12_F77(int N, std::vector<double>& y, const std::vector<double>& a, std::vector<double>& x, 
                const std::vector<double>& b, const std::vector<double>& c, const std::vector<double>& d, double u) {
    for (int i = 0; i < N; i++) {
        y[i] = u + a[i];
        x[i] = a[i] + b[i] + c[i] + d[i];
    }
}

// Helper function to compare double values with a tolerance
bool areEqual(double a, double b, double tolerance = 1e-6) {
    return std::abs(a - b) < tolerance;
}

int main() {
    const int N = 5;
    std::vector<double> y(N), a(N), x(N), b(N), c(N), d(N);
    double u = 1.0;

    // Initialize vectors with test values
    for (int i = 0; i < N; i++) {
        a[i] = (i + 1) * 1.0;
        b[i] = (i + 1) * 2.0;
        c[i] = (i + 1) * 3.0;
        d[i] = (i + 1) * 4.0;
    }

    // Call the function
    loop12_F77(N, y, a, x, b, c, d, u);

    // Check and print the results
    for (int i = 0; i < N; i++) {
        if (!areEqual(y[i], u + a[i]) || !areEqual(x[i], a[i] + b[i] + c[i] + d[i])) {
            std::cout << "Test Failed for index " << i << std::endl;
        } else {
            std::cout << "y[" << i << "] = " << y[i] << ", x[" << i << "] = " << x[i] << std::endl;
        }
    }

    return 0;
}