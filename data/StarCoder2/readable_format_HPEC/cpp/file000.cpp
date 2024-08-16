#include <iostream>
#include <omp.h>

int main() {
    const int len = 100;
    int a[len][len];

    // Initialize array elements to 0 (optional, as they are already 0 by default)
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            a[i][j] = 0;
        }
    }

    // Parallel loop with collapse(2)
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            a[i][j] = a[i][j] + 1;
        }
    }

    return 0;
}
