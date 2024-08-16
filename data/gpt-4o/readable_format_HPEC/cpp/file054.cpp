#include <omp.h>
#include <iostream>
#include <vector>
#include <cstdlib>

int main(int argc, char *argv[]) {
    int len = 1000;
    if (argc > 1)
        len = atoi(argv[1]);

    std::vector<int> a(len);

    for (int i = 0; i < len; i++)
        a[i] = i;

    #pragma omp parallel for
    for (int i = 0; i < len-1; i++)
        a[i] = a[i+1]+1;

    return 0;
}
