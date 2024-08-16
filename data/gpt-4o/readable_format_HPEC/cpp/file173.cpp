#include <stdio.h>
#include "mg_data.h"
double u[n1][n2][n3];
void comm3(int n1, int n2, int n3, int kk)
{
 int i1, i2, i3;
 if (timeron) timer_start(T_comm3);
 for (i3=1; i3<n3; i3++)
 for (i2=1; i2<n2; i2++)
 {
 u[0][i2][i3] = u[n1-2][i2][i3];
 u[n1-1][i2][i3] = u[1][i2][i3];
 }
 for (i3=1; i3<n3; i3++)
 for (i1=0; i1<n1; i1++)
 {
 u[i1][0][i3] = u[i1][n2-2][i3];
 u[i1][n2-1][i3] = u[i1][1][i3];
 }
 for (i2=0; i2<n2; i2++)
 for (i1=0; i1<n1; i1++)
 {
 u[i1][i2][0] = u[i1][i2][n3-2];
 u[i1][i2][n3-1] = u[i1][i2][1];
 }
 if (timeron) timer_stop(T_comm3);
 return;
}
