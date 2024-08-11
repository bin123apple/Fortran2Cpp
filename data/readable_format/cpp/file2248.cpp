#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>

class DLANST {
public:
    static double compute(char NORM, int N, const std::vector<double>& D, const std::vector<double>& E);
};

double DLANST::compute(char NORM, int N, const std::vector<double>& D, const std::vector<double>& E) {
    double sum_squares = 0.0;
    for (int i = 0; i < N; ++i) {
        sum_squares += D[i] * D[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        sum_squares += E[i] * E[i];
    }
    return std::sqrt(sum_squares);
}

int main() {
    std::vector<double> D = {1.0, 2.0, 3.0};
    std::vector<double> E = {0.5, 1.5};
    char NORM = 'F';
    int N = 3;

    double result = DLANST::compute(NORM, N, D, E);
    std::cout << "C++ Result: " << result << std::endl;

    // Assuming an acceptable small difference due to floating point arithmetic
    assert(std::abs(result - 4.062019) < 1e-5);
    std::cout << "Test passed!" << std::endl;

    return 0;
}