```cpp
void kernel_covariance(int m, int n, double float_n, double** dat, double** symmat, double* mean) {
    int i, j, j1, j2;

    // Determine mean of column vectors of input data matrix
    for (j = 0; j < m; j++) {
        mean[j] = 0.0;
        for (i = 0; i < n; i++) {
            mean[j] += dat[j][i];
        }
        mean[j] /= float_n;
    }

    // Center the column vectors
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            dat[j][i] -= mean[j];
        }
    }

    // Calculate the m * m covariance matrix
    for (j1 = 0; j1 < m; j1++) {
        for (j2 = j1; j2 < m; j2++) {
            symmat[j2][j1] = 0.0;
            for (i = 0; i < n; i++) {
                symmat[j2][j1] += dat[j1][i] * dat[j2][i];
            }
            symmat[j1][j2] = symmat[j2][j1];
        }
    }
}
```
