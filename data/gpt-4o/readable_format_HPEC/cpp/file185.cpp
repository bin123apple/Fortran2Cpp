#include <stdio.h>
#include <algorithm>

double z[18][14][18];
void showall(int n1, int n2, int n3) {
    int m1 = std::min(n1,18);
    int m2 = std::min(n2,14);
    int m3 = std::min(n3,18);

    for (int i3 = 0; i3 < m3; i3++) {
        printf("\n");
        for (int i1 = 0; i1 < m1; i1++) {
            for (int i2 = 0; i2 < m2; i2++) {
                printf("%6.3f ", z[i1][i2][i3]);
            }
            printf("\n");
        }
        printf(" - - - - - - -\n");
    }
    printf("\n");
}
