#include "sp_data.h"
#include <cmath>

void initialize() {
    int i, j, k, m, ix, iy, iz;
    double xi, eta, zeta, Pface[5][3][2], Pxi, Peta, Pzeta, temp[5];

    for(k=0;k<grid_points[3];k++){
        for(j=0;j<grid_points[2];j++){
            for(i=0;i<grid_points[1];i++){
                u[1][i][j][k] = 1.0;
                u[2][i][j][k] = 0.0;
                u[3][i][j][k] = 0.0;
                u[4][i][j][k] = 0.0;
                u[5][i][j][k] = 1.0;
            }
        }
    }

    for(k=0;k<grid_points[3];k++){
        for(j=0;j<grid_points[2];j++){
            zeta = double(k) * dnzm1;
            eta = double(j) * dnym1;
            for(i=0;i<grid_points[1];i++){
                xi = double(i) * dnxm1;
                for(ix=1;ix<=2;ix++){
                    Pxi = double(ix-1);
                    exact_solution(Pxi, eta, zeta, &Pface[1][1][ix-1]);
                }
                for(iy=1;iy<=2;iy++){
                    Peta = double(iy-1);
                    exact_solution(xi, Peta, zeta, &Pface[1][2][iy-1]);
                }
                for(iz=1;iz<=2;iz++){
                    Pzeta = double(iz-1);
                    exact_solution(xi, eta, Pzeta, &Pface[1][3][iz-1]);
                }
                for(m=1;m<=5;m++){
                    Pxi = xi * Pface[m-1][1][1] + (1.0-xi) * Pface[m-1][1][0];
                    Peta = eta * Pface[m-1][2][1] + (1.0-eta) * Pface[m-1][2][0];
                    Pzeta = zeta * Pface[m-1][3][1] + (1.0-zeta) * Pface[m-1][3][0];
                    u[m][i][j][k] = Pxi + Peta + Pzeta - Pxi*Peta - Pxi*Pzeta - Peta*Pzeta + Pxi*Peta*Pzeta;
                }
            }
        }
    }

    xi = 0.0;
    i = 0;
    for(k=0; k<grid_points[3]; k++){
        for(j=0; j<grid_points[2]; j++){
            zeta = double(k) * dnzm1;
            eta = double(j) * dnym1;
            exact_solution(xi, eta, zeta, temp);
            for(m=1; m<=5; m++){
                u[m][i][j][k] = temp[m-1];
            }
        }
    }

    xi = 1.0;
    i = grid_points[1]-1;
    for(k=0; k<grid_points[3]; k++){
        for(j=0; j<grid_points[2]; j++){
            zeta = double(k) * dnzm1;
            eta = double(j) * dnym1;
            exact_solution(xi, eta, zeta, temp);
            for(m=1; m<=5; m++){
                u[m][i][j][k] = temp[m-1];
            }
        }
    }

    eta = 0.0;
    j = 0;
    for(k=0; k<grid_points[3]; k++){
        for(i=0; i<grid_points[1]; i++){
            zeta = double(k) * dnzm1;
            xi = double(i) * dnxm1;
            exact_solution(xi, eta, zeta, temp);
            for(m=1; m<=5; m++){
                u[m][i][j][k] = temp[m-1];
            }
        }
    }

    eta = 1.0;
    j = grid_points[2]-1;
    for(k=0; k<grid_points[3]; k++){
        for(i=0; i<grid_points[1]; i++){
            zeta = double(k) * dnzm1;
            xi = double(i) * dnxm1;
            exact_solution(xi, eta, zeta, temp);
            for(m=1; m<=5; m++){
                u[m][i][j][k] = temp[m-1];
            }
        }
    }

    zeta = 0.0;
    k = 0;
    for(j=0; j<grid_points[2]; j++){
        for(i=0; i<grid_points[1]; i++){
            eta = double(j) * dnym1;
            xi = double(i) * dnxm1;
            exact_solution(xi, eta, zeta, temp);
            for(m=1; m<=5; m++){
                u[m][i][j][k] = temp[m-1];
            }
        }
    }

    zeta = 1.0;
    k = grid_points[3]-1;
    for(j=0; j<grid_points[2]; j++){
        for(i=0; i<grid_points[1]; i++){
            eta = double(j) * dnym1;
            xi = double(i) * dnxm1;
            exact_solution(xi, eta, zeta, temp);
            for(m=1; m<=5; m++){
                u[m][i][j][k] = temp[m-1];
            }
        }
    }
}
