#include <iostream>
#include <vector>
#include <cmath>

double ddwnrm(int neq, const double* v, const double* rwt, const double*, const int*) {
    double vmax = 0.0;
    for (int i = 0; i < neq; ++i) {
        double absVal = std::abs(v[i] * rwt[i]);
        if (absVal > vmax) vmax = absVal;
    }

    if (vmax <= 0.0) return 0.0;

    double sum = 0.0;
    for (int i = 0; i < neq; ++i) {
        sum += std::pow((v[i] * rwt[i]) / vmax, 2);
    }

    return vmax * std::sqrt(sum / neq);
}

int main() {
    // Test case 1
    std::vector<double> v = {1.0, 2.0, 3.0};
    std::vector<double> rwt = {0.5, 1.0, 1.5};
    std::cout << "Test Case 1: Expected result is close to 2.85774" << std::endl;
    double result = ddwnrm(v.size(), v.data(), rwt.data(), nullptr, nullptr);
    std::cout << "Result: " << result << std::endl;

    // Test case 2
    v = {4.0, -3.0};
    rwt = {1.0, 1.0};
    std::cout << "Test Case 2: Expected result is close to 3.53553" << std::endl;
    result = ddwnrm(v.size(), v.data(), rwt.data(), nullptr, nullptr);
    std::cout << "Result: " << result << std::endl;

    return 0;
}