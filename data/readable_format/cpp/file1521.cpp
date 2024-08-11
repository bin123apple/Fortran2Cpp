// Save this as 'moment.cpp'
#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

void moment(const std::vector<double>& data_in, int n, int skip_id, double& ave, double& adev, double& sdev, double& var, double& skew, double& curt) {
    double s = 0.0, ep = 0.0, p = 0.0;
    double n_real = static_cast<double>(n);
    for (int j = 0; j < n; ++j) {
        if (j != skip_id - 1) { // Adjusted for 0-based indexing
            s += data_in[j];
        }
    }
    ave = s / (n_real - 1.0);

    adev = 0.0;
    var = 0.0;
    skew = 0.0;
    curt = 0.0;

    for (int j = 0; j < n; ++j) {
        s = data_in[j] - ave;
        ep += s;
        adev += std::abs(s);
        p = s * s;
        var += p;
        p *= s;
        skew += p;
        p *= s;
        curt += p;
    }

    adev /= (n_real - 1.0);
    var = (var - std::pow(ep, 2) / n_real) / (n_real - 1.0);
    sdev = std::sqrt(var);
    if (var != 0.0) {
        skew = skew / ((n_real - 1.0) * std::pow(sdev, 3));
        curt = curt / ((n_real - 1.0) * var * var) - 3.0;
    } else {
        skew = 0.0;
        curt = 0.0;
    }
}

void test_moment() {
    std::vector<double> data_in = {1.0, 2.0, 3.0, 4.0, 5.0};
    int n = data_in.size();
    int skip_id = 2; // Adjusted to match Fortran's 1-based indexing
    double ave, adev, sdev, var, skew, curt;

    moment(data_in, n, skip_id, ave, adev, sdev, var, skew, curt);

    std::cout << "C++ Outputs:" << std::endl;
    std::cout << "Average: " << ave << std::endl;
    std::cout << "Absolute Deviation: " << adev << std::endl;
    std::cout << "Standard Deviation: " << sdev << std::endl;
    std::cout << "Variance: " << var << std::endl;
    std::cout << "Skewness: " << skew << std::endl;
    std::cout << "Kurtosis: " << curt << std::endl;
}

int main() {
    test_moment();
    return 0;
}