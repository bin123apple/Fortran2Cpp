#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int len = 100;
    double getSum = 0.0;

    // Dynamically allocate 2D vector
    std::vector<std::vector<double>> u(len, std::vector<double>(len));

    // Initialize the 2D vector
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            u[i][j] = 0.5;
        }
    }

    // Parallel processing using OpenMP
    #pragma omp parallel for collapse(2) reduction(+:getSum)
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            double temp = u[i][j];
            getSum += temp * temp;
        }
    }

    std::cout << "sum = " << getSum << std::endl;

    // No need to explicitly deallocate u as it will be automatically done by the vector destructor
    return 0;
}
