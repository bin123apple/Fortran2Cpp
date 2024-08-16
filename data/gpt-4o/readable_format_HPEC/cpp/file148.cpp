#include "sp_data.h"
#include <cmath>

void set_constants() {
    ce[0][0] = 2.0;
    ce[0][1] = 0.0;
    ce[0][2] = 0.0;
    ce[0][3] = 4.0;
    ce[0][4] = 5.0;
    ce[0][5] = 3.0;
    ce[0][6] = 0.5;
    ce[0][7] = 0.02;
    ce[0][8] = 0.01;
    ce[0][9] = 0.03;
    ce[0][10] = 0.5;
    ce[0][11] = 0.4;
    ce[0][12] = 0.3;

    //... similar assignments for ce[1][x], ce[2][x], ce[3][x], and ce[4][x] ...

    c1 = 1.4;
    c2 = 0.4;
    c3 = 0.1;
    c4 = 1.0;
    c5 = 1.4;

    bt = sqrt(0.5);

    dnxm1 = 1.0 / double(grid_points[0]-1);
    dnym1 = 1.0 / double(grid_points[1]-1);
    dnzm1 = 1.0 / double(grid_points[2]-1);

    c1c2 = c1 * c2;
    c1c5 = c1 * c5;
    c3c4 = c3 * c4;
    c1345 = c1c5 * c3c4;

    conz1 = (1.0-c1c5);

    tx1 = 1.0 / (dnxm1 * dnxm1);
    tx2 = 1.0 / (2.0 * dnxm1);
    tx3 = 1.0 / dnxm1;

    //... similar assignments for ty1, ty2, ty3, tz1, tz2, tz3 ...

    dx1 = 0.75;
    dx2 = 0.75;
    dx3 = 0.75;
    dx4 = 0.75;
    dx5 = 0.75;

    //... similar assignments for dy1, dy2, dy3, dy4, dy5 ...

    dz1 = 1.0;
    dz2 = 1.0;
    dz3 = 1.0;
    dz4 = 1.0;
    dz5 = 1.0;

    dxmax = std::max(dx3, dx4);
    dymax = std::max(dy2, dy4);
    dzmax = std::max(dz2, dz3);

    dssp = 0.25 * std::max(dx1, std::max(dy1, dz1));
    c4dssp = 4.0 * dssp;
    c5dssp = 5.0 * dssp;

    dttx1 = dt*tx1;
    dttx2 = dt*tx2;
    dtty1 = dt*ty1;
    //... and so on ...
    c2iv  = 2.5;
    con43 = 4.0/3.0;
    con16 = 1.0/6.0;

    xxcon1 = c3c4tx3*con43*tx3;
    xxcon2 = c3c4tx3*tx3;
    //... and so on ...
}
