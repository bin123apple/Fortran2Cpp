#include <iostream>
#include <omp.h>

// Assuming the content of the global module is declared here
// For example, a global variable or a function prototype
extern void f1(int& i);

int main() {
    int i = 0;

    #pragma omp parallel
    {
        f1(i);
    }

    if (i!= 0) {
        std::cout << "i = " << i << std::endl;
    }

    return 0;
}
