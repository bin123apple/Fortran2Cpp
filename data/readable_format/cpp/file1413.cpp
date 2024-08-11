#include <iostream>
#include <vector>
#include <numeric>

namespace mo_column {
    void compute(int nz, std::vector<float>& q, std::vector<float>& t) {
        // Assuming the compute function adds 1.0 to each element of q
        // and 2.0 to each element of t for demonstration purposes
        for (int i = 0; i < nz; ++i) {
            q[i] += 1.0f;
            t[i] += 2.0f;
        }
    }
}

int main() {
    const int nproma = 20;
    const int nz = 60;
    std::vector<std::vector<float>> q(nproma, std::vector<float>(nz, 0.0f));
    std::vector<std::vector<float>> t(nproma, std::vector<float>(nz, 0.0f));

    // Run compute on each "column"
    for (int p = 0; p < nproma; ++p) {
        mo_column::compute(nz, q[p], t[p]);
    }

    // Simple manual verification of the results
    bool testPassed = true;
    for (const auto& row : q) {
        for (auto elem : row) {
            if (elem != 1.0f) {
                testPassed = false;
                break;
            }
        }
    }
    for (const auto& row : t) {
        for (auto elem : row) {
            if (elem != 2.0f) {
                testPassed = false;
                break;
            }
        }
    }

    if (testPassed) {
        std::cout << "Test Passed: compute function works as expected." << std::endl;
    } else {
        std::cout << "Test Failed: compute function did not work as expected." << std::endl;
    }

    // Optionally, print sum of q and t for additional verification
    float sum_q = 0.0f, sum_t = 0.0f;
    for (const auto& row : q) {
        sum_q += std::accumulate(row.begin(), row.end(), 0.0f);
    }
    for (const auto& row : t) {
        sum_t += std::accumulate(row.begin(), row.end(), 0.0f);
    }

    std::cout << "Sum of q: " << sum_q << std::endl;
    std::cout << "Sum of t: " << sum_t << std::endl;

    return 0;
}