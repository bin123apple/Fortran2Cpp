#include <stdio.h>
#define DATA_TYPE int
#define DATA_PRINTF_MODIFIER "%d "
#define ni 100
#define nj 100

void print_array(DATA_TYPE a[nj][ni], DATA_TYPE r[nj][nj], DATA_TYPE q[nj][ni]) {
    for (int i = 0; i < ni; i++) {
        for (int j = 0; j < nj; j++) {
            printf(DATA_PRINTF_MODIFIER, a[j][i]);
            if (j % 20 == 0)
                printf("\n");
        }
    }
    printf("\n");

    for (int i = 0; i < nj; i++) {
        for (int j = 0; j < nj; j++) {
            printf(DATA_PRINTF_MODIFIER, r[j][i]);
            if (j % 20 == 0)
                printf("\n");
        }
    }
    printf("\n");

    for (int i = 0; i < ni; i++) {
        for (int j = 0; j < nj; j++) {
            printf(DATA_PRINTF_MODIFIER, q[j][i]);
            if (j % 20 == 0)
                printf("\n");
        }
    }
    printf("\n");
}
