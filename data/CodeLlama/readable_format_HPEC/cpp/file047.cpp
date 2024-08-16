#include <iostream>
#include <omp.h>

int main() {
    int init;
    int local;

    #pragma omp parallel shared(init) private(local)
    {
        #pragma omp master
        {
            init = 10;
        }
        local = init;
    }

    // If you need to print the value of local, you can do so here.
    // For demonstration, let's print it.
    #pragma omp parallel for
    for (int i = 0; i < 1; i++) {
        std::cout << "Local value: " << local << std::endl;
    }

    return 0;
}
