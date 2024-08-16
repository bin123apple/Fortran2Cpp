#include <math.h>
#define DATA_TYPE double
#define _PB_NI ni
#define _PB_NJ nj
void kernel_gramschmidt(int ni, int nj, DATA_TYPE a[_PB_NJ][_PB_NI], DATA_TYPE r[_PB_NJ][_PB_NJ], DATA_TYPE q[_PB_NJ][_PB_NI])
{
 DATA_TYPE nrm;
 int i, j, k;
 for (k = 0; k < _PB_NJ; k++) {
 nrm = 0.0;
 for (i = 0; i < _PB_NI; i++)
 nrm = nrm + (a[k][i] * a[k][i]);
 r[k][k] = sqrt(nrm);
 for (i = 0; i < _PB_NI; i++)
 q[k][i] = a[k][i] / r[k][k];
 for (j = k + 1; j < _PB_NJ; j++) {
 r[j][k] = 0.0;
 for (i = 0; i < _PB_NI; i++)
 r[j][k] = r[j][k] + (q[k][i] * a[j][i]);
 for (i = 0; i < _PB_NI; i++)
 a[j][i] = a[j][i] - (q[k][i] * r[j][k]);
 }
 }
}
