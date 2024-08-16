#include <omp.h>
#include <vector>

int main() {
    std::vector<int> a(100);

    for(int i = 0; i < 100; i++)
        a[i] = i;

#pragma omp target map(tofrom: a[0:100])
#pragma omp parallel for
    for(int i = 0; i < 100; i++)
        a[i] = a[i] + 1;

    return 0;
}
