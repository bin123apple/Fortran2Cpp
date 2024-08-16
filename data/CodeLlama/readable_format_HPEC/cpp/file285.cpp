#include <iostream>
#include <omp.h>

// Function declaration
void f1(int &i);

int main() {
    int i = 0;

    #pragma omp parallel
    {
        f1(i);
    }

    std::cout << "i = " << i << std::endl;

    return 0;
}

// Function definition
void f1(int &i) {
    #pragma omp atomic
    i += 1;
}
