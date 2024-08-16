#include <vector>

void init_array(int ni, int nj, double& alpha, double& beta, std::vector<std::vector<double>>& a, std::vector<std::vector<double>>& c) {
    alpha = 32412;
    beta = 2123;

    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            a[j][i] = static_cast<double>(i) * static_cast<double>(j) / static_cast<double>(ni);
        }
        for (int j = 0; j < ni; ++j) {
            c[j][i] = static_cast<double>(i) * static_cast<double>(j) / static_cast<double>(ni);
        }
    }
}

// Example usage
int main() {
    int ni = 10, nj = 5;
    double alpha, beta;
    std::vector<std::vector<double>> a(ni, std::vector<double>(ni));
    std::vector<std::vector<double>> c(ni, std::vector<double>(ni));

    init_array(ni, nj, alpha, beta, a, c);

    // Output results for verification
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < ni; ++j) {
            std::cout << "a[" << j << "][" << i << "] = " << a[j][i] << std::endl;
        }
    }

    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < ni; ++j) {
            std::cout << "c[" << j << "][" << i << "] = " << c[j][i] << std::endl;
        }
    }

    return 0;
}
