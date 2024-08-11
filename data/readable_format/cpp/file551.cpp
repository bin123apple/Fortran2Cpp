#include <iostream>
#include <omp.h>

int main() {
    const int num_steps = 100000;
    double step;
    double pi, x;
    double summ = 0.0;
    int i;

    step = 1.0 / num_steps;

    #pragma omp parallel for reduction(+:summ) private(x)
    for (i = 0; i <= num_steps; i++) {
        x = (i + 0.5) * step;
        summ += 4.0 / (1.0 + x * x);
    }
    
    pi = summ * step;
    
    std::cout << "pi is " << pi << std::endl;

    return 0;
}