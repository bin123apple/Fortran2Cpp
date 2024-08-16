#include <iostream>
#include <omp.h>

// Assuming the existence of a function f1 that takes an integer and modifies it.
void f1(int &i) {
    i = i + 1; // Example operation, modify i as per the Fortran code.
}

int main() {
    int sum = 0;
    int i = 0;

    #pragma omp parallel reduction(+:sum) num_threads(10) private(i)
    {
        f1(i); // Call the function f1
        #pragma omp atomic // Ensure sum is updated atomically
        sum += i;
    }

    if (sum != 10) {
        std::cout << "sum = " << sum << std::endl;
    }

    return 0;
}
