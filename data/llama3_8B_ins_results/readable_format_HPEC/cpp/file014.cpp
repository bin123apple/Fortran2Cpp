#include <iostream>
#include <omp.h>

int main() {
    double x, interval_width, pi;
    long long int i, num_steps;

    pi = 0.0;
    num_steps = 2000000000;
    interval_width = 1.0 / num_steps;

    #pragma omp parallel for reduction(+:pi) private(x)
    for (i = 1; i <= num_steps; i++) {
        x = (i + 0.5) * interval_width;
        pi += 1.0 / (x*x + 1.0);
    }

    pi *= 4.0 * interval_width;
    std::cout << "PI = " << std::fixed << std::setprecision(20) << pi << std::endl;

    return 0;
}
