#include <iostream>
#include <omp.h>
#include <unistd.h>

int main() {
    int i = 0;

    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp task depend(out:i)
            {
                sleep(3);
                i = 3;
            }
            #pragma omp task depend(out:i)
            {
                i = 2;
            }
        }
    }

    if (i!= 2) {
        std::cout << i << std::endl;
    }

    return 0;
}
