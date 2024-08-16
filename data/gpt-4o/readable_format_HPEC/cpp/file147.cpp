void set_constants()
{
 double ce[5][13];

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
 // similar assignments for ce[1] to ce[4]

 double c1 = 1.4;
 double c2 = 0.4;
 double c3 = 0.1;
 double c4 = 1.0;
 double c5 = 1.4;

 double dnxm1 = 1.0 / double(grid_points[0]-1);
 double dnym1 = 1.0 / double(grid_points[1]-1);
 double dnzm1 = 1.0 / double(grid_points[2]-1);

 double c1c2 = c1 * c2;
 double c1c5 = c1 * c5;
 double c3c4 = c3 * c4;
 double c1345 = c1c5 * c3c4;

 double conz1 = (1.0-c1c5);

 double tx1 = 1.0 / (dnxm1 * dnxm1);
 double tx2 = 1.0 / (2.0 * dnxm1);
 double tx3 = 1.0 / dnxm1;

 double ty1 = 1.0 / (dnym1 * dnym1);
 double ty2 = 1.0 / (2.0 * dnym1);
 double ty3 = 1.0 / dnym1;

 double tz1 = 1.0 / (dnzm1 * dnzm1);
 double tz2 = 1.0 / (2.0 * dnzm1);
 double tz3 = 1.0 / dnzm1;

 double dx1 = 0.75;
 double dx2 = 0.75;
 double dx3 = 0.75;
 double dx4 = 0.75;
 double dx5 = 0.75;
 // similar assignments for dy1 to dy5 and dz1 to dz5

 // similar calculations for dxmax, dymax, dzmax, dssp, c4dssp, c5dssp, dttx1, dttx2, dtty1, dtty2, dttz1, dttz2, c2dttx1, c2dtty1, c2dttz1, dtdssp.
 // similar calculations for comz1, comz4, comz5, comz6, c3c4tx3, c3c4ty3, c3c4tz3, dx1tx1, dx2tx1, dx3tx1, dx4tx1, dx5tx1.
 // similar calculations for dy1ty1, dy2ty1, dy3ty1, dy4ty1, dy5ty1, dz1tz1, dz2tz1, dz3tz1, dz4tz1, dz5tz1, c2iv, con43, con16.
 // similar calculations for xxcon1, xxcon2, xxcon3, xxcon4, xxcon5, yycon1, yycon2, yycon3, yycon4, yycon5, zzcon1, zzcon2, zzcon3, zzcon4, zzcon5.
}
