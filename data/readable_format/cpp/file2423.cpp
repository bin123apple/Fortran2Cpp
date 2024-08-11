#include <algorithm> // for std::min and std::max
#include <cmath> // for std::abs

// Function prototype
void fc3d_clawpack5_fort_tag4refinement(int mx, int my, int mz, int mbc,
                                        int meqn, double xlower, double ylower, double zlower,
                                        double dx, double dy, double dz, int blockno,
                                        double* q, double tag_threshold, int init_flag, int& tag_patch);

// Function definition
void fc3d_clawpack5_fort_tag4refinement(int mx, int my, int mz, int mbc,
                                        int meqn, double xlower, double ylower, double zlower,
                                        double dx, double dy, double dz, int blockno,
                                        double* q, double tag_threshold, int init_flag, int& tag_patch) {

    tag_patch = 0;

    int mq = 0; // Fortran is 1-based, C++ is 0-based

    // Initialize qmin and qmax
    double qmin = q[mq + (1 - mbc) * meqn + (1 - mbc) * meqn * (mx + 2 * mbc) + (1 - mbc) * meqn * (mx + 2 * mbc) * (my + 2 * mbc)];
    double qmax = qmin;

    for (int k = 1 - mbc; k <= mz + mbc; ++k) {
        for (int j = 1 - mbc; j <= my + mbc; ++j) {
            for (int i = 1 - mbc; i <= mx + mbc; ++i) {
                double qval = q[mq + i * meqn + j * meqn * (mx + 2 * mbc) + k * meqn * (mx + 2 * mbc) * (my + 2 * mbc)];
                qmin = std::min(qval, qmin);
                qmax = std::max(qval, qmax);

                if (qmax - qmin > tag_threshold) {
                    tag_patch = 1;
                    return;
                }
            }
        }
    }
}