#include <iostream>
#include <vector>

int main() {
    int len = 100;
    std::vector<int> a(len);

    for (int i = 0; i < len; i++) {
        a[i] = i + 1; // equivalent to Fortran's a(i) = i
    }

    #pragma omp parallel for
    for (int i = 0; i < len - 1; i++) {
        a[i + 1] = a[i] + 1;
    }

    std::cout << "a(50) = " << a[50] << std::endl;

    a.clear(); // equivalent to deallocate(a)

    return 0;
}
