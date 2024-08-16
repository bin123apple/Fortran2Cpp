#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int n, m, len;
    float value;
    std::vector<std::vector<float>> b;

    len = 1000;
    n = len;
    m = len;

    // Allocate the 2D vector
    b.resize(len, std::vector<float>(len));

    // Parallel region
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            b[i][j] = b[i][j - 1];
        }
    }

    // Print the value at the specified position
    value = b[499][499]; // Note: C++ uses 0-based indexing
    std::cout << "b(500,500) = " << value << std::endl;

    return 0;
}
