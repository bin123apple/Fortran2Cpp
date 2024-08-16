```C++
#include <cmath>

#define DATA_TYPE double
#define _PB_CZ cz
#define _PB_CYM cym
#define _PB_CXM cxm

void kernel_fdtd_apml(int cz, int cxm, int cym, DATA_TYPE mui, DATA_TYPE ch, 
                      DATA_TYPE ex[_PB_CXM+1][_PB_CYM+1][_PB_CZ+1], DATA_TYPE ey[_PB_CXM+1][_PB_CYM+1][_PB_CZ+1], 
                      DATA_TYPE hz[_PB_CXM+1][_PB_CYM+1][_PB_CZ+1], DATA_TYPE clf[_PB_CYM+1][_PB_CZ+1], 
                      DATA_TYPE ry[_PB_CYM+1][_PB_CZ+1], DATA_TYPE ax[_PB_CYM+1][_PB_CZ+1], 
                      DATA_TYPE cymh[_PB_CYM+1], DATA_TYPE cyph[_PB_CYM+1], DATA_TYPE cxmh[_PB_CXM+1], 
                      DATA_TYPE cxph[_PB_CXM+1], DATA_TYPE czm[_PB_CZ+1], DATA_TYPE czp[_PB_CZ+1], 
                      DATA_TYPE tmp[_PB_CYM+1][_PB_CZ+1], DATA_TYPE bza[_PB_CXM+1][_PB_CYM+1][_PB_CZ+1])
{
  int ix, iy, iz;

  for (iz = 1; iz <= _PB_CZ; iz++) {
    for (iy = 1; iy <= _PB_CYM; iy++) {
      for (ix = 1; ix <= _PB_CXM; ix++) {
        clf[iy][iz] = ex[ix][iy][iz] - ex[ix][iy + 1][iz] + ey[ix + 1][iy][iz] - ey[ix][iy][iz];
        tmp[iy][iz] = ((cymh[iy] / cyph[iy]) * bza[ix][iy][iz]) - ((ch / cyph[iy]) * clf[iy][iz]);
        hz[ix][iy][iz] = ((cxmh[ix] / cxph[ix]) * hz[ix][iy][iz]) + ((mui * czp[iz] / cxph[ix]) * tmp[iy][iz]) - ((mui * czm[iz] / cxph[ix]) * bza[ix][iy][iz]);
        bza[ix][iy][iz] = tmp[iy][iz];
      }

      // More code
    }
  }
}
```
