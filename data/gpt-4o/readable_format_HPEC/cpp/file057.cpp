#include <stdio.h>
#include <omp.h>

double b[1000][1000];

int main() {
    int i, j, n = 1000, m = 1000;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            b[i][j] = 0.5;
        }
    }
    #pragma omp parallel for private(j)
    for(i = 1; i < n; i++) {
        for(j = 1; j < m; j++) {
            b[i][j] = b[i-1][j-1];
        }
    }
    printf("b[500][500] = %.6f
", b[500][500]);
    return 0;
}
