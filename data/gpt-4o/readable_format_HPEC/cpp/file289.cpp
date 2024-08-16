void kernel_2mm(DATA_TYPE alpha, DATA_TYPE beta, DATA_TYPE tmp[nj][ni], DATA_TYPE a[nk][ni], DATA_TYPE b[nj][nk], DATA_TYPE c[nl][nj], DATA_TYPE d[nl][ni], int ni, int nj, int nk, int nl)
{
    int i, j, k;
#pragma scop
    for(i = 0; i < _PB_NI; i++){
        for(j = 0; j < _PB_NJ; j++){
            tmp[j][i] = 0.0;
            for(k = 0; k < _PB_NK; k++){
                tmp[j][i] = tmp[j][i] + alpha * a[k][i] * b[j][k];
            }
        }
    }
    for(i = 0; i < _PB_NI; i++){
        for(j = 0; j < _PB_NL; j++){
            d[j][i] = d[j][i] * beta;
            for(k = 0; k < _PB_NJ; k++){
                d[j][i] = d[j][i] + tmp[k][i] * c[j][k];
            }
        }
    }
#pragma endscop
}
