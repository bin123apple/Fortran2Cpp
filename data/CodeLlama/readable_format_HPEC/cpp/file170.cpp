#include <vector>

// Assuming the dimensions are defined globally or passed to the function
extern int nx0, ny0, nz;

// Assuming the ce array is defined globally or passed to the function
extern std::vector<std::vector<double>> ce;

void exact(int i, int j, int k, std::vector<double>& u000ijk) {
    double xi = (static_cast<double>(i - 1) / (nx0 - 1));
    double eta = (static_cast<double>(j - 1) / (ny0 - 1));
    double zeta = (static_cast<double>(k - 1) / (nz - 1));

    for (int m = 0; m < 5; ++m) {
        u000ijk[m] = ce[m][0]
                    + (ce[m][1]
                    + (ce[m][4]
                    + (ce[m][7]
                    + (ce[m][10]
                    + (ce[m][13] * xi) * xi) * xi) * xi) * xi
                    + (ce[m][2]
                    + (ce[m][5]
                    + (ce[m][8]
                    + (ce[m][11] * eta) * eta) * eta) * eta) * eta
                    + (ce[m][3]
                    + (ce[m][6]
                    + (ce[m][9]
                    + (ce[m][12] * zeta) * zeta) * zeta) * zeta) * zeta;
    }
}
