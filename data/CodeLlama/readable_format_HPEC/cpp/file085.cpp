#include <iostream>
#include <vector>
#include <omp.h>
#include <cmath>
#include <algorithm>
#include <numeric>

int main() {
    const int len = 100;
    std::vector<double> a(len);

    // Initialize array
    std::iota(a.begin(), a.end(), 1.0);

    // Generate a random number between 0 and 1
    double u = static_cast<double>(rand()) / RAND_MAX;
    int j = static_cast<int>(std::floor(100 * u));

    // Parallel loop if j is even
    if (j % 2 == 0) {
        #pragma omp parallel for
        for (int i = 0; i < len - 1; ++i) {
            a[i + 1] = a[i] + 1;
        }
    }

    // Print the 50th element
    std::cout << "a[49] = " << a[49] << std::endl; // C++ uses 0-based indexing

    return 0;
}
