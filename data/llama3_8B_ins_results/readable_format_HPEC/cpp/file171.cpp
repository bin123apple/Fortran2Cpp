#include <iostream>
#include <vector>
#include <random>

using namespace std;

void sprnvc(int n, int nz, int nn1, vector<double>& v, vector<int>& iv) {
  // Use a random number generator
  random_device rd;
  mt19937 gen(rd());
  uniform_real_distribution<double> randlc(0.0, 1.0);

  int nzv = 0;
  int ii, i, icnvrt;

  // Define the conversion function
  int icnvrt(double vecloc, int nn1) {
    return (int)(vecloc * nn1) + 1;
  }

  while (nzv < nz) {
    double vecelt = randlc(gen);
    double vecloc = randlc(gen);
    i = icnvrt(vecloc, nn1) + 1;
    if (i > n) continue;

    bool found = false;
    for (int j = 0; j < nzv; j++) {
      if (iv[j] == i) {
        found = true;
        break;
      }
    }
    if (!found) {
      nzv++;
      v.push_back(vecelt);
      iv.push_back(i);
    }
  }
}
