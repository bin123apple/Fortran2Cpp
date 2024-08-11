#include <iostream>
#include <vector>

class Column {
public:
    std::vector<std::vector<float>> compute_column(int nz, std::vector<std::vector<float>>& q, std::vector<std::vector<float>>& t, int nproma) {
        float c = 5.345;
        std::vector<std::vector<float>> res(nz, std::vector<float>(nproma));

        for (int k = 1; k < nz; ++k) {
            for (int proma = 0; proma < nproma; ++proma) {
                t[k][proma] = c * (k + 1);  // Adjusted for zero-based indexing
                q[proma][k] = t[k - 1][proma] + t[k][proma] * c;
            }
        }

        for (int proma = 0; proma < nproma; ++proma) {
            q[proma][nz - 1] *= c;
        }

        res = t;
        return res;
    }

    void compute_all(int nz, std::vector<std::vector<float>>& q, std::vector<std::vector<float>>& t, int nproma) {
        std::vector<std::vector<float>> z(nproma, std::vector<float>(nz));

        for (int k = 0; k < nz; ++k) {
            for (int proma = 0; proma < nproma; ++proma) {
                z[proma][k] = t[k][proma] + q[proma][k];
            }
        }

        auto res = compute_column(nz, q, t, nproma);

        // Optionally use res for further processing
    }
};

int main() {
    int nz = 5, nproma = 3;
    std::vector<std::vector<float>> t(nz, std::vector<float>(nproma, 0.0));
    std::vector<std::vector<float>> q(nproma, std::vector<float>(nz, 0.0));  // Adjusted dimensions to match Fortran code

    Column col;
    col.compute_all(nz, q, t, nproma);

    // Output results for verification
    std::cout << "Matrix t:" << std::endl;
    for (int i = 0; i < nz; ++i) {
        for (int j = 0; j < nproma; ++j) {
            std::cout << t[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Matrix q:" << std::endl;
    for (int i = 0; i < nproma; ++i) {
        for (int j = 0; j < nz; ++j) {
            std::cout << q[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}