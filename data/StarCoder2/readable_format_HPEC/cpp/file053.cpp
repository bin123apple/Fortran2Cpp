#include <iostream>
#include <omp.h>

int main() {
    int a = 0;

    #pragma omp parallel shared(a) private(i)
    {
        #pragma omp master
        {
            a = 0;
        }

        #pragma omp for reduction(+:a)
        for (int i = 1; i <= 10; ++i) {
            a += i;
        }

        #pragma omp single
        {
            std::cout << "Sum is " << a << std::endl;
        }
    }

    return 0;
}
