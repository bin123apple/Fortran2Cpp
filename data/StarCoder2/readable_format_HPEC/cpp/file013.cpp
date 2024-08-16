#include <iostream>
#include <omp.h>

// Assuming the functionality of f1 is defined elsewhere
void f1(int& i) {
    // Example functionality: increment i by 1
    i += 1;
}

int main() {
    int i = 0;
    int sum = 0;

    // OpenMP parallel region with reduction on sum
    #pragma omp parallel reduction(+:sum) num_threads(10)
    {
        f1(i);
        sum += i;
    }

    // Check the result
    if (sum!= 10) {
        std::cout << "sum = " << sum << std::endl;
    }

    return 0;
}
