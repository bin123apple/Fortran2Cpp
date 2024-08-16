void init_array(int length, int **c, double **w){
 for(int i=0; i<length; i++)
 for(int j=0; j<length; j++){
 c[j][i] = ((i)*(j)) % 2;
 w[j][i] = (double) ((i) - (j)) / (double) length;
 }
}
