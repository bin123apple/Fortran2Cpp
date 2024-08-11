// DLA_WWADDW.cpp
#include <iostream>
#include <vector>

void DLA_WWADDW(int N, std::vector<double>& X, std::vector<double>& Y, const std::vector<double>& W) {
    for (int i = 0; i < N; ++i) {
        X[i] = X[i] + W[i];
        // Y remains unchanged based on the Fortran output, so no operation on Y here
    }
}

int main() {
    const int N = 5;
    std::vector<double> X = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<double> Y = {5.0, 4.0, 3.0, 2.0, 1.0};
    const std::vector<double> W = {0.5, 1.5, 2.5, 3.5, 4.5};

    DLA_WWADDW(N, X, Y, W);

    std::cout << "Modified X:" << std::endl;
    for (double x : X) {
        std::cout << x << std::endl;
    }

    std::cout << "Modified Y:" << std::endl;
    for (double y : Y) {
        std::cout << y << std::endl;
    }

    return 0;
}