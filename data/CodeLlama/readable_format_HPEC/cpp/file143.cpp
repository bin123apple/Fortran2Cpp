#include <iostream>
#include <vector>
#include <omp.h>

void foo() {
    const int N = 1000;
    std::vector<std::vector<float>> a(N, std::vector<float>(N));
    std::vector<float> v(N);
    std::vector<float> v_out(N);

    // Initialize matrix a and vector v with some values for demonstration
    // In a real scenario, you would likely initialize them based on actual data
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            a[i][j] = static_cast<float>(i * j); // Example initialization
        }
        v[i] = static_cast<float>(i); // Example initialization
    }

    #pragma omp parallel for collapse(2) reduction(+:sum)
    for (int i = 0; i < N; ++i) {
        float sum = 0.0f;
        for (int j = 0; j < N; ++j) {
            sum += a[i][j] * v[j];
        }
        v_out[i] = sum;
    }

    // Optionally, print the results for verification
    // for (int i = 0; i < N; ++i) {
    //     std::cout << "v_out[" << i << "] = " << v_out[i] << std::endl;
    // }
}

int main() {
    foo();
    return 0;
}
