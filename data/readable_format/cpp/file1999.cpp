#include <iostream>
#include <omp.h>

int main() {
    float x = 1.0;

    std::cout << "Before Parallel Region X: " << x << std::endl;
    #pragma omp parallel private(x)
    {
        x = 10;
        #pragma omp critical
        std::cout << "Inside Parallel Region X: " << x << std::endl;
    }
    std::cout << "After Parallel Region X: " << x << std::endl;

    return 0;
}