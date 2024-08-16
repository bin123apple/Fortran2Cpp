#include <iostream>
#include <omp.h>

int main() {
    double x;
    int y;

    #pragma omp parallel
    {
        #pragma omp single
        {
            x = 1.0;
            y = 1;
        }
    }

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 1; ++i) {
        for (int j = 0; j < 1; ++j) {
            #pragma omp atomic
            std::cout << "x = " << x << " y = " << y << std::endl;
        }
    }

    return 0;
}
