#include <iostream>
#include <atomic>

int main() {
    std::atomic<int> x(0);
    int y = 0;
    int thrd = 0;
    int tmp = 0;

    #pragma omp parallel num_threads(2) private(thrd) private(tmp)
    {
        thrd = omp_get_thread_num();
        if (thrd == 0) {
            #pragma omp critical
            {
                x = 10;
            }
            #pragma omp atomic
            y = 1;
        } else {
            do {
                #pragma omp atomic read
                tmp = x;
            } while (tmp == 0);
            #pragma omp critical
            {
                std::cout << "x = " << x << std::endl;
            }
        }
    }

    return 0;
}
