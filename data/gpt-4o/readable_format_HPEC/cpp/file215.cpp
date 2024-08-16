void kernel_floyd_warshall(int n, DATA_TYPE path[][n])
{
 for(int k = 0; k < _PB_N; k++)
 for(int i = 0; i < _PB_N; i++)
 for(int j = 0; j < _PB_N; j++)
 if(path[j][i] >= path[k][i] + path[j][k])
 path[j][i] = path[k][i] + path[j][k];
}
