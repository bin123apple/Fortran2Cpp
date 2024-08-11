// mo_column.cpp
#include <iostream>
#include <vector>
#include <cmath>

class Column {
public:
    void compute(int nz, std::vector<std::vector<float>>& q, std::vector<std::vector<float>>& t, std::vector<float>& z, int nproma) {
        compute_column(nz, q, t, z, nproma);
    }

private:
    void compute_column(int nz, std::vector<std::vector<float>>& q, std::vector<std::vector<float>>& t, std::vector<float>& z, int nproma) {
        for (int proma = 0; proma < nproma; ++proma) {
            float c = 5.345f;
            float p = std::pow(c, 2.0f);
            for (int k = 1; k < nz; ++k) { // Starts from 1 for alignment with Fortran
                t[proma][k] = c * (k+1); // Adjusted to match Fortran logic
                p = t[proma][k] + 1.0f;
                q[proma][k] = q[proma][k - 1] + t[proma][k] * c;
                if (p > 2.0f) {
                    q[proma][k] = q[proma][k - 1] + t[proma][k] * c * 2.0f;
                }
            }
            q[proma][nz - 1] *= c;
        }
    }
};

int main() {
    int nz = 5;
    int nproma = 3;

    std::vector<std::vector<float>> t(nproma, std::vector<float>(nz, 0.0f));
    std::vector<std::vector<float>> q(nproma, std::vector<float>(nz, 1.0f));
    std::vector<float> z(nproma, 2.0f);

    Column column;
    column.compute(nz, q, t, z, nproma);

    // Print the results for verification
    std::cout << "Array t:" << std::endl;
    for (const auto& row : t) {
        for (const auto& val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "====================" << std::endl;

    std::cout << "Array q:" << std::endl;
    for (const auto& row : q) {
        for (const auto& val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}