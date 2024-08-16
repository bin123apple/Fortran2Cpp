#include <iostream>
#include <omp.h>
#include <thread>

int main() {
    int i, j, k;
    i = 0;

    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp task depend(out:i)
            {
                std::this_thread::sleep_for(std::chrono::seconds(3));
                i = 1;
            }

            #pragma omp task depend(in:i)
            {
                j = i;
            }

            #pragma omp task depend(in:i)
            {
                k = i;
            }
        }
    }

    std::cout << "j = " << j << "  k = " << k << std::endl;

    if (j != 1 || k != 1) {
        std::cout << "Race Condition" << std::endl;
    }

    return 0;
}
