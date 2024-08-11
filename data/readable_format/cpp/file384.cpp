#include <vector>
#include <iostream>
#include <cmath>

class DynamicalSystemsFunction {
public:
    std::vector<double> bogdanovTakensBifurcation(double x, const std::vector<double>& y) {
        return {y[0] + x, y[1] - x};
    }

    std::vector<double> pendulum(double x, const std::vector<double>& y) {
        return {y[0] - x, y[1] + x};
    }

    std::vector<double> lorenz(double x, const std::vector<double>& y) {
        return {-y[0] + x, -y[1] + x * y[0], y[2]};
    }
};

int main() {
    DynamicalSystemsFunction ds;

    // Test for Bogdanov-Takens Bifurcation
    auto resultBogdanov = ds.bogdanovTakensBifurcation(1.0, {0.5, -0.5});
    std::cout << "Bogdanov-Takens result: " << resultBogdanov[0] << ", " << resultBogdanov[1] << std::endl;

    // Test for Pendulum
    auto resultPendulum = ds.pendulum(9.8, {3.14159/4, 0.0});
    std::cout << "Pendulum result: " << resultPendulum[0] << ", " << resultPendulum[1] << std::endl;

    // Test for Lorenz Attractor
    auto resultLorenz = ds.lorenz(28.0, {1.0, 1.0, 1.0});
    std::cout << "Lorenz result: " << resultLorenz[0] << ", " << resultLorenz[1] << ", " << resultLorenz[2] << std::endl;

    return 0;
}