#include "tinfo.h"
#include "cg_data.h"
#include <algorithm>  

void makea(int n, int nz, double* a, int* colidx, int* rowstr, int firstrow, int lastrow, int firstcol, int lastcol, int* arow, int* acol, double* aelt, double* v, int *iv)
{
    int i, iouter, ivelt, nzv, nn1;
    int *ivc = new int [nonzer+1];
    double *vc = new double [nonzer+1];

    nn1 = 1;
    while (nn1 < n)
        nn1 *= 2;

    num_threads = 1;
    myid = 0;
    if (num_threads > max_threads) 
    {
        if (myid == 0) 
            printf("Warning: num_threads %d exceeded an internal limit %d
", num_threads, max_threads);
        num_threads = max_threads;
    }
    int work = (n + num_threads - 1) / num_threads;
    int ilow = work * myid + 1;
    int ihigh = ilow + work - 1;
    if (ihigh > n) 
        ihigh = n;

    for (iouter = 1; iouter <= ihigh; iouter++) 
    {
        nzv = nonzer;
        sprnvc(n, nzv, nn1, vc, ivc);
        if (iouter >= ilow) 
        {
            vecset(n, vc, ivc, nzv, iouter, .5);
            arow[iouter-1] = nzv;
            for (ivelt = 0; ivelt < nzv; ivelt++) 
            {
                acol[ivelt + (iouter - 1) * (nonzer+1)] = ivc[ivelt];
                aelt[ivelt + (iouter - 1) * (nonzer+1)] = vc[ivelt];
            }
        }
    }
    sparse(a, colidx, rowstr, n, nz, nonzer, arow, acol, aelt, firstrow, lastrow, v, &iv[0], &iv[nz], rcond, shift);

    delete [] ivc;
    delete [] vc;
}
