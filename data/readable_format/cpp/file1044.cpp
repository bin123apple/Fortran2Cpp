#include <vector>
#include <cassert>
#include <cmath>
#include <iostream> // Include for std::cout and std::endl

// Define the loop17_F77 function based on the translated version
void loop17_F77(int N, std::vector<double>& x, const std::vector<double>& a, const std::vector<double>& b, const std::vector<double>& c, const std::vector<double>& d) {
    for (int i = 0; i < N; ++i) {
        x[i] = (a[i] + b[i]) * (c[i] + d[i]);
    }
}

// Main function to run the unit test
int main() {
    const int N = 5;
    std::vector<double> x(N), a(N), b(N), c(N), d(N);

    // Initialize test data
    for (int i = 0; i < N; ++i) {
        a[i] = i + 1.0; // Adjusting for one-based index equivalent in values
        b[i] = (i + 1.0) * 2.0;
        c[i] = (i + 1.0) * 3.0;
        d[i] = (i + 1.0) * 4.0;
    }

    // Call the function
    loop17_F77(N, x, a, b, c, d);

    // Check results
    for (int i = 0; i < N; ++i) {
        assert(std::abs(x[i] - (a[i] + b[i]) * (c[i] + d[i])) < 1e-9); // Using a small threshold for floating point comparison
    }

    std::cout << "Test Passed" << std::endl;

    return 0;
}