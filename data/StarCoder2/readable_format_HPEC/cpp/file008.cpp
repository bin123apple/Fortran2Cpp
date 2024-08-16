#include "global_foo.h"
#include <omp.h>

int main() {
    #pragma omp parallel
    {
        foo();
    }
    return 0;
}
