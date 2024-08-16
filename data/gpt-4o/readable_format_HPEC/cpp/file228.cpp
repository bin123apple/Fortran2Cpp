void print_array(int maxgrid, DATA_TYPE path[][maxgrid])
{
 for(int i=0; i<maxgrid; i++)
 {
  for(int j=0; j<maxgrid; j++)
  {
    printf(DATA_PRINTF_MODIFIER, path[i][j]);
    if(((i*maxgrid)+j)%20 == 19)
    printf("
");
  }
 }
 printf("
");
}
