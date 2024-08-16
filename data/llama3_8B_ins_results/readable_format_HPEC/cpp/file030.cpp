#include <iostream>
#include <omp.h>

int main() {
    int x[64] = {0};
    int y[64] = {3};
    int a = 5;

    #pragma omp target teams distribute map(to:y,a) map(tofrom:x)
    {
        #pragma omp for
        for (int i = 0; i < 64; i++) {
            #pragma omp task depend(out:x[i])
            x[i] = a * x[i];

            #pragma omp task depend(out:x[i])
            x[i] = x[i] + y[i];
        }
    }

    #pragma omp taskwait

    for (int i = 0; i < 64; i++) {
        if (x[i]!= 3) {
            std::cout << x[i] << std::endl;
        }
    }

    return 0;
}
