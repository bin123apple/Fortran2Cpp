void init_array(int maxgrid, float sumTang[100][100], float mean[100][100], float path[100][100])
{
 for(int i=0; i<maxgrid; i++)
 for(int j=0; j<maxgrid; j++)
 {
  sumTang[j][i] = i*j;
  mean[j][i] = (float)(i-j)/maxgrid;
  path[j][i] = (float)((i-1)*(j-2))/maxgrid;
 }
}
