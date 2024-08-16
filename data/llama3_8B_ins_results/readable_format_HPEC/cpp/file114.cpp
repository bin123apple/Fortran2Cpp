#include <iostream>
#include <omp.h>

int main() {
    int* counter = new int;

    *counter = 0;

    #pragma omp parallel
    {
        (*counter)++;
    }

    std::cout << *counter << std::endl;

    delete counter;

    return 0;
}
