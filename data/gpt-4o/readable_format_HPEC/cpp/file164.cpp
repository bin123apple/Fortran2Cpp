#include "cg_data.h"
#include <cmath>

void conj_grad(double &rnorm)
{
    int j;
    int cgit, cgitmax = 25;
    int k;

    double d, sum = 0.0, rho = 0.0, rho0, alpha, beta, suml;

    for (j = 0; j <= naa; j++)
    {
        q[j] = 0.0;
        z[j] = 0.0;
        r[j] = x[j];
        p[j] = r[j];
    }

    for (j = 0; j <= lastcol - firstcol; j++)
        rho += r[j] * r[j];

    for (cgit = 0; cgit < cgitmax; cgit++)
    {
        rho0 = rho;
        d = 0.0;
        rho = 0.0;

        for (j = 0; j <= lastrow - firstrow; j++)
        {
            suml = 0.0;
            for (k = rowstr[j]; k < rowstr[j + 1]; k++)
                suml += a[k] * p[colidx[k]];

            q[j] = suml;
        }

        for (j = 0; j <= lastcol - firstcol; j++)
            d += p[j] * q[j];

        alpha = rho0 / d;

        for (j = 0; j <= lastcol - firstcol; j++)
        {
            z[j] += alpha * p[j];
            r[j] -= alpha * q[j];
            rho += r[j] * r[j];
        }

        beta = rho / rho0;

        for (j = 0; j <= lastcol - firstcol; j++)
            p[j] = r[j] + beta * p[j];
    }

    for (j = 0; j <= lastrow - firstrow; j++)
    {
        suml = 0.0;
        for (k = rowstr[j]; k < rowstr[j + 1]; k++)
            suml += a[k] * z[colidx[k]];

        r[j] = suml;
    }

    for (j = 0; j <= lastcol - firstcol; j++)
    {
        suml = x[j] - r[j];
        sum += suml * suml;
    }

    rnorm = sqrt(sum);
}
