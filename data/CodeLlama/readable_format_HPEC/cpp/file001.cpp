#include <iostream>
#include <omp.h>

int main() {
    const int len = 100;
    int** a = new int*[len];
    for (int i = 0; i < len; ++i) {
        a[i] = new int[len];
    }

    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp taskloop collapse(2)
            for (int i = 0; i < len; ++i) {
                for (int j = 0; j < len; ++j) {
                    a[i][j] = a[i][j] + 1;
                }
            }
        }
    }

    std::cout << "a[49][49] = " << a[49][49] << std::endl; // Adjusted for 0-based indexing

    for (int i = 0; i < len; ++i) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}
