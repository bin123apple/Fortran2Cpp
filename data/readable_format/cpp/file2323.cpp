#include <iostream>
#include <vector>

void matvec(int n, const std::vector<double>& x, std::vector<double>& y, int nelt, const std::vector<int>& ia, const std::vector<int>& ja, const std::vector<double>& a, int isym) {
    int nd = nelt - n;
    int na = nd / 2; // Used only if isym == 0
    if (isym == 0) {
        for (int i = 0; i < n; ++i) {
            y[i] = a[nd + i] * x[i];
        }
        for (int j = 0; j < n; ++j) {
            for (int l = ja[j] - 1; l < ja[j + 1] - 1; ++l) { // Adjust for 0-based indexing
                int i = ia[l] - 1; // Adjust for 0-based indexing
                y[i] += a[l] * x[j];
            }
        }
        for (int j = 0; j < n; ++j) {
            for (int l = ja[j] - 1; l < ja[j + 1] - 1; ++l) { // Adjust for 0-based indexing
                int i = ia[l] - 1; // Adjust for 0-based indexing
                y[j] += a[l + na] * x[i];
            }
        }
    } else {
        // Handle the symmetric case if required
    }
}

int main() {
    int n = 5, nelt = 10, isym = 0;
    std::vector<int> ia = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
    std::vector<int> ja = {1, 3, 5, 7, 9, 11};
    std::vector<double> a = {1.0, 2.0, 3.0, 4.0, 5.0, 0.5, 1.5, 2.5, 3.5, 4.5};
    std::vector<double> x = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<double> y(n, 0.0);

    matvec(n, x, y, nelt, ia, ja, a, isym);

    std::cout << "y = ";
    for (double val : y) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}