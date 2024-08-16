void init_array(int ni, int nj, int nk, double alpha, double beta, double c[nj][ni], double a[nk][ni], double b[nj][nk]){
 alpha = 32412;
 beta = 2123;
 for (int i = 0; i < ni; i++){
 for (int j = 0; j < nj; j++){
 c[j][i] = ((double(i - 1) * double(j - 1))) / double(ni);
 }
 }
 for (int i = 0; i < ni; i++){
 for (int j = 0; j < nk; j++){
 a[j][i] = ((double(i - 1) * double(j - 1))) / double(ni);
 }
 }
 for (int i = 0; i < nk; i++){
 for (int j = 0; j < nj; j++){
 b[j][i] = ((double(i - 1) * double(j - 1))) / double(ni);
 }
 }
}
