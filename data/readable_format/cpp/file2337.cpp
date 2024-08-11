#include <iostream>
#include <vector>

// Forward declarations of the functions
void compute_column(int nz, std::vector<std::vector<float>>& q, std::vector<std::vector<float>>& t, std::vector<float>& s, int nproma);
void compute(int nz, std::vector<std::vector<float>>& q, std::vector<std::vector<float>>& t, std::vector<float>& s, int nproma);

// Function definitions

void compute(int nz, std::vector<std::vector<float>>& q, std::vector<std::vector<float>>& t, std::vector<float>& s, int nproma) {
    compute_column(nz, q, t, s, nproma);
}

void compute_column(int nz, std::vector<std::vector<float>>& q, std::vector<std::vector<float>>& t, std::vector<float>& s, int nproma) {
    std::vector<std::vector<float>> y(nproma, std::vector<float>(nz));
    float c;
    int proma;

    for (proma = 0; proma < nproma; ++proma) {
        c = 5.345f;

        for (int k = 1; k < nz; ++k) {
            t[proma][k] = c * (k + 1);
            y[proma][k] = t[proma][k] + s[proma];
            q[proma][k] = q[proma][k - 1] + t[proma][k] * c + y[proma][k];
        }
        q[proma][nz - 1] *= c;
    }
}

// Unit test function
void test_compute() {
    int nproma = 3;
    int nz = 5;

    std::vector<std::vector<float>> t(nproma, std::vector<float>(nz, 0.0f));
    std::vector<std::vector<float>> q(nproma, std::vector<float>(nz, 0.0f));
    std::vector<float> s(nproma, 1.0f);

    compute(nz, q, t, s, nproma);

    std::cout << "Results:" << std::endl;
    for (int i = 0; i < nproma; ++i) {
        for (int j = 0; j < nz; ++j) {
            std::cout << "t[" << i << "][" << j << "] = " << t[i][j] << " ";
            std::cout << "q[" << i << "][" << j << "] = " << q[i][j] << std::endl;
        }
    }
}

int main() {
    test_compute();
    return 0;
}