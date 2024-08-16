#include <vector>

// Assuming the existence of a namespace or class containing the necessary data
// For example, if the Fortran code uses 'use lu_data', you would need to include or define
// the equivalent in C++.

namespace lu_data {
    extern std::vector<std::vector<double>> ce; // Assuming 'ce' is defined somewhere
    extern int nx0, ny0, nz; // Assuming these are defined somewhere
}

void exact(int i, int j, int k, std::vector<double>& u000ijk) {
    double xi = (static_cast<double>(i - 1)) / (lu_data::nx0 - 1);
    double eta = (static_cast<double>(j - 1)) / (lu_data::ny0 - 1);
    double zeta = (static_cast<double>(k - 1)) / (lu_data::nz - 1);

    for (int m = 0; m < 5; ++m) {
        u000ijk[m] = lu_data::ce[m][0] +
                    (lu_data::ce[m][1] +
                    (lu_data::ce[m][4] +
                    (lu_data::ce[m][7] +
                    (lu_data::ce[m][10] * xi) * xi) * xi) * xi) +
                    (lu_data::ce[m][2] +
                    (lu_data::ce[m][5] +
                    (lu_data::ce[m][8] +
                    (lu_data::ce[m][11] * eta) * eta) * eta) * eta) +
                    (lu_data::ce[m][3] +
                    (lu_data::ce[m][6] +
                    (lu_data::ce[m][9] +
                    (lu_data::ce[m][12] * zeta) * zeta) * zeta) * zeta);
    }
}
