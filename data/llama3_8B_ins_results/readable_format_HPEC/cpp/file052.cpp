#include <iostream>
#include <omp.h>

using namespace std;

int tp, var;

int main() {
    #pragma omp threadprivate(tp)

    void foo() {
        #pragma omp task
        tp = 1;
        #pragma omp task
        tp = 2;
        #pragma omp end task
        var = tp; // value of var can be 1 or 2
        #pragma omp end task
    }

    foo();

    return 0;
}
