#include <vector>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>

namespace numerics {

    void linspace(double x_min, double x_max, std::vector<double>& x_arr, double& dx) {
        std::size_t n_x = x_arr.size();
        dx = (x_max - x_min) / (n_x - 1);

        for (std::size_t i_x = 0; i_x < n_x; ++i_x) {
            x_arr[i_x] = x_min + i_x * dx;
        }
    }

}

void test_linspace() {
    double x_min = 0.0;
    double x_max = 10.0;
    std::size_t n_x = 10;
    std::vector<double> x_arr(n_x);
    double dx;

    numerics::linspace(x_min, x_max, x_arr, dx);

    double expected_dx = (x_max - x_min) / (n_x - 1);
    assert(std::fabs(dx - expected_dx) < 1e-10);

    for (std::size_t i_x = 0; i_x < n_x; ++i_x) {
        double expected_value = x_min + i_x * expected_dx;
        assert(std::fabs(x_arr[i_x] - expected_value) < 1e-10);
    }

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    test_linspace();
    return 0;
}