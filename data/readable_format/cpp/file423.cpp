#include <iostream>
#include <cmath>

class Fonction {
public:
    static constexpr double f_sigma = 1.0;
    static constexpr double f_mu = 0.0;
    static constexpr double pi = 3.14159265359;

    static double unefonction(double x) {
        return (std::exp(x) - 10.0) / (x + 2.0);
    }

    static double gaussienne(double x, double mu = f_mu, double sigma = f_sigma) {
        double norme = 1.0 / (sigma * std::sqrt(2.0 * pi));
        return norme * std::exp(-std::pow(x - mu, 2) / (2.0 * std::pow(sigma, 2)));
    }
};

// Manual testing
void test_unefonction() {
    double x = 1.0;
    double result = Fonction::unefonction(x);
    std::cout << "unefonction(" << x << ") = " << result << std::endl;
}

void test_gaussienne() {
    double x = 0.0;
    double mu = 0.0;
    double sigma = 2.0;
    double result_with_defaults = Fonction::gaussienne(x);
    double result_with_params = Fonction::gaussienne(x, mu, sigma);
    std::cout << "gaussienne(" << x << ") with defaults = " << result_with_defaults << std::endl;
    std::cout << "gaussienne(" << x << ", " << mu << ", " << sigma << ") = " << result_with_params << std::endl;
}

int main() {
    test_unefonction();
    test_gaussienne();
    return 0;
}