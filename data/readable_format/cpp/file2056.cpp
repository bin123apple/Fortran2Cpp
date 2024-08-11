#include <iostream>
#include <vector>

// Assuming the umpc_user signature as before
void umpc_user(const std::vector<std::vector<double>>& x, const std::vector<std::vector<double>>& u, double* f, const std::vector<double>& a, const std::vector<int>& jdof, size_t n, double& force, int iit, int idiscon) {
    force = 0.0;
    for (size_t i = 0; i < n; ++i) {
        force += a[i];
    }
}

int main() {
    // Example test case
    size_t n = 5;
    std::vector<std::vector<double>> x(2, std::vector<double>(3, 0)); // 2x3 matrix filled with 0s
    std::vector<std::vector<double>> u(2, std::vector<double>(3, 0)); // 2x3 matrix filled with 0s
    double f = 0.0;
    std::vector<double> a = {1, 2, 3, 4, 5}; // Example array
    std::vector<int> jdof(n, 0); // Just dummy data
    double force = 0.0;
    int iit = 1; // Dummy data
    int idiscon = 1; // Dummy data

    umpc_user(x, u, &f, a, jdof, n, force, iit, idiscon);

    std::cout << "Force: " << force << std::endl; // Expected output: Force: 15

    return 0;
}