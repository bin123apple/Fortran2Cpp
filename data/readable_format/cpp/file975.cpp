#include <iostream>
#include <vector>
#include <cmath>

class MyMath {
public:
    static double Lagrange(const std::vector<double>& x, const std::vector<double>& y, double z, int n) {
        double fn = 0.0;
        for (int i = 0; i < n; ++i) {
            double prod = 1.0;
            for (int j = 0; j < n; ++j) {
                if (j == i) {
                    continue;
                }
                prod *= (z - x[j]) / (x[i] - x[j]);
            }
            fn += prod * y[i];
        }
        return fn;
    }
};

void assert_approx_equal(double value1, double value2, double tol) {
    if (std::abs(value1 - value2) > tol) {
        std::cerr << "Test failed: " << value1 << " != " << value2 << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

int main() {
    // Test case 1
    std::vector<double> x = {1.0, 2.0, 3.0};
    std::vector<double> y = {2.0, 4.0, 6.0};
    double z = 2.5;
    double expected = 5.0;
    double result = MyMath::Lagrange(x, y, z, 3);
    assert_approx_equal(result, expected, 1.0e-5);
    
    // Test case 2
    z = 1.0;
    expected = 2.0;
    result = MyMath::Lagrange(x, y, z, 3);
    assert_approx_equal(result, expected, 1.0e-5);
    
    // Test case 3
    z = 3.0;
    expected = 6.0;
    result = MyMath::Lagrange(x, y, z, 3);
    assert_approx_equal(result, expected, 1.0e-5);

    std::cout << "All C++ tests passed." << std::endl;

    return 0;
}