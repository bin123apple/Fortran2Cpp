#include <iostream>
#include <omp.h>

int main() {
    int var = 0;

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            #pragma omp task shared(var) if(false)
            {
                var = var + 1;
            }
        }
    }

    std::cout << "var = " << var << std::endl;

    return 0;
}
