#include <iostream>
#include <omp.h>

int main() {
    const int len = 1000;
    int n = len;
    int m = len;

    // Dynamic allocation of a 2D array
    float** b = new float*[len];
    for (int i = 0; i < len; ++i) {
        b[i] = new float[len];
    }

    // Initialize the array with zeros (optional, for demonstration)
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            b[i][j] = 0.0f;
        }
    }

    // Parallel loop to fill the array
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            b[i][j] = b[i][j - 1];
        }
    }

    // Print the value of b(500,500)
    std::cout << "b(500,500) = " << b[499][499] << std::endl;

    // Deallocate the array
    for (int i = 0; i < len; ++i) {
        delete[] b[i];
    }
    delete[] b;

    return 0;
}
