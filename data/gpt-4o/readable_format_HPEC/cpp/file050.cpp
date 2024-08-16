#include <stdio.h>
#include <cstdlib>
#include <omp.h>

int main(int argc, char* argv[]) {
    int len = 1000;
    if (argc > 1) {
        len = atoi(argv[1]);
    }

    float b[len][len];

    for (int i = 0; i < len; i++) {
        #pragma omp parallel for
        for (int j = 1; j < len; j++) {
            b[i][j] = b[i][j-1];
        }
    }
    
    return 0;
}
