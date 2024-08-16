#include <iostream>
#include <omp.h>

// Assuming DRB076 module contains the definition of f1, we declare it here.
// You need to define this function based on what f1 does in your Fortran code.
void f1(int& i) {
    // Example implementation, modify according to your actual function
    i = 1;
}

int main() {
    int i = 0;
    int sum = 0;

    // OpenMP parallel region with reduction on sum
    #pragma omp parallel reduction(+:sum) num_threads(10) private(i)
    {
        f1(i); // Call the function within the parallel region
        sum += i; // Update sum in parallel
    }

    // Check the result
    if (sum!= 10) {
        std::cout << "sum = " << sum << std::endl;
    }

    return 0;
}
