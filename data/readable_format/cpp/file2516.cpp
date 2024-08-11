#include <iostream>
#include <vector>
#include <openacc.h>

int main() {
    std::vector<int> a(100);
    int j = 0;

    #pragma acc parallel loop reduction(+:j)
    for (int i = 1; i <= 100; ++i) {
        // The loop body is empty as in the original Fortran code
    }

    return 0;
}