#include <iostream>
#include <vector>

void updat(std::vector<double>& u, std::vector<double>& udt, std::vector<double>& udtt, const std::vector<double>& ui, double a6, double a7, double a8, double a9, double a10) {
    size_t neq = u.size();

    for (size_t i = 0; i < neq; ++i) {
        u[i] += ui[i];
    }

    for (size_t i = 0; i < neq; ++i) {
        double udttld = udtt[i];
        udtt[i] = a6 * ui[i] + a7 * udt[i] + a8 * udttld;
        udt[i] += a9 * udttld + a10 * udtt[i];
    }
}

int main() {
    int neq = 5;
    std::vector<double> u = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<double> udt = {0.1, 0.2, 0.3, 0.4, 0.5};
    std::vector<double> udtt = {0.01, 0.02, 0.03, 0.04, 0.05};
    std::vector<double> ui = {0.5, 0.5, 0.5, 0.5, 0.5};
    double a6 = 1.0, a7 = 1.0, a8 = 1.0, a9 = 1.0, a10 = 1.0;

    updat(u, udt, udtt, ui, a6, a7, a8, a9, a10);

    std::cout << "u: ";
    for (auto val : u) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << "udt: ";
    for (auto val : udt) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << "udtt: ";
    for (auto val : udtt) std::cout << val << " ";
    std::cout << std::endl;

    return 0;
}