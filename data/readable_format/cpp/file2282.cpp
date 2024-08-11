#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int N = 100;
    const int LIMIT = 60;
    std::vector<int> a(N);
    int errors = 0;

    // Initialize the vector a
    for (int i = 0; i < N; ++i) {
        a[i] = i + 1;
    }

    // Simplified parallel region without target offloading
    for (int j = 1; j <= N; ++j) {
        #pragma omp parallel for if(j < LIMIT)
        for (int i = 0; i < N; ++i) {
            a[i] += 1;
        }
    }

    // Verification step
    for (int i = 0; i < N; ++i) {
        if (a[i] != i + 101) { // i + 1 + 100 increments
            std::cout << "Error at index " << i << ": expected " << i + 101 << " but got " << a[i] << std::endl;
            errors++;
        }
    }

    if (errors == 0) {
        std::cout << "All tests passed!" << std::endl;
    } else {
        std::cout << "There were " << errors << " errors." << std::endl;
    }

    return 0;
}