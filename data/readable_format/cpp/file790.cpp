#include <iostream>
#include <vector>

class mo_column {
public:
    static std::vector<std::vector<float>> compute_column(int nz, std::vector<std::vector<float>>& q, std::vector<std::vector<float>>& t, int nproma) {
        std::vector<std::vector<float>> res(nz, std::vector<float>(nproma));
        float c = 5.345f;
        for (int proma = 0; proma < nproma; ++proma) {
            for (int k = 1; k < nz; ++k) {
                t[k][proma] = c * (k + 1);
                q[proma][k] = t[k - 1][proma] + t[k][proma] * c;
            }
            q[proma][nz - 1] *= c;
            for (int i = 0; i < nz; ++i) {
                res[i][proma] = t[i][proma];
            }
        }
        return res;
    }

    static void compute_all(int nz, std::vector<std::vector<float>>& q, std::vector<std::vector<float>>& t, int nproma) {
        auto res = compute_column(nz, q, t, nproma);
    }
};

int main() {
    int nz = 3, nproma = 2;
    std::vector<std::vector<float>> t = {{1.0f, 4.0f}, {2.0f, 5.0f}, {3.0f, 6.0f}};
    std::vector<std::vector<float>> q = {{6.0f, 3.0f}, {5.0f, 2.0f}, {4.0f, 1.0f}};

    mo_column::compute_all(nz, q, t, nproma);

    std::cout << "Testing compute_all:" << std::endl;
    for (int i = 0; i < nz; ++i) {
        for (int j = 0; j < nproma; ++j) {
            std::cout << "t(" << i << "," << j << ") = " << t[i][j] << std::endl;
        }
    }
    for (int i = 0; i < nproma; ++i) {
        for (int j = 0; j < nz; ++j) {
            std::cout << "q(" << i << "," << j << ") = " << q[i][j] << std::endl;
        }
    }

    return 0;
}