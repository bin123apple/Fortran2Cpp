#include <cmath>
extern double amult, tran;
extern double randlc(double* x, double a);
extern int icnvrt(double x, int ipwr2);
void sprnvc(int n, int nz, std::vector<double>& v, std::vector<int>& iv, int nn1)
{
    int nzv = 0;
    while(true)
    {
        if(nzv >= nz) break;
        double vecelt = randlc(&tran, amult);
        double vecloc = randlc(&tran, amult);
        int i = icnvrt(vecloc, nn1) + 1;
        if(i > n) continue;
        for(int ii = 0; ii < nzv; ii++)
        {
            if(iv[ii] == i) goto skip;
        }
        nzv++;
        v[nzv] = vecelt;
        iv[nzv] = i;
    skip:;
    }
}
