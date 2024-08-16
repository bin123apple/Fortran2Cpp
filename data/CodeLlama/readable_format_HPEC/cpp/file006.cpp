#include <iostream>
#include <vector>
#include <omp.h>

void foo() {
    int len = 100;
    std::vector<std::vector<float>> b(len, std::vector<float>(len));
    int n = len;
    int m = len;

    #pragma omp parallel for collapse(2) private(j)
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            b[i][j] = b[i][j + 1];
        }
    }
}

int main() {
    foo();
    return 0;
}
