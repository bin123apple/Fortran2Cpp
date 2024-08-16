#include <iostream>
#include <omp.h>

int main() {
    int var = 0;

    #pragma omp parallel sections
    {
        for (int i = 1; i <= 10; ++i) {
            #pragma omp task shared(var)
            {
                var = var + 1;
            }
        }
    }

    std::cout << "var = " << var << std::endl;

    return 0;
}
