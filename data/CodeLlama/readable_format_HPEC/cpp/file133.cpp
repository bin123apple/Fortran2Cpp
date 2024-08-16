#include <iostream>
#include <omp.h>

int main() {
    int sum;
    int* a = nullptr;
    int* psum = nullptr;

    // Allocate memory for arrays
    a = new int[4];
    psum = new int[4];

    #pragma omp parallel num_threads(2)
    {
        // Parallel loop to initialize array a
        #pragma omp for schedule(dynamic, 1)
        for (int i = 0; i < 4; ++i) {
            a[i] = i + 1; // Adjusted for 0-based indexing
        }

        // Single region to perform tasks
        #pragma omp single
        {
            // Task to compute psum[1]
            #pragma omp task
            {
                #pragma omp task
                {
                    psum[1] = a[2] + a[3]; // Adjusted for 0-based indexing
                }
                psum[0] = a[0] + a[1]; // Adjusted for 0-based indexing
            }

            // Taskwait to synchronize tasks
            #pragma omp taskwait
            sum = psum[1] + psum[0];
        }
    }

    std::cout << "sum = " << sum << std::endl;

    // Deallocate memory
    delete[] a;
    delete[] psum;

    return 0;
}
