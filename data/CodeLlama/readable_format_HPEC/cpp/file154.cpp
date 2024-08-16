#include <iostream>
#include <vector>

// Assuming the size of the arrays are defined globally
extern int nx2, ny2, nz2;
extern double bt;
extern std::vector<std::vector<std::vector<double>>> rhs;

void ninvr() {
    double r1, r2, r3, r4, r5, t1, t2;

    if (timeron) timer_start(t_ninvr);

    for (int k = 0; k < nz2; ++k) {
        for (int j = 0; j < ny2; ++j) {
            for (int i = 0; i < nx2; ++i) {
                r1 = rhs[0][i][j][k];
                r2 = rhs[1][i][j][k];
                r3 = rhs[2][i][j][k];
                r4 = rhs[3][i][j][k];
                r5 = rhs[4][i][j][k];

                t1 = bt * r3;
                t2 = 0.5 * (r4 + r5);

                rhs[0][i][j][k] = -r2;
                rhs[1][i][j][k] = r1;
                rhs[2][i][j][k] = bt * (r4 - r5);
                rhs[3][i][j][k] = -t1 + t2;
                rhs[4][i][j][k] = t1 + t2;
            }
        }
    }

    if (timeron) timer_stop(t_ninvr);
}

int main() {
    // Initialize global variables and the rhs array
    // For example:
    nx2 = 10; // Example value
    ny2 = 10; // Example value
    nz2 = 10; // Example value
    bt = 1.0;  // Example value

    // Allocate and initialize the rhs array
    rhs.resize(5);
    for (int i = 0; i < 5; ++i) {
        rhs[i].resize(nx2);
        for (int j = 0; j < nx2; ++j) {
            rhs[i][j].resize(ny2);
            for (int k = 0; k < ny2; ++k) {
                rhs[i][j][k].resize(nz2);
                // Initialize with some values
                rhs[i][j][k] = 0.0; // Example initialization
            }
        }
    }

    // Call the function
    ninvr();

    return 0;
}
