#include <iostream>
#include <vector>
#include <cmath>

void trdisb(int n, std::vector<double>& a, std::vector<double>& b, std::vector<double>& c, std::vector<double>& d) {
    d[0] = d[0] / b[0];
    for (int k = 1; k < n; ++k) {
        int km1 = k - 1;
        d[k] = (d[k] - a[km1] * d[km1]) / b[k];
    }
    for (int k = n - 2; k >= 0; --k) {
        d[k] = d[k] - c[k] * d[k + 1];
    }
}

int main() {
    std::vector<double> a = {1.0, 2.0, 3.0};
    std::vector<double> b = {4.0, 5.0, 6.0};
    std::vector<double> c = {7.0, 8.0, 9.0};
    std::vector<double> d = {10.0, 11.0, 12.0};

    trdisb(3, a, b, c, d);

    std::cout << "Modified d: ";
    for (const auto& val : d) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}