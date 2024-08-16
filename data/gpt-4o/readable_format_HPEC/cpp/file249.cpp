void kernel_reg_detect(int niter, int maxgrid, int length, double sumTang[100][100], double mean[100][100], double path[100][100], double diff[100][100][100], double sumDiff[100][100][100]) {

    int i, j, t, cnt;

    for (t = 0; t < niter; t++) {
        for (j = 0; j < maxgrid; j++) {
            for (i = j; i < maxgrid; i++) {
                for (cnt = 0; cnt < length; cnt++) {
                    diff[cnt][i][j] = sumTang[i][j];
                }
            }
        }
    }

    for (j = 0; j < maxgrid; j++) {
        for (i = j; i < maxgrid; i++) {
            sumDiff[0][i][j] = diff[0][i][j];
            for (cnt = 1; cnt < length; cnt++) {
                sumDiff[cnt][i][j] = sumDiff[cnt - 1][i][j] + diff[cnt][i][j];
            }
            mean[i][j] = sumDiff[length - 1][i][j];
        }
    }

    for (i = 0; i < maxgrid; i++) {
        path[i][0] = mean[i][0];
    }

    for (j = 1; j < maxgrid; j++) {
        for (i = j; i < maxgrid; i++) {
            path[i][j] = path[i - 1][j - 1] + mean[i][j];
        }
    }
}
