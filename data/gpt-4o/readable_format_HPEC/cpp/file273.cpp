#include <stdio.h>
#include <omp.h>

int main() {
    int var = 0;

    #pragma omp target map(tofrom:var) device(0)
    #pragma omp teams distribute
    for (int i = 0; i < 100; i++) {
        #pragma omp atomic update
        var++;
    }

    printf("%d
", var);
    return 0;
}
