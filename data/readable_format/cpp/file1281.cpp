#include <cmath>
#include <vector>
#include <iostream>
#include <functional>

// Function prototypes
double func12(double x);
double funcm12(double x);

// chebft translated to C++
void chebft(double a, double b, std::vector<double>& c, int n, std::function<double(double)> func) {
    double pi = 4.0 * atan(1.0);
    double bma = 0.5 * (b - a);
    double bpa = 0.5 * (b + a);
    std::vector<double> f(n);

    for (int k = 1; k <= n; ++k) {
        double y = cos(pi * (k - 0.5) / n);
        f[k - 1] = func(y * bma + bpa); // Adjusted index for 0-based C++ arrays
    }
    
    double fac = 2.0 / n;
    for (int j = 1; j <= n; ++j) {
        double sum = 0.0;
        for (int k = 1; k <= n; ++k) {
            sum += f[k - 1] * cos((pi * (j - 1)) * ((k - 0.5) / n)); // Adjusted index
        }
        c[j - 1] = fac * sum; // Adjusted index
    }
}

double func12(double x) {
    return std::pow(x, 0.5);
}

double funcm12(double x) {
    return 1.0 / std::pow(x, 0.5);
}

// Simple test function to verify the functionality
void testFunction(std::function<double(double)> func, const std::string& functionName) {
    std::vector<double> c(10);
    chebft(0.0, 1.0, c, 10, func);

    std::cout << "Results for " << functionName << ":" << std::endl;
    for (double val : c) {
        std::cout << val << std::endl;
    }
    std::cout << "-----------------------------" << std::endl;
}

// Main function demonstrating how to use the test function
int main() {
    testFunction(func12, "func12");
    testFunction(funcm12, "funcm12");

    return 0;
}