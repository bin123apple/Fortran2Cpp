#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

double overlap(const std::vector<double>& xa, const std::vector<double>& xb, double L2, int n, const std::vector<int>& atomlist, int nlist) {
    double q = 0.0;
    for (int j1 = 0; j1 < nlist; ++j1) {
        int i1 = (atomlist[j1] - 1) * 3;
        for (int j2 = 0; j2 < nlist; ++j2) {
            int i2 = (atomlist[j2] - 1) * 3;
            double dr2 = 0.0;
            for (int k = 0; k < 3; ++k) {
                double diff = xa[i1 + k] - xb[i2 + k];
                dr2 += diff * diff;
            }
            q += exp(-dr2 / L2);
        }
    }
    return q;
}

void overlap_gradient(const std::vector<double>& xa, const std::vector<double>& xb, double L2, int n, const std::vector<int>& atomlist, int nlist, double& q, std::vector<double>& gradient) {
    double iL2 = 1.0 / L2;
    q = 0.0;
    std::fill(gradient.begin(), gradient.end(), 0.0);
    for (int j1 = 0; j1 < nlist; ++j1) {
        int i1 = (atomlist[j1] - 1) * 3;
        for (int j2 = 0; j2 < nlist; ++j2) {
            int i2 = (atomlist[j2] - 1) * 3;
            std::vector<double> dr(3);
            double dr2 = 0.0;
            for (int k = 0; k < 3; ++k) {
                dr[k] = xa[i1 + k] - xb[i2 + k];
                dr2 += dr[k] * dr[k];
            }
            double q0 = exp(-dr2 * iL2);
            q += q0;
            for (int k = 0; k < 3; ++k) {
                gradient[i2 + k] += q0 * 2.0 * iL2 * dr[k];
            }
        }
    }
}

int main() {
    double L2 = 4.0;
    std::vector<double> xa = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    std::vector<double> xb = {1.5, 2.5, 3.5, 4.5, 5.5, 6.5};
    std::vector<int> atomlist = {1, 2};
    int n = 2;
    int nlist = 2;

    // Testing overlap function
    double result = overlap(xa, xb, L2, n, atomlist, nlist);
    std::cout << "Testing overlap function..." << std::endl;
    std::cout << "Result: " << result << std::endl;

    // Testing overlap_gradient function
    std::vector<double> gradient(3*n, 0);
    overlap_gradient(xa, xb, L2, n, atomlist, nlist, result, gradient);
    std::cout << "Testing overlap_gradient function..." << std::endl;
    std::cout << "Result (q): " << result << std::endl;
    std::cout << "Gradient: ";
    for (auto& val : gradient) std::cout << val << " ";
    std::cout << std::endl;

    return 0;
}