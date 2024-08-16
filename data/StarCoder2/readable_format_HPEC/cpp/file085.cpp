#include <iostream>
#include <vector>
#include <cmath>
#include <omp.h>

int main() {
    int len = 100;
    std::vector<double> a(len);

    for (int i = 0; i < len; ++i) {
        a[i] = i + 1; // Fortran arrays are 1-based, C++ arrays are 0-based
    }

    double u;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);
    u = dis(gen);
    int j = static_cast<int>(std::floor(100 * u));

    #pragma omp parallel for if (j % 2 == 0)
    for (int i = 0; i < len - 1; ++i) {
        a[i + 1] = a[i] + 1;
    }

    std::cout << "a[50] = " << a[50] << std::endl;

    return 0;
}
