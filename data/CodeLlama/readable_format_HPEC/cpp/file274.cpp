#include <omp.h>
#include <iostream>

int main() {
    int init = 0;
    int local = 0;

    #pragma omp parallel shared(init) private(local)
    {
        #pragma omp single
        {
            init = 10;
        }
        local = init;
    }

    // Assuming you want to print the result to verify correctness
    std::cout << "init: " << init << ", local: " << local << std::endl;

    return 0;
}
