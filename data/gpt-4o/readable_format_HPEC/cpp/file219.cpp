#include <stdio.h>
#define DATA_TYPE double
#define _PB_TMAX tmax
#define _PB_NX nx
#define _PB_NY ny

void kernel_fdtd_2d(int tmax, int nx, int ny, DATA_TYPE ex[ny][nx], DATA_TYPE ey[ny][nx], DATA_TYPE hz[ny][nx], DATA_TYPE fict[tmax]) 
{
 int i, j, t;
 for(t = 1; t < _PB_TMAX; t++)
 {
   for(j = 0; j < _PB_NY; j++)
   {
     ey[j][0] = fict[t];
   }
   for(i = 1; i < _PB_NX; i++)
   {
     for(j = 0; j < _PB_NY; j++)
     {
       ey[j][i] = ey[j][i] - 0.5 * (hz[j][i] - hz[j][i - 1]);
     }
   }
   for(i = 0; i < _PB_NX; i++)
   {
     for(j = 1; j < _PB_NY; j++)
     {
       ex[j][i] = ex[j][i] - 0.5 * (hz[j][i] - hz[j - 1][i]);
     }
   }
   for(i = 0; i < _PB_NX - 1; i++)
   {
     for(j = 0; j < _PB_NY - 1; j++)
     {
       hz[j][i] = hz[j][i] - 0.7 * ((ex[j + 1][i] - ex[j][i]) + (ey[j][i + 1] - ey[j][i]));
     }
   }
 }
}
