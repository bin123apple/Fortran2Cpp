#include <iostream>
#include <omp.h>

int main() {
    int a[100];

    // Initialize array elements to 0
    for (int i = 0; i < 100; ++i) {
        a[i] = 0;
    }

    // Parallel loop to increment each element by 1
    #pragma omp parallel for
    for (int i = 0; i < 100; ++i) {
        a[i] = a[i] + 1;
    }

    // Optional: Print the array to verify the results
    for (int i = 0; i < 100; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
