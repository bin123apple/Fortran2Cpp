#include <iostream>
#include <omp.h>

int main() {
    int a, b, c, d;

    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp task depend(out: c)
            c = 1;  // Task T1
            #pragma omp end task

            #pragma omp task depend(out: a)
            a = 2;  // Task T2
            #pragma omp end task

            #pragma omp task depend(out: b)
            b = 3;  // Task T3
            #pragma omp end task

            #pragma omp task depend(in: a)
            c = c + a;  // Task T4
            #pragma omp end task

            #pragma omp task depend(in: b)
            c = c + b;  // Task T5
            #pragma omp end task

            #pragma omp task depend(in: c)
            d = c;  // Task T6
            #pragma omp end task
        }
    }

    std::cout << d << std::endl;
    return 0;
}
