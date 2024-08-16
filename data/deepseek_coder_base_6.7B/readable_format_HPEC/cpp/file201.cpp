To translate the given Fortran code to C++, we need to consider several aspects, including array indexing, data types, and the loop structure. Fortran arrays are 1-based, while C++ arrays are 0-based. Also, Fortran passes arrays to functions and subroutines by reference by default, whereas in C++, we need to explicitly use pointers or references. For simplicity and to maintain the spirit of the original code, I'll use pointers for the arrays in C++. Note that in C++, we need to manually manage memory for the arrays, which is not shown in the Fortran code snippet.

Here's a C++ translation of the provided Fortran code:

```cpp
#include <iostream>

// Assuming DATA_TYPE is a float or double for this translation
typedef double DATA_TYPE;

void kernel_fdtd_apml(int cz, int cxm, int cym, DATA_TYPE mui, DATA_TYPE ch, 
                       DATA_TYPE* ax, DATA_TYPE* ry, DATA_TYPE* clf, DATA_TYPE* tmp, DATA_TYPE* bza, 
                       DATA_TYPE* ex, DATA_TYPE* ey, DATA_TYPE* hz, DATA_TYPE* czm, DATA_TYPE* czp, 
                       DATA_TYPE* cxmh, DATA_TYPE* cxph, DATA_TYPE* cymh, DATA_TYPE* cyph) {
    // Assuming the dimensions are (cxm + 1) x (cym + 1) x (cz + 1) for ex, ey, hz, and similarly for other arrays
    // Note: In C++, array indexing starts from 0, unlike Fortran which starts from 1

    // Loop over the indices
    for (int iz = 0; iz < cz; ++iz) {
        for (int iy = 0; iy < cym; ++iy) {
            for (int ix = 0; ix < cxm; ++ix) {
                // Compute clf, tmp, and hz
                clf[iy * cz + iz] = ex[ix * (cym + 1) * (cz + 1) + iy * (cz + 1) + iz] - 
                                    ex[ix * (cym + 1) * (cz + 1) + (iy + 1) * (cz + 1) + iz] + 
                                    ey[(ix + 1) * (cym + 1) * (cz + 1) + iy * (cz + 1) + iz] - 
                                    ey[ix * (cym + 1) * (cz + 1) + iy * (cz + 1) + iz];
                tmp[iy * cz + iz] = ((cymh[iy] / cyph[iy]) * bza[ix * (cym + 1) * (cz + 1) + iy * (cz + 1) + iz]) - 
                                    ((ch / cyph[iy]) * clf[iy * cz + iz]);
                hz[ix * (cym + 1) * (cz + 1) + iy * (cz + 1) + iz] = ((cxmh[ix] / cxph[ix]) * 
                                    hz[ix * (cym + 1) * (cz + 1) + iy * (cz + 1) + iz]) + 
                                    ((mui * czp[iz] / cxph[ix]) * tmp[iy * cz + iz]) - 
                                    ((mui * czm[iz] / cxph[ix]) * bza[ix * (cym + 1) * (cz + 1) + iy * (cz + 1) + iz]);
                bza[ix * (cym + 1) * (cz + 1) + iy * (cz + 1) + iz] = tmp[iy * cz + iz];
            }
        }
    }

    // Additional loops for the boundary conditions
    for (int iy = 0; iy < cym; ++iy) {
        for (int iz = 0; iz < cz; ++iz) {
            // Compute clf, tmp, and hz for the last column
            clf[iy * cz + iz] = ex[(cxm - 1) * (cym + 1) * (cz + 1) + iy * (cz + 1) + iz] - 
                                ex[(cxm - 1) * (cym + 1) * (cz + 1) + (iy + 1) * (cz + 1) + iz] + 
                                ry[iy * cz + iz] - 
                                ey[(cxm - 1) * (cym + 1) * (cz + 1) + iy * (cz + 1) + iz];
            tmp[iy * cz + iz] = ((cymh[iy] / cyph[iy]) * bza[(cxm - 1) * (cym + 1) * (cz + 1) + iy * (cz + 1) + iz]) - 
                                ((ch / cyph[iy]) * clf[iy * cz + iz]);
            hz[(cxm - 1) * (cym + 1) * (cz + 1) + iy * (cz + 1) + iz] = ((cxmh[cxm - 1] / cxph[cxm - 1]) * 
                                hz[(cxm - 1) * (cym + 1) * (cz + 1) + iy * (cz + 1) + iz]) + 
                                ((mui * czp[iz] / cxph[cxm - 1]) * tmp[iy * cz + iz]) - 
                                ((mui * czm[iz] / cxph[cxm - 1]) * bza[(cxm - 1) * (cym + 1) * (cz + 1) + iy * (cz + 1) + iz]);
            bza[(cxm - 1) * (cym + 1) * (cz + 1) + iy * (cz + 1) + iz] = tmp[iy * cz + iz];
        }
    }

    for (int ix = 0; ix < cxm; ++ix) {
        for (int iz = 0; iz < cz; ++iz) {
            // Compute clf, tmp, and hz for the last row
            clf[iy * cz + iz] = ex[ix * (cym + 1) * (cz + 1) + (cym - 1) * (cz + 1) + iz] - 
                                ax[ix * (cz + 1) + iz] + 
                                ey[(ix + 1) * (cym + 1) * (cz + 1) + (cym - 1) * (cz + 1) + iz] - 
                                ey[ix * (cym + 1) * (cz + 1) + (cym - 1) * (cz + 1) + iz];
            tmp[iy * cz + iz] = ((cymh[cym - 1] / cyph[iy]) * bza[ix * (cym + 1) * (cz + 1) + (cym - 1) * (cz + 1) + iz]) - 
                                ((ch / cyph[iy]) * clf[iy * cz + iz]);
            hz[ix * (cym + 1) * (cz + 1) + (cym - 1) * (cz + 1) + iz] = ((cxmh[ix] / cxph[ix]) * 
                                hz[ix * (cym + 1) * (cz + 1) + (cym - 1) * (cz + 1) + iz]) + 
                                ((mui * czp[iz] / cxph[ix]) * tmp[iy * cz + iz]) - 
                                ((mui * czm[iz] / cxph[ix]) * bza[ix * (cym + 1) * (cz + 1) + (cym - 1) * (cz + 1) + iz]);
            bza[ix * (cym + 1) * (cz + 1) + (cym - 1) * (cz + 1) + iz] = tmp[iy * cz + iz];
        }
    }

    // Compute clf, tmp, and hz for the last plane
