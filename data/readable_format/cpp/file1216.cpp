#include <iostream>
#include <vector>

void loop23_F77(int N, std::vector<double>& x, const std::vector<double>& a, 
                const std::vector<double>& b, const std::vector<double>& c, 
                const std::vector<double>& d, std::vector<double>& y) {
    for (int i = 0; i < N; ++i) {
        x[i] = a[i] * b[i] + c[i] * d[i];
        y[i] = b[i] + d[i];
    }
}

void loop23_F77Overhead(int N, std::vector<double>& x, const std::vector<double>& a, 
                        const std::vector<double>& b, const std::vector<double>& c, 
                        const std::vector<double>& d, std::vector<double>& y) {
    // This function intentionally left blank
}

int main() {
    const int N = 5;
    std::vector<double> x(N), a(N), b(N), c(N), d(N), y(N);

    // Initialize arrays
    for (int i = 0; i < N; ++i) {
        a[i] = (i + 1) * 1.0;
        b[i] = (i + 1) * 2.0;
        c[i] = (i + 1) * 3.0;
        d[i] = (i + 1) * 4.0;
    }

    // Call the function
    loop23_F77(N, x, a, b, c, d, y);

    // Print results
    std::cout << "x = ";
    for (const auto& val : x) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << "y = ";
    for (const auto& val : y) std::cout << val << " ";
    std::cout << std::endl;

    // Call the overhead function (which does nothing)
    loop23_F77Overhead(N, x, a, b, c, d, y);

    return 0;
}