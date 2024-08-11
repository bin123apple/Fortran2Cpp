#include <vector>
#include <complex>
#include <iostream>

void ZLA_WWADDW(int N, std::vector<std::complex<double>>& X, std::vector<std::complex<double>>& Y, const std::vector<std::complex<double>>& W) {
    std::complex<double> S;
    for (int i = 0; i < N; ++i) {
        S = X[i] + W[i];
        Y[i] = ((X[i] - S) + W[i]) + Y[i];
        X[i] = S;
    }
}

int main() {
    int N = 3;
    std::vector<std::complex<double>> X{{1, 1}, {2, 2}, {3, 3}};
    std::vector<std::complex<double>> Y{{1, -1}, {1, -1}, {1, -1}};
    std::vector<std::complex<double>> W{{0.5, 0.5}, {0.5, 0.5}, {0.5, 0.5}};

    ZLA_WWADDW(N, X, Y, W);

    for (int i = 0; i < N; ++i) {
        std::cout << "X[" << i << "] = " << X[i] << " Y[" << i << "] = " << Y[i] << std::endl;
    }

    return 0;
}