#include <iostream>
#include <cstdlib>

void test() {
    int* i = new int[1000000];
    int& j = i[49];  // i[50] in Fortran is i[49] in C++ (0-based indexing)

    j = 1;
    if (i[49] != j) {
        std::cerr << "STOP 1" << std::endl;
        std::exit(1);
    }

    delete[] i;
}

int main() {
    test();
    return 0;
}