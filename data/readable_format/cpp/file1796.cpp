#include <iostream>
#include <vector>

// Mock compute_column function
void compute_column(int nz, std::vector<float>& q, std::vector<float>& t) {
    for (int i = 0; i < nz; ++i) {
        q[i] += 1.0f; // Increment q by 1.0
        t[i] += 2.0f; // Increment t by 2.0
    }
}

int main() {
    const int nproma = 20;
    const int nz = 60;
    std::vector<std::vector<float>> q(nproma, std::vector<float>(nz, 0.0f));
    std::vector<std::vector<float>> t(nproma, std::vector<float>(nz, 0.0f));

    // Compute columns
    for (int p = 0; p < nproma; ++p) {
        compute_column(nz, q[p], t[p]);
    }

    // Calculate and print sums
    float sum_q = 0.0f, sum_t = 0.0f;
    for (int p = 0; p < nproma; ++p) {
        for (int z = 0; z < nz; ++z) {
            sum_q += q[p][z];
            sum_t += t[p][z];
        }
    }

    std::cout << "Total sum of q: " << sum_q << std::endl;
    std::cout << "Total sum of t: " << sum_t << std::endl;

    return 0;
}