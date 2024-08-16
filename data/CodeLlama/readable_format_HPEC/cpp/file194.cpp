#include <vector>
#include <cmath>

void init_array(int ni, int nj, std::vector<std::vector<double>>& a, std::vector<std::vector<double>>& r, std::vector<std::vector<double>>& q) {
    // Resize the arrays to match the dimensions nj x ni
    a.resize(nj, std::vector<double>(ni));
    r.resize(nj, std::vector<double>(nj));
    q.resize(nj, std::vector<double>(ni));

    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            a[j][i] = (static_cast<double>(i) * static_cast<double>(j)) / static_cast<double>(ni);
            q[j][i] = (static_cast<double>(i) * static_cast<double>(j + 1)) / static_cast<double>(nj);
        }
    }

    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            r[j][i] = (static_cast<double>(i) * static_cast<double>(j + 1)) / static_cast<double>(nj);
        }
    }
}

int main() {
    int ni = 5; // Example values
    int nj = 5;
    std::vector<std::vector<double>> a;
    std::vector<std::vector<double>> r;
    std::vector<std::vector<double>> q;

    init_array(ni, nj, a, r, q);

    // Optional: Print the arrays to verify the results
    for (int i = 0; i < nj; ++i) {
        for (int j = 0; j < ni; ++j) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
