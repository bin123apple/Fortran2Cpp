#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void makea(int n, int nz, vector<double>& a, vector<int>& colidx, vector<int>& rowstr, 
           int firstrow, int lastrow, int firstcol, int lastcol, 
           vector<int>& arow, vector<int>& acol, vector<double>& aelt, vector<double>& v, 
           vector<int>& iv) {
  // Use tinfo
  // Use cg_data, only : nonzer, rcond, shift

  int i, iouter, ivelt, nzv, nn1;
  int ivc[nonzer + 1];
  double vc[nonzer + 1];

  // External functions
  extern void sparse(vector<double>&, vector<int>&, vector<int>&, int, int, int, 
                     vector<int>&, vector<int>&, vector<double>&, int, int, 
                     vector<double>&, vector<int>&, double, double);
  extern void sprnvc(int, int, int, vector<double>&, vector<int>&);
  extern void vecset(int, vector<double>&, vector<int>&, int, int, double);

  // Initialize variables
  nn1 = 1;
  while (nn1 < n) {
    nn1 *= 2;
  }

  // Set number of threads and myid
  int num_threads = 1;
  int myid = 0;
  if (num_threads > max_threads) {
    if (myid == 0) {
      cout << "Warning: num_threads " << num_threads << " exceeded an internal limit " << max_threads << endl;
    }
    num_threads = max_threads;
  }

  int work = (n + num_threads - 1) / num_threads;
  int ilow = work * myid + 1;
  int ihigh = ilow + work - 1;
  if (ihigh > n) {
    ihigh = n;
  }

  // Loop over threads
  for (int iouter = 1; iouter <= ihigh; iouter++) {
    int nzv = nonzer;
    sprnvc(n, nzv, nn1, vc, ivc);
    if (iouter >= ilow) {
      vecset(n, vc, ivc, nzv, iouter, 0.5);
      arow[iouter] = nzv;
      for (int ivelt = 1; ivelt <= nzv; ivelt++) {
        acol[ivelt][iouter] = ivc[ivelt];
        aelt[ivelt][iouter] = vc[ivelt];
      }
    }
  }

  // Call sparse
  sparse(a, colidx, rowstr, n, nz, nonzer, arow, acol, aelt, firstrow, lastrow, v, iv[0], iv[nz + 1], rcond, shift);

  return;
}
