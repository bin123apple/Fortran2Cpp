#include <iostream>
#include <omp.h>

int main() {
    int i = 1;

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            #pragma omp critical(NAME)
            {
                #pragma omp parallel
                {
                    #pragma omp single
                    {
                        i = i + 1;
                    }
                }
            }
        }
    }

    std::cout << "i = " << i << std::endl;

    return 0;
}
