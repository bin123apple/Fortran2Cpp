#include <iostream>
#include <cmath>
#include <algorithm> // For std::max_element
#include <vector>

int main() {
    const int size = 1001;
    std::vector<double> x(size), y(size);
    
    for (int j = 0; j < size; ++j) {
        x[j] = -20.0 + j * 40.0 / 1000.0;
        y[j] = sin(x[j]) / x[j];
    }

    // Finding the maximum value in y
    auto max_iter = std::max_element(y.begin(), y.end());
    double max_value_of_y = *max_iter;
    
    std::cout << "The max value of y is " << max_value_of_y << std::endl;
    std::cout << "x(501) is " << x[500] << std::endl; // Note: C++ uses 0-based indexing
    std::cout << "y(501) is " << y[500] << std::endl;

    return 0;
}