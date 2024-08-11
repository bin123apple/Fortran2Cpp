#include <vector>

void advance(std::vector<std::vector<float>>& q, std::vector<std::vector<float>>& v, 
             std::vector<std::vector<float>>& oq, std::vector<std::vector<float>>& f, 
             float dt, float& flg, int nmol, int ndim) {
    
    float dt2 = dt * dt;
    float dt2i = 1.0f / (2.0f * dt);
    float dti = 1.0f / dt;

    if (static_cast<int>(flg) == 0) {
        for (int j = 0; j < ndim; ++j) {
            for (int i = 0; i < nmol; ++i) {
                float temp = 2.0f * q[i][j] - oq[i][j] + f[i][j] * dt2;
                v[i][j] = (temp - oq[i][j]) * dt2i;
                oq[i][j] = q[i][j];
                q[i][j] = temp;
            }
        }
    } else {
        for (int j = 0; j < ndim; ++j) {
            for (int i = 0; i < nmol; ++i) {
                float temp = q[i][j] + v[i][j] * dt + 0.5f * f[i][j] * dt2;
                v[i][j] = (temp - q[i][j]) * dti;
                oq[i][j] = q[i][j];
                q[i][j] = temp;
            }
        }
        flg = 0.0f;
    }
}

int main() {
    // Define the size of your arrays
    int nmol = 64;
    int ndim = 3;
    float dt = 0.01f;
    float flg = 1.0f;

    // Initialize your arrays
    std::vector<std::vector<float>> q(nmol, std::vector<float>(ndim, 0.0f));
    std::vector<std::vector<float>> v(nmol, std::vector<float>(ndim, 0.0f));
    std::vector<std::vector<float>> oq(nmol, std::vector<float>(ndim, 0.0f));
    std::vector<std::vector<float>> f(nmol, std::vector<float>(ndim, 0.0f));

    // Call the advance function
    advance(q, v, oq, f, dt, flg, nmol, ndim);

    return 0;
}