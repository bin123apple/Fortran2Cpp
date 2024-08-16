#include <iostream>
#include <omp.h>

int main() {
    int* counter = new int;

    *counter = 0;

    #pragma omp parallel
    {
        foo();
    }

    std::cout << *counter << std::endl;

    delete counter;

    return 0;
}

void foo() {
    // your code here
}
