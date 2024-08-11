#include <cmath>
#include <vector>
#include <stdexcept>
#include <iostream>

namespace nt_FunctionsModule {

    double nt_logistic(double x, const std::vector<double>& args) {
        if (args.size() < 3) {
            throw std::invalid_argument("args vector must have at least 3 elements");
        }
        return args[0] / (args[1] + std::exp(-args[2] * x));
    }

    double logisticd(const std::vector<double>& args, double x) {
        (void)args; // Silence unused parameter warning
        return 2.0 / (1.0 + std::exp(-2.0 * x)) - 1.0;
    }

    double const_func(const std::vector<double>& args, double x) {
        if (args.empty()) {
            throw std::invalid_argument("args vector must have at least 1 element");
        }
        return args[0];
    }

    double constd(const std::vector<double>& args, double x) {
        if (args.empty()) {
            throw std::invalid_argument("args vector must have at least 1 element");
        }
        return args[0] / 2.0;
    }

} // End of namespace nt_FunctionsModule

int main() {
    // Test the functions
    std::vector<double> args1 = {1.0, 2.0, 1.0}; // Adjusted to match the expected argument size
    double x = 1.0;

    try {
        double result1 = nt_FunctionsModule::nt_logistic(x, args1);
        std::cout << "nt_logistic: " << result1 << std::endl;

        double result2 = nt_FunctionsModule::logisticd(args1, x);
        std::cout << "logisticd: " << result2 << std::endl;

        double result3 = nt_FunctionsModule::const_func(args1, x);
        std::cout << "const_func: " << result3 << std::endl;

        double result4 = nt_FunctionsModule::constd(args1, x);
        std::cout << "constd: " << result4 << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1; // Return with error code
    }

    return 0; // Successful execution
}