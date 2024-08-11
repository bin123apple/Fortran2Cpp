#include <vector>
#include <cmath>

// Assuming that the C++ translation of applu.incl defines the following:
const int nx0 = /* appropriate value */;
const int ny0 = /* appropriate value */;
const int nz = /* appropriate value */;
const double ce[5][13] = {
    /* appropriate values */
};

void exact(int i, int j, int k, std::vector<double>& u000ijk) {
    double xi = static_cast<double>(i - 1) / (nx0 - 1);
    double eta = static_cast<double>(j - 1) / (ny0 - 1);
    double zeta = static_cast<double>(k - 1) / (nz - 1);

    for (int m = 0; m < 5; ++m) {
        u000ijk[m] = ce[m][0]
            + ce[m][1] * xi
            + ce[m][2] * eta
            + ce[m][3] * zeta
            + ce[m][4] * xi * xi
            + ce[m][5] * eta * eta
            + ce[m][6] * zeta * zeta
            + ce[m][7] * xi * xi * xi
            + ce[m][8] * eta * eta * eta
            + ce[m][9] * zeta * zeta * zeta
            + ce[m][10] * xi * xi * xi * xi
            + ce[m][11] * eta * eta * eta * eta
            + ce[m][12] * zeta * zeta * zeta * zeta;
    }
}