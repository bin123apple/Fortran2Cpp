#include <iostream>
#include <cstdlib>
#include <omp.h>

int main(int argc, char **argv) {
    int len = 100;
    int tmp = 10;
    int *a = new int[len];

    if (argc > 1) {
        len = atoi(argv[1]);
        if (len <= 0) {
            std::cout << "Error, invalid integer value." << std::endl;
            exit(1);
        }
    }

#pragma omp parallel for
    for (int i = 0; i < len; i++) {
        a[i] = tmp;
        tmp = a[i] + i;
    }

    delete[] a;
    return 0;
}
