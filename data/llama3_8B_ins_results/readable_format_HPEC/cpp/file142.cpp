#include <iostream>
#include <omp.h>

int fib(int n) {
    if (n < 2) {
        return n;
    } else {
        int i, j;
        #pragma omp task shared(i)
        i = fib(n-1);
        #pragma omp task shared(j)
        j = fib(n-2);
        return i + j;
    }
}

int main() {
    int input = 30;
    int result;

    #pragma omp parallel
    {
        #pragma omp single
        result = fib(input);
    }

    std::cout << "Fib for " << input << " = " << result << std::endl;

    return 0;
}
