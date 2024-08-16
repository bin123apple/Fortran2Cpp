#include <iostream>
#include <omp.h>

int main() {
    double pi = 0.0;
    int64_t num_steps = 2000000000;
    double interval_width = 1.0 / num_steps;

    #pragma omp parallel for reduction(+:pi) private(interval_width)
    for (int64_t i = 1; i <= num_steps; ++i) {
        double x = (i + 0.5) * interval_width;
        pi += 1.0 / (x * x + 1.0);
    }

    pi = pi * 4.0 * interval_width;

    std::cout << "PI = " << pi << std::endl;

    return 0;
}
