#include <iostream>
#include <omp.h>

// Function prototype
int fib(int n);

int main() {
    int input = 30;
    int result;

    #pragma omp parallel
    {
        #pragma omp single
        {
            result = fib(input);
        }
    }

    std::cout << "Fib for " << input << " = " << result << std::endl;

    return 0;
}

// Recursive function fib
int fib(int n) {
    int i, j;

    if (n < 2) {
        return n;
    } else {
        #pragma omp task shared(i)
        i = fib(n - 1);
        #pragma omp task shared(j)
        j = fib(n - 2);
        #pragma omp taskwait
        return i + j;
    }
}
