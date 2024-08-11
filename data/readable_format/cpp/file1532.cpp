#include <vector>

void per_getcof(std::vector<double>& coffs, int npt, std::vector<double>& g, int m) {
    for (int j = 0; j < m; ++j) {
        g[j] = -coffs[j + 1];
    }
}