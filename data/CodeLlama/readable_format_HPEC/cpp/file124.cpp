#include <omp.h>

// Assuming the definition of foo() is available here
extern void foo();

int main() {
    #pragma omp parallel
    {
        foo();
    }
    return 0;
}
