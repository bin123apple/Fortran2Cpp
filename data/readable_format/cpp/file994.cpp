#include <iostream>

namespace olbfgs_module {

// Implementation for double precision
double dolbfgs(double a, double b) {
    return a + b;
}

// Implementation for single precision
float solbfgs(float a, float b) {
    return a + b;
}

} // namespace olbfgs_module

int main() {
    double result_d = olbfgs_module::dolbfgs(1.0, 2.0);
    std::cout << "Result (double): " << result_d << std::endl;

    float result_s = olbfgs_module::solbfgs(1.0f, 2.0f);
    std::cout << "Result (single): " << result_s << std::endl;

    return 0;
}