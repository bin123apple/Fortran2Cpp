#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    std::vector<int> a(10);
    std::vector<int> b(10, -1234);
    int nerr = 0;

    #pragma omp parallel num_threads(2)
    {
        int me = omp_get_thread_num() + 1;

        #pragma omp for
        for (int i = 0; i < 10; ++i) {
            a[i] = i + 1;
        }

        #pragma omp barrier

        if (me == 2) {
            for (int i = 0; i < 7; ++i) {
                b[i] = a[i];
            }
        }

        #pragma omp barrier

        if (me == 1) {
            for (int i = 0; i < 7; ++i) {
                if (b[i] != a[i]) {
                    std::cout << "b(" << i + 1 << ")[" << me << "]=" << b[i] << " should be " << a[i] << std::endl;
                    nerr++;
                }
            }

            for (int i = 7; i < 10; ++i) {
                if (b[i] != -1234) {
                    std::cout << "b(" << i + 1 << ")[" << me << "]=" << b[i] << " should be -1234" << std::endl;
                    nerr++;
                }
            }
        }
    }

    if (nerr == 0) {
        std::cout << "result[1] OK" << std::endl;
    } else {
        std::cout << "result[1] number of NGs: " << nerr << std::endl;
    }

    return 0;
}