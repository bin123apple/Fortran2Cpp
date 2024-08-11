#include <iostream>
#include <vector>
#include <cstdlib>

void sub(int N, std::vector<std::vector<double>>& u) {
    u[-N + N][N + N] = 0.0;
}

int main() {
    const int N = 10;
    std::vector<std::vector<double>> a(2 * N + 1, std::vector<double>(2 * N + 1, 1.0));

    sub(N, a);

    if (a[0][2 * N] != 0.0) {
        std::abort();
    }

    return 0;
}