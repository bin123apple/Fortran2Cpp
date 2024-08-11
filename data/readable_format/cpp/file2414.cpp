#include <iostream>
#include <vector>

class Column {
public:
    void compute(int nz, std::vector<std::vector<float>>& q, std::vector<std::vector<float>>& t, std::vector<float>& s, int nproma) {
        compute_column(nz, q, t, s, nproma);
    }

private:
    void compute_column(int nz, std::vector<std::vector<float>>& q, std::vector<std::vector<float>>& t, std::vector<float>& s, int nproma) {
        std::vector<float> y(nz, 0.0);
        float c = 5.345f;

        for (int k = 1; k < nz; ++k) { // Adjusted to start from 1 for direct comparison
            for (int proma = 0; proma < nproma; ++proma) {
                t[proma][k] = c * (k + 1); // Adjusted to match Fortran's 1-based indexing
                y[k] = t[proma][k] + s[proma];
                q[proma][k] = q[proma][k - 1] + t[proma][k] * c + y[k];
            }
        }

        for (int proma = 0; proma < nproma; ++proma) {
            q[proma][nz - 1] *= c;
        }
    }
};

int main() {
    int nz = 10;
    int nproma = 5;
    std::vector<std::vector<float>> q(nproma, std::vector<float>(nz, 0.0f));
    std::vector<std::vector<float>> t(nproma, std::vector<float>(nz, 0.0f));
    std::vector<float> s(nproma, 1.0f);

    Column column;
    column.compute(nz, q, t, s, nproma);

    for (int i = 0; i < nproma; ++i) {
        for (int j = 0; j < nz; ++j) {
            std::cout << "q(" << i + 1 << ", " << j + 1 << ") = " << q[i][j] << std::endl;
        }
    }

    return 0;
}