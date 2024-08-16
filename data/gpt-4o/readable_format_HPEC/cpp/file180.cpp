void setbv() 
{
    int i, j, k, m;
    double temp1[5], temp2[5];

    for (j = 0; j < ny; j++) 
    {
        for (i = 0; i < nx; i++) 
        {
            exact( i, j, 0, temp1 );
            exact( i, j, nz-1, temp2 );
            for (m = 0; m < 5; m++) 
            {
                u[m][i][j][0] = temp1[m];
                u[m][i][j][nz-1] = temp2[m];
            }
        }
    }

    for (k = 0; k < nz; k++) 
    {
        for (i = 0; i < nx; i++) 
        {
            exact( i, 0, k, temp1 );
            exact( i, ny-1, k, temp2 );
            for (m = 0; m < 5; m++) 
            {
                u[m][i][0][k] = temp1[m];
                u[m][i][ny-1][k] = temp2[m];
            }
        }
    }

    for (k = 0; k < nz; k++) 
    {
        for (j = 0; j < ny; j++) 
        {
            exact( 0, j, k, temp1 );
            exact( nx-1, j, k, temp2 );
            for (m = 0; m < 5; m++) 
            {
                u[m][0][j][k] = temp1[m];
                u[m][nx-1][j][k] = temp2[m];
            }
        }
    }
}
