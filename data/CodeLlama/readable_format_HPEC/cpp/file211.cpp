#include <vector>
#include <cmath>

void init_array(int n, double& alpha, double& beta, 
                std::vector<std::vector<double>>& a, 
                std::vector<double>& u1, std::vector<double>& u2, 
                std::vector<double>& v1, std::vector<double>& v2, 
                std::vector<double>& w, std::vector<double>& x, 
                std::vector<double>& y, std::vector<double>& z) {
    // Initialize alpha and beta
    alpha = 43532.0;
    beta = 12313.0;

    // Resize vectors to match the size n
    a.resize(n, std::vector<double>(n));
    u1.resize(n);
    u2.resize(n);
    v1.resize(n);
    v2.resize(n);
    w.resize(n);
    x.resize(n);
    y.resize(n);
    z.resize(n);

    // Fill vectors with values
    for (int i = 0; i < n; ++i) {
        u1[i] = static_cast<double>(i);
        u2[i] = static_cast<double>(i) / n / 2.0;
        v1[i] = static_cast<double>(i) / n / 4.0;
        v2[i] = static_cast<double>(i) / n / 6.0;
        y[i] = static_cast<double>(i) / n / 8.0;
        z[i] = static_cast<double>(i) / n / 9.0;
        x[i] = 0.0;
        w[i] = 0.0;

        for (int j = 0; j < n; ++j) {
            a[j][i] = static_cast<double>(i - 1) * static_cast<double>(j - 1) / static_cast<double>(n);
        }
    }
}
