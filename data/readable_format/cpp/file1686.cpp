#include <iostream>
#include <vector>

void fd(const std::vector<double>& data_in, std::vector<double>& df_out, int N, double dx, int kd) {
    std::vector<double> temp_data_in(N + 2 * kd);
    std::vector<double> cd1(9); // For coefficients -4 to 4, but in 0-based indexing

    // Copy data_in to the middle part of temp_data_in
    for(int i = 0; i < N; ++i) {
        temp_data_in[i + kd] = data_in[i];
    }

    // Implement periodic boundary conditions
    for(int i = 1; i <= kd; ++i) {
        temp_data_in[kd - i] = data_in[N - i];
        temp_data_in[N + kd - 1 + i] = data_in[i - 1];
    }

    // Coefficients, using 0-based indexing for cd1
    cd1[4 - 4] = 1.0 / 280.0;
    cd1[4 - 3] = -4.0 / 105.0;
    cd1[4 - 2] = 0.2;
    cd1[4 - 1] = -0.8;
    cd1[4] = 0.0;
    cd1[4 + 1] = 0.8;
    cd1[4 + 2] = -0.2;
    cd1[4 + 3] = 4.0 / 105.0;
    cd1[4 + 4] = -1.0 / 280.0;

    // Calculate finite differences
    for(int j = 0; j < N; ++j) {
        double s = 0.0;
        for(int i = -kd; i <= kd; ++i) {
            s += cd1[i + 4] * temp_data_in[j + i + kd]; // Adjusted indexing for cd1
        }
        s /= dx;
        df_out[j] = s;
    }
}

int main() {
    std::vector<double> data_in = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<double> df_out(data_in.size(), 0.0); // Initialized with zeros
    int N = 5;
    double dx = 0.1;
    int kd = 4;

    fd(data_in, df_out, N, dx, kd);

    std::cout << "Test 1: N=5, dx=0.1, kd=4" << std::endl;
    for (auto val : df_out) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}