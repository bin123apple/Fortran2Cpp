#include <vector>

void msolve(int n, const std::vector<double>& r, std::vector<double>& z, int nelt, const std::vector<int>& ia, const std::vector<int>& ja, const std::vector<double>& a, int isym, std::vector<double>& rwork, std::vector<int>& iwork) {

    for (int i = 0; i < n; ++i) {
        z[i] = r[i] * rwork[i];
    }
}