#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int len = 100;
    std::vector<int> a(len);
    std::vector<int> b(len);

    for (int i = 0; i < len; i++) {
        a[i] = i;
        b[i] = i + 1;
    }

    #pragma omp parallel for
    for (int i = 0; i < len - 1; i++) {
        a[i + 1] = a[i] + b[i];
    }

    std::cout << "a(50) = " << a[50] << std::endl;

    a.clear();
    b.clear();

    return 0;
}
