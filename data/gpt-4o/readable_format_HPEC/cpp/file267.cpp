#include <stdio.h>
#include <string.h>
#include <omp.h>

char a[100][100];

int main() {
    char str[51];
    int i;

#pragma omp parallel for private(str)
    for (i = 0; i < 100; i++) {
        sprintf(str, "%d", i);
        strcpy(a[i], str);
    }

    printf("a[i]=%s\n", a[23]);

    return 0;
}
