#include <stdio.h>
#include <stdlib.h>

#define DATA_TYPE double
DATA_TYPE ex[101][101][101];
DATA_TYPE ey[101][101][101];
DATA_TYPE hz[101][101][101];
DATA_TYPE ry[101][101];
DATA_TYPE ax[101][101];
DATA_TYPE cymh[101];
DATA_TYPE cyph[101];
DATA_TYPE cxmh[101];
DATA_TYPE cxph[101];
DATA_TYPE czm[101];
DATA_TYPE czp[101];
DATA_TYPE mui, ch;

void init_array(int cz, int cxm, int cym) {
    int i, j, k;
    mui = 2341;
    ch = 42;
    for (i = 0; i <= cz; i++) {
        czm[i] = ((double)i + 1.0) / (double)cxm;
        czp[i] = ((double)i + 2.0) / (double)cxm;
    }
    for (i = 0; i <= cxm; i++) {
        cxmh[i] = ((double)i + 3.0) / (double)cxm;
        cxph[i] = ((double)i + 4.0) / (double)cxm;
    }
    for (i = 0; i <= cym; i++) {
        cymh[i] = ((double)i + 5.0) / (double)cxm;
        cyph[i] = ((double)i + 6.0) / (double)cxm;
    }
    for (i = 0; i <= cz; i++) {
        for (j = 0; j <= cym; j++) {
            ry[j][i] = (((double)i * (double)j) + 10.0) / (double)cym;
            ax[j][i] = (((double)i * (double)(j + 1)) + 11.0) / (double)cym;
            for (k = 0; k <= cxm; k++) {
                ex[k][j][i] = (((double)i * (double)(j + 2)) + (double)k + 1.0) / (double)cxm;
                ey[k][j][i] = (((double)i * (double)(j + 3)) + (double)k + 2.0) / (double)cym;
                hz[k][j][i] = (((double)i * (double)(j + 4)) + (double)k + 3.0) / (double)cz;
            }
        }
    }
}

int main() {
    init_array(100, 100, 100);
    return 0;
}
