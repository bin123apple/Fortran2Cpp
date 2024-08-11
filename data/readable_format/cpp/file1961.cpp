#include <vector>

void foo(std::vector<double>& x, int nnd) {
    for(int i = 1; i <= nnd; ++i) {
        x[i-1] = 1.0 + (1.0 * i) / nnd;
    }
}