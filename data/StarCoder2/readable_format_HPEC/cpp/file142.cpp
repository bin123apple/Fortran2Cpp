#include <iostream>
#include <omp.h>

// Function to calculate the Fibonacci number of a given integer n
int fib(int n) {
    int i, j, r;

    if (n < 2) {
        return n;
    } else {
        // OpenMP task to calculate fib(n-1)
        #pragma omp task shared(i)
        i = fib(n - 1);

        // OpenMP task to calculate fib(n-2)
        #pragma omp task shared(j)
        j = fib(n - 2);

        // Wait for all tasks to complete
        #pragma omp taskwait

        r = i + j;
    }
    return r;
}

int main() {
    int input = 30;
    int result;

    // OpenMP parallel region
    #pragma omp parallel
    {
        // OpenMP single region
        #pragma omp single
        result = fib(input);
    }

    std::cout << "Fib for " << input << " = " << result << std::endl;

    return 0;
}
