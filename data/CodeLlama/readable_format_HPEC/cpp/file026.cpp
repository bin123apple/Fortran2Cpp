#include <iostream>
#include <omp.h>

int main() {
    const int len = 100;
    float getSum = 0.0f;
    float** u = new float*[len];

    // Allocate and initialize the 2D array
    for (int i = 0; i < len; ++i) {
        u[i] = new float[len];
        for (int j = 0; j < len; ++j) {
            u[i][j] = 0.5f;
        }
    }

    // Parallel reduction to compute the sum
    #pragma omp parallel for collapse(2) reduction(+:getSum) private(j)
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            float temp = u[i][j];
            getSum += temp * temp;
        }
    }

    std::cout << "sum = " << getSum << std::endl;

    // Deallocate the 2D array
    for (int i = 0; i < len; ++i) {
        delete[] u[i];
    }
    delete[] u;

    return 0;
}
