#include <iostream>
#include <vector>

// Function declaration
void fclaw2d_clawpatch5_fort_timeinterp(int mx, int my, int mbc, int meqn, int psize, 
                                        const std::vector<std::vector<std::vector<double>>>& qcurr,
                                        const std::vector<std::vector<std::vector<double>>>& qlast,
                                        std::vector<std::vector<std::vector<double>>>& qinterp,
                                        double alpha, int& ierror);

// Main function for unit testing
int main() {
    int mx = 10, my = 10, mbc = 2, meqn = 1, psize = 100;
    double alpha = 0.5;
    int ierror;

    std::vector<std::vector<std::vector<double>>> qcurr(meqn, std::vector<std::vector<double>>(mx + 2*mbc, std::vector<double>(my + 2*mbc, 1.0)));
    std::vector<std::vector<std::vector<double>>> qlast(meqn, std::vector<std::vector<double>>(mx + 2*mbc, std::vector<double>(my + 2*mbc, 0.5)));
    std::vector<std::vector<std::vector<double>>> qinterp(meqn, std::vector<std::vector<double>>(mx + 2*mbc, std::vector<double>(my + 2*mbc)));

    // Call the function
    fclaw2d_clawpatch5_fort_timeinterp(mx, my, mbc, meqn, psize, qcurr, qlast, qinterp, alpha, ierror);

    // Print qinterp to standard output or check its values
    for (const auto& eqn : qinterp) {
        for (const auto& row : eqn) {
            for (const auto& value : row) {
                std::cout << value << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "-------" << std::endl;
    }

    return 0;
}

// Function definition
void fclaw2d_clawpatch5_fort_timeinterp(int mx, int my, int mbc, int meqn, int psize, 
                                        const std::vector<std::vector<std::vector<double>>>& qcurr,
                                        const std::vector<std::vector<std::vector<double>>>& qlast,
                                        std::vector<std::vector<std::vector<double>>>& qinterp,
                                        double alpha, int& ierror) {
    ierror = 0;
    int k = 0;
    int mint = 2;
    int ng = 0;

    for (int m = 0; m < meqn; ++m) {
        for (int i = -ng; i < mx + ng; ++i) {
            for (int j = -ng; j < my + ng; ++j) {
                if (i >= 0 && i < mx && j >= 0 && j < my) { // Ensure indices are within bounds
                    qinterp[m][i + mbc][j + mbc] = qlast[m][i + mbc][j + mbc] + alpha * (qcurr[m][i + mbc][j + mbc] - qlast[m][i + mbc][j + mbc]);
                    ++k;
                }
            }
        }
    }

    if (k != psize) {
        ierror = 2;
    }
}