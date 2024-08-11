#include <vector>
#include <iostream>
#include <cmath> // For std::abs

// Definition of the MoColumn class
class MoColumn {
public:
    void compute(int nz, std::vector<std::vector<float>>& t, std::vector<std::vector<float>>& q, int nproma) {
        float c = 5.345f;
        for (int k = 1; k < nz; ++k) {
            for (int proma = 0; proma < nproma; ++proma) {
                t[k][proma] = c * (k + 1); // Adjusted for 1-based indexing in the original Fortran code
                q[k][proma] = q[k - 1][proma] + t[k][proma] * c;
            }
        }
        for (int proma = 0; proma < nproma; ++proma) {
            q[nz - 1][proma] *= c; // Adjusted for 0-based indexing
        }
    }
};

// Main function or test function
int main() {
    MoColumn column;
    int nz = 5; // Number of vertical levels
    int nproma = 3; // Number of columns
    std::vector<std::vector<float>> t(nz, std::vector<float>(nproma, 0.0f)); // Temperature array
    std::vector<std::vector<float>> q(nz, std::vector<float>(nproma, 0.0f)); // Humidity array

    column.compute(nz, t, q, nproma);

    // Example of output for verification purposes
    std::cout << "T array:" << std::endl;
    for (const auto &row : t) {
        for (float val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Q array:" << std::endl;
    for (const auto &row : q) {
        for (float val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}