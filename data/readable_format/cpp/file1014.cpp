#include <vector>

void dv7scp(int p, std::vector<double>& y, double s) {
    for (int i = 0; i < p; ++i) {
        y[i] = s;
    }
}