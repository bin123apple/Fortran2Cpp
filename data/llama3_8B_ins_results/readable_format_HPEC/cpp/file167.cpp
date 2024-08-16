#include <iostream>
#include <vector>

using namespace std;

void exact(int i, int j, int k, vector<double>& u000ijk) {
    double xi, eta, zeta;

    xi = (double(i - 1) / (double(nx0 - 1)));
    eta = (double(j - 1) / (double(ny0 - 1)));
    zeta = (double(k - 1) / (double(nz - 1)));

    vector<double> ce = { /* initialize ce array with values */ };
    for (int m = 1; m <= 5; m++) {
        u000ijk[m - 1] = ce[m - 1] + (ce[m] + (ce[m + 4] + (ce[m + 8] + ce[m + 11] * xi) * xi) * xi) * xi
                         + (ce[m + 1] + (ce[m + 2] + (ce[m + 5] + ce[m + 12] * eta) * eta) * eta) * eta
                         + (ce[m + 3] + (ce[m + 4] + (ce[m + 7] + ce[m + 13] * zeta) * zeta) * zeta) * zeta;
    }
}
