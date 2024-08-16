Below is the translated Fortran code to C++. This translation attempts to maintain the original structure and logic of the Fortran code, while adapting it to C++ syntax and conventions. Note that some adjustments are made to adapt to C++'s 0-based indexing and the way arrays are handled. Additionally, I've assumed the existence of certain functions or variables that were not provided in the original Fortran code snippet, such as `myid`, `num_threads`, and `last_n`, which are placeholders for parallel processing context information.

```cpp
#include <iostream>
#include <vector>
#include <cmath>

// Assuming the existence of these functions or variables in the original Fortran code
extern int myid;
extern int num_threads;
extern std::vector<int> last_n;

// Assuming the existence of a type kz equivalent to Fortran's integer(kz)
using kz = int;

void sparse(std::vector<double>& a, std::vector<int>& colidx, std::vector<kz>& rowstr, int n, kz& nz, int nonzer, std::vector<int>& arow, std::vector<std::vector<int>>& acol, 
            std::vector<std::vector<double>>& aelt, int firstrow, int lastrow, 
            std::vector<double>& v, std::vector<int>& iv, std::vector<kz>& nzloc, double& rcond, double shift) {
    int nrows = lastrow - firstrow + 1;
    kz j1 = ilow + 1;
    kz j2 = ihigh + 1;

    // Initializing rowstr
    for (kz j = j1; j <= j2; ++j) {
        rowstr[j] = 0;
    }

    // Computing rowstr
    for (int i = 1; i <= n; ++i) {
        for (kz nza = 1; nza <= arow[i]; ++nza) {
            int j = acol[nza][i];
            if (j >= ilow && j <= ihigh) {
                j = j + 1;
                rowstr[j] += arow[i];
            }
        }
    }

    // Adjusting rowstr for myid = 0
    if (myid == 0) {
        rowstr[1] = 1;
        j1 = 1;
    }
    for (kz j = j1 + 1; j <= j2; ++j) {
        rowstr[j] += rowstr[j - 1];
    }

    // Computing nzrow for myid < num_threads
    kz nzrow = 0;
    if (myid < num_threads) {
        for (int i = 0; i < myid; ++i) {
            nzrow += last_n[i];
        }
    }
    if (nzrow > 0) {
        for (kz j = j1; j <= j2; ++j) {
            rowstr[j] += nzrow;
        }
    }

    kz nza = rowstr[nrows + 1] - 1;

    if (nza > nz) {
        std::cerr << "Space for matrix elements exceeded in sparse" << std::endl;
        std::cerr << "nza, nzmax = " << nza << ", " << nz << std::endl;
        exit(1);
    }

    // Initializing v and iv
    for (kz j = ilow; j <= ihigh; ++j) {
        for (kz k = rowstr[j]; k < rowstr[j + 1]; ++k) {
            v[k] = 0.0;
            iv[k] = 0;
        }
        nzloc[j] = 0;
    }

    double size = 1.0;
    double ratio = std::pow(rcond, 1.0 / static_cast<double>(n));

    for (int i = 1; i <= n; ++i) {
        for (kz nza = 1; nza <= arow[i]; ++nza) {
            int j = acol[nza][i];

            if (j < ilow || j > ihigh) goto label60;

            double scale = size * aelt[nza][i];
            for (kz nzrow = 1; nzrow <= arow[i]; ++nzrow) {
                int jcol = acol[nzrow][i];
                double va = aelt[nzrow][i] * scale;

                if (jcol == j && j == i) {
                    va = va + rcond - shift;
                }

                for (kz k = rowstr[j]; k < rowstr[j + 1]; ++k) {
                    if (iv[k] > jcol) {
                        for (kz kk = rowstr[j + 1] - 2; kk >= k; --kk) {
                            if (iv[kk] > 0) {
                                v[kk + 1] = v[kk];
                                iv[kk + 1] = iv[kk];
                            }
                        }
                        iv[k] = jcol;
                        v[k] = 0.0;
                        goto label40;
                    } else if (iv[k] == 0) {
                        iv[k] = jcol;
                        goto label40;
                    } else if (iv[k] == jcol) {
                        nzloc[j]++;
                        goto label40;
                    }
                }
                std::cerr << "internal error in sparse: i=" << i << std::endl;
                exit(1);
            label40:
                v[k] += va;
            }
        }
    label60:
        continue;
    }

    size *= ratio;

    for (kz j = ilow + 1; j <= ihigh; ++j) {
        nzloc[j] += nzloc[j - 1];
    }

    // Computing nzrow for myid < num_threads
    nzrow = 0;
    if (myid < num_threads) {
        for (int i = 0; i < myid; ++i) {
            nzrow += last_n[i];
        }
    }
    if (nzrow > 0) {
        for (kz j = ilow; j <= ihigh; ++j) {
            nzloc[j] += nzrow;
        }
    }

    for (kz j = 1; j <= nrows; ++j) {
        kz j1 = (j > 1) ? rowstr[j] - nzloc[j - 1] : 1;
        kz j2 = rowstr[j + 1] - nzloc[j] - 1;
        kz nza = rowstr[j];
        for (kz k = j1; k <= j2; ++k) {
            a[k] = v[nza];
            colidx[k] = iv[nza];
            nza++;
        }
    }

    for (kz j = 2; j <= nrows + 1; ++j) {
        rowstr[j] -= nzloc[j - 1];
    }
    nza = rowstr[nrows + 1] - 1;
}

int main() {
    // Example usage
    int n = 10; // Example size
    kz nz = 100; // Example nonzeros
    int nonzer = 5; // Example nonzeros per row
    std::vector<int> arow(n + 1); // Example row sizes
    std::vector<std::vector<int>> acol(nonzer + 1, std::vector<int>(n + 1)); // Example column indices
    std::vector<std::vector<double>> aelt(nonzer + 1, std::vector<double>(n + 1)); // Example element values
    int firstrow = 1, lastrow = n; // Example row range
    std::vector<double> v(nz); // Example vector for values
    std::vector<int> iv(nz); // Example vector for indices
    std::vector<kz> nzloc(n + 1); // Example vector for nonzeros per row
    double rcond
