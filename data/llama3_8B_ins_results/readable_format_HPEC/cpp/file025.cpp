#include <iostream>
#include <omp.h>

int tp;
int var;

void foo() {
    #pragma omp task
    tp = 1;
    #pragma omp task
    var = tp;
    #pragma omp end task
    #pragma omp end task
}

int main() {
    #pragma omp parallel
    {
        foo();
    }
    std::cout << var << std::endl;
    return 0;
}
