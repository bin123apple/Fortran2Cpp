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

    for (int i = 0; i < len; i++) {
        std::cout << "Values for i and a(i) are: " << i << " " << a[i] << std::endl;
    }

    return 0;
}
