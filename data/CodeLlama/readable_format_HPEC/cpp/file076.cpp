#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int len = 20;
    std::vector<std::vector<float>> a(len, std::vector<float>(len, 0.5f));

    // Parallel loop to initialize the array
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            a[i][j] = 0.5f;
        }
    }

    // Parallel loop to perform the computation
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len; ++j) {
            a[i][j] += a[i + 1][j];
        }
    }

    // Print the value of a(10,10)
    std::cout << "a(10,10) = " << a[9][9] << std::endl;

    return 0;
}
