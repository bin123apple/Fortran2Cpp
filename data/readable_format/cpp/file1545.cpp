#include <vector>
#include <cassert>
#include <iostream>
#include <cmath>

// Implementation of the linspace function in C++
std::vector<double> linspace(double a, double b, int n) {
    if (n <= 0) {
        throw std::invalid_argument("n must be greater than 0.");
    }
    std::vector<double> x(n);
    double s = (n == 1) ? 0 : (b - a) / (n - 1.0);
    for (int i = 0; i < n; ++i) {
        x[i] = a + s * i;
    }
    return x;
}

int main() {
    try {
        // Normal case
        {
            auto array = linspace(0, 10, 5);
            assert(array.size() == 5);
            assert(array[0] == 0);
            assert(array[4] == 10);
            std::cout << "Normal case passed." << std::endl;
        }

        // Edge case: n=1
        {
            auto array = linspace(0, 10, 1);
            assert(array.size() == 1);
            assert(array[0] == 0);
            std::cout << "Edge case n=1 passed." << std::endl;
        }

        // Edge case: n is a very large number
        {
            auto array = linspace(0, 10, 100000);
            assert(array.size() == 100000);
            assert(array[0] == 0);
            assert(array[99999] == 10);
            std::cout << "Edge case large n passed." << std::endl;
        }

        std::cout << "All tests passed." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Test failed with exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}