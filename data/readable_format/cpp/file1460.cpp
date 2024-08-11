#include <cstdint> // For std::int64_t

void nidentll(const std::int64_t* x, std::int64_t px, int n, int& id) {
    id = 0;
    if (n == 0) return;
    int n2 = n + 1;
    int m;
    while (true) {
        m = (n2 + id) / 2;
        if (px >= x[m-1]) { // Adjusted index for 0-based array in C++
            id = m;
        } else {
            n2 = m;
        }
        if ((n2 - id) == 1) return;
    }
}