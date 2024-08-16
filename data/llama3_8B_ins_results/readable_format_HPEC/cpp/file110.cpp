#include <iostream>
#include <vector>

int main() {
    int len = 2000;
    std::vector<int> a(len);

    for (int i = 0; i < len; i++) {
        a[i] = i;
    }

    #pragma omp parallel for
    for (int i = 0; i < 1000; i++) {
        a[2 * i] = a[i] + 1;
    }

    std::cout << "a(1002) = " << a[1002] << std::endl;

    a.clear();

    return 0;
}
