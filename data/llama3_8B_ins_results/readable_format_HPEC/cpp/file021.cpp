#include <iostream>
#include <vector>

int main() {
    int len = 100;
    std::vector<int> a(len);

    for (int i = 0; i < len; i++) {
        a[i] = i;
    }

    #pragma omp parallel for
    for (int i = 0; i < len; i++) {
        int tmp = a[i] + i;
        a[i] = tmp;
    }

    std::cout << "a(50) = " << a[50] << std::endl;

    return 0;
}
