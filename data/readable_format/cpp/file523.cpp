#include <iostream>
#include <cmath>

class Powell {
public:
    void trsapp(int n, const double* d, double& crvmin) {
        crvmin = 0.0;
        for (int i = 0; i < n; ++i) {
            crvmin += d[i] * d[i];
        }
    }
};

int main() {
    Powell powell;
    const int n = 2;
    double d[n] = {1.0, 2.0};
    double crvmin = 0.0;

    powell.trsapp(n, d, crvmin);

    std::cout << "Step: Not applicable in this test" << std::endl;
    std::cout << "CRVMIN: " << crvmin << std::endl;

    return 0;
}