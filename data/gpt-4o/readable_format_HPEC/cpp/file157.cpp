#include <stdio.h>
#include <cmath>
void norm2u3(double u[100][100][100], int n1, int n2, int n3, double &rnm2, double &rnmu,
              int nx, int ny, int nz);
void rep_nrm(double u[100][100][100], int n1, int n2, int n3, char* title, int kk)
{
    double rnm2, rnmu;
    norm2u3(u,n1,n2,n3,rnm2,rnmu,nx,ny,nz);
    printf(" Level %d in %s: norms = %.14e %.14e
", kk, title, rnm2, rnmu);
}
