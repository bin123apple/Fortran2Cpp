#include <vector>

void init_array(int n, std::vector<double>& p, std::vector<std::vector<double>>& a) {
    // Resize vectors to match the dimensions of the Fortran arrays
    p.resize(n);
    a.resize(n, std::vector<double>(n));

    // Initialize p and a as per the Fortran code
    for (int i = 0; i < n; ++i) {
        p[i] = 1.0 / n;
        for (int j = 0; j < n; ++j) {
            a[j][i] = 1.0 / n;
        }
    }
}
