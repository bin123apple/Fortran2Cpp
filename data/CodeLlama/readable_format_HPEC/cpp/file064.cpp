#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int size = 20;
    std::vector<std::vector<float>> a(size, std::vector<float>(size, 0.0f));

    // Initialize the matrix
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            a[i][j] = 0.0f;
        }
    }

    // Parallel region to update the matrix
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 19; ++i) {
        for (int j = 0; j < size; ++j) {
            a[i][j] += a[i + 1][j];
        }
    }

    // No need to explicitly deallocate 'a' as it will be automatically done by the vector destructor
    return 0;
}
