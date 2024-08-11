// plfit.cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

void plfit(const std::vector<double>& x, int nosmall, std::vector<double>& ksa, std::vector<double>& av) {
    int lx = x.size();
    double xmin = 0.0;

    for (int i = 0; i < lx; ++i) {
        if (x[i] <= xmin) {
            ksa[i] = 0.0;
            av[i] = 0.0;
        } else {
            xmin = x[i];
            double lzs = 0.0;
            int n = 0;
            for (int j = i; j < lx; ++j) {
                lzs += log(x[j] / xmin);
                n++;
            }
            av[i] = 1.0 + static_cast<double>(n) / lzs;
            if (nosmall > 0 && (av[i] - 1.0) / sqrt(static_cast<double>(n)) < 0.1) {
                ksa[i] = 0.0; // This condition was adjusted to match the Fortran logic
            } else {
                double ksp = 0.0;
                int nk = lx - i;
                for (int k = 1; k <= nk; ++k) {
                    double cx = static_cast<double>(k) / static_cast<double>(nk);
                    double cf = 1.0 - pow((xmin / x[k + i - 1]), (av[i] - 1));
                    double ks = std::fabs(cf - cx);
                    if (ks > ksp) {
                        ksp = ks;
                    }
                }
                ksa[i] = ksp;
            }
        }
    }
}

int main() {
    std::vector<double> x = {1.0, 2.0, 3.0, 4.0, 5.0};
    int nosmall = 1;
    std::vector<double> ksa(x.size()), av(x.size());

    plfit(x, nosmall, ksa, av);

    std::cout << "ksa: ";
    for (const auto& val : ksa) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "av: ";
    for (const auto& val : av) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}