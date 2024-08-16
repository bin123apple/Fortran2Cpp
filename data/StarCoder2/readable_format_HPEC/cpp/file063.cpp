#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int len = 1000;
    std::vector<int> a(len);

    // Initialize the array
    for (int i = 0; i < len; ++i) {
        a[i] = i + 1; // Arrays in C++ are 0-indexed, so we add 1
    }

    // Target directive with OpenMP
    #pragma omp target map(a[0:len])
    {
        // Parallel loop with OpenMP
        #pragma omp parallel for
        for (int i = 0; i < len - 1; ++i) {
            a[i] = a[i + 1] + 1;
        }
    }

    // Print the results
    for (int i = 0; i < len; ++i) {
        std::cout << "Values for i and a[i] are: " << i + 1 << " " << a[i] << std::endl;
    }

    return 0;
}
