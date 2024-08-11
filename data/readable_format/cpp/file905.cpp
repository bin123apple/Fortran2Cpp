#include <vector>
#include <iostream>

class mo_column {
public:
    void compute_column(int nz, std::vector<std::vector<float>>& q, std::vector<std::vector<float>>& t, bool l, int nproma) {
        if (!l) return; // Early exit if l is false, matching Fortran logic.
        
        float c = 5.345f;
        for (int proma = 0; proma < nproma; ++proma) {
            for (int k = 1; k < nz; ++k) { // Note: C++ uses 0-based indexing
                t[proma][k] = c * (k + 1); // Adjusted for 0-based indexing
                q[proma][k] = q[proma][k - 1] + t[proma][k] * c;
            }
            q[proma][nz - 1] *= c; // Adjusted for 0-based indexing
        }
    }
};

// C++ Unit Test Code using a simple main function
int main() {
    int nz = 5, nproma = 2;
    std::vector<std::vector<float>> t(nproma, std::vector<float>(nz, 0));
    std::vector<std::vector<float>> q(nproma, std::vector<float>(nz, 0));
    bool l = true;

    mo_column column;
    column.compute_column(nz, q, t, l, nproma);

    // Output results to match Fortran output format for manual verification
    std::cout << "Testing compute_column function: ";
    for (int i = 0; i < nproma; ++i) {
        std::cout << "ProMa = " << i + 1 << " ";
        for (int j = 0; j < nz; ++j) {
            std::cout << "t(" << i + 1 << ", " << j + 1 << ") = " << t[i][j] << " q(" << i + 1 << ", " << j + 1 << ") = " << q[i][j] << " ";
        }
        std::cout << std::endl; // Add a newline for readability
    }

    return 0;
}