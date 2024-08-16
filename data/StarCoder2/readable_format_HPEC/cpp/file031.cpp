#include <iostream>
#include <omp.h>

int main() {
    int x = 0;
    int y = 0;
    int thrd;
    int tmp;

    #pragma omp parallel num_threads(2) private(thrd) private(tmp)
    {
        thrd = omp_get_thread_num();
        if (thrd == 0) {
            #pragma omp critical
            {
                x = 10;
            }
            #pragma omp atomic write
            {
                y = 1;
            }
        } else {
            tmp = 0;
            while (tmp == 0) {
                #pragma omp atomic read acquire // or seq_cst
                {
                    tmp = x;
                }
            }
            #pragma omp critical
            {
                std::cout << "x = " << x << std::endl;
            }
        }
    }

    return 0;
}
