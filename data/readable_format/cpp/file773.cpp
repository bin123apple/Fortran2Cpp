// ksd.cpp
#include <vector>
#include <cmath>
#include <iostream>

void ksd(double& df, const std::vector<double>& g, const std::vector<double>& dgdx, int ng, double rho) {
    const double toler = -40.0;
    double sum1 = 0.0;
    double sum2 = 0.0;
    double gmax = g[0];
    
    if (ng < 2) goto label30;
    for (int i = 1; i < ng; ++i) {
        if (g[i] > gmax) gmax = g[i];
    }
    
    for (int i = 0; i < ng; ++i) {
        double val = rho * (g[i] - gmax);
        if (val < toler) continue;
        sum1 += exp(val) * dgdx[i];
        sum2 += exp(val);
    }
    
label30:
    df = dgdx[0];
    if (ng > 1) df = sum1 / sum2;
}

int main() {
    std::vector<double> g = {1.0, 2.0, 3.0};
    std::vector<double> dgdx = {0.1, 0.2, 0.3};
    double df;
    double rho = 1.0;
    int ng = g.size();

    ksd(df, g, dgdx, ng, rho);

    std::cout << "Computed df: " << df << std::endl;
    return 0;
}