void init_array(int n, double* a, double* b){
 for (int i=0; i<n; i++){
 a[i] = (double(i-1) + 2.0) / n;
 b[i] = (double(i-1) + 3.0) / n;
 }
}
