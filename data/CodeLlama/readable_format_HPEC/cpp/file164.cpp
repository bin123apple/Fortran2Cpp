#include <algorithm> // For std::max

// Assuming the existence of a namespace lu_data and its members nx0, ny0, nz0
// and the definition of the array ce.

namespace lu_data {
    extern int nx0, ny0, nz0;
    extern double ce[13][13];
}

void setcoeff() {
    double dxi, deta, dzeta;
    double tx1, tx2, tx3;
    double ty1, ty2, ty3;
    double tz1, tz2, tz3;
    double dx1, dx2, dx3, dx4, dx5;
    double dy1, dy2, dy3, dy4, dy5;
    double dz1, dz2, dz3, dz4, dz5;
    double dssp;

    dxi = 1.0 / (lu_data::nx0 - 1);
    deta = 1.0 / (lu_data::ny0 - 1);
    dzeta = 1.0 / (lu_data::nz0 - 1);

    tx1 = 1.0 / (dxi * dxi);
    tx2 = 1.0 / (2.0 * dxi);
    tx3 = 1.0 / dxi;

    ty1 = 1.0 / (deta * deta);
    ty2 = 1.0 / (2.0 * deta);
    ty3 = 1.0 / deta;

    tz1 = 1.0 / (dzeta * dzeta);
    tz2 = 1.0 / (2.0 * dzeta);
    tz3 = 1.0 / dzeta;

    dx1 = 0.75;
    dx2 = dx1;
    dx3 = dx1;
    dx4 = dx1;
    dx5 = dx1;

    dy1 = 0.75;
    dy2 = dy1;
    dy3 = dy1;
    dy4 = dy1;
    dy5 = dy1;

    dz1 = 1.0;
    dz2 = dz1;
    dz3 = dz1;
    dz4 = dz1;
    dz5 = dz1;

    dssp = std::max({dx1, dy1, dz1}) / 4.0;

    lu_data::ce[0][0] = 2.0;
    lu_data::ce[0][1] = 0.0;
    lu_data::ce[0][2] = 0.0;
    lu_data::ce[0][3] = 4.0;
    lu_data::ce[0][4] = 5.0;
    lu_data::ce[0][5] = 3.0;
    lu_data::ce[0][6] = 5.0e-01;
    lu_data::ce[0][7] = 2.0e-02;
    lu_data::ce[0][8] = 1.0e-02;
    lu_data::ce[0][9] = 3.0e-02;
    lu_data::ce[0][10] = 5.0e-01;
    lu_data::ce[0][11] = 4.0e-01;
    lu_data::ce[0][12] = 3.0e-01;

    lu_data::ce[1][0] = 1.0;
    lu_data::ce[1][1] = 0.0;
    lu_data::ce[1][2] = 0.0;
    lu_data::ce[1][3] = 0.0;
    lu_data::ce[1][4] = 1.0;
    lu_data::ce[1][5] = 2.0;
    lu_data::ce[1][6] = 3.0;
    lu_data::ce[1][7] = 1.0e-02;
    lu_data::ce[1][8] = 3.0e-02;
    lu_data::ce[1][9] = 2.0e-02;
    lu_data::ce[1][10] = 4.0e-01;
    lu_data::ce[1][11] = 3.0e-01;
    lu_data::ce[1][12] = 5.0e-01;

    lu_data::ce[2][0] = 2.0;
    lu_data::ce[2][1] = 2.0;
    lu_data::ce[2][2] = 0.0;
    lu_data::ce[2][3] = 0.0;
    lu_data::ce[2][4] = 0.0;
    lu_data::ce[2][5] = 2.0;
    lu_data::ce[2][6] = 3.0;
    lu_data::ce[2][7] = 4.0e-02;
    lu_data::ce[2][8] = 3.0e-02;
    lu_data::ce[2][9] = 5.0e-02;
    lu_data::ce[2][10] = 3.0e-01;
    lu_data::ce[2][11] = 5.0e-01;
    lu_data::ce[2][12] = 4.0e-01;

    lu_data::ce[3][0] = 2.0;
    lu_data::ce[3][1] = 2.0;
    lu_data::ce[3][2] = 0.0;
    lu_data::ce[3][3] = 0.0;
    lu_data::ce[3][4] = 0.0;
    lu_data::ce[3][5] = 2.0;
    lu_data::ce[3][6] = 3.0;
    lu_data::ce[3][7] = 3.0e-02;
    lu_data::ce[3][8] = 5.0e-02;
    lu_data::ce[3][9] = 4.0e-02;
    lu_data::ce[3][10] = 3.0e-01;
    lu_data::ce[3][11] = 2.0e-01;
    lu_data::ce[3][12] = 1.0e-01;

    lu_data::ce[4][0] = 5.0;
    lu_data::ce[4][1] = 4.0;
    lu_data::ce[4][2] = 3.0;
    lu_data::ce[4][3] = 2.0;
    lu_data::ce[4][4] = 1.0e-01;
    lu_data::ce[4][5] = 4.0e-01;
    lu_data::ce[4][6] = 3.0e-01;
    lu_data::ce[4][7] = 5.0e-02;
    lu_data::ce[4][8] = 4.0e-02;
    lu_data::ce[4][9] = 3.0e-02;
    lu_data::ce[4][10] = 3.0e-01;
    lu_data::ce[4][11] = 2.0e-01;
    lu_data::ce[4][12] = 1.0e-01;

    lu_data::ce[5][0] = 4.0;
    lu_data::ce[5][1] = 3.0;
    lu_data::ce[5][2] = 2.0;
    lu_data::ce[5][3] = 1.0;
    lu_data::ce[5][4] = 3.0e-01;
    lu_data::ce[5][5] = 2.0e-01;
    lu_data::ce[5
