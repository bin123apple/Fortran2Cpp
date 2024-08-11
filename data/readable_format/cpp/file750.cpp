#include <vector>
#include <numeric>
#include <iostream>

// Define the compute function.
void compute(int nz, int b, float* q_subarray, float* t_subarray) {
    for (int i = 0; i < nz; ++i) {
        q_subarray[i] += 1.0f;
    }
    for (int i = 0; i < b; ++i) {
        t_subarray[i] += 1.0f;
    }
}

int main() {
    const int nproma = 20; // Corresponds to columns in q, rows in t
    const int nz = 60;     // Corresponds to rows in q, columns in t

    std::vector<float> q(nproma * nz, 0.0f);
    std::vector<float> t(nz * nproma, 0.0f);

    for (int p = 0; p < nproma; ++p) {
        compute(nz, nproma, &q[p * nz], &t[p * nproma]);
    }

    float sum_q = std::accumulate(q.begin(), q.end(), 0.0f);
    float sum_t = std::accumulate(t.begin(), t.end(), 0.0f);

    std::cout << "Sum of q: " << sum_q << std::endl;
    std::cout << "Sum of t: " << sum_t << std::endl;

    return 0;
}