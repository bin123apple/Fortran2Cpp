#include <vector>
#include <omp.h>

void foo() {
    int i, j, n, m, len;
    len = 100;
    std::vector<std::vector<float>> b(len, std::vector<float>(len));

    n = len;
    m = len;
#pragma omp parallel for private(j)
    for(i = 0; i < n; i++)
        for(j = 0; j < m-1; j++)
            b[i][j] = b[i][j+1];
}

int main() {
    foo();
    return 0;
}
