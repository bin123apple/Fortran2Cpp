#include "ft_data.h"
#include <complex>
#include <iostream>

void cfftz(int is, int m, int n, std::complex<double>** x, std::complex<double>** y)
{
    int i, j, l, mx;

    mx = u[0];
    if((is != 1 && is != -1) || m < 1 || m > mx)
    {
        std::cerr << "CFFTZ: Either U has not been initialized, or else "
                  << "one of the input parameters is invalid" 
                  << is << " " << m << " " << mx << std::endl;
        exit(1);
    }

    for(l = 1; l <= m; l+=2)
    {
        fftz2(is, l, m, n, fftblock, fftblockpad, u, x, y);
        if(l == m)
        {
            for(j = 0; j < n; j++)
            {
                for(i = 0; i < fftblock; i++)
                {
                    x[i][j] = y[i][j];
                }
            }
        }
        else
        {
            fftz2(is, l + 1, m, n, fftblock, fftblockpad, u, y, x);
        }
    }
}
