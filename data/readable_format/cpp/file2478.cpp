#include <iostream>
#include <vector>

void seto2(int nz, const std::vector<double>& z, int nw, const std::vector<double>& wl, const std::vector<double>& cz, const std::vector<double>& o2xs1, std::vector<std::vector<double>>& dto2) {
    for (int iz = 0; iz < nz; ++iz) {
        for (int iw = 0; iw < nw - 1; ++iw) {
            dto2[iz][iw] = 0.2095 * cz[iz] * o2xs1[iw];
        }
        dto2[iz][nw - 1] = 0.0; // Set the last element to 0 explicitly
    }
}

int main() {
    const int nz = 3;
    const int nw = 4;
    std::vector<double> z = {1, 2, 3};
    std::vector<double> wl = {0.4, 0.5, 0.6, 0.7};
    std::vector<double> cz = {0.1, 0.2, 0.3};
    std::vector<double> o2xs1 = {0.01, 0.02, 0.03, 0.04};
    std::vector<std::vector<double>> dto2(nz, std::vector<double>(nw, 0.0));

    seto2(nz, z, nw, wl, cz, o2xs1, dto2);

    std::cout << "dto2:" << std::endl;
    for (int iz = 0; iz < nz; ++iz) {
        for (int iw = 0; iw < nw; ++iw) {
            std::cout << dto2[iz][iw] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}