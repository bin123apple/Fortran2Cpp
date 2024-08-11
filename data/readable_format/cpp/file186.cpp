#include <iostream>
#include <vector>
#include <stdexcept> // For std::invalid_argument
#include <numeric> // For std::inner_product

double dot(const std::vector<double>& x, const std::vector<double>& y);

int main() {
    std::vector<double> x = {1.0, 2.0, 3.0};
    std::vector<double> y = {4.0, 5.0, 6.0};

    try {
        double result = dot(x, y);
        std::cout << "Dot product is: " << result << std::endl;
        // Expected output: Dot product is: 32.0
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

double dot(const std::vector<double>& x, const std::vector<double>& y) {
    if (x.size() != y.size()) {
        throw std::invalid_argument("Vectors x and y must be of the same size.");
    }
    double result = std::inner_product(x.begin(), x.end(), y.begin(), 0.0);
    return result;
}