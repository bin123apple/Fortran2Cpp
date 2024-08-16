#include <iostream>
#include <fstream>
#include <omp.h>

int main() {
    int i, ret, len, stat;
    int a[1000];
    bool exist;

    len = 1000;

    for (i = 1; i <= len; i++) {
        a[i-1] = i; // Fortran arrays are 1-indexed, C++ arrays are 0-indexed
    }

    std::ifstream file("mytempfile.txt");
    exist = file.is_open();

    if (exist) {
        file.open("mytempfile.txt", std::ios::app | std::ios::out);
    } else {
        file.open("mytempfile.txt", std::ios::out);
    }

    #pragma omp parallel for
    for (i = 1; i <= len; i++) {
        file << a[i-1] << std::endl;
    }

    if (!file.fail()) {
        file.close();
        file.open("mytempfile.txt", std::ios::in);
        file.close();
        file.remove();
    }

    return 0;
}
