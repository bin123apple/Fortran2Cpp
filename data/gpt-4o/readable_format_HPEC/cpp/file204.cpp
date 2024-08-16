#include <stdio.h>
#define DATA_TYPE double
void init_array(int n, DATA_TYPE p[], DATA_TYPE a[n][n]) {
 for (int i = 0; i < n; i++) {
 p[i] = 1.0 / n;
 for (int j = 0; j < n; j++) {
 a[j][i] = 1.0 / n;
 }
 }
}
