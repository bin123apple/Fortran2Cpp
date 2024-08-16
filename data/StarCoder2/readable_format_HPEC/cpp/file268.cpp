#include <iostream>
#include <omp.h>

class DRB105 {
public:
    static int fib(int n) {
        int i, j, r;

        if (n < 2) {
            r = n;
        } else {
            #pragma omp task shared(i)
            i = fib(n - 1);
            #pragma omp end task

            #pragma omp task shared(j)
            j = fib(n - 2);
            #pragma omp end task

            #pragma omp taskwait
            r = i + j;
        }

        return r;
    }
};

int main() {
    int input = 30;
    int result;

    #pragma omp parallel
    {
        #pragma omp single
        result = DRB105::fib(input);
    }

    std::cout << "Fib for " << input << " = " << result << std::endl;

    return 0;
}
