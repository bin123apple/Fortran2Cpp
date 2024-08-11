#include <iostream>
#include <vector>

double fdot(const std::vector<double>& a, const std::vector<double>& b, int n) {
    double fdot = 0.0;
    for (int i = 0; i < n; ++i) {
        fdot += a[i] * b[i];
    }
    return fdot;
}

int main() {
    // Example usage
    std::vector<double> a = {1.0, 2.0, 3.0};
    std::vector<double> b = {4.0, 5.0, 6.0};
    int n = 3;

    double result = fdot(a, b, n);
    std::cout << "Dot product: " << result << std::endl;

    return 0;
}