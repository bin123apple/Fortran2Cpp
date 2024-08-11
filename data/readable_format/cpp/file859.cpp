#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

double calculate_pi(int64_t npts) {
    double sum = 0.0;
    double x;
    
    srand(static_cast<unsigned>(time(0)));
    for (int64_t i = 0; i < npts; ++i) {
        x = static_cast<double>(rand()) / RAND_MAX;
        sum += 4.0 / (1.0 + x * x);
    }
    return sum / static_cast<double>(npts);
}

int main() {
    int64_t npts = 10000; // Reduced for testing
    double pi_estimate = calculate_pi(npts);
    std::cout << "Estimated PI = " << pi_estimate << std::endl;
    return 0;
}