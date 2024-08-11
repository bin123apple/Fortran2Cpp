#include <iostream>
#include <cmath>
#include <vector>

const int N = 100;

int main() {
    std::vector<std::vector<std::vector<int>>> a(N, std::vector<std::vector<int>>(N, std::vector<int>(N, 1)));
    std::vector<std::vector<std::vector<double>>> b(N, std::vector<std::vector<double>>(N, std::vector<double>(N, 0.5)));
    std::vector<std::vector<std::vector<float>>> c(N, std::vector<std::vector<float>>(N, std::vector<float>(N, 0.25)));

    int sa = 0;
    double sb = 0.0;
    float sc = 0.0;

    for (int k = 0; k < N; ++k) {
        for (int j = 0; j < N; ++j) {
            for (int i = 0; i < N; ++i) {
                sa += a[i][j][k];
            }
        }
    }

    for (int k = 0; k < N; ++k) {
        for (int j = 0; j < N; ++j) {
            for (int i = 0; i < N; ++i) {
                sb += b[i][j][k];
            }
        }
    }

    for (int k = 0; k < N; ++k) {
        for (int j = 0; j < N; ++j) {
            for (int i = 0; i < N; ++i) {
                sc += c[i][j][k];
            }
        }
    }

    int result = 0;
    if (sa != N * N * N ||
        std::abs(sb - (static_cast<double>(N * N * N) * 0.5)) > 0.000001 ||
        std::abs(sc - (static_cast<float>(N * N * N) * 0.25)) > 0.0001) {
        result = -1;
    }

    if (result == 0) {
        std::cout << "PASS" << std::endl;
    } else {
        std::cout << "ERROR" << std::endl;
        return 1;
    }

    return 0;
}