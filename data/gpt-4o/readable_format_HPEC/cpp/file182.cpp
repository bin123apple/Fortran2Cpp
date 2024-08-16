void vecset(int n, double* v, int* iv, int& nzv, int i, double val)
{
 bool set = false;
 for(int k = 0; k < nzv; k++)
 {
  if(iv[k] == i)
  {
   v[k] = val;
   set = true;
   break;
  }
 }
 if(!set)
 {
  nzv++;
  v[nzv-1] = val;
  iv[nzv-1] = i;
 }
}
