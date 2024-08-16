#include <complex>
#include <cmath>
#include <ctime>
#define T_ffty 1
#define fftblockpad 128
#define d1 128
#define d2 128
#define d3 128

std::complex<double> x[d1+1][d2][d3];
std::complex<double> xout[d1+1][d2][d3];
std::complex<double> y1[fftblockpad][d2];
std::complex<double> y2[fftblockpad][d2];

bool timers_enabled = false;

void cfftz(int is, int logd2, int d2, std::complex<double> y1[][d2], std::complex<double> y2[][d2]);

void timer_start(int i);
void timer_stop(int i);

void cffts2(int is, int d1, int d2, int d3, std::complex<double> x[][d2][d3], std::complex<double> xout[][d2][d3], std::complex<double> y1[][d2], std::complex<double> y2[][d2])
{
    int i, j, k, ii, in;
    int logd2 = log2(d2);

    if (timers_enabled) timer_start(T_ffty);

    for (k = 0; k < d3; ++k)
    {
        for (in = 0; in < d1/fftblockpad; ++in)
        {
            ii = in*fftblockpad;
            for (j = 0; j < d2; ++j)
            {
                for (i = 0; i < fftblockpad; ++i)
                {
                    y1[i][j] = x[i+ii][j][k];
                }
            }

            cfftz(is, logd2, d2, y1, y2);

            for (j = 0; j < d2; ++j)
            {
                for (i = 0; i < fftblockpad; ++i)
                {
                    xout[i+ii][j][k] = y1[i][j];
                }
            }
        }
    }

    if (timers_enabled) timer_stop(T_ffty);
}
