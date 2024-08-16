#include <iostream>
#include <omp.h>

int main() {
    int var = 0;

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            #pragma omp task shared(var)
            {
                for (int i = 1; i <= 10; ++i) {
                    var = var + 1;
                }
            }
        }
    }

    std::cout << "var = " << var << std::endl;

    return 0;
}
