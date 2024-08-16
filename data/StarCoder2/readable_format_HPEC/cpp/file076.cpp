#include <iostream>
#include <omp.h>

int main() {
    const int len = 20;
    float a[len][len];

    // Initialize array
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            a[i][j] = 0.5f;
        }
    }

    // Parallel region with OpenMP
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len; ++j) {
            a[i][j] = a[i][j] + a[i + 1][j];
        }
    }

    // Print the value of a[10][10]
    std::cout << "a[10][10] = " << a[10][10] << std::endl;

    return 0;
}
