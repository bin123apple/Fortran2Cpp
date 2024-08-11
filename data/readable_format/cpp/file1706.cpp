#include <iostream>
#include <omp.h>

int main() {
    const int n = 5;
    float a[n][n], b[n][n], c[n][n];

    // Initialize arrays b and c for demonstration purposes
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            b[i][j] = i + j;
            c[i][j] = i - j;
        }
    }

    #pragma omp parallel
    {
        std::cout << "parallel" << std::endl;

        #pragma omp for nowait
        for (int i = 0; i < 4; ++i) {
            std::cout << "do nowait " << i + 1 << std::endl;
        }

        #pragma omp sections nowait
        {
            #pragma omp section
            std::cout << "section nowait 1" << std::endl;
            #pragma omp section
            std::cout << "section nowait 2" << std::endl;
        }

        #pragma omp single nowait
        std::cout << "single nowait" << std::endl;

        #pragma omp task untied
        std::cout << "task" << std::endl;
    }

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = b[i][j] + c[i][j];
        }
    }

    // Demonstrate that the array operation was performed
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << "a[" << i << "][" << j << "] = " << a[i][j] << std::endl;
        }
    }

    return 0;
}