#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    std::vector<int> a(4);
    std::vector<int> psum(4);
    int sum = 0;

    #pragma omp parallel num_threads(2)
    {
        #pragma omp for schedule(dynamic, 1)
        for (int i = 0; i < 4; ++i) {
            a[i] = i + 1; // Adjusting for 0-based indexing
        }

        #pragma omp single
        {
            #pragma omp task
            {
                #pragma omp task
                {
                    psum[1] = a[2] + a[3]; // Adjusting for 0-based indexing
                }
                psum[0] = a[0] + a[1]; // Adjusting for 0-based indexing
            }
            #pragma omp taskwait
            sum = psum[1] + psum[0];
        }
    }

    std::cout << "sum = " << sum << std::endl;

    return 0;
}
