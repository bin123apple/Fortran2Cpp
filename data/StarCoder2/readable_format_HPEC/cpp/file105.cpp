#include <iostream>
#include <omp.h>

// Assuming DRB102.h is the header file for the DRB102 module
#include "DRB102.h"

int main() {
    double x = 0.0;
    int y = 0;

    #pragma omp parallel
    {
        #pragma omp single copyprivate(x, y)
        {
            x = 1.0;
            y = 1;
        }
    }

    std::cout << "x = " << x << "  y = " << y << std::endl;

    return 0;
}
