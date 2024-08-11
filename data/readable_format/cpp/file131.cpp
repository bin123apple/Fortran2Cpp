#include <iostream>
#include <vector>

// Define the compute function directly in the global namespace
void compute(int nz, int b, std::vector<std::vector<float>>& q, std::vector<std::vector<float>>& t, int nproma) {
    float c = 5.345f;
    for (int k = 1; k < nz; ++k) {
        for (int proma = 0; proma < nproma; ++proma) {
            t[k][proma] = c * (k + 1); // +1 because Fortran index starts at 1
            q[k][proma] = q[k - 1][proma] + t[k][proma] * c;
        }
    }
    for (int proma = 0; proma < nproma; ++proma) {
        q[nz - 1][proma] *= c; // -1 because of zero-based indexing
    }
}

// Main function to test compute
int main() {
    const int nproma = 2, nz = 3, b = 3;
    std::vector<std::vector<float>> t(b, std::vector<float>(nproma, 0.0f));
    std::vector<std::vector<float>> q(b, std::vector<float>(nproma, 0.0f));

    // Call the compute function
    compute(nz, b, q, t, nproma);

    // Output the results for T
    std::cout << "Results for T:" << std::endl;
    for (const auto& row : t) {
        for (float val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    // Output the results for Q
    std::cout << "Results for Q:" << std::endl;
    for (const auto& row : q) {
        for (float val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}