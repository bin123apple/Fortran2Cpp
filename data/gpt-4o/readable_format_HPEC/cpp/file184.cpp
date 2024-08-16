void bubble(double ten[][2], int j1[][2], int j2[][2], int j3[][2], int m, int ind){
 double temp;
 int i, j_temp;
 if(ind == 1){
  for(i=0; i<m-1; i++){
   if(ten[i][ind] > ten[i+1][ind]){
    temp = ten[i+1][ind];
    ten[i+1][ind] = ten[i][ind];
    ten[i][ind] = temp;

    j_temp = j1[i+1][ind];
    j1[i+1][ind] = j1[i][ind];
    j1[i][ind] = j_temp;

    j_temp = j2[i+1][ind];
    j2[i+1][ind] = j2[i][ind];
    j2[i][ind] = j_temp;

    j_temp = j3[i+1][ind];
    j3[i+1][ind] = j3[i][ind];
    j3[i][ind] = j_temp;
   }
   else return;
  }
 }
 else{
  for(i=0; i<m-1; i++){
   if(ten[i][ind] < ten[i+1][ind]){
    temp = ten[i+1][ind];
    ten[i+1][ind] = ten[i][ind];
    ten[i][ind] = temp;

    j_temp = j1[i+1][ind];
    j1[i+1][ind] = j1[i][ind];
    j1[i][ind] = j_temp;

    j_temp = j2[i+1][ind];
    j2[i+1][ind] = j2[i][ind];
    j2[i][ind] = j_temp;

    j_temp = j3[i+1][ind];
    j3[i+1][ind] = j3[i][ind];
    j3[i][ind] = j_temp;
   }
   else return;
  }
 }
}
