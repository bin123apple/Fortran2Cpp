#include <iostream>
#include <omp.h>

int main() {
    int count = 0;

    #pragma omp parallel shared(count)
    {
        #pragma omp single
        {
            count++;
        }
    }

    std::cout << "count = " << count << std::endl;

    return 0;
}
