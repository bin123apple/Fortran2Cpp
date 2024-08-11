#include <iostream>
#include <vector>
#include <cmath>

void SLARRA(int n, std::vector<float>& d, std::vector<float>& e, std::vector<float>& e2, float spltol, float tnrm,
            int& nsplit, std::vector<int>& isplit, int& info) {
    
    const float ZERO = 0.0f;
    float eabs, tmp1;
    info = 0;
    
    if (n <= 0) {
        return;
    }
    
    nsplit = 1;
    if (spltol < ZERO) {
        tmp1 = std::abs(spltol) * tnrm;
        for (int i = 0; i < n-1; ++i) {
            eabs = std::abs(e[i]);
            if (eabs <= tmp1) {
                e[i] = ZERO;
                e2[i] = ZERO;
                isplit[nsplit - 1] = i + 1; // Fortran to C++ index adjustment
                nsplit++;
            }
        }
    } else {
        for (int i = 0; i < n-1; ++i) {
            eabs = std::abs(e[i]);
            if (eabs <= spltol * std::sqrt(std::abs(d[i]))*std::sqrt(std::abs(d[i+1]))) {
                e[i] = ZERO;
                e2[i] = ZERO;
                isplit[nsplit - 1] = i + 1; // Fortran to C++ index adjustment
                nsplit++;
            }
        }
    }
    
    isplit[nsplit - 1] = n; // Final split point
}

int main() {
    std::vector<float> d = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<float> e = {0.1, 0.2, 0.3, 0.4};
    std::vector<float> e2(e.size());
    for (size_t i = 0; i < e.size(); ++i) {
        e2[i] = e[i] * e[i];
    }
    float spltol = 0.15f;
    float tnrm = 5.0f;
    int nsplit, info;
    std::vector<int> isplit(d.size(), 0); // Initialize vector with 0

    SLARRA(d.size(), d, e, e2, spltol, tnrm, nsplit, isplit, info);

    std::cout << "INFO: " << info << std::endl;
    std::cout << "NSPLIT: " << nsplit << std::endl;
    std::cout << "ISPLIT: ";
    for (int i = 0; i < nsplit; ++i) {
        std::cout << isplit[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}