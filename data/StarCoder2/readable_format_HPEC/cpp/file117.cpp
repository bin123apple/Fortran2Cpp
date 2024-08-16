#include <iostream>
#include <omp.h>

int main() {
    int i = 0;

    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp task depend(out:i)
            {
                i = 1;
            }
            #pragma omp task depend(in:i)
            {
                i = 2;
            }
        }
    }

    if (i!= 2) {
        std::cout << "i is not equal to 2" << std::endl;
    }

    return 0;
}
