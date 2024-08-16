void kernel_doitgen(int nr, int nq, int np, double a[np][nq][nr], double cFour[np][np], double sumA[np][nq][nr]){
 int r,s,p,q;
 
#pragma scop
 for (r = 0; r < nr; r++)
 for (q = 0; q < nq; q++)
 for (p = 0; p < np; p++){
 sumA[p][q][r] = 0.0;
 for (s = 0; s < np; s++)
 sumA[p][q][r] += a[s][q][r] * cFour[p][s];
 }
 for (p = 0; p < np; p++)
 a[p][q][r] = sumA[p][q][r];
#pragma endscop
}
