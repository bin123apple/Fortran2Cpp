#include <iostream>
#include <random>
#include <cmath>

int main() {
    int i, len, rem, j;
    double u;
    const int dp = sizeof(double);
    double* a;

    len = 100;
    a = new double[len];

    for (i = 0; i < len; i++) {
        a[i] = i + 1;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(0.0, 1.0);
    u = dis(gen);
    j = std::floor(100 * u);

    if (j % 2 == 0) {
        #pragma omp parallel for
        for (i = 0; i < len - 1; i++) {
            a[i + 1] = a[i] + 1;
        }
    }

    std::cout << "a(50) = " << a[50] << std::endl;

    delete[] a;
    return 0;
}
