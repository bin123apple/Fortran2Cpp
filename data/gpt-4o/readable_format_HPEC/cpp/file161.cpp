#include "ft_data.h"
#include <cmath>
#include <complex>

void cffts3(int is, int d1, int d2, int d3, std::complex<double> x[(d1+1)*d2*d3], std::complex<double> xout[(d1+1)*d2*d3], std::complex<double> y1[fftblockpad*d3], std::complex<double> y2[fftblockpad*d3]) 
{
    int logd3;
    int i, j, k, ii, in;

    logd3 = (int)std::log2(d3);

    if (timers_enabled)
        timer_start(T_fftz);

    for (j = 0; j < d2; j++)
        for (in = 0; in < d1/fftblock; in++)
        {
            ii = in*fftblock;
            for (k = 0; k < d3; k++)
                for (i = 0; i < fftblock; i++)
                    y1[i + k*fftblockpad] = x[(i+ii) + j*(d1+1) + k*(d1+1)*d2];

            cfftz (is, logd3, d3, y1, y2);

            for (k = 0; k < d3; k++)
                for (i = 0; i < fftblock; i++)
                    xout[(i+ii) + j*(d1+1) + k*(d1+1)*d2] = y1[i + k*fftblockpad];
        }

    if (timers_enabled) 
        timer_stop(T_fftz);

    return;
}
