#include <iostream>
#include <vector>
#include <omp.h>

void foo() {
    int N = 1000;
    std::vector<std::vector<double>> a(N, std::vector<double>(N));
    std::vector<double> v(N);
    std::vector<double> v_out(N);

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < N; i++) {
        double sum = 0.0;
        for (int j = 0; j < N; j++) {
            sum += a[i][j] * v[j];
            std::cout << sum << std::endl;
        }
        v_out[i] = sum;
    }
}

int main() {
    foo();
    return 0;
}
