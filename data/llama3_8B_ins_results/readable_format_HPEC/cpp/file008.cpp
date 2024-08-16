#include <omp.h>
#include "global_foo.h"

int main() {
    #pragma omp parallel
    {
        foo();
    }
    return 0;
}
