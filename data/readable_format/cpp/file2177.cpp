#include <cmath>
#include <vector>

void clawpack46_tag4refinement(int mx, int my, int mbc, int meqn,
                               double xlower, double ylower, double dx, double dy,
                               int blockno, const std::vector<std::vector<std::vector<double>>>& q,
                               double refine_threshold, int init_flag, int& tag_for_refinement) {
    tag_for_refinement = 0;

    for (int mq = 0; mq < meqn; ++mq) {
        for (int i = 1; i <= mx; ++i) {
            for (int j = 1; j <= my; ++j) {
                double qx = (q[i + 1][j][0] - q[i - 1][j][0]) / (2 * dx);
                double qy = (q[i][j + 1][0] - q[i][j - 1][0]) / (2 * dy);
                if (std::abs(qx) > refine_threshold || std::abs(qy) > refine_threshold) {
                    tag_for_refinement = 1;
                    return;
                }
            }
        }
    }
}