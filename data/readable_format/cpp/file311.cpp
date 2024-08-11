#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

// Function declarations
void avevar(const double* data, int n, double& ave, double& var);
void avevar2(const double* data, double* data2, int n, double& ave, double& var);

int main() {
    std::vector<double> data = {1.0, 2.0, 3.0, 4.0, 5.0};
    int n = data.size();
    std::vector<double> data2(n, 0.0);
    double ave, var;

    avevar(data.data(), n, ave, var);
    std::cout << "Test avevar" << std::endl;
    std::cout << "Average: " << ave << std::endl;
    std::cout << "Variance: " << var << std::endl;

    avevar2(data.data(), data2.data(), n, ave, var);
    std::cout << "Test avevar2" << std::endl;
    std::cout << "Average: " << ave << std::endl;
    std::cout << "Variance: " << var << std::endl;
    std::cout << "Filtered Data (n <= 3*std): ";
    for (const auto& d : data2) {
        if (d != 0.0) std::cout << d << " ";
    }
    std::cout << std::endl;

    return 0;
}

// Function implementations
void avevar(const double* data, int n, double& ave, double& var) {
    int m;
    double s, ep = 0.0;
    ave = 0.0;
    m = std::min(1000, n);
    for (int j = 0; j < m; j++) {
        ave += data[j];
    }
    ave /= m;
    var = 0.0;
    for (int j = 0; j < n; j++) {
        s = data[j] - ave;
        ep += s;
        var += s * s;
    }
    var = (var - ep * ep / n) / (n - 1);
}

void avevar2(const double* data, double* data2, int n, double& ave, double& var) {
    int n2 = 0;
    double s, ep = 0.0, std;
    var = 0.0;
    for (int j = 0; j < n; j++) {
        s = data[j] - ave;
        ep += s;
        var += s * s;
    }
    var = (var - ep * ep / n) / (n - 1);
    std = sqrt(var);

    for (int i = 0; i < 1; i++) {
        n2 = 0;
        for (int j = 0; j < n; j++) {
            if (std::abs(data[j] - ave) < 3.0 * std) {
                data2[n2] = data[j];
                n2++;
            }
        }

        var = 0.0;
        ep = 0.0;
        for (int j = 0; j < n2; j++) {
            s = data2[j] - ave;
            ep += s;
            var += s * s;
        }
        var = (var - ep * ep / n2) / (n2 - 1);
    }
}