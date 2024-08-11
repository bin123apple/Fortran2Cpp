#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using dp = double;

namespace mo_salsa_sizedist {
    void size_distribution(int kproma, int kbdim, int klev,
                           const std::vector<dp>& n,
                           const std::vector<dp>& dpg,
                           const std::vector<dp>& sigmag,
                           std::vector<std::vector<std::vector<dp>>>& naero) {
        dp pi = 3.141592653589793;
        dp pi6 = 6.0 * pi;
        naero.assign(kbdim, std::vector<std::vector<dp>>(klev, std::vector<dp>(kproma, 0.0)));
        for (int jj = 0; jj < klev; ++jj) {
            for (int ii = 0; ii < kbdim; ++ii) {
                for (int kk = 1; kk <= kproma; ++kk) {
                    dp deltadp = std::pow(kk, 1.0/3.0) - std::pow(kk-1, 1.0/3.0);
                    deltadp /= std::pow(pi6, 1.0/3.0);
                    for (size_t i = 0; i < n.size(); ++i) {
                        naero[ii][jj][kk-1] += n[i] * deltadp / (dpg[i] * std::sqrt(2.0 * M_PI) * std::log(sigmag[i])) *
                                               std::exp(-std::pow(std::log(dpg[i]/dpg[kk-1]), 2.0) / (2.0 * std::pow(std::log(sigmag[i]), 2.0)));
                    }
                }
            }
        }
    }
}

int main() {
    const int nmod = 7, kbdim = 2, klev = 3, fn2b = 5;
    std::vector<dp> n = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
    std::vector<dp> dpg = {1.0, 1.2, 1.4, 1.6, 1.8, 2.0, 2.2};
    std::vector<dp> sigmag = {1.1, 1.1, 1.1, 1.1, 1.1, 1.1, 1.1};
    std::vector<std::vector<std::vector<dp>>> naero;

    mo_salsa_sizedist::size_distribution(fn2b, kbdim, klev, n, dpg, sigmag, naero);

    for (const auto& layer : naero) {
        for (const auto& lev : layer) {
            for (const auto val : lev) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "-----" << std::endl;
    }

    return 0;
}