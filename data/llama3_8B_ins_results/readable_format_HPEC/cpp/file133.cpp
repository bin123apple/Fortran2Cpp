#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int numThreads = 2;
    std::vector<int> a(4);
    std::vector<int> psum(4);
    int sum = 0;

    #pragma omp parallel num_threads(numThreads)
    {
        #pragma omp for schedule(dynamic, 1)
        for (int i = 1; i <= 4; i++) {
            a[i-1] = i;
        }

        #pragma omp single
        {
            #pragma omp task
            {
                #pragma omp task
                psum[1] = a[1] + a[2];
                #pragma omp end task
                psum[2] = a[3] + a[4];
            }
            #pragma omp end task
            sum = psum[1] + psum[2];
        }
        #pragma omp end single
    }

    std::cout << "sum = " << sum << std::endl;

    return 0;
}
