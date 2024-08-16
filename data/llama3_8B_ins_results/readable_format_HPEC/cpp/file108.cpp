#include <iostream>
#include <vector>
#include <omp.h>

void foo() {
    int N = 100;
    std::vector<std::vector<double>> a(N, std::vector<double>(N));
    std::vector<double> v(N);
    std::vector<double> v_out(N);

    double sum = 0.0;

    #pragma omp parallel for private(i, j, sum)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum += a[i][j] * v[j];
        }
        v_out[i] = sum;
        sum = 0.0;
    }
}

int main() {
    foo();
    return 0;
}
