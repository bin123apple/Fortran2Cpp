#include <iostream>
#include <vector>

int main() {
    int i, j, len;
    std::vector<std::vector<int>> a;

    len = 100;

    a.resize(len, std::vector<int>(len, 0));

    #pragma omp parallel for
    for (i = 0; i < len; i++) {
        for (j = 0; j < len; j++) {
            a[i][j]++;
        }
    }

    // Note: We don't need to deallocate the vector in C++,
    // as it is automatically managed by the memory allocator.

    return 0;
}
