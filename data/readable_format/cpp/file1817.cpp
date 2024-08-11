// advec_corrected.cpp
#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>

int main() {
    const int x_s = 12;
    const int t_s = 100;
    const float dt = 0.1f;
    const float dx = 0.1f;
    const float c = 1.0f;
    const float decay = 0.02f;
    const int ipos = 25 - 1;
    std::vector<float> u(x_s, 0.0f);
    std::vector<float> du(x_s, 0.0f);  // Adjusted size

    // Initialization
    for (int i = 0; i < x_s; ++i) {
        u[i] = std::exp(-decay * std::pow(i - ipos, 2));
    }

    // Simulation loop
    for (int i = 0; i < t_s; ++i) {
        for (int j = 0; j < x_s - 1; ++j) {
            du[j] = u[j + 1] - u[j];
        }
        du[x_s - 1] = u[0] - u[x_s - 1];  // Corrected for circular boundary condition

        for (int j = 0; j < x_s; ++j) {
            u[j] = u[j] - c * du[j] / dx * dt;
        }

        if (i == 0 || i == t_s - 1) {
            std::cout << "Iteration " << i + 1 << " sum: " << std::accumulate(u.begin(), u.end(), 0.0f) << std::endl;
        }
    }

    return 0;
}