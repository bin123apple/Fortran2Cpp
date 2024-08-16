#include <iostream>
#include <vector>

// Assuming the existence of these global variables and functions
extern bool timeron;
extern void timer_start(int t_tzetar);
extern void timer_stop(int t_tzetar);
extern std::vector<std::vector<std::vector<double>>> us, vs, ws, speed, rhs, u, qs;
extern double bt;
extern int nx2, ny2, nz2;

void tzetar() {
    int i, j, k;
    double t1, t2, t3, ac, xvel, yvel, zvel, r1, r2, r3, r4, r5, btuz, ac2u, uzik1;

    if (timeron) timer_start(t_tzetar);

    for (k = 1; k <= nz2; ++k) {
        for (j = 1; j <= ny2; ++j) {
            for (i = 1; i <= nx2; ++i) {
                xvel = us[i-1][j-1][k-1]; // Adjusted for 0-based indexing
                yvel = vs[i-1][j-1][k-1];
                zvel = ws[i-1][j-1][k-1];
                ac = speed[i-1][j-1][k-1];

                ac2u = ac * ac;

                r1 = rhs[0][i-1][j-1][k-1]; // Adjusted for 0-based indexing
                r2 = rhs[1][i-1][j-1][k-1];
                r3 = rhs[2][i-1][j-1][k-1];
                r4 = rhs[3][i-1][j-1][k-1];
                r5 = rhs[4][i-1][j-1][k-1];

                uzik1 = u[0][i-1][j-1][k-1]; // Adjusted for 0-based indexing
                btuz = bt * uzik1;

                t1 = btuz / ac * (r4 + r5);
                t2 = r3 + t1;
                t3 = btuz * (r4 - r5);

                rhs[0][i-1][j-1][k-1] = t2; // Adjusted for 0-based indexing
                rhs[1][i-1][j-1][k-1] = -uzik1 * r2 + xvel * t2;
                rhs[2][i-1][j-1][k-1] = uzik1 * r1 + yvel * t2;
                rhs[3][i-1][j-1][k-1] = zvel * t2 + t3;
                rhs[4][i-1][j-1][k-1] = uzik1 * (-xvel * r2 + yvel * r1) + qs[i-1][j-1][k-1] * t2 + c2iv * ac2u * t1 + zvel * t3;
            }
        }
    }

    if (timeron) timer_stop(t_tzetar);
}

int main() {
    // Example initialization of global variables
    bool timeron = true;
    int t_tzetar = 0; // Example value, adjust as necessary
    std::vector<std::vector<std::vector<double>>> us(10, std::vector<std::vector<double>(10, std::vector<double>(10, 0.0))),
                                                    vs, ws, speed, rhs(5, std::vector<std::vector<std::vector<double>>>(10, std::vector<std::vector<double>>(10, std::vector<double>(10, 0.0)))),
                                                    u(1, std::vector<std::vector<std::vector<double>>>(10, std::vector<std::vector<double>>(10, std::vector<double>(10, 0.0)))),
                                                    qs(10, std::vector<std::vector<double>>(10, std::vector<double>(10, 0.0)));
    double bt = 0.0; // Example value, adjust as necessary
    int nx2 = 10, ny2 = 10, nz2 = 10; // Example values, adjust as necessary

    // Call the function
    tzetar();

    return 0;
}
