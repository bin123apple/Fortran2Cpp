#include <iostream>
#include <omp.h>

int main() {
    int count = 0;
    int num_threads = 0;

    #pragma omp parallel reduction(+:count)
    {
        #pragma omp master
        {
            num_threads = omp_get_num_threads();
        }

        #pragma omp for collapse(2)
        for (int i = 1; i <= 10; ++i) {
            for (int j = 1; j <= 10; ++j) {
                if (i < 5) continue; // Correctly placed within the loop context.
                count += 1; // Increment count instead of printing.
            }
        }
    }

    std::cout << "Expected count: 60, Actual count: " << count << std::endl;
    std::cout << "Number of threads used: " << num_threads << std::endl;

    return 0;
}